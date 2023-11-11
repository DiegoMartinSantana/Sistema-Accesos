#pragma once
#include <cstring>
#include "Persona.h"



class Visita : public Persona {

public:
	Visita();
	void setUnidad(int unidad);
	void setFamiliar(bool es);
	int getUnidad()const;
	bool getFamiliar()const;

	std::string mostrarvisitastring();
	void cargarvisita();
	void mostrar();

private:
	int _unidad;
	bool _familiar; // 1 si es

};