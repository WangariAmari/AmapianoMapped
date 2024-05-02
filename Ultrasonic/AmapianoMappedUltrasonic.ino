#include <Adafruit_NeoPixel.h>
// #include <HCSR04.h>
#include "SR04.h"

#define PIN 4

#define NUMPIXELS 100

#define ECHO_PIN 3
#define TRIG_PIN 2

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// UltraSonicDistanceSensor distanceSensor(ECHO_PIN,TRIG_PIN);
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

int current_Last_LED = 0;
long a;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // delay(1000);
  strip.begin();
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  a=sr04.Distance();
  Serial.print(a);
  Serial.println("cm");
  // delay(1000);
  pixels.clear();
  current_First_LED = a*0.8;
  current_Last_LED = (a+22)*0.8;

  for (int = current_First_LED; i < current_Last_LED; i++)
  {
    pixels.setPixelColor(i, 0, 0, 255);
  }

  pixels.show();
}