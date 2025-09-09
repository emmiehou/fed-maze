/*
 Arudino QTPY external circuit manual button for BNC stim output
 Last updated 9/9/25
 Emmie Hou

 This will send BNC signals out of A0 when the button is pressed

 Button pin should be out of A2
*/
#define BUTTONPIN A2
// variables will change:
int buttonState = 0, lastState=0; // variable for reading the pushbutton

//pin for bnc output
#define BEH   A0

//how to send BNC signal
void sendBNC(int ms) {
  digitalWrite(BEH, HIGH);
  delay(ms);
  digitalWrite(BEH, LOW);
}

void setup() {
  // initialize the sensor pin as an input:
  pinMode(BEH, OUTPUT);
  pinMode(BEH, LOW)
  // initialize button pin as an input
  pinMode(BUTTONPIN, INPUT);
  Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(BUTTONPIN);

  // if the button is pressed, send BNC
  if (buttonState == HIGH) {
    // send BNC signal:
    sendBNC(1000);
  }
  else {
  lastState = buttonState;
  }
}