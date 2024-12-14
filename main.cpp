#include "include/models/ClientModel.hpp"
#include "include/service/EmployeeService.hpp"
#include "include/models/EmployeeModel.hpp"
#include <iostream>
#include <vector>

int main() { 
  EmployeeModel empleado(1,"sebas",17,10000,"martes",2);
  EmployeeModel empleado_1(2,"james",17,10000,"martes",2);
  EmployeeService empleado_s;
  empleado_s.Add(empleado);
  empleado_s.Add(empleado_1);
  empleado_s.Remove();
  return 0;
}
