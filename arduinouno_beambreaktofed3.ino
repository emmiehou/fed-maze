/*
 Arudino UNO external circuit in maze
 Last updated 8/25/25
 Emmie Hou

 This will send BNC signals out of A0 when the beam is broken
*/
#define LEDPIN 13
 // Pin 13: Arduino has an LED connected on pin 13
 // Pin 11: Teensy 2.0 has the LED on pin 11
 // Pin 6: Teensy++ 2.0 has the LED on pin 6
 // Pin 13: Teensy 3.0 has the LED on pin 13
#define SENSORPIN 4
// variables will change:
int sensorState = 0, lastState=0; // variable for reading the pushbutton
static

//pin for bnc output
#define BEH   A0

//how to send BNC signal
void sendBNC(int ms) {
  digitalWrite(BEH, HIGH);
  delay(ms);
  digitalWrite(BEH, LOW);
}

void setup() {
  // initialize the LED pin as an output:
  pinMode(LEDPIN, OUTPUT);
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT_PULLUP);
  pinMode(BEH, OUTPUT);
  digitalWrite(BEH, LOW);  // Start LOW
  Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
  Serial.print(digitalRead(SENSORPIN));
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW, send BNC signal and turn LED on:
  if (sensorState == LOW) {
    // send BNC signal:
    sendBNC(1000);
    // turn LED on:
    digitalWrite(LEDPIN, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(LEDPIN, LOW);
  lastState = sensorState;
  }
}