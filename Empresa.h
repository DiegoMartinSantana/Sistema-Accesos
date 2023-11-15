#pragma once
#include <cstring>
class Empresa
{
public:
	Empresa();
	int getCuit() const;
	std::string  getRazonSocial();
	std::string getDescripcion();

	void setCuit(int cuit);
	void setRazonSocial(std::string razonSocial);
	void setDescripcion(std::string descripcion);
	void setId(int id);
	int getId();
	void cargar();
	bool getEstado();
	void setEstado(bool estado);
	
		std::string mostrarempresastring();
	void mostrar();
	bool validarrazonsocial(std::string razon);


private:
	int _id;
	int _cuit;
	char _razonSocial[50]; //registrar razones sociales por defecto.
	char _descripcion[50];
	bool _estado;

};

