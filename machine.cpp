#include "machine.h"

#define DEFAULT_BET_AMOUNT 1
#define MAX_BET_AMOUNT 10

SlotMachine::SlotMachine(double denom, int credits) {
  this->_denom = denom;
  this->_credits = credits;
  this->_bet = DEFAULT_BET_AMOUNT;
};

int SlotMachine::credits() {
  return this->_credits;
};

double SlotMachine::value() { 
  return this->_denom * this->_credits;
}

int SlotMachine::placeBet() {
  if (this->_credits >= this->_bet) {
    this->_credits -= this->_bet;
    return 0;
  } else {
    return -1; // not enough credits to bet
  }
}

int SlotMachine::incrementBet() {
  int attemptedBet = this->_bet + 1;

  if (attemptedBet <= this->_credits && attemptedBet <= MAX_BET_AMOUNT) {
    this->_bet = attemptedBet;
    return 0;
  } else {
    return -1; // unable to increment bet
  }
}

int SlotMachine::decrementBet() {
  if (this->_bet >= 1) {
    this->_bet--;
    return 0;
  } else {
    return -1;
  }
}

int SlotMachine::amountBet() {
  return this->_bet;
}

int SlotMachine::spin() {
  if (this->placeBet() == 0) {
    this->_r1 = random(0, N_SYMBOLS);
    this->_r2 = random(0, N_SYMBOLS);
    this->_r3 = random(0, N_SYMBOLS);
    this->_credits += this->payout();
    return 0;
  } else {
    return 1;
  }
}

int SlotMachine::payout() {
  int payout = 0;

  if (this->s1() == this->s2() ||
      this->s2() == this->s3() ||
      this->s1() == this->s3()) {

        payout = 5;
      }


  return payout;
}

int SlotMachine::r1() {
  return this->_r1;
}

int SlotMachine::r2() {
  return this->_r2;
}

int SlotMachine::r3() {
  return this->_r3;
}

char* SlotMachine::s1() {
  return this->symbols_1[this->_r1];
}

char* SlotMachine::s2() {
  return this->symbols_2[this->_r2];
}

char* SlotMachine::s3() {
  return this->symbols_3[this->_r3];
}
