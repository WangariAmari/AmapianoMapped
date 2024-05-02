//www.elegoo.com
//2016.12.9

// int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 7; // Input for HC-S501

int pirValue; // Place to store read PIR Value


void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pirPin, INPUT);
 
  digitalWrite(LED_BUILTIN, LOW);
  
  
  
}

void loop() {
  pirValue = digitalRead(pirPin);
  digitalWrite(LED_BUILTIN, pirValue);

}
