#include "../../include/service/CardService.hpp"
#include "../../include/models/utils.hpp"

CardService::CardService(CardModel card) {
  if(card.GetType().GetType() == "credit"){
    this->filename = "db/credit_cards.csv";
  }
  else{
    this->filename = "db/debit_cards.csv";
  }
}

bool CardService::Find(int number) {
  std::string strnumber = std::to_string(number);
  std::ifstream file(filename);
  std::string line;
  while (std::getline(file, line)) {
    auto data = split(line, ',')[1];
    if (data == strnumber) {
      return true;
    }
  }
  return false;
}

void CardService::Add(CardModel card){
  std::ofstream file(filename, std::ios::app);
  file << card.ToString();
}

void CardService::Update(int number){
    std::string strnumber = std::to_string(number);
    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line)) {
        auto data = split(line, ',')[1];
        if (data == strnumber) {
            lines.push_back(line);
        }
    }
    file.close();
    
}