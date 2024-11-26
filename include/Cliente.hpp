#pragma once

#include "ArchivoCSV.hpp"
#include "TarjetaCredito.hpp"
#include "TarjetaDebito.hpp"
#include "Persona.hpp"
#include <vector>

class Cliente : public Persona {
public:
  Cliente(std::string name, int age, int id);
  Cliente();

  void agregar_cuenta_ahorro();
  void agregar_cuenta_corriente();
  void add_debit_card(std::shared_ptr<TarjetaDebito> tarjeta);
  void add_credit_card(std::shared_ptr<TarjetaCredito> tarjeta);
  std::vector<std::shared_ptr<TarjetaDebito>> get_debit_cards();
  std::vector<std::shared_ptr<TarjetaCredito>> get_credit_cards();

  // manipulacion de archivos
  ArchivoCSV& get_file();
  void load_data(std::string id);
  void save_data();
  void update_data();
  void remove_data();
  bool& get_DataLoaded();

private:
  std::vector<std::shared_ptr<TarjetaDebito>> debit_cards;
  std::vector<std::shared_ptr<TarjetaCredito>> credit_cards;
  bool data_loaded = false;
  ArchivoCSV file{"DB/Clientes/clientes.csv"};
};
