#include <iostream>
#include <cstring>
#include "Movimientos.h"
#include "Fecha_Hora.h"
using namespace std;

Movimientos::Movimientos( int idunidad, int dni,int sentido, std::string observacion, int tipoautorizacion) {
    _unidad.setId(idunidad);
    setDni(dni);
    _fechayhora = Fecha_Hora(); // la del sistema
    setSentido(sentido);
    setObservaciones(observacion);
    setEstado(true);
    setTipoAutorizacion(tipoautorizacion);

}
Movimientos::Movimientos () {

}


int Movimientos::getDni()
{
    return _dnipersona;
}

Unidad Movimientos::getUnidad()
{
    return _unidad;
}

Fecha_Hora Movimientos::getFechayHoraMovimiento()
{
    return _fechayhora;
}

int Movimientos::getSentido()
{
    return _sentido;
}

string Movimientos::getObservaciones()
{
    return _observaciones;
}

string  Movimientos::getTipoAutorizacion()
{
    string tipo;
    if (_tipoAutorizacion == 1) {
        tipo = "Permanente";
    }
    else if (_tipoAutorizacion == 2) {
        tipo = "Telefonica";
    }
    return tipo;
}

bool Movimientos::getEstado()
{
    return _estado;
}

void Movimientos::setDni(int dni)
{
    _dnipersona = dni;
}

void Movimientos::setUnidad(Unidad unidad)
{
    _unidad = unidad;
}

void Movimientos::setFechayHoraMovimiento(Fecha_Hora fechahora)
{
    _fechayhora = fechahora;
}

void Movimientos::setObservaciones(std::string observaciones)
{
    strcpy(_observaciones, observaciones.c_str());
}

void Movimientos::setTipoAutorizacion(int tipo)
{
    if (tipo == 1) {
        _tipoAutorizacion = tipo;
    }
    else if (tipo == 2) {
        _tipoAutorizacion = tipo;
    }
    else {
        _tipoAutorizacion = -1;
    }
    
    }

void Movimientos::setEstado(bool estado)
{
    _estado = estado;
}
void  Movimientos::setSentido(bool sentido)
{
    _sentido = sentido;
}
void Movimientos::cargar()
{

    //fecha y hora del sistema :D

    bool sentido;
    setEstado(true);
    string Observaciones;
    int tipo, dni;

    cout << "Ingrese Dni a registrar : " << endl;
    cin >> dni;

    _unidad.cargar();
   
    cout << "Ingrese el sentido 1- Entrada 2-Salida" << endl;
    cin >> sentido;
    cin.ignore();

    cout << "Ingrese el tipo de autorizacion " << endl; 
    cout << "1- Permanente 2- Telefonica " << endl;
    if (sentido == 1) {
        cin >> tipo;
        //minivalidacion
        if (tipo != 1 && tipo != 2) {
            cout << "Tipo no valido - Ingrese el tipo de autorizacion nuevamente. " << endl;
            cout << "1- Permanente 2- Telefonica " << endl;
        }
    }
    cin.ignore();
    cout << "Observaciones" << endl;
    getline(cin, Observaciones);

    setDni(dni);
    setSentido(sentido);
    setObservaciones(Observaciones);
    setTipoAutorizacion(tipo);

    Fecha_Hora actual; //obtiene la del sistema?

    setFechayHoraMovimiento(actual);
}

void Movimientos::mostrar()
{
    cout << endl;
    
    cout << " Dni : " << getDni() << endl;
    cout << "Id Unidad : " << _unidad.getId() << endl;
    cout << "Apellido de la Unidad :  "<<_unidad.getApellidoFamilia() << endl;
    _fechayhora.toString();
    cout << "Sentido: " << _sentido << endl;
    cout << "Tipo Autorizacion: " << _tipoAutorizacion << endl;
    cout << "Observaciones: " << _observaciones << endl;

}
