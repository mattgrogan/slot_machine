#include "Arduino.h"

#ifndef SlotMachine_h
#define SlotMachine_h

#define N_SYMBOLS 21

class SlotMachine {
  public:
    SlotMachine() {};
    SlotMachine(double denom, int credits);
    int credits();
    double value();
    int placeBet();
    int incrementBet();
    int decrementBet();
    int amountBet();
    int spin();
    int r1(); // Reel positions
    int r2();
    int r3();
    char* s1(); // Symbols
    char* s2();
    char* s3();
    int payout();
    char* symbols_1[N_SYMBOLS] = {
      "DOLPHIN", "SEVEN", "CHERRIES", "DOLPHIN", "BELL",
      "PLUM", "BAR", "DOLPHIN", "WATERMELON", "DOLPHIN",
      "CHERRIES", "SEVEN", "BELL", "BAR", "DOLPHIN",
      "SEVEN", "PLUM", "DOLPHIN", "BELL", "PLUM",
      "BAR"  
    };
    
    char* symbols_2[N_SYMBOLS] = {
      "BELL", "PLUM", "WATERMELON", "CHERRIES", "BAR",
      "PLUM", "WATERMELON", "CHERRIES", "BELL", "PLUM",
      "DOLPHIN", "CHERRIES", "BELL", "PLUM", "WATERMELON",
      "CHERRIES", "SEVEN", "CHERRIES", "PLUM", "DOLPHIN",
      "CHERRIES"
    };
    
    char* symbols_3[N_SYMBOLS] = {
      "CHERRIES", "PLUM", "BELL", "CHERRIES", "PLUM",
      "SEVEN", "BELL", "DOLPHIN", "CHERRIES", "PLUM",
      "WATERMELON", "BAR", "BELL", "CHERRIES", "PLUM",
      "BELL", "CHERRIES", "PLUM", "SEVEN", "BELL",
      "DOLPHIN"
    };

  private:
    double  _denom;
    int     _credits;
    int     _bet;
    int     _r1;
    int     _r2;
    int     _r3; 
};

#endif
