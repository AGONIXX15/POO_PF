#pragma once
#include <string>
#include <iostream>


class AccountModel{

private:
  std::string owner;
  std::string type;
  int accountNumber;
  std::string status;
  std::string creationDate;
  float balance;

public:
  AccountModel(std::string owner, std::string type, int accountNumber, std::string status, std::string creationDate, float balance);
  std::string GetOwner();
  std::string GetType();
  std::string GetAccountNumber();
  std::string GetStatus();
  std::string GetCreationDate();
  float GetBalance();
  void SetOwner(std::string);
  void SetType(std::string);
  void SetAccountNumber(int);
  void SetStatus(std::string);
  void SetCreationDate(std::string);
  void SetBalance(float);
  std::string ToString();
  void ShowInfo();
  

};

