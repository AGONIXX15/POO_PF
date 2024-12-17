#include "../../include/models/ClientModel.hpp"
using namespace std;


ClientModel::ClientModel(string id, string name, int age): PersonModel(id,name,age){}


string ClientModel::ToString(){
  return PersonModel::ToString();
}

void ClientModel::ShowInfo(){
  cout << "__________________________" << endl;
  cout << "id: " << GetId() << "nombre: " << GetName() << "edad: " << GetAge() << endl;
  cout << "__________________________" << endl;
}
