#include <iostream>
#include <cstring>
#include "Movimientos.h"
#include "Utilidades.h"
#include "Fecha_Hora.h"
using namespace std;

Movimientos::Movimientos(int idunidad, int dni, int sentido, std::string observacion, int tipoautorizacion) {
	setUnidad(idunidad);
	setDni(dni);
	_fechayhora = Fecha_Hora(); // la del sistema
	setSentido(sentido);
	setObservaciones(observacion);
	setTipoAutorizacion(tipoautorizacion);
	
}
Movimientos::Movimientos() {

}


int Movimientos::getDni()
{
	return _dnipersona;
}

int  Movimientos::getUnidad()
{
	return _idunidad;
}

Fecha_Hora Movimientos::getFechayHoraMovimiento()
{
	return _fechayhora;
}

bool Movimientos::getSentido()
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



void Movimientos::setDni(int dni)
{
	_dnipersona = dni;
}

void Movimientos::setUnidad(int unidad)
{
	_idunidad = unidad;
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


void  Movimientos::setSentido(bool sentido)
{
	_sentido = sentido;
}
void Movimientos::cargar()
{
	Utilidades util;

	//fecha y hora del sistema :D

	int sentido;
	string Observaciones;
	int tipo, dni, id;

	cout << "Ingrese Dni a registrar : " << endl;
	cin >> dni;
	util.validarInt(dni);
	cout << "Ingrese el Id de unidad a la que va o de la que sale " << endl;
	cin >> id;

	cout << "Ingrese el sentido 1- Entrada 2-Salida" << endl;

	cin >> sentido;

	util.validarInt(sentido);

	while (sentido <1 || sentido > 2) {
		cout << "Sentido no Valido.  " << endl;
		cout << "Ingrese el sentido 1- Entrada 2-Salida" << endl;

		cin >> sentido;
		util.validarInt(sentido);
	}

	cin.ignore();

	cout << "Ingrese el tipo de autorizacion " << endl;
	cout << "1- Permanente 2- Telefonica " << endl;
	if (sentido == 1) {
		cin >> tipo;
		util.validarInt(tipo);

		while (tipo <1 || tipo >2) {
			cout << "Tipo no valido - Ingrese el tipo de autorizacion nuevamente. " << endl;
			cout << "1- Permanente 2- Telefonica " << endl;
			cin >> tipo;
			util.validarInt(tipo);
		}

	}
	cin.ignore();
	cout << "Observaciones" << endl;
	getline(cin, Observaciones);

	if (sentido==1) {
		setSentido(true);
	}
	else {
		setSentido(false);
	}
	if (sentido == 1) {
		setTipoAutorizacion(tipo);
	}
	else {
		setTipoAutorizacion(2);
	}
	
	Fecha_Hora actual; 
	setObservaciones(Observaciones);
	setFechayHoraMovimiento(actual);
	setDni(dni);
	setUnidad(id);
}

void Movimientos::mostrar()
{
	cout << endl;

	cout << " Dni : " << getDni() << endl;
	cout << "Id de Unidad : " << getUnidad() << endl;
	
	if(getSentido()){
		cout << "Sentido :  Entrada." << endl;
	}
	else {
		cout << "Sentido :  Salida. " << endl;

	}
	cout << "Fecha  y hora : " << getFechayHoraMovimiento().toString() << endl;
	cout << "Tipo Autorizacion : " <<  getTipoAutorizacion() << endl;
	cout << "Observaciones : " << getObservaciones() << endl;

}
