#pragma once
#include <cstring>
#include "Fecha.h"
class Persona {
public:
	Persona();
	Persona(int id, int dni, Fecha f, bool estado, std::string apellido, std::string nombre);
	std::string getApellidos();
	std::string getNombres();
	std::string getApellidosyNombres();

	void setApellidos(std::string apellidos);
	void setNombres(std::string nombres);
	void setId(int id);
	void setDni(int dni);
	void setNacimiento(int dia, int mes, int anio);
	void setEstado(bool estado);
	int getDni();
	int getId();
	std::string  getNacimiento();
	bool getEstado();
	Fecha getObjectNacimiento();

	void cargarPersona();
	std::string mostrarPersonastring();
	void mostrarPersona();
	
private:

	char _nombres[50];
	char _apellidos[50];
	int _id;
	int _dni;
	Fecha _nacimiento;
	bool _estado;
};