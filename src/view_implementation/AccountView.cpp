#include "../../include/service/AccountService.hpp"
#include "../../include/view/AccountView.hpp"
#include <iostream>
#include <string>
using namespace std;
AccountView::AccountView() {}

void AccountView::menu_account() {
  AccountService account_service;
  int option;
  string account_number;
  int ammount;
  do {
    cout << "1. Crear cuenta" << endl;
    cout << "2. Depositar" << endl;
    cout << "3. Retirar" << endl;
    cout << "4. Transferir" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
    cin >> option;
    switch (option) {
    case 1:
      account_service.CreateAccount();
      break;
    case 2:
      cout << "Ingrese el numero de cuenta: ";
      cin >> account_number;
      cout << "Ingrese la cantidad a depositar: ";
      cin >> ammount;
      account_service.Deposit(account_number, ammount);
      break;
    case 3:
      cout << "Ingrese el numero de cuenta: ";
      cin >> account_number;
      cout << "Ingrese la cantidad a retirar: ";
      cin >> ammount;
      account_service.Withdraw(account_number, ammount);
      break;
    case 4:
      account_service.Transfer();
      break;
    case 5:
      cout << "Saliendo..." << endl;
      break;
    default:
      cout << "Opcion no valida" << endl;
      break;
    }
  } while (option != 5);
}
