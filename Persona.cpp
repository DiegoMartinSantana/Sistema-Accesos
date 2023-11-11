#include <cstring>
#include <string>
#include<iostream>
#include "Persona.h"
#include "Utilidades.h"
using namespace std;
Persona::Persona() {

}
Persona::Persona(int id, int dni, Fecha f, bool estado, std::string apellido, std::string nombre) {
	setApellidos(apellido);
	setNombres(nombre);
	setDni(dni);
	setId(id);
	setNacimiento(f.getDia(), f.getMes(), f.getAnio());
	setEstado(estado);
}
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
Fecha Persona::getObjectNacimiento() {
	return _nacimiento;
}
string  Persona::getNacimiento() {
	return _nacimiento.toString();
}
bool  Persona::getEstado() {
	return _estado;
}

void  Persona::cargarPersona() {
	Utilidades util;

	string apellidos, nombres;
	int dia, mes, anio, id, dni;
	cout << "Ingrese ID" << endl;
	cin >> id;
	util.validarInt(id);

	setId(id);
	cout << "Ingrese DNI ( 8 Digitos )  " << endl;
	cin >> dni;
	util.validarInt(dni);
	while (util.contarDigitosInt(dni) != 8) {
		cout << "Dni Valido solo de 8 digitos , ingrese nuevamente   " << endl;
		cin >> dni;
		util.validarInt(dni);

	}
	cin.ignore();
	cout << "Ingrese nombre/s: " << endl;
	getline(cin, nombres);
	setNombres(nombres);
	cout << "Ingrese apellido/s: " << endl;
	getline(cin, apellidos);
	setApellidos(apellidos);
	cout << "Ingrese Dia de nacimiento : " << endl;
	cin >> dia;
	util.validarInt(dia);
	while ( util.contarDigitosInt(dia) > 2 ) { //mientras ingrese mas de dos digitos. puede ingresar uno si quiere. pero tres o mas no.
		cout << "No existen dias de mas de dos digitos.  " << endl;
		cin >> dia;
		util.validarInt(dia);
	}
	cout << "Ingrese Mes de nacimiento : " << endl;
	cin >> mes;
	util.validarInt(mes);
	while (util.contarDigitosInt(mes) > 2) {
		cout << "No existen meses de mas de dos digitos. " << endl;
		cin >> mes;
		util.validarInt(mes);
	}
	cout << "Ingrese Anio de nacimiento : " << endl;
	cin >> anio;
	util.validarInt(anio);
	while (util.contarDigitosInt(anio) > 4) {
		cout << "No existen anios de mas de cuatro digitos. " << endl;
		cin >> anio;
		util.validarInt(anio);
	}
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
