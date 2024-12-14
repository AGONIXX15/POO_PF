#include "../../include/service/EmployeeService.hpp"
#include "../../include/models/EmployeeModel.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
EmployeeService::EmployeeService(){
}


void EmployeeService::Add(EmployeeModel empleado){
    ofstream doc_employeed("empleados.csv",ios::app);
    if(!doc_employeed){
        cout<<"archivo no creado"<<endl;
    }else{
        doc_employeed<<empleado.ToString()<<endl;
    }


}


bool EmployeeService::Find(int id){

}

void EmployeeService::Remove(){
    int id_remove;
    string data,id;
    bool find_employeed = false; // para confirmar si encontro el empleado
    ifstream doc_employeed("empleados.csv",ios::in);
    if(!doc_employeed){
        cout<<"no se abrio el documento";
    }else{
        vector<string>remove_employeed;
        
        cout<<"digita la id del empleado a eliminar"<<endl;
        cin>>id_remove;
        while(getline(doc_employeed,data)){
            stringstream registers(data); // convertimos en string
            getline(registers,id,','); // leamos los ids hasta las comas
          if((id_remove == stoi(id))){ // valida que id a elimar se encuentre y la id ingresa a int
            find_employeed = true;

          }else{
            remove_employeed.push_back(data);
          }

        }
    doc_employeed.close();
    // si se encontro el empleado
    if(find_employeed){
        cout<<"usuario eliminado";
        ofstream doc_delate("empleados.csv"); // creamos un nuevo documento
        for(int i=0; i<remove_employeed.size();i++){ // leemos el vector
            doc_delate<<remove_employeed[i]<<endl;  // guardamos los nuevos datos en el documeto

        }doc_delate.close();
    
        }else{
            cout<< "la id no encontrado"<<endl;
        }
    }
}
void EmployeeService::Read(){
    string data,id,name,wage,timetable,dni;
    ifstream doc_employeed("empleados.csv",ios::in);
    if(!doc_employeed){
        cout<<"Error al tratar de abrir el documento csv"<<endl;
    }else{

        while(getline(doc_employeed,data)){
            stringstream registros(data); //convertimos la cadena de datos en un flujo de datos

            getline(registros,id,',');
            getline(registros,name,','); 
            getline(registros,wage,',');
            getline(registros,timetable,',');
            getline(registros,dni,',');

            cout<<"id del empleado: "<<id<<endl;
            cout<<"nombre del emplead: "<<name<<endl;
            cout<<"salario del empleado : "<<wage<<endl;
            cout <<"horario del empleado: "<<timetable<<endl;
            cout<<"id del banco: "<<dni<<endl;
        }
        doc_employeed.close();
    }
}

// revisar como se esta guardando en el archivo empleado hay ;y ,
// emplear metodo read

void EmployeeService::Update(int id){

}