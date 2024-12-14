#pragma once
#include "../models/AccountModel.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class AccountService {
    public:
        AccountService();
        std::string filename = "db/accounts.csv";
        bool Find(int numberAccount);
        void Add(AccountModel account);
        void Read();
        void Update(int numberAccount);
        void Remove(int numberAccount);
};




