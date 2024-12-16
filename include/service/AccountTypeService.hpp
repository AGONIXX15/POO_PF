#pragma once
#include "AccountService.hpp"
#include <iostream>
#include <string>

class AccountTypeService : public AccountService {
    public:
        AccountTypeService();
        std::string filename1 = "db/accounts_savings.csv";
        std::string filename2 = "db/accounts_current.csv";
        void ProcessAccounts(int);
        void Read(int numberAccount);
        void Read2(int numberAccount);
        void Remove(int numberAccount);
        void Remove2(int numberAccount);
};
