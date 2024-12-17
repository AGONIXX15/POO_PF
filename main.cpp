#include "include/models/ClientModel.hpp"
#include "include/utils.hpp"
#include "models/CardModel.hpp"
#include "service/CardService.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() { 
  CardService service;

  auto data = service.LoadData("123");
  for (auto card : data) {
    card.ShowInfo();
  }

  return 0;
}
