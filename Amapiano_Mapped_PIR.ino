// #include <MD_Parola.h>
// #include <MD_MAX72xx.h>
// #include <SPI.h>
#include "LedControl.h"
// #include "SR04.h"

// #define HARDWARE_TYPE MD_MAX72XX::FC16_HW
// #define MAX_DEVICES 1

#define DATA_PIN  13
#define CS_PIN    12
#define CLK_PIN   11
// #define TRIG_PIN A1
// #define ECHO_PIN A0
// #define scrollSpeed  20   // scroll speed
// #define scrollPause  0    // ms of pause after finished displaying message

// Hardware SPI connection
// MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
// MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(DATA_PIN,CLK_PIN,CS_PIN,1);
// SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
// int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 7; // Input for HC-S501

int pirValue; // Place to store read PIR Value

// sets scrolling direction if slider in middle at start
// textEffect_t scrollEffect = PA_SCROLL_LEFT;
// textPosition_t scrollAlign = PA_LEFT;  // how to align the text

// #define  BUF_SIZE  75  // Maximum of 75 characters
// #define trigPin  A0
// #define echoPin  A1

// char testStr[10] = { "" };
// String heightStr = "";
// long duration;
// int distance;
// int height;

/* we always wait a bit between updates of the display */
unsigned long delaytime1=1000;
unsigned long delaytime2=50;
unsigned long delaytime3=10;

void setup() {
   /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,0);
  /* and clear the display */
  lc.clearDisplay(0);

  // Serial.begin(9600);
  // delay(2000);

  // pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pirPin, INPUT);

  Serial.begin(9600);
 
  // digitalWrite(LED_BUILTIN, LOW);

  // columns();

  // pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  // pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  // Serial.begin(9600); // Starts the serial communication
  // P.begin();
}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void rows() {
  for(int row=0;row<8;row++) {
    delay(delaytime2);
    lc.setRow(0,row,B11111111);
    delay(delaytime2);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(delaytime2);
      lc.setRow(0,row,B11111111);
      delay(delaytime2);
      lc.setRow(0,row,(byte)0);
    }
  }
}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
void columns() {
  for(int col=0;col<8;col++) {
    delay(delaytime2);
    lc.setColumn(0,col,B11111111);
    delay(delaytime2);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++) {
      delay(delaytime2);
      lc.setColumn(0,col,B11111111);
      delay(delaytime2);
      lc.setColumn(0,col,(byte)0);
    }
  }
}

// void measure() {

//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   duration = pulseIn(echoPin, HIGH);
//   distance = duration * 0.017;

// }

void loop() {
  // measure();
  //  distance=sr04.Distance();
  //  Serial.print(distance);
  //  Serial.println("cm");
  //  delay(1000);

  pirValue = digitalRead(pirPin);
  // digitalWrite(LED_BUILTIN, pirValue);

   if (pirValue == HIGH) {
    // P.displayText("TINGGI", PA_LEFT, 0, 0, PA_PRINT, PA_NO_EFFECT);
      rows();
   } else {
    columns();
    // height = 180 - distance;
    // heightStr = String(height, DEC) + "cm";
    // heightStr.toCharArray(testStr, 75);
    // P.displayText(testStr, PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
    }
    delay(delaytime3);
  // P.displayAnimate();
  // delay(100);
}