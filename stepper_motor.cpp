#include "stepper_motor.h"

StepperMotor::StepperMotor() {

};

StepperMotor::StepperMotor(int steps, int pin1, int pin2, unsigned long rpm) {
    this->steps = steps;
    this->pin1 = pin1;
    this->pin2 = pin2;

    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);

    this->stepDelay = 60L * 1000L * 1000L / this->steps / rpm;
};

void StepperMotor::setSteps(int steps) {
    this->stepsToMove = steps;
};

int StepperMotor::step() {
    int stepsMoved = 0;
    unsigned long now = micros();

    if (this->stepsToMove > 0) {
        if (now - this->lastStepTime >= this->stepDelay) {
            this->lastStepTime = now;
            this->stepMotor(this->stepsToMove % 4);
            this->stepsToMove--;
            stepsMoved = 1;
        }
    }

    return stepsMoved;
}

bool StepperMotor::isFinished() {
  return this->stepsToMove == 0;
}

void StepperMotor::stepMotor(int thisStep) {
    switch(thisStep) {
        case 0:
            digitalWrite(this->pin1, LOW);
            digitalWrite(this->pin2, HIGH);
            break;
        case 1:
            digitalWrite(this->pin1, HIGH);
            digitalWrite(this->pin2, HIGH);
            break;
        case 2:
            digitalWrite(this->pin1, HIGH);
            digitalWrite(this->pin2, LOW);
            break;
        case 3:
            digitalWrite(this->pin1, LOW);
            digitalWrite(this->pin2, LOW);
            break;
    }
};
