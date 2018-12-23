/* Control the stepper motor */

#ifndef StepperMotor_h
#define StepperMotor_h

#include "Arduino.h"

class StepperMotor {
    public:
        StepperMotor();
        StepperMotor(int steps, int pin1, int pin2, unsigned long rpm);
        void setSteps(int steps);
        int step();
        bool isFinished();
    private:
        int pin1;
        int pin2;
        int steps;
        int stepsToMove;
        unsigned long stepDelay;
        unsigned long lastStepTime;
        void stepMotor(int thisStep);
};

#endif
