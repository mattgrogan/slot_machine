#include "reel_stepper.h"

int numberOfSteps = 200;

ReelStepper motor1 = ReelStepper(numberOfSteps, 8, 9);
ReelStepper motor2 = ReelStepper(numberOfSteps, 10, 11);

void setup() {
  motor1.moveTo(300);
  motor2.moveTo(500);
}

void loop() {

    if (motor1.stepsRemaining() > 980) {
        motor1.setSpeed(15);
        motor2.setSpeed(15);
    } else {
        motor1.setSpeed(30);
        motor2.setSpeed(30);
    }

    motor1.step();
    motor2.step();
}



