#include<iostream>
#include <cstring>
#include "Persona.h"
#include "Empleado.h"
#include "Utilidades.h"
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
}

int Empleado::getLegajo() const {
	return _legajo;
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


	cargarPersona();


	cout << "Ingrese el legajo: ";
	cin >> legajo;
	util.validarInt(legajo);
	setLegajo(legajo);

	cout << "Ingrese el tipo: 1- Propio 2- Ajeno ";
	cin >> tipo;
	util.validarInt(tipo);
	while (tipo < 0 || tipo >2) {
		cout << "Tipo inexistente " << endl;
		cin >> tipo;
		util.validarInt(tipo);
	}

	setTipo(tipo);
	if (tipo == 1) {
		cout << "Ingrese la categor�a: ";
		cout << "  L - Limpieza  , S - Seguridad , A - Administrativo ." << endl;;
		cin >> categoria;
		util.validarChar(categoria);
		while (categoria != 'A' || categoria != 'a' || categoria != 'S' || categoria != 's'
			|| categoria != 'L' || categoria != 'l') { // mientras no sea una valida

			cout << "Categoria Inexistente ,ingrese nuevamente " << endl;
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
	cout << "Ingrese descripci�n: ";
	getline(cin, descripcion);
	setDescripcion(descripcion);
	if (tipo == 2) {
		_perteneciente.cargar();
	}

}

void Empleado::mostrar() {

	mostrarPersona();
	cout << " Legajo empleado : " << getLegajo() << endl;
	cout << "Tipo  : " << getTipo() << endl;
	cout << "Categoria : " << getCategoria() << endl;
	cout << "Descripcion : " << getDescripcion() << endl;
	if (_tipo == 2) {
		_perteneciente.mostrar();
	}

}