/* This file controls the low level stepper motor action 
 *
 */

#ifndef Reel_Stepper_h
#define Reel_Stepper_h

class ReelStepper {
    public:
        // Constructor
        ReelStepper(int steps, int motor_pin_1, int motor_pin_2);
        ReelStepper(int steps, int motor_pin_1, int motor_pin_2, int sensor_pin);
        void setSpeed(unsigned long rpm);
        void initialize();
        void move(int number_of_steps);
        void moveTo(int position, int revolutions = 0);
        int step();
        int stepsRemaining();
        int position;

    private:
        void stepMotor(int this_step);
        int number_of_steps;
        int steps_to_move;
        int motor_pin_1;
        int motor_pin_2;
        int sensor_pin;
        unsigned long step_delay;
        unsigned long last_step_time;
};

#endif
