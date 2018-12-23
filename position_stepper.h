/* This enhances the stepper motor with a position sensor */

#ifndef PositionStepper_h
#define PositionStepper_h

#include "Arduino.h"
#include "stepper_motor.h"

class PositionStepper {
    public:
        PositionStepper(StepperMotor &motor, int sensorPin);
        int position = 1000;
        bool readSensorPin();
        void setSteps(int steps);
        int step();
        void stepToStart();
        bool isFinished();
    private:
        StepperMotor motor;
        int sensorPin;
        bool prevReading;
        bool isAtStart();
};

#endif
