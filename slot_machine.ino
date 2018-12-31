#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>

#include "stepper_motor.h"
#include "position_stepper.h"
#include "machine.h"
#include "slot_ui.h"

const int numberOfSteps = 200;
const int nPositions = 21;
const int buttonPin = 4;

SlotMachine slotMachine = SlotMachine(0.05, 100);
SlotUI ui = SlotUI();

StepperMotor sm1 = StepperMotor(numberOfSteps, 6, 7, 28);
PositionStepper ps1 = PositionStepper(sm1, 2);

StepperMotor sm2 = StepperMotor(numberOfSteps, 8, 9, 30);
PositionStepper ps2 = PositionStepper(sm2, 0);

StepperMotor sm3 = StepperMotor(numberOfSteps, 10, 11, 32);
PositionStepper ps3 = PositionStepper(sm3, 1);



int stops_1[] = {
  0, 10, 20, 30, 40, 
  50, 60, 68, 78, 88, 
  98, 106, 116, 126, 136, 
  146, 156, 164, 174, 184, 
  194
};

int stops_2[] = {
  2, 13, 23, 33, 43,
  52, 62, 71, 81, 90,
  99, 109, 118, 128, 138,
  146, 156, 166, 176, 185,
  195
};

int stops_3[] = {
  8, 18, 28, 37, 46, 
  56, 66, 76, 86, 95, 
  105, 115, 123, 133, 142, 
  152, 161, 171, 180, 190, 
  199
};


void setup() {

  Serial.begin(9600);
  Serial.println("Booting...");

  Serial.println("Initializing UI");
  ui.begin(0x70, 0x71, 0x72);
  ui.updateCredits(slotMachine.credits());
  ui.updateAmountBet(slotMachine.amountBet());
  ui.clearWinnerPaid();
  

  Serial.println("Step to start");
  ui.lcd.clear();
  ui.lcd.setCursor(0, 0);
  ui.lcd.print("Initializing...");  
  ps1.stepToStart();
  ps2.stepToStart();
  ps3.stepToStart();

  randomSeed(millis());
  pinMode(buttonPin, INPUT_PULLUP);

  ui.lcd.clear();
  ui.lcd.setCursor(0, 0);
  ui.lcd.print("Press SPIN");    

}

/* THIS LOOP HELPS DETERMINE THE CORRECT STOPS. DO NOT DELETE 
void loop() {
  while (Serial.available()) {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
      delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() > 0) {
    Serial.println("STRING: "); Serial.print(readString);  //so you can see the captured string 
    int n = readString.toInt();  //convert readString into a number
    
    ps2.setPosition(n, 1);
  
    while (!ps2.isFinished() ) {
      Serial.println(ps2.step());
    }
  
    readString = "";
  }

  delay(5000);
}
*/

#define STATE_READY 0
#define STATE_SPINNING 1
#define STATE_PAYOUT 2

int currentState = STATE_READY;

void loop() {

  // Handle events
  if (currentState == STATE_READY) {
    int buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
      Serial.println("Read button");

       if (slotMachine.spin() == 0) {
        ps1.setPosition(stops_1[slotMachine.r1()], 1);
        ps2.setPosition(stops_2[slotMachine.r2()], 2);
        ps3.setPosition(stops_3[slotMachine.r3()], 3);
        
        ui.updateCredits(slotMachine.credits());
        ui.clearWinnerPaid();
        ui.lcd.clear();
        ui.lcd.setCursor(0, 0);
        ui.lcd.print("Good Luck!");     
        currentState = STATE_SPINNING;        
      }
    }
  }

  // Update game

  if (currentState == STATE_SPINNING) {
    ps1.step();
    ps2.step();
    ps3.step();
    if (ps1.isFinished() && ps2.isFinished() && ps3.isFinished()) {
      currentState = STATE_PAYOUT;
    }
  }

  if (currentState == STATE_PAYOUT) {
    ui.lcd.clear();
    ui.lcd.setCursor(0, 0);
    ui.lcd.print("Credits $");
    ui.lcd.print(slotMachine.value());

    ui.lcd.setCursor(0, 1);
    ui.lcd.print(slotMachine.s1());
    ui.lcd.setCursor(0, 2);
    ui.lcd.print(slotMachine.s2());
    ui.lcd.setCursor(0, 3);
    ui.lcd.print(slotMachine.s3());

    ui.updateCredits(slotMachine.credits());
    ui.updateWinnerPaid(slotMachine.payout());


    delay(5000);

    ui.lcd.clear();
    ui.lcd.setCursor(0, 0);
    ui.lcd.print("Press SPIN");    
    currentState = STATE_READY;
  }

  // Elapse time


}




