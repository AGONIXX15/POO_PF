#include "../include/ArchivoCSV.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/*constructor recibe un string y lo setea a filename
 * @param string filename: nombre del archivo al que se van a poder aplicar
 * los metodos de esta clase 
 * @return void*/
ArchivoCSV::ArchivoCSV(std::string filename) { 
  this->filename = filename; 
}

/* metodo split es la implementacion para devolver un vector separado
 * por x cosa
 * @param string str: la cadena la cual se va a separar 
 * @param char delimiter: el caracter por el cual va a ser separado
 * @return vector<string> tokens: el cual es cada cosa separada guardada
 * en un vector*/
std::vector<std::string> ArchivoCSV::split(const std::string &str,
char delimiter) {
  std::vector<std::string> tokens; // el vector en el que se guarda la separacion
  std::stringstream ss(str); // analiza la cadena
  std::string token; // string el cual se le carga cada separacion
  while (std::getline(ss, token, delimiter)) {
    tokens.push_back(token); // se agrega cada separacion al vector
  }
  return tokens; // devolvemos el vector
}

// devuelve el nombre del archivo al cual se le aplican los metodos
std::string ArchivoCSV::get_filename() { return this->filename; }

/* metodo read de ArchivoCSV
 * parametros:
 * bool header: se pasa para saber si quiere que se muestre el header o no
 * no retorna nada*/
void ArchivoCSV::read(bool header) {
  std::string sep, head = ""; // sep = separacion, head = encabezado
  std::ifstream read(this->get_filename());
  std::string line; // variable a la cual se cargan datos de la linea
  std::getline(read, line);
  if (header) {
    for (size_t i = 0; i < line.size(); ++i) {
      sep += "-";
      head += line[i];
    }
  }
  std::cout << head << std::endl; // imprime encabezado
  std::cout << sep << std::endl; // imprime separacion
  while (std::getline(read, line)) {
    std::cout << line << std::endl; // imprimir cada linea
  }
  std::cout << sep << std::endl; // imprime separacion
}

/* metodo find de ArchivoCSV
 * parametros:
 * int index: este se le pasa para buscar en que
 * columna se encuentra el dato
 * string key: este se le pasa para buscar ese dato
 * retorna un dato
 * booleano (verdadero o falso segun si se encontro)*/
bool ArchivoCSV::find(std::string id) {
  std::ifstream read(this->get_filename()); // lee el archivo
  std::string line; // variable a la cual se cargan datos de la linea
  std::getline(read, line); // cargar el encabezado pq no nos interesa
  while (std::getline(read, line)) {
    // carga lo que hay en la posicion 0 a la variable data
    std::string data = split(line, ',')[0];
    // si son iguales es porque se encontro el id
    if (data == id) {
      return true;
    }
  }
  // no se encontro el id
  return false;
}

/* metodo write de ArchivoCSV
 * parametros:
 * @param vector<string> data: este se le pasa para escribir en el archivo
 * @return  nada*/
void ArchivoCSV::write(std::vector<std::string> data) {
  std::ofstream file(this->get_filename(), std::ios::app);
  for (size_t i = 0; i < data.size(); ++i) {
    file << data[i]; // escribir el dato en la posicion i
    if (i < data.size() - 1) {
      file << ",";
    }
  }
  file << std::endl;
}

/*metodo remove recibe el id el cual se va a remover a ese usuario
 * @param string id: es el id de x cosa que va a ser removido 
 * @return void
 * */
void ArchivoCSV::remove(std::string id) {
  std::ifstream read(this->get_filename());
  std::string line;
  std::vector<std::vector<std::string>> data; // matriz
  int index = 0;
  while (std::getline(read, line)) {
    data.emplace_back(split(line, ',')); // lo agrega al vector
    if (data[index][0] == id) {
      data.pop_back();
    }else {
    index++;
    }
  }
  read.close();
  std::ofstream write(this->get_filename());
  for (size_t i = 0; i < data.size(); i++) {
    for (size_t j = 0; j < data[i].size(); j++) {
      if (j == data[i].size() - 1) {
        write << data[i][j]; // rescribir al archivo
        break;
      }
      write << data[i][j] << ",";
    }
    write << std::endl;
  }
}

/*metodo actualizar
 * @param string id: es el id de x cosa que voy a actualizar
 * @param string replace: es con lo que voy actualizar 
 * @param int index_replace: el indice de lo que voy actualizar 
 * @return void*/
void ArchivoCSV::update(std::string id, std::string replace,
                        int index_replace) {
  std::ifstream read(this->get_filename()); // el archivo que lee
  std::string line; // la variable a la cual se cargan los datos
  std::getline(read, line); // leemos pq no queremos headers
  std::vector<std::vector<std::string>> data; // matriz 
  data.emplace_back(split(line, ',')); // agrega el header
  int i = 1; // empieza desde uno para no revisar el header
  while (std::getline(read, line)) {
    data.emplace_back(split(line, ','));
    if (data[i][0] == id) {
      data[i][index_replace] = replace;
    }
    i++;
  }
  std::ofstream write(this->get_filename()); // reescribe
  for (size_t i = 0; i < data.size(); i++) {
    for (size_t j = 0; j < data[i].size(); j++) {
      if (j == data[i].size() - 1) {
        write << data[i][j];
        break;
      }
      write << data[i][j] << ",";
    }
    write << std::endl;
  }
}

/* metodo load_data el cual devuelve un vector con los datos 
 * @param string id: el id de x cosa que se van a cargar sus datos 
 * @return vector<vector<string>> data: devuelve un vector con los datos 
 * cargados*/
std::vector<std::vector<std::string>> ArchivoCSV::load_data(std::string id) {
  // archivo que lee
  std::ifstream read(this->get_filename()); 
  if (!read.is_open()) {
    throw std::runtime_error("Error: No se pudo abrir el archivo " + this->get_filename());
}
  // variable a la cual se cargan los datos de x linea
  std::string line;  
  // se leen los encabezados pq no queremos
  std::getline(read, line);
  std::cout << line << std::endl;
  std::vector<std::vector<std::string>> data;
  while (std::getline(read, line)) {
    // leo una linea
    if (line.size() == 0 || line == "\n"){
      continue;
    }
    auto row = split(line, ','); 
    // si es igual al id la agrego a mi matriz
    if (row.size() == 0 ){
      std::cout << "\n--------" << "\n";
      std::cout << line << "\n";
      std::cout << "mala fila" << std::endl;
      continue;
    }
    if (row[0] == id) { 
      data.push_back(row);
    }
  }
  // devuelvo mi matriz
  return data;
}
