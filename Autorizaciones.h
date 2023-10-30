#pragma once
#include "Fecha.h"
class Autorizaciones
{
public :
	//recibe dni  y id unidad, sino no existe una autorizacion
	Autorizaciones(int dni , int idunidad);

	int getDniPersona();
	int  getIdUnidad();
	bool getAutorizado();
	std::string getHasta();
std::string getApellido();

	void  setDniPersona(int dni);
	void   setUnidad(int idunidad);
	void  setAutorizado(bool aut);
    void  setHasta(int dia, int mes, int anio);
	void setApellido(std::string apellido);
	void cargar();
	void mostrar();

private: 
	int _dniPersona;
	int _idUnidad;
	bool _autorizado;
	Fecha _hasta;
	char _apellido[50];
	//horario¿? 

};

