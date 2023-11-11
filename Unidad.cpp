#include <iostream>
#include <cstring>
#include "Unidad.h"
#include "Utilidades.h"
using namespace std;

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

	int id, telefono;
	string observaciones, apellido;
	cout << "Ingrese los datos de la Unidad : " << endl;
	cout << endl;
	cout << "Id unidad : 0(Base) - 200" << endl;
	cin >> id;
	util.validarInt(id);
	while (id < 0 || id > 200) {
		cout << "Id invalido , Ingrese de nuevo " << endl;
		cin >> id;
		util.validarInt(id);

	}
	cout << " Numero de Telefono: (10 digitos) " << endl;
	cin >> telefono;
	
	util.validarInt(telefono);
	while (util.contarDigitosInt(telefono) != 10) {
		cout << " Numeracion erronea " << endl;
		cin >> telefono;
		util.validarInt(telefono);
	}

	cin.ignore();
	cout << "Apellido Familia : " << endl;
	getline(cin, apellido);
	cout << "Observaciones: " << endl;
	getline(cin, observaciones);


	setId(id);
	setEstado(true);
	setNroTelefono(telefono);
	setApellidoFamilia(apellido);
	setObservaciones(observaciones);
	if (id == 0) {
		setBase(true);
	}
	else {
		setBase(false);
	}
}

void Unidad::mostrar() {

	cout << "Id unidad : " << getId() << endl;
	cout << "Tipo: " << getBase() << endl;
	cout << "Familia: " << getApellidoFamilia() << endl; // validar
	cout << "Telefono: " << getNroTelefono() << endl;
	cout << "Observaciones: " << getObservaciones() << endl; //validar

}




