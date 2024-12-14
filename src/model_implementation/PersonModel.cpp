#include "../../include/models/PersonModel.hpp"

PersonModel::PersonModel(int id, std::string name, int age)
    : name(name), age(age), id(id) {}

std::string PersonModel::GetName() { return name; }

int PersonModel::GetAge() { return age; }

int PersonModel::GetId() { return id; }

std::string PersonModel::ToString() {
  return std::to_string(id) + "," + name + "," + std::to_string(age);
}
