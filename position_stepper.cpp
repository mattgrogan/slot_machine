#include "position_stepper.h"

#define SENSOR_CUTOFF_VALUE 500

PositionStepper::PositionStepper(StepperMotor &motor, int sensorPin) {
    this->motor = motor;
    this->sensorPin = sensorPin;

    pinMode(this->sensorPin, INPUT);

    this->prevReading = this->readSensorPin();

    //Serial.print("PREV READING IS: "); Serial.println(this->prevReading);
};

bool PositionStepper::readSensorPin() {
    int reading = analogRead(this->sensorPin);

    //Serial.print("READ: "); Serial.println(reading > SENSOR_CUTOFF_VALUE);

    return reading > SENSOR_CUTOFF_VALUE;
};

void PositionStepper::setSteps(int steps) {
    this->motor.setSteps(steps);
};

bool PositionStepper::isAtStart() {

    bool isAtStart = false;
    bool newReading = this->readSensorPin();

    if (!newReading && this->prevReading) {
        // New reading is high and prev reading is low
        isAtStart = true;
    } 

    this->prevReading = newReading;

    return isAtStart;
}

int PositionStepper::step() {
    // Returns the position of the stepper motor

    if (this->motor.step()) {
      //Serial.println("Stepping");
        if (this->isAtStart()) {
            //Serial.println("Is at start");
            this->position = 0;
        } else {
            //Serial.println("Not at start");
            this->position++;
        }
    }

    //Serial.print("Returning "); Serial.println(this->position);
    return this->position;
};

void PositionStepper::stepToStart() {
   this->motor.setSteps(250);
   while (this->step() != 0) { }
   this->motor.setSteps(0);
}

bool PositionStepper::isFinished() {
  return this->motor.isFinished();
}

