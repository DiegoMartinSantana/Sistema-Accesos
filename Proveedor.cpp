#include<iostream>
#include <cstring>
#include "Utilidades.h"
#include "Persona.h"
#include "Empresa.h"
#include "Fecha.h"
#include "Proveedor.h"

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

string Proveedor::getArt() {
	string retornar = _art.toString();
	return retornar;

}

std::string Proveedor::getEmpresa() {
	return _perteneciente.getRazonSocial();

}


void Proveedor::setTipo(char tipo) {
	_tipo = tipo;
}

void Proveedor::setArt(int dia, int mes, int anio) {
	_art.cargar(dia, mes, anio);
}




void Proveedor::cargarProveedor() {
	Utilidades util;
	cargarPersona();
	char tipo;
	string empresa;
	int dia, mes, anio;

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


	cout << "Ingrese datos de la Empresa proveedora :  " << endl;

	_perteneciente.cargar();

	cout << endl;
	cout << "Ingrese dia de su Art " << endl;
	cin >> dia;
	util.validarInt(dia);

	util.validarDia(dia);

	cout << "Ingrese mes de su Art " << endl;
	cin >> mes;
	util.validarInt(mes);
	util.validarMes(mes);

	
	cout << "Ingrese anio  de su Art" << endl;
	cin >> anio;
	util.validarAnio(anio);

	setArt(dia, mes, anio);
}

string Proveedor::mostrarProveedorstring() {
	string retornar = mostrarPersonastring();
	retornar += "Tipo Proveedor : " + getTipo() + "\n"
		+ " Empresa perteneciente : " + getEmpresa() + "\n"
		+ "Fecha de su Art : " + getArt();

	return retornar;
}

void Proveedor::mostrar() {


	mostrarPersona();

	cout << "Tipo Proveedor : " << getTipo() << endl;
	cout << " Empresa perteneciente : " << getEmpresa() << endl;
	cout << "Fecha de su Art : " << getArt() << endl;
}
