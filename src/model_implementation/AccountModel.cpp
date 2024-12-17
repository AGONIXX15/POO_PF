#include  "../../include/models/AccountModel.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
inline string load_id() {
    ifstream file("cuentas.csv");
    string line, last_id = "0";
    
    while (getline(file, line)) {
        stringstream ss(line);
        string id;
        getline(ss, id, ',');
        last_id = id;
    }
    
    int new_id = stoi(last_id) + 1;
    return to_string(new_id);
}

AccountModel::AccountModel(string id_,string owner, string accountNumber, float balance) {
    owner_name = owner;
    accountNumber = accountNumber;
    balance = balance;
    id_ = load_id();
}   
AccountModel::AccountModel(){
    
    this->id = stoi(load_id()); // Asigna el nuevo id
}


int AccountModel::get_id() {
    return id;
}

//metodos getters
float AccountModel::GetBalance() {
    return balance;
}

string AccountModel::GetOwner() {
    return owner_name;
}

string AccountModel::GetAccountNumber() {
    return accountNumber;
}

string AccountModel::GetExpirateDate() {
    return expirate_Date;
}

string AccountModel::getinfo() {
    return "Owner: " + owner_name + " Account Number: " + accountNumber +  "Balance: " + to_string(balance);
}

//metodos setters

void AccountModel::SetBalance(float balance) {
    balance = balance;
}

void AccountModel::SetOwner(string owner) {
    owner_name = owner;
}

void AccountModel::SetAccountNumber(string accountNumber) {
    accountNumber = accountNumber;
}

void AccountModel::SetType(string AccountType) {
    AccountType = AccountType;
}

void AccountModel::SetExpirateDate(string expirate_Date) {
    expirate_Date = expirate_Date;
}

