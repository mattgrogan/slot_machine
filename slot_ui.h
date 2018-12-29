#include <LiquidCrystal_I2C.h>
#include "Adafruit_LEDBackpack.h"

#ifndef slot_ui_h
#define slot_ui_h

const int LCD_ADDR = 0x3F;
const int LCD_COLS = 20;
const int LCD_ROWS = 4;

class SlotUI {
  public:
    //SlotUI();
    void begin(int credits_addr, int bet_addr, int won_addr);
    void updateCredits(int credits);
    void updateAmountBet(int bet);
    void updateWinnerPaid(int won);
    void clearCredits();
    void clearAmountBet();
    void clearWinnerPaid();
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(LCD_ADDR, LCD_COLS, LCD_ROWS);
  private:
    Adafruit_7segment _credits_matrix = Adafruit_7segment();
    Adafruit_7segment _winner_paid_matrix = Adafruit_7segment();
    Adafruit_7segment _amount_bet_matrix = Adafruit_7segment();
};

#endif
