#include <iostream>
#include <cstring>
#include "Unidad.h"
#include "Utilidades.h"
using namespace std;

Unidad::Unidad() {
	setApellidoFamilia("");
	setBase(false);
	setEstado(false);
	setId(-1);
	setNroTelefono(1);
	setObservaciones("nada");
	
}
void Unidad::setEstado(bool estado)
{
	_estado = estado;

}

void Unidad::setId(int id)
{
	_id = id;
}


void Unidad::setNroTelefono(int telefono)
{
	_telefonoFamilia = telefono;
}


void Unidad::setObservaciones(string observaciones)
{

	strcpy(_observaciones, observaciones.c_str());
}

void Unidad::setApellidoFamilia(string apellido)
{
	strcpy(_apellidoFamilia, apellido.c_str());
}


int Unidad::getId()
{
	return _id;
}


void Unidad::setBase(bool base) {
	if (base) {
		_unidadBase=base;
		setId(0); // PISA EL VALOR INGRESADO, PORQUE ES IMPORTANTE QUE SEA SI O SI LA 0 LA BASE.
	}
	else
	{
		_unidadBase = base;
	}
}
string Unidad::getBase() {

	string retornar;
	if (_unidadBase) {
		retornar = "Unidad Base ";
		return retornar;

	}
	else {
		retornar = "Unidad Comun";
		return retornar;

	}

}


int Unidad::getNroTelefono()
{
	return _telefonoFamilia;
}

string Unidad::getApellidoFamilia()
{
	return _apellidoFamilia; 
}

string Unidad::getObservaciones()
{
	return _observaciones; 
}

bool Unidad::getEstado()
{
	return _estado;
}

void Unidad::cargar()
{
	setEstado(true);
	Utilidades util;

	int telefono;
	string observaciones;
	
	
	cout << " Numero de Telefono de la familia : (10 digitos) " << endl;
	cin >> telefono;
	
	util.validarInt(telefono);
	while (util.contarDigitosInt(telefono) != 10) {
		cout << " Numeracion erronea " << endl;
		cin >> telefono;
		util.validarInt(telefono);
	}

	cin.ignore();
	
	cout << "Observaciones: " << endl;
	getline(cin, observaciones);


	setEstado(true);
	setNroTelefono(telefono);
	setObservaciones(observaciones);
	setBase(false);

}

void Unidad::mostrar() {

	cout << "Id unidad : " << getId() << endl;
	cout << "Tipo: " << getBase() << endl;
	cout << "Familia: " << getApellidoFamilia() << endl; // validar
	cout << "Telefono: " << getNroTelefono() << endl;
	cout << "Observaciones: " << getObservaciones() << endl; //validar
	string es;
	if (_estado) {
		es = "Activa";
	}
	else {
		es = "Inactiva";
	}
	cout << "Estado : " << es << endl;
}




