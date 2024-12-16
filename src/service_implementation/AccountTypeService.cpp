#include "../../include/service/AccountTypeService.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

AccountTypeService::AccountTypeService() {}

std::vector<std::string> split1(std::string line, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(line);
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void AccountTypeService::ProcessAccounts(int specificAccountNumber) {
    std::ifstream file(filename); // Archivo original
    std::ofstream savingsFile(filename1, std::ios::app); // Archivo para cuentas de ahorro (modo append)
    std::ofstream currentFile(filename2, std::ios::app); // Archivo para cuentas corrientes (modo append)
    std::string line;

    if (!file.is_open() || !savingsFile.is_open() || !currentFile.is_open()) {
        std::cerr << "Error al abrir los archivos." << std::endl;
        return;
    }

    bool accountFound = false;

    while (std::getline(file, line)) {
        std::vector<std::string> tokens = split1(line, ',');
        if (tokens.size() < 6) {
            std::cerr << "Formato incorrecto en la línea: " << line << std::endl;
            continue;
        }

        // Extraer datos de la cuenta
        int accountNumber = std::stoi(tokens[2]);

        // Verificar si es la cuenta específica que se desea procesar
        if (accountNumber != specificAccountNumber) {
            continue; // Saltar a la siguiente cuenta si no es la cuenta buscada
        }

        accountFound = true;

        std::string owner = tokens[0];
        std::string type = tokens[1];
        std::string status = tokens[3];
        std::string creationDate = tokens[4];
        double balance = std::stod(tokens[5]);

        double interest = 0;    
        double limit = 0;       
        double maintenanceFee = 0; 

        // Procesar cuentas de ahorro
        if (type == "Ahorro") {
            std::cout << "\nCuenta de ahorro detectada:\n";
            std::cout << "Propietario: " << owner << ", Número de cuenta: " << accountNumber << "\n";
            std::cout << "Balance actual: " << balance << "\n";

            double interestRate = 9; 
            interestRate /= 100; 
            interest = balance * interestRate;
            balance += interest;
            std::cout << "Interés aplicado: " << interest << "\nNuevo balance: " << balance << "\n";

            std::cout << "Introduce el límite de dinero: ";
            std::cin >> limit;
            std::cin.ignore();
            if (balance >= limit) {
                std::cout << "El balance excede el límite.\n";
                std::cout << "Ingrese un nuevo limite de saldo acorde al balance actual: "<< balance << std::endl;
                std::cin >> limit;
                std::cin.ignore();
            }

            maintenanceFee = 0;

            // Guardar en el archivo de ahorro
            savingsFile << owner << "," << type << "," << accountNumber << "," << status << ","
                        << creationDate << "," << balance << "," << interest << "," << limit << ","
                        << maintenanceFee << "\n";
        }

        // Procesar cuentas corrientes
        else if (type == "Corriente") {
            std::cout << "\nCuenta corriente detectada:\n";
            std::cout << "Propietario: " << owner << ", Número de cuenta: " << accountNumber << "\n";
            std::cout << "Balance actual: " << balance << "\n";

            double maintenanceFee = 5;
            maintenanceFee /= 100;
            maintenanceFee = balance * maintenanceFee;
            balance -= maintenanceFee;
            std::cout << "Cuota de mantenimiento aplicada: " << maintenanceFee << "\n";
            std::cout << "Nuevo balance: " << balance << "\n";

            interest = 0;
            limit = 0;

            // Guardar en el archivo de corrientes
            currentFile << owner << "," << type << "," << accountNumber << "," << status << ","
                        << creationDate << "," << balance << "," << interest << "," << limit << ","
                        << maintenanceFee << "\n";
        }

        break; // Salir del bucle después de procesar la cuenta específica
    }

    file.close();
    savingsFile.close();
    currentFile.close();

    if (!accountFound) {
        std::cout << "No se encontró la cuenta con número: " << specificAccountNumber << std::endl;
    } else {
        std::cout << "\nProcesamiento completado para la cuenta: " << specificAccountNumber << "\n";
    }
}

void AccountTypeService::Read(int numberAccount) {
    std::ifstream savingsFile(filename1);
    //verificar el numero de cuenta para mostrar la informacion
    std::string line;
    while (std::getline(savingsFile, line)) {
        std::vector<std::string> tokens = split1(line, ',');
        if (std::stoi(tokens[2]) == numberAccount) {
            std::cout << "Propietario: " << tokens[0] << std::endl;
            std::cout << "Tipo de cuenta: " << tokens[1] << std::endl;
            std::cout << "Numero de cuenta: " << tokens[2] << std::endl;
            std::cout << "Estado: " << tokens[3] << std::endl;
            std::cout << "Fecha de creacion: " << tokens[4] << std::endl;
            std::cout << "Dinero disponible: " << tokens[5] << std::endl;
            std::cout << "Interes: " << tokens[6] << std::endl;
            std::cout << "Limite: " << tokens[7] << std::endl;
            std::cout << "Cuota de mantenimiento: " << tokens[8] << std::endl;
            std::cout << "--------------------------------" << std::endl;
            return;
        }
    }
}

void AccountTypeService::Read2(int numberAccount) {
    std::ifstream currentFile(filename2);
    //verificar el numero de cuenta para mostrar la informacion
    std::string line;
    while (std::getline(currentFile, line)) {
        std::vector<std::string> tokens = split1(line, ',');
        if (std::stoi(tokens[2]) == numberAccount) {
            std::cout << "Propietario: " << tokens[0] << std::endl;
            std::cout << "Tipo de cuenta: " << tokens[1] << std::endl;
            std::cout << "Numero de cuenta: " << tokens[2] << std::endl;
            std::cout << "Estado: " << tokens[3] << std::endl;
            std::cout << "Fecha de creacion: " << tokens[4] << std::endl;
            std::cout << "Dinero disponible: " << tokens[5] << std::endl;
            std::cout << "Interes: " << tokens[6] << std::endl;
            std::cout << "Limite: " << tokens[7] << std::endl;
            std::cout << "Cuota de mantenimiento: " << tokens[8] << std::endl;
            std::cout << "--------------------------------" << std::endl;
            return;
        }
    }
}

void AccountTypeService::Remove(int numberAccount) {
    std::ifstream savingsFile(filename1);
    std::ofstream tempFile("db/temp.csv", std::ios::app);
    std::string line;
    while (std::getline(savingsFile, line)) {
        std::vector<std::string> tokens = split1(line, ',');
        if (std::stoi(tokens[2]) != numberAccount) {
            tempFile << line << "\n";
        }
    }
    savingsFile.close();
    tempFile.close();
    remove(filename1.c_str());
    rename("db/temp.csv", filename1.c_str());
}

void AccountTypeService::Remove2(int numberAccount) {
    std::ifstream currentFile(filename2);
    std::ofstream tempFile("db/temp.csv", std::ios::app);
    std::string line;
    while (std::getline(currentFile, line)) {
        std::vector<std::string> tokens = split1(line, ',');
        if (std::stoi(tokens[2]) != numberAccount) {
            tempFile << line << "\n";
        }
    }
    currentFile.close();
    tempFile.close();
    
    remove(filename2.c_str());
    rename("db/temp.csv", filename2.c_str());
}

