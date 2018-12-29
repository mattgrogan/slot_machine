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

