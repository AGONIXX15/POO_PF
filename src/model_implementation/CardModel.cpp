#include "../../include/models/CardModel.hpp"

CardModel::CardModel(std::string brand, int number, int cvv, float balance, CardTypeModel type) {
  this->brand = brand;
  this->number = number;
  this->cvv = cvv;
  this->balance = balance;
  this->type = type;
}

std::string CardModel::GetBrand() {
  return this->brand;
}

int CardModel::GetNumber() {
  return this->number;
}

int CardModel::GetCvv() {
  return this->cvv;
}

float CardModel::GetBalance() {
  return this->balance;
}


CardTypeModel CardModel::GetType() {
  return this->type;
}

void CardModel::Transfer(float amount) {
  this->balance -= amount;
}
