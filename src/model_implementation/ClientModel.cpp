#include "../../include/models/ClientModel.hpp"


ClientModel::ClientModel(int id, std::string name, int age): PersonModel(id,name,age){}

std::string ClientModel::ToString(){
  return PersonModel::ToString();
}
