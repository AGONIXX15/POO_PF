#include "../../include/service/AccountService.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

AccountService::AccountService(){

}

std::vector<std::string> split(std::string line, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(line);
        while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool AccountService::Find(int numberAccount) {
    std::string strid = std::to_string(numberAccount);
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        auto data = split(line, ',')[0];
        if (data == strid) {
        return true;
        }
    }
    return false;
}

void AccountService::Add(AccountModel account){
    std::ofstream file(filename, std::ios::app);
    file << account.ToString();
}

void AccountService::Update(int numberAccount){
    std::ifstream file(filename);
    std::ofstream temp("db/temp.csv");
    std::string line;
    while (std::getline(file, line)) {
        auto data = split(line, ',')[0];
        if (data != std::to_string(numberAccount)) {
            temp << line << std::endl;
        }
    }
    