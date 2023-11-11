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
	case 'B':
		retornar = " BEBIDAS ";
		return retornar;
		break;
	case 'S':
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
	while (tipo != 'A' || tipo != 'a' || tipo != 'S' || tipo != 's'
		|| tipo != 'b' || tipo != 'B') {

		cout << "Tipo Inexistente ,ingrese nuevamente " << endl;
		cin >> tipo;
		util.validarChar(tipo);

	}
	setTipo(tipo);

	cin.ignore();
	cout << "Ingrese Empresa perteneciente " << endl;
	_perteneciente.cargar();

	cout << endl;
	cout << "Ingrese dia de su Art " << endl;
	cin >> dia;
	util.validarInt(dia);

	while (util.contarDigitosInt(dia) > 2) {
		cout << "No existen dias de mas de dos digitos.  " << endl;
		cin >> dia;
		util.validarInt(dia);
	}

	cout << "Ingrese mes de su Art " << endl;
	cin >> mes;
	util.validarInt(mes);

	while (util.contarDigitosInt(mes) > 2) {
		cout << "No existen meses de mas de dos digitos.  " << endl;
		cin >> mes;
		util.validarInt(mes);
	}
	cout << "Ingrese anio  de su Art" << endl;
	cin >> anio;
	while (util.contarDigitosInt(anio) > 4) {
		cout << "No existen anios de mas de cuatro digitos. " << endl;
		cin >> anio;
		util.validarInt(anio);
	}

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
