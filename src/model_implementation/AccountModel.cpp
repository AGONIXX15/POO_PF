#include "../../include/models/AccountModel.hpp"   

AccountModel::AccountModel(std::string owner, int accountNumber, std::string status, std::string creationDate, float balance)
    : owner(owner), accountNumber(accountNumber), status(status), creationDate(creationDate), balance(balance) {}

float AccountModel::GetBalance() { return balance; }

std::string AccountModel::GetOwner() { return owner; }

std::string AccountModel::GetAccountNumber() { return std::to_string(accountNumber); }

std::string AccountModel::GetStatus() { return status; }

std::string AccountModel::GetCreationDate() { return creationDate; }

std::string AccountModel::ToString() {
    return owner + "," + std::to_string(accountNumber) + "," + status + "," + creationDate + "," + std::to_string(balance) + "\n";
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

