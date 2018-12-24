#include "stepper_motor.h"
#include "position_stepper.h"

const int numberOfSteps = 200;
const int nPositions = 21;

const int buttonPin = 4;

String readString;

StepperMotor sm1 = StepperMotor(numberOfSteps, 6, 7, 30);
PositionStepper ps1 = PositionStepper(sm1, 2);

StepperMotor sm2 = StepperMotor(numberOfSteps, 8, 9, 30);
PositionStepper ps2 = PositionStepper(sm2, 0);

StepperMotor sm3 = StepperMotor(numberOfSteps, 10, 11, 30);
PositionStepper ps3 = PositionStepper(sm3, 1);

char* symbols_1[] = {
  "DOLPHIN", "SEVEN", "CHERRIES", "DOLPHIN", "BELL",
  "GRAPE", "BAR", "DOLPHIN", "WATERMELON", "DOLPHIN",
  "CHERRIES", "SEVEN", "BELL", "BAR", "DOLPHIN",
  "SEVEN", "GRAPE", "DOLPHIN", "BELL", "GRAPE",
  "BAR"  
};

int stops_1[] = {
  0, 10, 20, 30, 40, 
  50, 60, 68, 78, 88, 
  98, 106, 116, 126, 136, 
  146, 156, 164, 174, 184, 
  194
};

char* symbols_2[] = {
  "BELL", "GRAPE", "WATERMELON", "CHERRIES", "BAR",
  "GRAPE", "WATERMELON", "CHERRIES", "BELL", "GRAPE",
  "DOLPHIN", "CHERRIES", "BELL", "GRAPE", "WATERMELON",
  "CHERRIES", "SEVEN", "CHERRIES", "GRAPE", "DOLPHIN",
  "CHERRIES"
};

int stops_2[] = {
  2, 13, 23, 33, 43,
  52, 62, 71, 81, 90,
  99, 109, 118, 128, 138,
  146, 156, 166, 176, 185,
  195
};

char* symbols_3[] = {
  "CHERRIES", "GRAPE", "BELL", "CHERRIES", "GRAPE",
  "SEVEN", "BELL", "DOLPHIN", "CHERRIES", "GRAPE",
  "WATERMELON", "BAR", "BELL", "CHERRIES", "GRAPE",
  "BELL", "CHERRIES", "GRAPE", "SEVEN", "BELL",
  "DOLPHIN"
};

int stops_3[] = {
  8, 18, 28, 37, 46, 
  56, 66, 76, 86, 95, 
  105, 115, 123, 133, 142, 
  152, 161, 171, 180, 190, 
  199
};


void setup() {
  Serial.begin(9600);
  Serial.println("Step to start");
  ps1.stepToStart();
  ps2.stepToStart();
  ps3.stepToStart();

  randomSeed(millis());
  pinMode(buttonPin, INPUT_PULLUP);

}

/* THIS LOOP HELPS DETERMINE THE CORRECT STOPS. DO NOT DELETE 
void loop() {
  while (Serial.available()) {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
      delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() > 0) {
    Serial.println("STRING: "); Serial.print(readString);  //so you can see the captured string 
    int n = readString.toInt();  //convert readString into a number
    
    ps2.setPosition(n, 1);
  
    while (!ps2.isFinished() ) {
      Serial.println(ps2.step());
    }
  
    readString = "";
  }

  delay(5000);
}
*/


 
void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    int r1 = random(0, nPositions);
    int r2 = random(0, nPositions);
    int r3 = random(0, nPositions);

    ps1.setPosition(stops_1[r1], 1);
    ps2.setPosition(stops_2[r2], 2);
    ps3.setPosition(stops_3[r3], 3);

    Serial.println("Good Luck! ");
    Serial.print(symbols_1[r1]);
    Serial.print("-");
    Serial.print(symbols_2[r2]);
    Serial.print("-");
    Serial.println(symbols_3[r3]);

    while (!ps1.isFinished() || !ps2.isFinished() || !ps3.isFinished() ) {
      ps1.step();
      ps2.step();
      ps3.step();
    }
    
  }

  delay(100);


  

}




