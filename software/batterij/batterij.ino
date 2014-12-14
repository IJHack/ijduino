
#include "LedControl.h"
#include "penlight.h"
#include "lipo.h"

static const float Vin = 4.5;

/* using VCC, GND, DIN 20, CS 21, CLK 5 for the MAX7219 */
static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

LedControl lc=LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);

void setup() {
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,15);
  /* and clear the display */
  lc.clearDisplay(0);
}

void loop() {
  float batteryV;
  for (;;)  { 
    batteryV = analogRead(A0) / (51.0 * Vin);
    
    if (batteryV <= 1) {
      render(penlight1,20);
    } 
    else if (batteryV <= 1.1) {
      render(penlight2,20);
    }
    else if (batteryV <= 1.2) {
      render(penlight3,20);
    }
    else if (batteryV <= 1.3) {
      render(penlight4,20);
    }
    else if  (batteryV <= 1.4) {
      render(penlight5,20);
    }
    else if (batteryV <= 1.5) {
      render(penlight6,20);
    }
    else if (batteryV <= 2) {
      render(penlight7,20);
    } 
    else if (batteryV <= 3.6) {
      render(lipo1,20);
    } 
    else if (batteryV <= 3.7) {
      render(lipo2,20);
    }
    else if (batteryV <= 3.8) {
      render(lipo3,20);
    }
    else if (batteryV <= 3.9) {
      render(lipo4,20);
    }
    else if  (batteryV <= 4) {
      render(lipo5,20);
    }
    else if (batteryV <= 4.1) {
      render(lipo6,20);
    }
    else {
      render(lipo7,20);
    }
  }
}

void render(const byte* frame, long delaytime) {
    for (int r = 0; r < 8; r++) {
        lc.setColumn(0, 7-r, pgm_read_byte(&frame[r]));
    }
} 





