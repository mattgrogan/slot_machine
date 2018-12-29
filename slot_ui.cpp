#include "slot_ui.h"

void SlotUI::begin(int credits_addr, int bet_addr, int won_addr) {
  this->_credits_matrix.begin(credits_addr);
  this->_winner_paid_matrix.begin(won_addr);
  this->_amount_bet_matrix.begin(bet_addr);

  this->lcd.begin();
  this->lcd.backlight();
}

void SlotUI::updateCredits(int credits) {
  this->_credits_matrix.print(credits);
  this->_credits_matrix.writeDisplay();
}


void SlotUI::updateWinnerPaid(int amount) {
  this->_winner_paid_matrix.print(amount);
  this->_winner_paid_matrix.writeDisplay();
}


void SlotUI::updateAmountBet(int bet) {
  this->_amount_bet_matrix.print(bet);
  this->_amount_bet_matrix.writeDisplay();
}

void SlotUI::clearCredits() {
  this->_credits_matrix.clear();
  this->_credits_matrix.writeDisplay();
}

void SlotUI::clearWinnerPaid() {
  this->_winner_paid_matrix.clear();
  this->_winner_paid_matrix.writeDisplay();
}

void SlotUI::clearAmountBet() {
  this->_amount_bet_matrix.clear();
  this->_amount_bet_matrix.writeDisplay();
}

