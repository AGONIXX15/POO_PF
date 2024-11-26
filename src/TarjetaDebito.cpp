#include "../include/TarjetaDebito.hpp"


TarjetaDebito::TarjetaDebito(int id, std::string name, int number, int cvv,
                             float balance)
    : Tarjeta(id, name, number, cvv, balance) {}

ArchivoCSV TarjetaDebito::get_file() { return this->file; }
void TarjetaDebito::show_info() {
  std::cout << "Tarjeta de Debito: " << this->get_name() << std::endl;
  std::cout << "Numero de tarjeta: " << this->get_number() << std::endl;
  std::cout << "CVV: " << this->get_cvv() << std::endl;
  std::cout << "Saldo: " << this->get_balance() << std::endl;
}

void TarjetaDebito::write() {
  this->get_file().write({std::to_string(this->get_id()), this->get_name(),
  std::to_string(this->get_number()),
  std::to_string(this->get_cvv()),
  std::to_string(this->get_balance())});
}

void TarjetaDebito::update() {
  this->get_file().update(std::to_string(this->get_id()), this->get_name(), 1);
  this->get_file().update(std::to_string(this->get_id()),
                          std::to_string(this->get_number()), 2);
  this->get_file().update(std::to_string(this->get_id()),
                          std::to_string(this->get_cvv()), 3);
  this->get_file().update(std::to_string(this->get_id()),
                          std::to_string(this->get_balance()), 4);
}

void TarjetaDebito::remove() {
  this->get_file().remove(std::to_string(this->get_id()));
}

