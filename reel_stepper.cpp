#include "Arduino.h"
#include "reel_stepper.h"

ReelStepper::ReelStepper(int number_of_steps, int motor_pin_1, int motor_pin_2) {
    this->number_of_steps = number_of_steps;

    this->motor_pin_1 = motor_pin_1;
    this->motor_pin_2 = motor_pin_2;

    pinMode(this->motor_pin_1, OUTPUT);
    pinMode(this->motor_pin_2, OUTPUT);
};

void ReelStepper::setSpeed(unsigned long rpm) {
    this->step_delay = 60L * 1000L * 1000L / this->number_of_steps / rpm;
}

void ReelStepper::moveTo(int steps_to_move) {
    this->steps_to_move = steps_to_move;
};

void ReelStepper::step() {
    unsigned long now = micros();

    // Return if there's no steps to move
    if (steps_to_move == 0) {
        return;
    }

    // Move only if the appropriate delay has passed
    if (now - this->last_step_time >= this->step_delay) {
        this->last_step_time = now;
        this->stepMotor(this->steps_to_move % 4);
        this->steps_to_move--;

    }
};

void ReelStepper::stepMotor(int thisStep) {
  switch(thisStep) {
    case 0:
      digitalWrite(this->motor_pin_1, LOW);
      digitalWrite(this->motor_pin_2, HIGH);
      break;
     case 1:
      digitalWrite(this->motor_pin_1, HIGH);
      digitalWrite(this->motor_pin_2, HIGH);
      break;
     case 2:
      digitalWrite(this->motor_pin_1, HIGH);
      digitalWrite(this->motor_pin_2, LOW);
      break;
     case 3:
      digitalWrite(this->motor_pin_1, LOW);
      digitalWrite(this->motor_pin_2, LOW);
      break;
  }
};

int ReelStepper::stepsRemaining() {
    return this->steps_to_move;
};