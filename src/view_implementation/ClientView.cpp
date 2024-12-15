#include "../../include/view/ClientView.hpp"
#include "../../include/service/ClientService.hpp"
#include <iostream>
#include <string>

ClientView::ClientView() {
}


void ClientView::ShowMenu() {
    ClientService client; 
    int option = 0;
    std::cout << "Bienvenido a el banco la perra de rubio " << std::endl;
    std::cout << "1. Quiere registrarse en ingles?" << std::endl;
    std::cout << "2. Quiere salirse del banco?" << std::endl;
    std::cout << "3. Quire saber tu estado en el banco" << std::endl;
    std::cout << "4. desea actualizar tus datos" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << std::endl; 
    std::cout << "selest on optin: "; std::cin >> option;
    std::cin.ignore();
    std::cout << std::endl;
    switch(option) {
        case 1:{
            std::string names; 
            int age; 
            std::cout << "Registrarse" << std::endl;
            std::cout<<std::endl; 
            std::cout << "Ingrese su nombre: "; std::cin >> names;
            std::cout << "Ingrese su edad: "; std::cin >> age;
            std::cin.ignore();
            ClientModel client(names, age);
            client.Add(client);
            std::cout << "cliente registrado" << std::endl;
            break;
            }
        case 2:{
            int id; 
            std::cout << "Renunciando a nuestro servicios" << std::endl;
            std::cout<< "Ingrese su id: "; std::cin >> id;       
            std::cin.ignore();
            cliente.Remove(id);
            std::cout<<"cliente eliminado" <<std:: endl; 
            break;
            }
        case 3:{
            int id; 
            std::cout << "Inicie tu seccion: " << std::endl;
            std::cout<< "Ingrese su id: "; std::cin >> id;       
            std::cin.ignore();
            client.FindYou(id);
            break;
            }
        case 4:{
            int id, age; 
            std::string name; 
            std::cout << "Actualizar datos" << std::endl;  
            std::cout << "ingrese su id: "; std::cin >> id; 
            std::cin.ignore(); 
            std:: cout << "ingrese su nombre: "; std::cin >> name; 
            std::cout << "ingrese su edad: "; std::cin >> age;
            std::cin.ignore(); 
            ClientModel client(id, name, age); 
            client.Update(client);
            break;
            }
        case 0:
            std::cout << "Exit" << std::endl;
            break;
        default:
            std::cout << "Invalid option" << std::endl;
            break;
    }
}