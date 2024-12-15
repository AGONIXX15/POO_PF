#include "include/models/ClientModel.hpp"
#include "include/service/ClientService.hpp"
#include "include/models/CardModel.hpp"
#include "include/models/CardTypeModel.hpp"
#include "include/service/CardService.hpp"
#include <iostream>
#include <vector>

int main() { 
  CardModel card(1234, 123, 123456, CardTypeModel());
  card.type.SetType(true, false);
  card.type.SetCreditLimit(1000);
  card.type.SetInterestRate(0);
  CardService card_service(card);
  card_service.Add(card);
  return 0;
}
