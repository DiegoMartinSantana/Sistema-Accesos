#pragma once

#include<string>
#include<cstring>
#include "Fecha.h"
#include "Persona.h"
#include "Empresa.h"

class Proveedor : public Persona {

public:
	Proveedor();
	char getTipo() const;
	std::string getArt();
	std::string getEmpresa() ;


	void setTipo(char tipo);
	void setArt(int dia, int mes, int anio);
	void cargarProveedor();
	std::string mostrarProveedorstring();
	void mostrar();
private:
	char _tipo;
	Fecha _art;
	
	Empresa _perteneciente;

};