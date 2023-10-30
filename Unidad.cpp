#include <iostream>
#include <cstring>
#include "Unidad.h"
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

void Unidad::setTipo(int tipo)
{
	_tipo = tipo;
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

int Unidad::getTipo()
{
	return _tipo;
}



int Unidad::getNroTelefono()
{
	return _telefonoFamilia;
}

string Unidad::getApellidoFamilia()
{
	return _apellidoFamilia; // validar..
}

string Unidad::getObservaciones()
{
	return _observaciones; //validar..
}

bool Unidad::getEstado()
{
	return _estado;
}

void Unidad::cargar()
{
	setEstado(true);
	int id, tipo, telefono;
	string observaciones, apellido;
	cout << "Ingrese los datos de la Unidad : " << endl;
	cout << endl;
	cout << "Id unidad : " << endl;
	cin >> id;
	cout << "Tipo :" << endl; // y que tipos son?
	cin >> tipo;
	cout << " Numero de Telefono: (10 digitos) " << endl;
	cin >> telefono;
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

}

void Unidad::mostrar() {

	cout << "Id unidad : " << getId() << endl;
	cout << "Tipo: " << getTipo() << endl;
	cout << "Familia: " << getApellidoFamilia() << endl; // validar
	cout << "Telefono: " << getNroTelefono() << endl;
	cout << "Observaciones: " << getObservaciones() << endl; //validar

}




