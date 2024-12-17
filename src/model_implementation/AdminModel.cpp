#include "../../include/models/AdminModel.hpp"
using namespace std;

AdminModel::AdminModel(string id, string name, int age, string password): PersonModel(id,name,age){
  this->password = password;
}

string AdminModel::GetPassword(){
  return password;
}

int AdminModel::GetAdminId(){
  return admin_id;
}

string AdminModel::ToString(){
  return PersonModel::ToString() + ","+ to_string(admin_id) + "," + password;
}
