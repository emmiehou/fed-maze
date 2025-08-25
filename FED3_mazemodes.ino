/*
  Feeding experimentation device 3 (FED3)

  FED files for modular maze assay paradigm
  Christine Liu and Emmie Hou

  Last updated 8/25/25

  Modes for habituation and experimentation for FED modular maze.

  // FEDmodes:
  // 1 [Freefeed with CondStim] Auto pellet delivery with conditioned stimulus. Infinite.
  // 2 [Dispenser with CondStim] Pellet delivery with conditioned stimulus when BNC signal received from external circuit

*/

#include <FED3.h>               //Include the FED3 library
String sketch = "fed-maze";     //Unique identifier text for each sketch
FED3 fed3(sketch);              //Start the FED3 object


/////////////////////////////////////////////////////////
// Setup commands. Runs once upon booting up.
/////////////////////////////////////////////////////////

void setup() {
  fed3.DisplayPokes = false;     //turn off poke indicators on screen
  fed3.FED3Menu = true;          //Activate the menu function at startup
  fed3.disableSleep();           //need to disable or won't run continuously
  fed3.begin();                  //Setup the FED3 hardware
}

void loop() {
  // Allow mode selection if both ports poked at same time
  if ((digitalRead(LEFT_POKE) == LOW) && (digitalRead(RIGHT_POKE) == LOW)) {
    fed3.SelectMode();
  }  

  /////////////////////////////////////////////////////////////
  // Mode 1: [Freefeed with CondStim] Auto pellet delivery with conditioned stimulus. Infinite.
  /////////////////////////////////////////////////////////////
  if (fed3.FEDmode == 0) {
    fed3.sessiontype = "FF with CondStim";  //The text in "sessiontype" will appear on the screen and in the logfile

    delay(2);
    fed3.Feed();  //Drop pellet

    if (digitalRead(PELLET_WELL) == HIGH) {  // Once pellet is taken, add to counter
      fed3.counter++;
    }
    delay(2);
  }
  /////////////////////////////////////////////////////////////
  // Mode 2: [Dispenser with CondStim] Pellet delivery with conditioned stimulus when BNC signal received from external circuit
  /////////////////////////////////////////////////////////////
  if (fed3.FEDmode == 1) {
    fed3.sessiontype = "Dispenser with CondStim";  //The text in "sessiontype" will appear on the screen and in the logfile
    fed3.ReadBNC(true);                                   //This sets the BNC to be input and reads it.  The boolean argument refers to whether you want the green LED on the Adalogger board insied of FED3 to blink when it detects an input (true) or not (false)
    if (fed3.BNCinput) {                                  //If HIGH is detected on BNC input
      fed3.ConditionedStimulus();                         //Deliver conditioned stimulus (tone and lights)
      fed3.Feed();                                        //Deliver pellet
   }
  }

  ////////////////////////////////////////////////////////////
  // If Mode does not exist
  ////////////////////////////////////////////////////////////
  if (fed3.FEDmode > 1) {
    fed3.DisplayNoProgram();
  }

  ///////////////////////////////////////////////////////////
  //// Run at least once per loop
  ///////////////////////////////////////////////////////////
  fed3.run();
}