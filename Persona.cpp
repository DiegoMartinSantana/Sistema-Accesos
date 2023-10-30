#include "Persona.h"
#include <cstring>
#include <string>
#include<iostream>
using namespace std;

string Persona::getApellidos() {
	return _apellidos;
}
string Persona::getNombres() {
	return _nombres;
}

string Persona::getApellidosyNombres() {
	string nombrecompleto = _apellidos;
	nombrecompleto += _nombres;
	return nombrecompleto;
}
void Persona::setApellidos(string apellidos) {
	strcpy(_apellidos, apellidos.c_str());
}
void Persona::setNombres(string nombres) {
	strcpy(_nombres, nombres.c_str());
}


void Persona::setId(int id) {
	_id = id;
}
void  Persona::setDni(int dni) {
	_dni = dni;
}
void  Persona::setNacimiento(int dia, int mes, int anio) {
	_nacimiento.cargar(dia, mes, anio);
}
void  Persona::setEstado(bool estado) {
	_estado = estado;
}

int  Persona::getDni() {
	return _dni;
}

int  Persona::getId() {
	return _id;
}
string  Persona::getNacimiento() {
	return _nacimiento.toString();
}
bool  Persona::getEstado() {
	return _estado;
}
void  Persona::cargarPersona() {
	string apellidos, nombres;
	int dia, mes, anio, id;
	cout << "Ingrese ID" << endl;
		cin >> id;
	setId(id);
	cout << "Ingrese nombre/s: " << endl;
	cin.ignore();
	getline(cin, nombres);
	setNombres(nombres);
	cin.ignore();
	cout << "Ingrese apellido/s: " << endl;
	getline(cin, apellidos);
	setApellidos(apellidos);
	cout << "Ingrese Dia de nacimiento : " << endl;
	cin >> dia;
	cout << "Ingrese Mes de nacimiento : " << endl;
	cin >> mes;
	cout << "Ingrese Anio de nacimiento : " << endl;
	cin >> anio;
	setNacimiento(dia, mes, anio);
	setEstado(true);
}



string  Persona::mostrarPersonastring() {
	string  estadoString;
	if (getEstado()) {
		estadoString = "Activo";
	}
	else {
		estadoString = "Inactivo";

	}

	string retornar = "Id: " + to_string(_id) + "\n" +
		"Nombre/s: " + _nombres + "\n" +
		"Apellido/s: " + _apellidos + "\n" +
		"DNI: " + to_string(_dni) + "\n" +
		"Fecha de Nacimiento: " + _nacimiento.toString() + "\n" +
		"Estado: " + estadoString;

	return retornar;
}
void Persona::mostrarPersona() {
	string  estadoString;
	if (getEstado()) {
		estadoString = "Activo";
	}
	else {
		estadoString = "Inactivo";
	}
	cout << "Id: " + to_string(_id) << endl;
	cout << "Nombre/s: " << _nombres << endl;
	cout << "Apellido/s: " << _apellidos << endl;
	cout << "DNI: " << to_string(_dni) << endl;
	cout << "Fecha de Nacimiento: " << _nacimiento.toString() << endl;
	cout << "Estado: " << estadoString << endl;
}
