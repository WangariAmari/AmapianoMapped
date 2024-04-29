#include <FastLED.h>


#define LED_PIN  7

#define NUM_LEDS 20

CRGB leds[NUM_LEDS]; /* an array of type C RGBs - 
contains leds with 3 1-byte data members for each 
of the 3 Red, Green, and Blue color channels */

int onTime = 10*1000; // 30 seconds
int PIR_PIN = 10;


void setup() {
  // put your setup code here, to run once:
  // initialize FastLED with the parameters defined above
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  // FastLED.setBrightness(brightness);
  pinMode(pin_num, INPUT);


  // set 45 proximity sensor pin as inputs, from digital pin 3 to pin 48
  // for (int pin_num = 0 + 3; pin_num <= 45 + 3; pin_num++) {
  //   pinMode(pin_num, INPUT);
  // }
}

void loop() {
  // put your main code here, to run repeatedly:

  /* In Tutorial: (9 x 5 matrix/ floor)
  45 leds, 45 IR Proximity sensors, HC05 Bluetooth Module
  all connected to one Arduino megaboard (use extension )
  powered by a 5V 6A Power supply */ 

  // using a single for loop
  for (int pin_num = 0; pin_num <= 45; pin_num++) {
    // set all LEDS to a particular color (green in this case)
    leds[pin_num] = CRGB(0, 255, 0);
    // if an object is detected on top of a particular sensor, turn on the 
    if ( digitalRead(pin_num + 3) == LOW ) {
      leds[pin_num] = CRGB(0, 0, 255); // reactive color set to blue
    }
  }

  FastLED.show(); // Update the LEDs
  delay(20); 
  // end of tutorial // 



  // getting familiar with the FastLED library
  // we set any of the 20 LEDs to any color using the 3 RGB parameters
  leds[0] = CRGB(255, 0, 0);
  FastLED.show(); // call show() to make the color change happen on the LEDs
  delay(500);

  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);

  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  // etc ...  //

  // we can make some fun animations using for loops
  // this loop lights up the leds (blue) in order from 0 - 19
  for (int i = 0; i <= 19; i++) {
    leds[i] = CRGB (0, 0, 255);
    FastLED.show();
    delay(40);
  }

  // this loop lights up the leds (red) in reverse order from 19 - 0
  for (int i = 19; i >= 0; i++) {
    leds[i] = CRGB (255, 0, 0);
    FastLED.show();
    delay(40);
  }

  /* FastLED library has more functions with which 
  we can make more interesting animations */
}
