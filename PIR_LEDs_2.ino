#include <FastLED.h>

#define LED_PIN  7

#define NUM_LEDS 20

CRGB leds[NUM_LEDS]; /* an array of type C RGBs - 
contains leds with 3 1-byte data members for each 
of the 3 Red, Green, and Blue color channels */

int PIR_PIN = 10;
int fadeTimeDiff = 10;
int onTime = 1000; // 30 seconds

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (digitalRead(PIR_PIN) == 1)
 {
  fadeIn();
  delay(onTime);
  fadeOut();
 }
}

void fadeIn() {
  for (int led = 0; led < NUM_LEDS; led++) {
    leds[led] = CRGB(0, 150, 0);
  }
  for (int b = 0; b < 255; b++){
    FastLED.setBrightness(b);
    FastLED.show();
    delay(fadeTimeDiff);
  }
}

void fadeOut() {
  for (int led = 0; led < NUM_LEDS; led++) {
    leds[led] = CRGB(0, 150, 0);
  }
  for (int b = 255; b > 0; b-= 2){
    FastLED.setBrightness(b);
    FastLED.show();
    delay(fadeTimeDiff);
  }
  for (int led = 0; led < NUM_LEDS; led++) {
    leds[led] = CRGB::Black;
    FastLED.show();
  }
}
