#include<iostream>
#include <cstring>
#include "Utilidades.h"
#include "Persona.h"
#include "Fecha.h"
#include "Proveedor.h"
#include "ArchivosTemplate.h"

using namespace std;
Proveedor::Proveedor() {

}
string Proveedor::getTipo() const {
	//A - ALIMENTOS, B - BEBIDAS, S - SERVICIOS GENERALES
	string retornar;
	switch (_tipo) {
	case 'A':
		retornar = "ALIMENTICIO ";
		return retornar;
		break;
	case 'a':
		retornar = "ALIMENTICIO ";
		return retornar;
		break;
	case 'B':
		retornar = " BEBIDAS ";
		return retornar;
		break;
	case 'b':
		retornar = " BEBIDAS ";
		return retornar;
		break;
	case 'S':
		retornar = "SERVICIOS GENERALES ";
		return retornar;
		break;
	case 's':
		retornar = "SERVICIOS GENERALES ";
		return retornar;
		break;
	}

	return retornar;
}


std::string Proveedor::getEmpresa() {
	return _perteneciente;

}


void Proveedor::setTipo(char tipo) {
	_tipo = tipo;
}



void Proveedor::cargarProveedor() {
	Utilidades util;
	cargarPersona(4);
	char tipo;
	string empresa;
	
	cout << "Ingrese Tipo del proveedor " << endl;
	cout << " A - ALIMENTOS , B - BEBIDAS, S - SERVICIOS GENERALES " << endl;
	cin >> tipo;

	util.validarChar(tipo);
	while (tipo != 'A' && tipo != 'a' && tipo != 'S' && tipo != 's'
		&& tipo != 'b' && tipo != 'B') {

		cout << "Tipo Inexistente ,ingrese nuevamente " << endl;
		cin >> tipo;
		util.validarChar(tipo);

	}
	setTipo(tipo);

	cin.ignore();
	string empresaprov;
	cout << "Ingrese Empresa proveedora :  " << endl;

	getline(cin, empresaprov);
	strcpy(_perteneciente, empresaprov.c_str());
	cout << endl;
	
}

string Proveedor::mostrarProveedorstring() {
	string retornar = mostrarPersonastring();
	retornar += "Tipo Proveedor : " + getTipo() + "\n"
		+ "Empresa perteneciente : " + getEmpresa() ;

	return retornar;
}

void Proveedor::mostrar() {


	mostrarPersona();

	cout << "Tipo Proveedor : " << getTipo() << endl;
	cout << "Empresa perteneciente : " << getEmpresa() << endl;
	cout << endl;

}
