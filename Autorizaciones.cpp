#include <iostream>
#include <string>
#include "ArchivosTemplate.h"
#include "Persona.h"
#include "Autorizaciones.h"


using namespace std;
Autorizaciones::Autorizaciones(int id) {

    
    
}
Autorizaciones::Autorizaciones(int dni, int iduni, bool residente ,int mes, int anio) { // si es residente significa que no pase mes y anio
    int dia = 1;
    setDniPersona(dni);
    setUnidad(iduni);
    _hasta.cargar(dia,mes,anio); 
    _residente = residente;
}

void Autorizaciones::setEstado(bool estado) {
    _estado = estado;
}
bool Autorizaciones::getEstado() {
    return _estado;
}


int Autorizaciones::getDniPersona()
{
    return _dniPersona;
}

int Autorizaciones::getIdUnidad()
{
    return _idUnidad;
}

bool Autorizaciones::getResidente()
{
    return _residente;
}

string Autorizaciones::getHasta()
{
    return _hasta.toString();
}


void Autorizaciones::setDniPersona(int dni)
{
    _dniPersona = dni;
}

void Autorizaciones::setUnidad(int id)
{
    _idUnidad = id;
}

void Autorizaciones::setResidente(bool res)
{
    _residente =res ;
}

void Autorizaciones::setHasta(int dia, int mes ,int anio )
{
    _hasta.cargar(dia, mes, anio);

}


string nombreyapellido(int dni) {

    ArchivosTemplate archipersona;
    Persona p;
    string nombrearchivo = "Personas.dat";
    int tot = archipersona.contarRegistros(nombrearchivo, p);

    for (int x = 0;x < tot;x++) {

        p = archipersona.ObtenerObjeto(nombrearchivo, p, x);
        if (p.getDni() == dni) {

            string nombreape = p.getApellidosyNombres();
            return nombreape;
        }
    }
    return "Invalido";
}
void Autorizaciones::mostrar()
{
    cout << "Id Unidad : " << getIdUnidad() << endl;
    cout << "Dni : " << getDniPersona() << endl;
   
    cout << nombreyapellido(getDniPersona()) << endl;

    if (_residente) {
        cout << "Autorizacion Permanente" << endl;
    }
    else {
        cout << "Autorizado hasta  " << getHasta() << endl;
    }
}



