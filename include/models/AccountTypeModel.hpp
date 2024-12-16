#pragma once
#include "AccountModel.hpp"
#include <vector>
#include <iostream>

class AccountTypeModel : public AccountModel {
    private:
        float interest;
        float limit;
        float maintenanceCost;
    public:
        AccountTypeModel(std::string owner, std::string accountType, int accountNumber, std::string status, std::string creationDate, float balance, std::string type, float interest, float limit, float maintenanceCost);
        float GetInterest();
        float GetLimit();
        float GetMaintenanceCost();
        std::string ToString();
        void ShowInfo();
};
