#include <iostream>
#include <string>
#include "Autorizaciones.h"

using namespace std;

Autorizaciones::Autorizaciones(int dni, int idunidad) {

    _dniPersona = dni;
    _idUnidad = idunidad;
    
}

string Autorizaciones::getApellido() {
    return _apellido;
}
void Autorizaciones::setApellido(string apellido) {
    strcpy(_apellido, apellido.c_str());
}
int Autorizaciones::getDniPersona()
{
    return _dniPersona;
}

int Autorizaciones::getIdUnidad()
{
    return _idUnidad;
}

bool Autorizaciones::getAutorizado()
{
    return _autorizado;
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

void Autorizaciones::setAutorizado(bool aut)
{
    _autorizado = aut;
}

void Autorizaciones::setHasta(int dia, int mes ,int anio)
{
    _hasta.cargar(dia, mes, anio);

}




void Autorizaciones::cargar()
{

    int dia, mes, anio, dni, idunidad;
    string apellido;

    setAutorizado(true); // por defecto en true , no creo una autorizacion en false.

    cin.ignore();
    cout << "Ingrese Apellido  a autorizar " << endl;
    getline(cin, apellido);
    cout << "Ingrese Dni Persona  a autorizar " << endl;
    cin >> dni;
    cout << "Ingrese Id Unidad del autorizado" << endl;
    cin >> idunidad;
    //posible fecha de consola..
    cout << "Ingrese Dia " << endl;
    cin >> dia;
    cout << "Ingrese Mes " << endl;
    cin >> mes;
    cout << "Ingrese Anio " << endl;
    cin >> anio;

    setHasta(dia, mes, anio);
    setDniPersona(dni);
    setUnidad(idunidad);
    setApellido(apellido);

}

void Autorizaciones::mostrar()
{
    cout << "Id Unidad : " << getIdUnidad() << endl;
    cout << "Dni : " << getDniPersona() << endl;
    cout << "Apellido " << getApellido() << endl;
    if (_autorizado) {
        cout << "Autorizado hasta: " << getHasta() << endl;
    }
    else {
        cout << "No se encuentra autorizado " << endl;
    }

}



