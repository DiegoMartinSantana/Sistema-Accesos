#pragma once
#include <string>
#include "Fecha.h"
class Autorizaciones
{
public :
	
	Autorizaciones(int id);
	Autorizaciones(int dni=-1, int iduni=-1,bool residente = false, int mes=1, int anio=1);

	int getDniPersona();
	int  getIdUnidad();
	bool getResidente();
	std::string getHasta();

	void  setDniPersona(int dni);
	void   setUnidad(int idunidad);
	void  setResidente(bool res);
    void  setHasta( int mes,int anio);
	void mostrar();
	void setEstado(bool estado);
	bool getEstado();
private:
	int _dniPersona;
	int _idUnidad;
	bool _residente;

	Fecha _hasta;
	bool _estado;

};

