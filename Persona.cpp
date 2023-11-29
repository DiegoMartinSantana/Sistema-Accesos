#include <cstring>
#include <string>
#include<iostream>
using namespace std;

#include "ArchivosTemplate.h"
#include "Persona.h"
#include "Residente.h"
#include "Proveedor.h"
#include "Empleado.h"
#include "Visita.h"
#include "Utilidades.h"

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


bool buscarDni(int dni) {
	Residente r;
	Visita v;
	Empleado emp;
	Proveedor prov;

	bool exister, existev, existeprov, existeemp;
	ArchivosTemplate temp;
	Utilidades u;
	exister = temp.validarDni(u._archivoResidentes, r, dni);
	existev = temp.validarDni(u._archivoVisitas, v, dni);
	existeprov = temp.validarDni(u._archivoProveedores, prov, dni);
	existeemp = temp.validarDni(u._archivoEmpleados, emp, dni);


	if (exister) {
		cout << endl;
		cout << "Dni ingresado ya existente en Residentes" << endl;
		cout << endl;
		return exister;
	}
	if (existev) {
		cout << endl;
		cout << "Dni ingresado ya existente en Visitantes" << endl;
		cout << endl;
		return existev;

	}
	if (existeprov) {
		cout << endl;
		cout << "Dni ingresado ya existente en Proveedores" << endl;
		cout << endl;
		return existeprov;

	}
	if (existeemp) {
		cout << endl;
		cout << "Dni ingresado ya existente en Empleados" << endl;
		cout << endl;
		return existeemp;
	}
	return false;

}
bool validarId(int llamado, int id) {
	Residente r;
	Visita v;
	Empleado emp;
	Proveedor prov;
	Utilidades util;
	ArchivosTemplate archi;
	bool existeid;
	switch (llamado) {
	case 1: {
		Residente r;
		existeid = archi.Idexistenteono(util._archivoResidentes, r, id); // devuelve true si existe
		if (existeid) {
			cout << endl;
			cout << "Id de Residente ya Existente " << endl;
			cout << endl;
			return existeid;
		}
		else {
			return false;
		}
		break;
	}
	case 2: {
		Visita v;
		existeid = archi.Idexistenteono(util._archivoVisitas, v, id);
		if (existeid) {
			cout << endl;
			cout << "Id de Visitante ya Existente " << endl;
			cout << endl;
			return existeid;
		}
		else {
			return false;
		}

		break;
	}
	case 3: {
		Empleado emp;
		existeid = archi.Idexistenteono(util._archivoEmpleados, emp, id);
		if (existeid) {
			cout << endl;
			cout << "Id de Empleado ya Existente " << endl;
			cout << endl;
			return existeid;
		}
		else {
			return false;
		}
		break;
	}
	case 4: {
		Proveedor prov;
		existeid = archi.Idexistenteono(util._archivoProveedores, prov, id);
		if (existeid) {
			cout << endl;
			cout << "Id de Proveedor ya Existente " << endl;
			cout << endl;
			return existeid;
		}
		else {
			return false;
		}
		break;
	}
	}

}
void  Persona::cargarPersona(int llamado) {

	Utilidades util;
	ArchivosTemplate archi;
	string apellidos, nombres;
	int dia, mes, anio, id, dni;
	cout << "Ingrese ID" << endl;
	cin >> id;
	util.validarInt(id);
	while (id <= 0) {
		cout << "Id invalido. Ingrese nuevamente " << endl;
		cin >> id;
		util.validarInt(id);

	}
	//valido la existencia del id x archivo.

	while (validarId(llamado, id)) { // mientras devuelva true se ejecuta

		cout << "Ingrese nuevamente : " << endl;
		cin >> id;
		util.validarInt(id);
		while (id < 0) {
			cout << "Id invalido. Ingrese nuevamente " << endl;
			cin >> dni;
			util.validarInt(dni);

		}
	}

	setId(id);

	cout << "Ingrese DNI ( 7-8 Digitos )  " << endl;
	cin >> dni;
	util.validarInt(dni);
	while (util.contarDigitosInt(dni) <7  || util.contarDigitosInt(dni) > 8) {
		cout << "Dni Valido solo de 7 u 8 digitos , ingrese nuevamente   " << endl;
		cin >> dni;

		util.validarInt(dni);

	}

	//valido dni EN TODOS LOS ARCHIVOS
	//no deberia existir en ningun archivo	
	while (buscarDni(dni)) { //
		cout << "Ingrese Dni nuevamente : " << endl;
		cin >> dni;
		util.validarInt(dni);

		while (util.contarDigitosInt(dni) < 7 || util.contarDigitosInt(dni) > 8) {
			cout << "Dni Valido solo de 7 u 8 digitos , ingrese nuevamente : " << endl;
			cin >> dni;

			util.validarInt(dni);
		}
	}



	setDni(dni);
	cin.ignore();
	cout << "Ingrese nombre/s: " << endl;
	getline(cin, nombres);
	setNombres(nombres);
	cout << "Ingrese apellido/s: " << endl;
	getline(cin, apellidos);
	setApellidos(apellidos);
	Fecha actual;

	if (llamado == 1 || llamado == 2) {
		cout << "Ingrese Anio de nacimiento : " << endl;
		cin >> anio;
		util.validarInt(anio);
		util.validarAnioActual(anio, actual.getAnio());

		cout << "Ingrese Mes de nacimiento : " << endl;
		cin >> mes;
		util.validarInt(mes);
		if (anio == actual.getAnio()) {
			util.validarMesActual(mes);
		}
		else {
			util.validarMes(mes);
		}
		cout << "Ingrese Dia de nacimiento : " << endl;
		cin >> dia;
		util.validarInt(dia);
		if (anio == actual.getAnio()) {
			while (!util.validarActualPersonaDiaAutorizacion(dia, mes, anio)) {
				cout << "Dia invalido, Ingrese nuevamente : " << endl;
				cin >> dia;
				util.validarInt(dia);
			}
		}
		else {
			while (!util.validarDia(dia, mes, anio)) {
				cout << "Dia invalido, Ingrese nuevamente : " << endl;
				cin >> dia;
				util.validarInt(dia);
			}
		}


	}
	else {

		cout << "Ingrese Anio de nacimiento  : " << endl;
		cin >> anio;
		util.validarInt(anio);
		int edad = actual.getAnio() - anio;
		while (edad < 18 || anio < 1920 || anio > actual.getAnio()) {
			if (edad < 18) {
				cout << "Anio Invalido, se precisa la mayoria de edad : " << endl;

			}
			else {
				cout << "Anio Invalido, ingrese nuevamente : " << endl;
			}
			cin >> anio;
			util.validarInt(anio);
			edad = actual.getAnio() - anio;
		}


		cout << "Ingrese Mes de nacimiento : " << endl;
		cin >> mes;
		util.validarInt(mes);
		if (edad == 18) {

			while (mes < actual.getMes() || mes < 1 || mes > 12) {
				if (mes < actual.getMes() ){
					cout << "Mes Invalido, se precisa la mayoria de edad : " << endl;

				}
				else {
					cout << "Mes invalido ,ingrese nuevamente : " << endl;

				}
				cin >> mes;
				util.validarInt(mes);
			}


		}
		else {
			util.validarMes(mes);

		}
	}
	cout << "Ingrese Dia de nacimiento : " << endl;
	cin >> dia;
	util.validarInt(dia);

	if (mes == actual.getMes()) {
		while (!util.validarDia(dia, mes, anio) ||  dia < actual.getDia()) {
			if (dia < actual.getDia()) {
				cout << "Dia invalido, No cumplio la mayoria de Edad Todavia : " << endl;
			}
			else {
				cout << "Mes invalido ,ingrese nuevamente : " << endl;

			}
			cin >> dia;
			util.validarInt(dia);

		}
		if (dia == actual.getDia()) {
			cout << endl;
			cout << " Feliz cumple! :) " << endl;
			cout << endl;

			system("pause");
		}
	}
	else {
		while (!util.validarDia(dia, mes, anio)) {
			cout << "Dia invalido, Ingrese nuevamente : " << endl;
			cin >> dia;
			util.validarInt(dia);
		}
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
	cout << endl;
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

}
