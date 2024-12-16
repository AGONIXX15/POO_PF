#pragma once
#include "PersonModel.hpp"
#include <iostream>

using namespace std;

class AdminModel : public PersonModel {
private:
  string password;
  int admin_id;

public:
  AdminModel(int id, string name, int age, string password);
  string GetPassword();
  int GetAdminId();
  string ToString() override;
  void ShowInfo();
};
