#pragma once
#include "../models/ClientModel.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class ClientService{
public:
  std::string filename = "db/clientes.csv";
  ClientService();
  bool Find(int id);
  void Remove(int id);
  void Update(ClientModel client);
  void Read();
  void Add(ClientModel client);
};
