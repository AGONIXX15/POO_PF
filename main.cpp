#include "include/Cliente.hpp"


int main() {
  Cliente cliente;
  cliente.load_data("1");
  auto credit_cards = cliente.get_credit_cards();

  for (auto& card : credit_cards) {
    card->show_info();
  }
  return 0;
}

