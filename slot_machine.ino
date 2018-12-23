#include "stepper_motor.h"
#include "position_stepper.h"

int numberOfSteps = 200;

StepperMotor sm1 = StepperMotor(numberOfSteps, 6, 7, 30);
PositionStepper ps1 = PositionStepper(sm1, 2);

StepperMotor sm2 = StepperMotor(numberOfSteps, 8, 9, 30);
PositionStepper ps2 = PositionStepper(sm2, 0);

StepperMotor sm3 = StepperMotor(numberOfSteps, 10, 11, 30);
PositionStepper ps3 = PositionStepper(sm3, 1);

void setup() {
  Serial.begin(9600);
  Serial.println("Step to start");
  ps1.stepToStart();
  ps2.stepToStart();
  ps3.stepToStart();

  delay(2000);
  ps1.setSteps(201);
  ps2.setSteps(201);
  ps3.setSteps(201);

  while (!ps1.isFinished() || !ps2.isFinished() || !ps3.isFinished()) {
    ps1.step();
    ps2.step();
    ps3.step();
  }

  delay(2000);
  ps1.setSteps(201);
  ps2.setSteps(201);
  ps3.setSteps(201);

  while (!ps1.isFinished() || !ps2.isFinished() || !ps3.isFinished()) {
    ps1.step();
    ps2.step();
    ps3.step();
  }


  delay(2000);
  ps1.setSteps(201);
  ps2.setSteps(201);
  ps3.setSteps(201);

  while (!ps1.isFinished() || !ps2.isFinished() || !ps3.isFinished()) {
    ps1.step();
    ps2.step();
    ps3.step();
  }

  
}

void loop() {
  //  Serial.println(position1.step());



}


/*

ReelStepper motor1 = ReelStepper(numberOfSteps, 6, 7, 2);
ReelStepper motor2 = ReelStepper(numberOfSteps, 8, 9, 0);
ReelStepper motor3 = ReelStepper(numberOfSteps, 10, 11, 1);

const int buttonPin = 4;     // the number of the pushbutton pin

int reel1Positions[] = {
  0, 12, 22, 30, 42, 52, 62, 70, 80, 90, 100,
  108, 118, 130, 138, 146, 156, 166, 176, 186, 196
};

char* reel1Symbols[] = {
  "DOLPHIN",
  "SEVEN",
  "CHERRIES",
  "DOLPHIN",
  "BELL",
  "GRAPE",
  "BAR",
  "DOLPHIN",
  "WATERMELON",
  "DOLPHIN",
  "CHERRIES",
  "SEVEN",
  "BELL",
  "BAR",
  "DOLPHIN",
  "SEVEN",
  "GRAPE",
  "DOLPHIN",
  "BELL",
  "GRAPE",
  "BAR"  
};

int nPositions = 21;

void setup() {
  //motor1.moveTo(300);
  //motor2.moveTo(500);
  Serial.begin(9600);
  motor1.initialize();
  motor2.initialize();
  motor3.initialize();
  Serial.println("Initialization complete");


  pinMode(buttonPin, INPUT_PULLUP);
  //motor1.move(202);
  //motor2.move(202);
  //motor3.move(202);
  //motor1.moveTo(0);

  motor1.setSpeed(32);
  motor2.setSpeed(32);
  motor3.setSpeed(32);
  
}

int pos = 0;
int i = 0;
  
void loop() {
  //motor1.step();
  //motor2.step();
  //motor3.step();

  //Serial.println(motor1.position);

  
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {

    /*
    motor1.step();
    pos++;
    Serial.println(pos);
    delay(500);
    
    
    Serial.println(reel1Symbols[i]);
    Serial.println(reel1Positions[i]);

    motor1.moveTo(0, 1);
    motor2.moveTo(0, 2);
    motor3.moveTo(0, 3);
    pos = reel1Positions[i];
    while(motor1.stepsRemaining() > 0 || motor2.stepsRemaining() > 0 || motor3.stepsRemaining() > 0) {
      motor1.step();
      motor2.step();
      motor3.step();
    }
    Serial.println(motor1.position);
    i++;
  
    delay(1000);
  }
  

}
*/



