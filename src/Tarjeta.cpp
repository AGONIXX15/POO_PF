#include "../include/Tarjeta.hpp"


Tarjeta::Tarjeta(int id, std::string name, int number, int cvv, float balance)
: id(id), name(name), number(number), cvv(cvv), balance(balance) {}

// SETTERS
void Tarjeta::set_number(int number) { this->number = number; }

void Tarjeta::set_cvv(int cvv) { this->cvv = cvv; }

void Tarjeta::set_balance(float balance) { this->balance = balance; }

// GETTERS

int Tarjeta::get_number() { return    this->number; }

int Tarjeta::get_cvv() { return this->cvv; }

float Tarjeta::get_balance() { return this->balance; }

int Tarjeta::get_id() {return this->id;}

std::string Tarjeta::get_name() {return this->name;}

