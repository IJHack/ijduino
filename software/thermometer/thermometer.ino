//We always have to include the library
#include "LedControl.h"
#include "font.h"
#include <avr/pgmspace.h>

/* using VCC, GND, DIN 21, CS 21, CLK 5 for the MAX7219 */
LedControl lc=LedControl(20,5,21,1);

void setup() {
  //we have already set the number of devices when we created the LedControl
  int devices=lc.getDeviceCount();
  //we have to init all devices in a loop
  for(int address=0;address<devices;address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    lc.shutdown(address,false);
    /* Set the brightness to a medium values */
    lc.setIntensity(address,8);
    /* and clear the display */
    lc.clearDisplay(address);
  }

}

// Change these values to adjust scroll speeds and animation iterations

#define TEXT_SCROLL_SPEED 100     // how fast to scrill the text (wait)

#define REPEAT_TEXT 1              // how often to repeat the text if in cycling mode

// How to add a new message:
// * add the new message (only upper case, see font.h)
// * adjust MAX_MESSAGES
// * add the new message to messages
// NOTE: messages may not be longer than 255 chars.
// http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1193587488
// Since 0012, PGM_P is broken. Fortunately there's a workaround 

char message_00[] PROGMEM = "Serial IJhack v1.1 ";
char message_01[] PROGMEM = "test ";
char message_02[] PROGMEM = "lol";

#define MAX_MESSAGES 3
//PGM_P PROGMEM messages[] = {
PROGMEM const char *messages[] = {  
    message_00
    ,message_01
    ,message_02
}; 

uint8_t screen_mem[64];                  // screen memory
uint8_t active_row=1;                  // active row
uint8_t message_ptr = 0;                 // points to the active char in the message
uint8_t message_displayed = 0;           // how often has the message been displayed?
uint8_t active_char = 0;                 // stores the active char
uint8_t message_length = 0;              // stores the length of the active message
uint8_t char_ptr = 0;                    // points to the active col in the char
uint8_t char_length = 0;                 // stores the length of the active char
/*
* copy screen_mem[] to LED Matrix 8x8
*/
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  int i;
  for (i=0; i<8; i++){
    lc.setRow(7,i,screen_mem[i+56]);
    lc.setRow(6,i,screen_mem[i+48]);
    lc.setRow(5,i,screen_mem[i+40]);
    lc.setRow(4,i,screen_mem[i+32]);
    lc.setRow(3,i,screen_mem[i+24]);
    lc.setRow(2,i,screen_mem[i+16]);  
    lc.setRow(1,i,screen_mem[i+8]); 
    lc.setRow(0,i,screen_mem[i]) ;
  }
}
/*
* show_char
* Displays the actual message. 
* Scrolls the screen to the left and draws new pixels on the right.
* char stop bit is bit.7
*/
void show_char(const prog_uint8_t string[]) {
  uint8_t i;
  uint8_t b;

// shift the screen to the left
  for (i = 0; i < 63; i++) {
    screen_mem[i] = screen_mem[i+1]; 
}
  // advance a char if needed
  if (char_length == 0x80) {

   char_length =0;      //reset stop bit

    //read next char from progmem
    memcpy_P(&active_char,&string[message_ptr],1);
    //this is an alternativ PROGMEM access:
    //active_char =  pgm_read_byte_near(string + message_ptr);
    message_ptr++;

    //string stop byte 0x00 
    if (active_char == 0) {
      message_ptr = 0;
      message_displayed++;
      char_length =0x80; // immediately read next char
    }

    active_char -= CHAR_OFFSET;
    char_ptr = 0;

    // this makes the space between two chars
    screen_mem[63]=0;
    return; 
  }

  // read pixels for current column of char
  b = pgm_read_byte(&font[active_char * 5 + char_ptr]);
  char_ptr++;
  //char_length= (b & 0x01);
  //b = (b >> 1);
  char_length= (b & 0x80);
  b = (b & 0x7F);
  // write pixels into screen memory
  screen_mem[63] =b;
  Serial.print((uint16_t)active_char); Serial.print(" / "); Serial.println(char_ptr, HEX); 
}


/*
* copy_to_buffer
* Copies the given sprite from PROGMEM to 8x8 LED RAM.
*/
void copy_to_buffer(const prog_uint8_t sprite[8]) {
  memcpy_P(screen_mem, sprite, 8);
}




void loop() {
  
  int devices=lc.getDeviceCount();
  int8_t i,j,k;

  while (1) {
  
   
   
      writeArduinoOnMatrix(); 
      delay(TEXT_SCROLL_SPEED);
    

    

    //6
    for (i = 0; i < MAX_MESSAGES; i++) {
      message_displayed = 0;
      while (message_displayed < REPEAT_TEXT) {
        show_char((uint8_t*)pgm_read_word(&(messages)));  //show_char((prog_uint8_t*)pgm_read_word(&(messages[i])));
        writeArduinoOnMatrix(); 
        delay(TEXT_SCROLL_SPEED);
      }
    }



  }

}

