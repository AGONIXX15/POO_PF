#pragma once
#include "CardTypeModel.hpp"
#include <string>

/* */ 
class CardModel {

private:
  std::string brand;
  int number;
  int cvv;
  float balance;
  CardTypeModel type;
public:
  CardModel(std::string brand, int number, int cvv, float balance, CardTypeModel type);
  std::string GetBrand();
  int GetNumber();
  int GetCvv();
  float GetBalance();
  CardTypeModel GetType();
  void Transfer(float amount);
};
