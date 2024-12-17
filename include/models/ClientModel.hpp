#pragma once
#include "PersonModel.hpp"
#include <string>
#include <vector>

using namespace std;

class ClientModel : public PersonModel {

private:

public:
  ClientModel(string id,string name, int age);


  string ToString() override;
  void ShowInfo();
};
