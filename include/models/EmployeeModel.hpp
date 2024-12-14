#pragma once
#include <iostream>
#include "PersonModel.hpp"




class EmployeeModel:public PersonModel{
private:
    float wage; // salario
    std::string timetable; // horario
    int dni; // la cedula del  del empleado
  
public:
    EmployeeModel(int,std::string,int,float,std::string,int);
    float get_wage(); // get_salario
    string get_dni(); // get_cedula
    std::string get_timetable(); //get_horario
    void set_wage(float );
    void set_timetable(std::string);
    std:: string ToString() override;
   


};
