/* This file controls the low level stepper motor action 
 *
 */

#ifndef Reel_Stepper_h
#define Reel_Stepper_h

class ReelStepper {
    public:
        // Constructor
        ReelStepper(int steps, int motor_pin_1, int motor_pin_2);
        void setSpeed(unsigned long rpm);
        void moveTo(int number_of_steps);
        void step();
        int stepsRemaining();

    private:
        void stepMotor(int this_step);
        int number_of_steps;
        int steps_to_move;
        int motor_pin_1;
        int motor_pin_2;
        unsigned long step_delay;
        unsigned long last_step_time;
};

#endif