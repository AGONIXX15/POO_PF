#pragma once
#include "AccountModel.hpp"
#include "CardModel.hpp"
#include "PersonModel.hpp"
#include <string>
#include <vector>

class ClientModel : public PersonModel {

private:
  std::vector<CardModel> cards;
  std::vector<AccountModel> accounts;

public:
  ClientModel(int id,std::string name, int age);
  std::string ToString() override;
};
