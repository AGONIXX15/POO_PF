#include "../include/TarjetaCredito.hpp"


TarjetaCredito::TarjetaCredito(int id, std::string name, int number, int cvv,
                               float balance)
    : Tarjeta(id, name, number, cvv, balance) {}

ArchivoCSV TarjetaCredito::get_file() { return this->file; }
// mostrar informacion acerca de la tarjeta
void TarjetaCredito::show_info() {
  std::cout << "_________________________" << std::endl;
  std::cout << "ID: " << this->get_id() << std::endl;
  std::cout << "Nombre: " << this->get_name() << std::endl;
  std::cout << "Número: " << this->get_number() << std::endl;
  std::cout << "CVV: " << this->get_cvv() << std::endl;
  std::cout << "Saldo: " << this->get_balance() << std::endl;
  std::cout << "_________________________" << std::endl;
}

// guardar informacion de la tarjeta en un archivo
void TarjetaCredito::write() {
  this->get_file().write({std::to_string(this->get_id()), this->get_name(), std::to_string(this->get_number()),
                         std::to_string(this->get_cvv()), std::to_string(this->get_balance())});
}
// eliminar informacion de la tarjeta en un archivo
void TarjetaCredito::remove() {
  this->get_file().remove(std::to_string(this->get_id()));
}

// actualizar informacion de la tarjeta en un archivo
void TarjetaCredito::update() {
  this->get_file().update(std::to_string(this->get_id()), this->get_name(), 1);
  this->get_file().update(std::to_string(this->get_id()),
                          std::to_string(this->get_number()), 2);
  this->get_file().update(std::to_string(this->get_id()),
                          std::to_string(this->get_cvv()), 3);
  this->get_file().update(std::to_string(this->get_id()),
                          std::to_string(this->get_balance()), 4);
}
