#pragma once
#include <string>


class AccountModel {
private:
  float balance;
  std::string owner;
  std::string accountNumber;
  std::string status;
  std::string creationDate;
public:
  AccountModel(std::string owner, std::string accountNumber, std::string status, std::string creationDate, float balance);
  float GetBalance();
  std::string GetOwner();
  std::string GetAccountNumber();
  std::string GetStatus();
  std::string GetCreationDate();
};
