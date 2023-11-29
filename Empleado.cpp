#include<iostream>
#include <cstring>
#include "Persona.h"
#include "Empleado.h"
#include "Utilidades.h"
#include "ArchivosTemplate.h"
using namespace std;

Empleado::Empleado() {

}

void Empleado::setTipo(char tipo) {
	if (tipo > 0 && tipo < 3)
		_tipo = tipo;
}

void Empleado::setCategoria(char categoria) {
	_categoria = categoria;
}

void Empleado::setLegajo(int legajo) {
	_legajo = legajo;
}

void Empleado::setDescripcion(const string descripcion) {
	strcpy(_descripcion, descripcion.c_str());

}

string  Empleado::getTipo() const {
	string retornar;
	if (_tipo == 1) {
		retornar = " Propio ";
		return retornar;

	}
	else {
		retornar = " Ajeno ";
		return retornar;
	}
}

string Empleado::getCategoria() const {
	//A - Limpieza  , B - Seguridad , C - Administrativo D - CONTRATADO X EMPRESA EXTERNA .
	string retornar;
	switch (toupper(_categoria)) {
	case  'L':
		retornar = "Limpieza";
		return retornar;
		break;
	case  'S':
		retornar = "Seguridad";
		return retornar;

		break;
	case  'A':
		retornar = "Administrativo";
		return retornar;

		break;
	case  'C':
		retornar = "CONTRATADO POR EMPRESA EXTERNA ";
		return retornar;

		break;

	}
	return retornar;
}


int Empleado::getLegajo() const {
	return _legajo;
}

bool validarLegajo(int legajo) {
	Utilidades u;
	ArchivosTemplate a;
	Empleado e;
	int tot = a.contarRegistros(u._archivoEmpleados, e);
		for (int x = 0;x < tot;x++) {

			e = a.ObtenerObjeto(u._archivoEmpleados, e, x);
			if (e.getLegajo() == legajo) {
				return false;
			}

		}
		return true;



}

string Empleado::getDescripcion() const {
	string retornar = _descripcion;
	return retornar;


}

void Empleado::CargarEmpleado() {
	Utilidades util;
	int legajo;
	int tipo;
	char categoria;
	string descripcion;


	cargarPersona(3);


	cout << "Ingrese el legajo 0 - 100 :  " << endl;
	cin >> legajo;

	util.validarInt(legajo);
	//valdiar no exista legajo

	while (legajo < 1 || legajo > 100 || !validarLegajo(legajo)) {
		cout << endl;
		cout << "Legajo invalido o existente ,ingrese nuevamente : " << endl;
		cin >> legajo;
		util.validarInt(tipo);
	}
	setLegajo(legajo);

	cout << "Ingrese el tipo: 1- Propio 2- Ajeno " << endl;
	cin >> tipo;
	util.validarInt(tipo);
	while (tipo < 0 || tipo >2) {
		cout << "Tipo inexistente ,ingrese nuevamente :" << endl;
		cin >> tipo;
		util.validarInt(tipo);
	}

	setTipo(tipo);
	if (tipo == 1) {
		cout << "Ingrese la categoria: " << endl;
		cout << "  L - Limpieza  , S - Seguridad , A - Administrativo ." << endl;;
		cin >> categoria;
		util.validarChar(categoria);
		while (categoria != 'A' && categoria != 'a' && categoria != 'S' && categoria != 's'
			&& categoria != 'L' && categoria != 'l') { // mientras no sea una valida

			cout << "Categoria Inexistente ,ingrese nuevamente : " << endl;
			cin >> categoria;
			util.validarChar(categoria);

		}
		setCategoria(toupper(categoria));
	}
	else {
		categoria = 'C'; // ajeno
		setCategoria(categoria);
	}


	cin.ignore();
	cout << "Ingrese descripcion del Empleado : " << endl;
	getline(cin, descripcion);
	setDescripcion(descripcion);
	if (tipo == 2) {
		cout << endl;
		string a;
		cout << "Ingrese nombre de la Empresa a la que pertenece : " << endl;
		cout << endl;
		getline(cin, a);
		strcpy(_perteneciente, a.c_str());

	}
	else {
		string a = "Empleado Propio";
		strcpy(_perteneciente, a.c_str());
	}
	cout << endl;
}

void Empleado::mostrar() {

	mostrarPersona();
	cout << "Legajo empleado : " << getLegajo() << endl;
	cout << "Tipo  : " << getTipo() << endl;
	cout << "Categoria : " << getCategoria() << endl;
	cout << "Descripcion : " << getDescripcion() << endl;
	if (_tipo == 2) {
		cout << "Empresa :" << _perteneciente << endl;
	}
	cout << endl;

}