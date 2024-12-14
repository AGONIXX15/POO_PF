#include "include/models/ClientModel.hpp"
#include "include/service/ClientService.hpp"
#include "include/models/AccountModel.hpp"
#include "include/service/AccountService.hpp"

#include <iostream>
#include <vector>

int main() { 
  ClientService service;
  ClientModel client(123,"sebastian",15);
  ClientModel client1(124,"karen",18);
  service.Add(client);
  service.Add(client1);

  return 0;
}
