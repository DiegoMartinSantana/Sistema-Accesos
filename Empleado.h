#pragma once
#include <cstring>
#include "Persona.h"

class Empleado :public Persona {
public:
    Empleado();
    void setTipo(char tipo);
    void setCategoria(char categoria);
    void setLegajo(int legajo);
    void setDescripcion(const std::string descripcion);
    std::string getTipo() const ;
    std::string getCategoria()const;
    int getLegajo() const;
    std::string getDescripcion() const;
    void CargarEmpleado();
    void mostrar();
private:
    int _tipo; //1 - del complejo - 2 - externo
    char _categoria; //a-b-c-d
    int _legajo;
    char _descripcion[100];
    char _perteneciente[100];
};