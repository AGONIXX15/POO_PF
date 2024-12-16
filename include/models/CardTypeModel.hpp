#pragma once
#include <string>

class CardTypeModel {
private:
  bool is_credit;
  bool is_debit;
  std::string type;
  float credit_limit;
  float interest_rate;

public:
  std::string GetType();
  float GetCreditLimit();
  float GetInterestRate();
  void SetType(bool, bool);
  void SetCreditLimit(float);
  void SetInterestRate(float);
  void PayDoubts(float);
};
