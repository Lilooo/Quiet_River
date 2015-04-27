/* Quiet-River
By: Alice
inspired by : Andrew Tuline
Date: Avril 2015
Blue sine wave interference pattern.
*/

#include "FastLED.h"
#include <avr/power.h>

// Fixed definitions
#define DATA_PIN 6
#define CLOCK_PIN 11
#define COLOR_ORDER RGB                                      
#define LED_TYPE NEOPIXEL
#define NUM_LEDS 29

CRGB leds[NUM_LEDS];

// The following variables can be changed.
int wave1=0;
int wave2=0;
int wave3=0;

void setup() {
  // To make it work w/ an 8 Mhz proc (example : Lilypad Arduino)
  clock_prescale_set(clock_div_2);
  
  // Use this for WS2801 Leds
  //  LEDS.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  // Use this for NEOPIXEL
  LEDS.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);  
}


void loop() {
  // Waves of different frequencies
  wave1+=835;                                    
  wave2-=693;                                    
  wave3+=493;

  for (int k=0; k<NUM_LEDS; k++) {
    //Three combined waves (added)
   leds[k].b = ((sin16(wave1+k*wave1)/256+128) + (sin16(wave2+k*wave2)/256+128)+ (sin16(wave3+k*wave3)/256+128))/4;    
  }
  LEDS.show();
  delay(60);
}
