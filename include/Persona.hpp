#pragma once


// para el nombre de la persona
#include <string>

class Persona {
public:
  /**/
	Persona(std::string name, int age, int id); // constructor
  Persona(); // constructor
  std::string get_name(); // getter del nombre
  int get_age(); // getter de la edad
  int get_id(); // getter del id

  void set_name(std::string);
  void set_age(int);
  void set_id(int);
private:
  std::string name; // nombre de la persona
  int age; // edad de la persona
	int id; // cedula
};
