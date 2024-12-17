#include "include/models/ClientModel.hpp"
#include "include/models/EmployeeModel.hpp"
#include "include/service/AccountService.hpp"
#include "include/service/EmployeeService.hpp"
#include "include/view/AccountView.hpp"
#include "include/view/EmployeeView.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  AccountView account_view;
  account_view.menu_account();
}
