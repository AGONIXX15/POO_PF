#include "../../include/models/AccountTypeModel.hpp"
#include "../../include/models/AccountModel.hpp"
#include <iostream>

AccountTypeModel::AccountTypeModel(std::string owner, std::string accountType, int accountNumber, std::string status, std::string creationDate, float balance, std::string type, float i, float l, float m)
    : AccountModel(owner, accountType, accountNumber, status, creationDate, balance), interest(i), limit(l), maintenanceCost(m) {}
    
float AccountTypeModel::GetInterest() { return interest; }

float AccountTypeModel::GetLimit() { return limit; }

float AccountTypeModel::GetMaintenanceCost() { return maintenanceCost; }

std::string AccountTypeModel::ToString() {
    return AccountModel::ToString() + std::to_string(interest) + "," + std::to_string(limit) + "," + std::to_string(maintenanceCost) + "\n";
}

void AccountTypeModel::ShowInfo() {
    AccountModel::ShowInfo();
    std::cout << "Interes: " << interest << std::endl;
    std::cout << "Limite: " << limit << std::endl;
    std::cout << "Cuota de mantenimiento: " << maintenanceCost << std::endl;
}
