#pragma once
#include <string>
#include "Fecha.h"
#include "Persona.h"
class Residente :public Persona
{
public:

    std::string getIngreso();
    bool getPropietario_Inquilino() const;
    int getUnidad() const;
    

    void setUnidad(int idunidad);
    void setIngreso(int dia, int mes, int anio);
    void setPropietario_Inquilino(bool propietario);
    void cargarResidente();
    std::string mostrarResidentestring();
    void mostrar();
private:
	int _unidad;
	bool _propietario_inquilino; // true propietario
	Fecha _ingreso;

	
};

