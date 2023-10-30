#pragma once
#include <string>
class Unidad
{
public:
	
	std::string getApellidoFamilia();
	std::string getObservaciones();

	int getId();
	int getTipo();
	int getNroTelefono();
	bool getEstado();

	void setId(int id);
	void setNroTelefono(int telefono);
	void setTipo(int tipo);
	void setApellidoFamilia(std::string apellido);
	void setEstado(bool estado);
	void setObservaciones(std::string observaciones);

	void cargar();
	void mostrar();

private:


	int _id;
	char _apellidoFamilia[50];
	// numero = id..
	char _observaciones[300];
	int _telefonoFamilia;
	int _tipo;
	bool _estado;

};

