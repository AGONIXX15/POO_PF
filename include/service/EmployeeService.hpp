#pragma once
#include <iostream>
#include "../models/EmployeeModel.hpp"
using namespace std;



class EmployeeService{

public:
    EmployeeService();
    bool Find(int id);
    void Add(EmployeeModel employee);
    void Remove();
    void Update(int id);
    void Read();
    
};




