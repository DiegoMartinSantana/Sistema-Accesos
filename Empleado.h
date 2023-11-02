#pragma once
#include <cstring>
#include "Persona.h"
#include "Empresa.h"

class Empleado :public Persona {
public:
    Empleado();
    void setTipo(char tipo);
    void setCategoria(char categoria);
    void setLegajo(int legajo);
    void setDescripcion(const std::string descripcion);
    char getTipo() const;
    char getCategoria() const;
    int getLegajo() const;
    std::string getDescripcion() const;
    void CargarEmpleado();
    std::string MostrarEmpleadostring();
    void mostrar();
private:
    char _tipo; //1 - del complejo - 2 - externo
    char _categoria; //a-b-c-d
    int _legajo;
    char _descripcion[100];
    Empresa _perteneciente;
};