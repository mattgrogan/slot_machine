
#ifndef SlotMachine_h
#define SlotMachine_h

class SlotMachine {
  public:
    SlotMachine(double denom, int credits);
    int credits();
    double value();
    int placeBet();
    int incrementBet();
    int decrementBet();
    int amountBet();

  private:
    double  _denom;
    int     _credits;
    int     _bet;

    
      
};

#endif
