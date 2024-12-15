#include "../../include/service/AccountService.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

AccountService::AccountService() {}

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
    std::ifstream file(filename);   
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> tokens = split(line, ',');
        if (std::stoi(tokens[2]) == numberAccount) {
            return true;
        }
    }
    std::cout <<"No se encontró la cuenta con número: " << numberAccount << std::endl;
    return false;
}

void AccountService::Add(AccountModel account) {
    if (Find(std::stoi(account.GetAccountNumber()))) {
        std::cout << "El número de cuenta ya está registrado. No se puede agregar." << std::endl;
        return;
    }

    std::ofstream file(filename, std::ios::app);
    file << account.ToString();
    
    file.close();
    std::cout << "Cuenta agregada exitosamente." << std::endl;
}

void AccountService::Read() {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> tokens = split(line, ',');
        std::cout << "Propietario: " << tokens[0] << std::endl;
        std::cout << "Tipo de cuenta: " << tokens[1] << std::endl;
        std::cout << "Numero de cuenta: " << tokens[2] << std::endl;
        std::cout << "Estado: " << tokens[3] << std::endl;
        std::cout << "Fecha de creacion: " << tokens[4] << std::endl;
        std::cout << "Dinero disponible: " << tokens[5] << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
    file.close();
}

void AccountService::Update(int numberAccount) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line)) {
        std::vector<std::string> tokens = split(line, ',');
        if (std::stoi(tokens[2]) == numberAccount) {
            std::string owner, type, status, creationDate, balance;
            std::cout << "Propietario: ";
            std::getline(std::cin, owner);
            std::cout << "Tipo de cuenta: ";
            std::getline(std::cin, type);
            std::cout << "Estado: ";
            std::getline(std::cin, status);
            std::cout << "Fecha de creacion xx-xx-xxxx: ";
            std::getline(std::cin, creationDate);
            std::cout << "Dinero disponible: ";
            std::cin >> balance;
            std::cin.ignore();
            line = owner + "," + type + "," + std::to_string(numberAccount) + "," + status + "," + creationDate + "," + balance;
        }
        lines.push_back(line);
    }
    file.close();
    std::ofstream file2(filename);
    for (std::string line : lines) {
        file2 << line << std::endl;
    }
    file2.close();
}

void AccountService::Remove(int numberAccount) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> lines;
    bool accountFound = false;

    while (std::getline(file, line)) {
        std::vector<std::string> tokens = split(line, ',');
        if (std::stoi(tokens[2]) != numberAccount) {
            lines.push_back(line);
        } else {
            accountFound = true;
        }
    }
    file.close();

    std::ofstream file2(filename);
    for (std::string line : lines) {
        file2 << line << std::endl;
    }
    file2.close();

    if (accountFound) {
        std::cout << "Cuenta eliminada exitosamente." << std::endl;
    } else {
        std::cout << "Cuenta no encontrada." << std::endl;
    }
}
