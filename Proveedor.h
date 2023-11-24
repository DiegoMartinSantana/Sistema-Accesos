#pragma once
#include<string>
#include<cstring>
#include "Fecha.h"
#include "Persona.h"

class Proveedor : public Persona {

public:
	Proveedor();
	std::string getTipo() const;
	std::string getEmpresa() ;

	void setTipo(char tipo);
	void cargarProveedor();
	std::string mostrarProveedorstring();
	void mostrar();
private:
	char _tipo;
	char _perteneciente[100];

};