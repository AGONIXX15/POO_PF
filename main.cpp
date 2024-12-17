<<<<<<< HEAD
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
=======
#include "include/models/ClientModel.hpp"
#include "include/service/EmployeeService.hpp"
#include "include/models/EmployeeModel.hpp"
#include "include/view/EmployeeView.hpp"
#include "include/service/AccountService.hpp"
#include "include/view/AccounView.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>



int main()
{
 AccountView account_view;  
  account_view.menu_account();
    

  
  
}
>>>>>>> origin/devia
