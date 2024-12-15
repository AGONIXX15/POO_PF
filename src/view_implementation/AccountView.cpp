#include  "../../include/view/AccountView.hpp"
#include "../../include/models/AccountModel.hpp"
#include "../../include/service/AccountService.hpp"
#include "../../include/service/AccountTypeService.hpp"
#include "../../include/models/AccountTypeModel.hpp"

#include <iostream>


AccountView::AccountView() {

}

void AccountView::ShowMenu() {
    int option;
    do {
        std::cout << "\n=== Menú de Gestión de Cuentas ===" << std::endl;
        std::cout << "1. Agregar cuenta" << std::endl;
        std::cout << "2. Leer cuentas" << std::endl;
        std::cout << "3. Actualizar cuenta" << std::endl;
        std::cout << "4. Eliminar cuenta" << std::endl;
        std::cout << "5. Agregar Intereses, Limite y Cuota de manejo" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";
        
        std::cin >> option;
        std::cin.ignore();

        AccountService service;
        AccountTypeService typeService;

        switch (option) {
            case 1: {
                std::cout << "\n=== Agregar cuenta ===" << std::endl;
                std::string owner, type, status, creationDate;
                int accountNumber;
                float balance;

                std::cout << "Propietario: ";
                std::getline(std::cin, owner);

                std::cout << "Tipo de cuenta (Ahorro/Corriente): ";
                std::getline(std::cin, type);

                std::cout << "Número de cuenta: ";
                std::cin >> accountNumber;
                std::cin.ignore();

                std::cout << "Estado (Activa/Inactiva): ";
                std::getline(std::cin, status);

                std::cout << "Fecha de creación (xx-xx-xxxx): ";
                std::getline(std::cin, creationDate);

                std::cout << "Balance inicial: ";
                std::cin >> balance;
                std::cin.ignore();

                AccountModel account(owner, type, accountNumber, status, creationDate, balance);
                service.Add(account);
                break;
            }

            case 2: {
                std::cout << "\n=== Leer cuentas ===" << std::endl;
                std::cout << "Eliga el tipo de cuenta a leer 1. Ahorro 2. Corriente: ";
                int opc;
                std::cin >> opc;
                std::cin.ignore();
                if(opc == 1){
                    int numberAccount;
                    std::cout << "Ingrese el número de cuenta a leer: ";
                    std::cin >> numberAccount;
                    std::cin.ignore();
                    typeService.Read(numberAccount);
                }else if(opc == 2){
                    int numberAccount;  
                    std::cout << "Ingrese el número de cuenta a leer: ";
                    std::cin >> numberAccount;
                    std::cin.ignore();
                    typeService.Read2(numberAccount);
                }
                break;
            }

            case 3: {
                std::cout << "\n=== Actualizar cuenta ===" << std::endl;
                int accountNumber;
                std::cout << "Ingrese el número de cuenta a actualizar: ";
                std::cin >> accountNumber;
                std::cin.ignore();
                service.Update(accountNumber);
                break;
            }

            case 4: {
                std::cout << "\n=== Eliminar cuenta ===" << std::endl;
                int accountNumber;
                std::cout << "Ingrese el número de cuenta a eliminar: ";
                std::cin >> accountNumber;
                std::cin.ignore();
                service.Remove(accountNumber);
                break;
            }

            case 5: {
                int accountNumber;
                std::cout << "\n=== Agregar Intereses, Límite y Cuota de manejo ===" << std::endl;
                std::cout << "Ingrese el número de cuenta a procesar: ";
                std::cin >> accountNumber;
                std::cin.ignore();
                typeService.ProcessAccounts(accountNumber);
                break;
            }

            case 6:
                std::cout << "Saliendo del sistema. ¡Hasta pronto!" << std::endl;
                return;

            default:
                std::cout << "Opción inválida. Por favor, intente de nuevo." << std::endl;
                break;
        }
    } while (true);
}
