#pragma once
#include <string>

class AccountModel {

private:
  float balance;
  std::string owner;
  int accountNumber;
  std::string status;
  std::string creationDate;

public:
  AccountModel(std::string owner, int accountNumber, std::string status, std::string creationDate, float balance);
  float GetBalance();
  std::string GetOwner();
  std::string GetAccountNumber();
  std::string GetStatus();
  std::string GetCreationDate();
  void SetBalance(float);
  void SetOwner(std::string);
  void SetAccountNumber(int);
  void SetStatus(std::string);
  void SetCreationDate(std::string);
  std::string ToString();

};

