#pragma once
#include "Tarjeta.hpp"
#include "ArchivoCSV.hpp"

class TarjetaCredito : public Tarjeta {
public:
  TarjetaCredito(int id, std::string name, int number, int cvv, float balance);
  void show_info() override;
  void write() override;
  void remove() override;
  void update() override;

  ArchivoCSV get_file();
  ~TarjetaCredito() = default;

 

private:
  ArchivoCSV file{"DB/Clientes/Tarjetas/tarjetas_credito.csv"};
};
