#pragma once
#include <string>
#include "Fecha.h"
class Vehiculo
{
public:
	
	std::string getFechaSeguro();
	int getTipo();
	std::string getPatente();
	std::string getTitular();

	void setPatente(std::string patente);
	void setTitular(std::string titular);
	void setSeguro(int dia, int mes,int anio);
	void setTipo(int tipo);

	void cargar();
	void mostrar();
private:

	char _patente[10];
	char _titular[50];
	Fecha _fechaseguro;
	int _tipo;
};

