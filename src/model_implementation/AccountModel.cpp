#include "../../include/models/AccountModel.hpp"
#include <iostream>

AccountModel::AccountModel(std::string owner, std::string type, int accountNumber, std::string status, std::string creationDate, float balance)
    : owner(owner), type(type), accountNumber(accountNumber), status(status), creationDate(creationDate), balance(balance) {}

float AccountModel::GetBalance() { return balance; }

std::string AccountModel::GetOwner() { return owner; }

std::string AccountModel::GetAccountNumber() { return std::to_string(accountNumber); }

std::string AccountModel::GetStatus() { return status; }

std::string AccountModel::GetCreationDate() { return creationDate; }

std::string AccountModel::GetType() { return type; }

std::string AccountModel::ToString() {
    return owner + "," + type + "," + std::to_string(accountNumber) + "," + status + "," + creationDate + "," + std::to_string(balance) + "\n";
}

void AccountModel::SetBalance(float b){
    balance = b;
}

void AccountModel::SetOwner(std::string o){
    owner = o;
}

void AccountModel::SetAccountNumber(int a){
    accountNumber = a;
}

void AccountModel::SetStatus(std::string s){
    status = s;
}

void AccountModel::SetCreationDate(std::string c){
    creationDate = c;
}

void AccountModel::SetType(std::string t){
    type = t;
}

void AccountModel::ShowInfo(){
    std::cout << "Propietario: " << owner << std::endl;
    std::cout << "Tipo de cuenta: " << type << std::endl;
    std::cout << "Numero de cuenta: " << accountNumber << std::endl;
    std::cout << "Estado: " << status << std::endl;
    std::cout << "Fecha de creacion: " << creationDate << std::endl;
    std::cout << "Dinero disponible: " << balance << std::endl;
    
}
