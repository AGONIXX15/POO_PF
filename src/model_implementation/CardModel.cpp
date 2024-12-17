#include "../../include/models/CardModel.hpp"
#include "../../include/utils.hpp"

CardModel::CardModel(int balance, string id_client, string name) {

  this->id_client = id_client;
  this->name = name;
  number = gen_number(16);
  cvv = gen_number(3);
  this->balance = balance;
}

CardModel::CardModel(string line){
  auto data = split(line, ',');
  id_client = data[0];
  number = data[1];
  cvv = data[2];
  balance = stoi(data[3]);
  name = data[4];
  expire_date = data[5];
}

string CardModel::GetNumber() { return number; }

string CardModel::GetCvv() { return cvv; }

int CardModel::GetBalance() { return balance; }

string CardModel::ToString() {
  return id_client + "," + number + "," + cvv + "," + to_string(balance) + "," + name + "," +
         expire_date;
}

void CardModel::ShowInfo() {
  cout << "______________________" << endl;
  cout << "nombre del propietario: " << name << endl;
  cout << "Card number: " << number << endl;
  cout << "CVV: " << cvv << endl;
  cout << "Balance: " << balance << endl;
  cout << "Expire date: " << expire_date << endl;
  cout << "______________________" << endl;
}

void CardModel::LowerBalance(int amount) {
  if (balance - amount < 0) {
    cout << "No tienes suficiente dinero" << endl;
    return;
  }
  balance -= amount;
}

void CardModel::UpperBalance(int amount) { balance += amount; }
=======
#include "../../include/models/CardModel.hpp"

CardModel::CardModel(std::string brand, int number, int cvv, float balance, CardTypeModel type) {
  this->brand = brand;
  this->number = number;
  this->cvv = cvv;
  this->balance = balance;
  this->type = type;
}

std::string CardModel::GetBrand() {
  return this->brand;
}

int CardModel::GetNumber() {
  return this->number;
}

int CardModel::GetCvv() {
  return this->cvv;
}

float CardModel::GetBalance() {
  return this->balance;
}


CardTypeModel CardModel::GetType() {
  return this->type;
}

void CardModel::Transfer(float amount) {
  this->balance -= amount;
}
>>>>>>> origin/devia
