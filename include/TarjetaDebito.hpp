#pragma once
#include "Tarjeta.hpp"
#include "ArchivoCSV.hpp"

class TarjetaDebito : public Tarjeta {
public:
  TarjetaDebito() = default;
  TarjetaDebito(int id, std::string name, int number, int cvv, float balance);
  void show_info() override;
  void write() override;
  void remove() override;
  void update() override;

  ArchivoCSV get_file();
private:
  ArchivoCSV file{"DB/Clientes/Tarjetas/tarjetas_debito.csv"};
};
