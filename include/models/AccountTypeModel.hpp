#pragma once
#include "AccountModel.hpp"
#include <vector>
#include <iostream>

class AccountTypeModel : public AccountModel {
    private:
        std::string type;
    public:
        AccountTypeModel(std::string owner, std::string accountNumber, std::string status, std::string creationDate, float balance, std::string type);
        std::string GetType();
        void SetType(std::string type);
        void PrintAccountType();
};
