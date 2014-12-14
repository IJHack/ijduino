// Developed by Eduardo Zola (Zola Labs)

#include "LedControl.h"

byte MSG[8*20];

byte SPACE[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000  
};


byte Z[8] = {
  B00000000,
  B01111110,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01111110,
  B00000000  
};


byte O[8] = {
  B00000000,
  B00111100,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00111100,
  B00000000  
};

byte L[8] = {
  B00000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01111110,
  B00000000  
};

byte A[8] = {
  B00000000,
  B00011000,
  B00100100,
  B01000010,
  B01111110,
  B01000010,
  B01000010,
  B00000000  
};


byte P[8] = {
  B00000000,
  B01111100,
  B01000010,
  B01000010,
  B01111100,
  B01000000,
  B01000000,
  B00000000  
};

byte E[8] = {
  B00000000,
  B01111110,
  B01000000,
  B01111100,
  B01000000,
  B01000000,
  B01111110,
  B00000000  
};

byte R[8] = {
  B00000000,
  B01111100,
  B01000010,
  B01111100,
  B01001000,
  B01000100,
  B01000010,
  B00000000  
};


byte B[8] = {
  B00000000,
  B01111100,
  B01000010,
  B01111100,
  B01000010,
  B01000010,
  B01111100,
  B00000000  
};


byte W[8] = {
  B00000000,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01011010,
  B01100110,
  B00000000  
};

byte N[8] = {
  B00000000,
  B01000010,
  B01100010,
  B01010010,
  B01001010,
  B01000110,
  B01000010,
  B00000000  
};


byte I[8] = {
  B00000000,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00111100,
  B00000000
};


int ledPin = 13; 
int speakerPin = 8;

#define N_c 261
#define N_d 294
#define N_e 329
#define N_f 349
#define N_g 391
#define N_gS 415
#define N_a 440
#define N_aS 455
#define N_b 466
#define N_cH 523
#define N_cSH 554
#define N_dH 587
#define N_dSH 622
#define N_eH 659
#define N_fH 698
#define N_fSH 740
#define N_gH 784
#define N_gSH 830
#define N_aH 880

int step_col;
int step_row;
int subidas; 
boolean showBars_enabled = false;
int row_bar = 0;
 
LedControl LC=LedControl(20,5,21,2);   // 2 =  dois modulos de matrizes de led
//LedControl LC2=LedControl(speakerPin,6,5,1);

int X = 4,OLD_X,sensor;

int row,col;
int sc,sr;

int cnt = 0;
int desarma = 0;

boolean INTRO_SHOWED = false;

int dly;

void setup() {

  Serial.begin(9600);

  pinMode(A5,INPUT);
  pinMode(speakerPin, OUTPUT);


  LC.shutdown(0,false);
  LC.setIntensity(0,8);
  LC.clearDisplay(0);

  LC.shutdown(1,false);
  LC.setIntensity(1,8);
  LC.clearDisplay(1);

   randomSeed(analogRead(1)*millis());

  if(INTRO_SHOWED == false)
  {
     copyLetter(SPACE,0);
     copyLetter(SPACE,1);
     
     copyLetter(Z,2);
     copyLetter(O,3);
     copyLetter(L,4);   
     copyLetter(A,5);
  
     copyLetter(SPACE,6);
  
     copyLetter(L,7);
     copyLetter(A,8);   
     copyLetter(B,9);   
     copyLetter(SPACE,10);
     copyLetter(SPACE,11);

     showMSG(11,50); 

     INTRO_SHOWED = true;
   } 
 
   loose();

   dly = 500;
   
   setLED(15,X,true);setLED(15,X+1,true);setLED(15,X+2,true);
   OLD_X = -1;
   subidas = 0;

   step_col = 1;
   step_row = 1;

   sc = step_col;
   sr = step_row;

//   row = -step_row;
   row = -1+random(3);
   col = random(8);
   
   showBars(false);     
}




void loop() 
{ 
 
  
   sensor = analogRead(A5);

//Serial.println(sensor);
   X = map(sensor,0,980,1,6);

//   X = int(sensor / 127);
//   if(X < 1) X = 1;
//   if(X > 6) X = 6;
   
   if(X != OLD_X)
   {
      OLD_X = X;
      setROW(15,0x00);   
      setLED(15,X-1,true);setLED(15,X,true);setLED(15,X+1,true);
   }
  

   if(cnt == 0) 
   {
     setLED(row,col,false);

     
     if((subidas==1 || random(2)==1) && showBars_enabled == false && row == 0) {showBars(true);subidas=0;desarma=2+random(5);};
     if(subidas==desarma && showBars_enabled == true) {showBars(false);subidas=0;};

     if(col == 7) {sc = -step_col;tone(speakerPin,1000,20);};
     if(col == 0) {sc = step_col;tone(speakerPin,1000,20);};

     if(row == 0) {sr = step_row;subidas++;dly-=5;tone(speakerPin,1000,20);};
     if(dly <= 190) winner();

     if(showBars_enabled == true && sr > 0 && row < row_bar)
     {
         if(row == row_bar - 1) {sr=-step_row;tone(speakerPin,1000,20);};
     }  

     if(row == 14)
     {
        if(col >= X-1 && col <= X+1) {sr = -step_row;tone(speakerPin,1500,20);}
        else if(col == X-2 && sc > 0) {sr = -step_row; sc = -step_col;tone(speakerPin,1500,20);}
        else if(col == X+2 && sc < 0) {sr = -step_row; sc = step_col;tone(speakerPin,1500,20);};
     }
     
     row += sr;
     col += sc;

     if(col == 8) col = 7;
     if(col == -1) col = 0;

     setLED(row,col,true);

     if(row == 15) setup();

     
   }
   
   cnt++;
   if(cnt == dly) cnt = 0;
}


void setLED(int l,int c, boolean state)
{
    int disp=0;
    if(l > 7) {l = l-8;disp=1;};
    LC.setLed(disp,l,c,state); 
}

void setROW(int r,char ch)
{
   int disp = 0;
   if(r > 7) {r = r - 8; disp=1;};   
   LC.setRow(disp,r,ch);
}

void loose()
{
    delay(80);
    for(row = 0;row<16;row++)
    {
       setROW(row,0xFF);
       tone(speakerPin,row*500,10);
       delay(20);       
    } 

    delay(130);
    
    for(row = 15;row>=0;row--)
    {
       setROW(row,0x00);
       tone(speakerPin,row*500,10);
       delay(20);       
    } 
       
}



void showBars(boolean show)
{
   showBars_enabled = show;

   if(show) row_bar = 2+random(5);
   setROW(row_bar,(show == true ? 0xFF : 0x00) );
}

void showLetter(int r,byte *ch)
{
    int i;
    for(i = 0;i < 8;i++) setROW(r+i,*(ch+i));
}

void copyLetter(byte *ch,int pos)
{
    int i;
    for(i = 0;i<8;i++) *(MSG+i+(pos*8)) = *(ch+i);
}

void showMSG(int qtde,int tempo)
{
   LC.clearDisplay(0);
   LC.clearDisplay(1);

   int idx;   
   for(idx = 0; idx < 8*qtde;idx ++)
   {
      for(row = 0;row<16;row++) setROW(row,*(MSG+row+idx));
      delay(tempo); 
   }

  LC.clearDisplay(0);
  LC.clearDisplay(1);
 
}



void winner()
{
     copyLetter(SPACE,0);
     copyLetter(SPACE,1);
     
     copyLetter(W,2);
     copyLetter(I,3);
     copyLetter(N,4);   
     copyLetter(N,5);
     copyLetter(E,6);
     copyLetter(R,7);
  
     copyLetter(SPACE,8);
     copyLetter(SPACE,9);

     showMSG(9,80); 

     march();
     setup();   
}


void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{ 
    digitalWrite(ledPin, HIGH);	 
    //use led to visualize the notes being played
    
    int x; 	 
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
 
    for(row = 0;row<16;row++) setROW(row,0xFF);

    for (x=0;x<loopTime;x++) 	 
    { 	 
        digitalWrite(speakerPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speakerPin,LOW);
        delayMicroseconds(delayAmount);
    } 	 
    
    digitalWrite(ledPin, LOW);
    //set led back to low
    
    LC.clearDisplay(0);
    LC.clearDisplay(1);    

    delay(20);
    //a little delay to make all notes sound separate
} 	 



void march()
{ 	 
    beep(speakerPin, N_a, 500); 
    beep(speakerPin, N_a, 500);     
    beep(speakerPin, N_a, 500); 
    beep(speakerPin, N_f, 350); 
    beep(speakerPin, N_cH, 150);
    
    beep(speakerPin, N_a, 500);
    beep(speakerPin, N_f, 350);
    beep(speakerPin, N_cH, 150);
    beep(speakerPin, N_a, 1000);
    //first bit
    
    beep(speakerPin, N_eH, 500);
    beep(speakerPin, N_eH, 500);
    beep(speakerPin, N_eH, 500);    
    beep(speakerPin, N_fH, 350); 
    beep(speakerPin, N_cH, 150);
    
    beep(speakerPin, N_gS, 500);
    beep(speakerPin, N_f, 350);
    beep(speakerPin, N_cH, 150);
    beep(speakerPin, N_a, 1000);
    //second bit...    
}


