#include "../../include/models/EmployeeModel.hpp"
#include <iostream>
using namespace std;

EmployeeModel::EmployeeModel(int id, string name, int age, float wage_, string timetable_, int dni_)
    : PersonModel(id, name, age), wage(wage_), timetable(timetable_), dni(dni_) {
}

float EmployeeModel::get_wage() {
    return wage;
}

std::string EmployeeModel::get_timetable() {
    return timetable;
}

void EmployeeModel::set_wage(float wage_) {
    wage = wage_;
}

void EmployeeModel::set_timetable(std::string time_) {
    timetable = time_;
}

std::string EmployeeModel::ToString() {
    return PersonModel::ToString() + "," + to_string(wage) + "," + timetable + "," + to_string(dni);
}