#pragma once
#include "CardTypeModel.hpp"
#include <string>

class CardModel {
public:
  std::string brand;
  int number;
  int cvv;
  float balance;
  CardTypeModel type;
  CardModel(int number, int cvv, float balance, CardTypeModel type);
  std::string GetBrand();
  int GetNumber();
  int GetCvv();
  float GetBalance();
  CardTypeModel GetType();
  void Transfer(float amount);
  void SaveFunds(float amount, bool is_credit);
  void WithdrawFunds(float amount, bool is_credit);
  std::string ToString();
};
