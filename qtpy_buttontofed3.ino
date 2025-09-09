/*
 Arduino QTPY external circuit for button BNC signals to the FED3 device
 Last updated 9/8/25
 Emmie Hou

 This will send a BNC signal out of A0 when the button is pressed
*/

//pushbutton attached to pin 4 from +3.3V
//10K resistor attached to pin 4 from GRD

#define LEDPIN 13
#define buttonPin 4
// variables will change

// variables will change:
int buttonState = 0, lastState=0; // variable for reading the pushbutton status

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
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);

    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
      // send BNC signal
      sendBNC(1000);
      // turn LED on:
      digitalWrite(LEDPIN, HIGH);
    } else {
      // turn LED off:
      digitalWrite(LEDPIN, LOW);
    }
    lastState = buttonState;
}
