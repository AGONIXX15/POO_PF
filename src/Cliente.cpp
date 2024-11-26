#include "../include/Cliente.hpp"
#include "../include/TarjetaCredito.hpp"
#include "../include/TarjetaDebito.hpp"
/* este constructor se usa cuando se va agregar un cliente */
Cliente::Cliente(std::string name, int age, int id) : Persona(name, age, id) {}

/*el constructor vacio se usa cuando se van a cargar datos */
Cliente::Cliente() {}

void Cliente::add_debit_card(std::shared_ptr<TarjetaDebito> tarjeta) {
  this->debit_cards.emplace_back(tarjeta);
}

void Cliente::add_credit_card(std::shared_ptr<TarjetaCredito> tarjeta) {
  this->credit_cards.push_back(tarjeta);
}

/*cargar los datos a la clase cliente
 * @param string id: es el id del cliente
 * @return void*/
void Cliente::load_data(std::string id) {
  auto data = this->get_file().load_data(id);
  this->set_id(std::stoi(data[0][0]));
  this->set_name(data[0][1]);
  this->set_age(std::stoi(data[0][2]));
  ArchivoCSV credit("DB/Clientes/Tarjetas/tarjetas_credito.csv");
  ArchivoCSV  debit("DB/Clientes/Tarjetas/tarjetas_debito.csv");
  // cargar datos de la tarjeta de credito
  for (auto credit_card : credit.load_data(id)) {
    std::cout << "size of credit_card: " << credit_card.size() << std::endl; 
    for (auto val : credit_card) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
    try {
      if (credit_card.size() != 5) {
        throw std::runtime_error("Invalid credit card data");
      }
       
      auto card = std::make_shared<TarjetaCredito>(
          std::stoi(credit_card[0]), credit_card[1], std::stoi(credit_card[2]),
          std::stoi(credit_card[3]), std::stof(credit_card[4]));
      this->credit_cards.emplace_back(card);
    } catch (const std::exception &e) {
      std::cerr << "Error loading credit card data: " << e.what() << std::endl;
    }
  }
  // cargar datos de las tarjetas de debito
  for (auto debit_card : debit.load_data(id)) {
    std::cout <<debit_card.size() << std::endl;
    for (auto val : debit_card) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
    std::shared_ptr<TarjetaDebito> card = std::make_shared<TarjetaDebito>(
        std::stoi(debit_card[0]), debit_card[1], std::stoi(debit_card[2]),
        std::stoi(debit_card[3]), std::stof(debit_card[4]));
    this->debit_cards.emplace_back(card);
  }
  this->data_loaded = true;
}

/*actualiza los datos del cliente
 * @return void*/
void Cliente::update_data() {
  this->get_file().update(std::to_string(this->get_id()), this->get_name(), 1);
  this->get_file().update(std::to_string(this->get_id()),
                          std::to_string(this->get_age()), 2);
  for (size_t i = 0; i < this->credit_cards.size(); ++i) {
    this->credit_cards[i]->update();
  }

  for (size_t i = 0; i < this->debit_cards.size(); ++i) {
    this->debit_cards[i]->update();
  }
}

void Cliente::save_data() {
  this->get_file().write({{std::to_string(this->get_id()), this->get_name(),
                           std::to_string(this->get_age())}});
  for (size_t i = 0; i < this->credit_cards.size(); ++i) {
    this->credit_cards[i]->write();
  }
}

void Cliente::remove_data() {
  if (this->get_DataLoaded()) {
    std::cout << "removiendo data" << std::endl;
    this->get_file().remove(std::to_string(this->get_id()));
    return;
  }
  std::cerr << "estas intentando remover algo que no existe" << std::endl;
  exit(1);
}

ArchivoCSV &Cliente::get_file() { return this->file; }

bool &Cliente::get_DataLoaded() { return this->data_loaded; }

std::vector<std::shared_ptr<TarjetaDebito>> Cliente::get_debit_cards() {
  return debit_cards;
}

std::vector<std::shared_ptr<TarjetaCredito>> Cliente::get_credit_cards() {
  return credit_cards;
}
