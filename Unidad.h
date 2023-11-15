#pragma once
#include <string>
class Unidad
{	//LA UNIDAD 0 CORRESPONDE A EMPLEADOS Y A PROVEEDORES
public:
	Unidad();
	std::string getApellidoFamilia();
	std::string getObservaciones();

	int getId();
	std::string getBase();
	int getNroTelefono();
	bool getEstado();

	void setId(int id);
	void setNroTelefono(int telefono);
	void setBase(bool base); // true es base SOLO LA 0
	void setApellidoFamilia(std::string apellido);
	void setEstado(bool estado);
	void setObservaciones(std::string observaciones);

	void cargar();
	void mostrar();

private:


	int _id;
	char _apellidoFamilia[50];
	char _observaciones[300];
	int _telefonoFamilia;
	bool _unidadBase;
	bool _estado;

};

