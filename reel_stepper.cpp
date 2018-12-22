#include "Arduino.h"
#include "reel_stepper.h"

ReelStepper::ReelStepper(int number_of_steps, int motor_pin_1, int motor_pin_2) {
    this->number_of_steps = number_of_steps;

    this->motor_pin_1 = motor_pin_1;
    this->motor_pin_2 = motor_pin_2;

    pinMode(this->motor_pin_1, OUTPUT);
    pinMode(this->motor_pin_2, OUTPUT);
};

ReelStepper::ReelStepper(int number_of_steps, int motor_pin_1, 
                         int motor_pin_2, int sensor_pin) {
    this->number_of_steps = number_of_steps;

    this->motor_pin_1 = motor_pin_1;
    this->motor_pin_2 = motor_pin_2;
    this->sensor_pin = sensor_pin;

    pinMode(this->motor_pin_1, OUTPUT);
    pinMode(this->motor_pin_2, OUTPUT);
    pinMode(this->sensor_pin, INPUT_PULLUP);
};


void ReelStepper::setSpeed(unsigned long rpm) {
    this->step_delay = 60L * 1000L * 1000L / this->number_of_steps / rpm;
}

void ReelStepper::initialize() {
    bool is_at_start = false;
    int prev_reading = analogRead(this->sensor_pin);
    int new_reading = prev_reading;
    Serial.print("START READ:");
    Serial.println(prev_reading);

    this->setSpeed(30);
    this->move(210);

    while (!is_at_start) {

        if (this->step()) {
          new_reading = analogRead(this->sensor_pin);
  
          Serial.print("READ:");
          Serial.println(new_reading);
          
          if (prev_reading >= 500 && new_reading < 500) {
              Serial.println("IS AT START");
              is_at_start = true;
              this->move(0);
              this->position = 0;
          }
  
          prev_reading = new_reading;          
        }


    }
}

void ReelStepper::move(int steps_to_move) {
    this->steps_to_move = steps_to_move;
};

void ReelStepper::moveTo(int position, int revolutions = 0) {
  int steps_to_move = 0;

  if (position == this->position) {
    // Go one full revolution
    steps_to_move = this->number_of_steps; 
  } else if (position > this->position) {
    steps_to_move = position - this->position;
  } else {
    steps_to_move = this->number_of_steps - position;
  }

  steps_to_move += this->number_of_steps * revolutions;

  this->move(steps_to_move);
}

int ReelStepper::step() {
    unsigned long now = micros();

    // Return if there's no steps to move
    if (steps_to_move == 0) {
        return 0;
    }

    // Move only if the appropriate delay has passed
    if (now - this->last_step_time >= this->step_delay) {
        this->last_step_time = now;
        this->stepMotor(this->steps_to_move % 4);
        this->steps_to_move--;
        this->position++;
        this->position = this->position % this->number_of_steps;
        return 1;
    }

    return 0;
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
