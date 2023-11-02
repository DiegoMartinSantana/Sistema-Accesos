#include <cstring>
#include "Persona.h"
#include "Empresa.h"
#include "Fecha.h"
#include "Proveedor.h"
#include<iostream>

using namespace std;
Proveedor::Proveedor(){

}
char Proveedor::getTipo() const {
	return _tipo;

}

string Proveedor::getArt() {
	string retornar = _art.toString();
	return retornar;

}

std::string Proveedor::getEmpresa()  {
	return _perteneciente.getRazonSocial();

}


void Proveedor::setTipo(char tipo) {
	_tipo = tipo;
}

void Proveedor::setArt(int dia, int mes, int anio) {
	_art.cargar(dia, mes, anio);
}




void Proveedor::cargarProveedor() {
	cargarPersona();
	char tipo;
	string empresa;
	int dia, mes, anio;

	cout << "Ingrese Tipo del proveedor " << endl;
	cin >> tipo;
	setTipo(tipo);
	cin.ignore();
	cout << "Ingrese Empresa perteneciente " << endl;
	_perteneciente.cargar();
	
	cout << endl;
	cout << "Ingrese dia de su Art " << endl;
	cin >> dia;
	cout << "Ingrese mes de su Art " << endl;
	cin >> mes;
	cout << "Ingrese anio  de su Art" << endl;
	cin >> anio;
	setArt(dia, mes, anio);
}

string Proveedor::mostrarProveedorstring() {
	string retornar = mostrarPersonastring();
	retornar += "Tipo Proveedor : " + to_string(getTipo()) + "\n"
		+ " Empresa perteneciente : " + getEmpresa() + "\n"
		+ "Fecha de su Art : " + getArt();

	return retornar;
}

void Proveedor::mostrar() {


	mostrarPersona();

	cout << "Tipo Proveedor : " << to_string(getTipo()) << endl;
	cout << " Empresa perteneciente : " << getEmpresa() << endl;
	cout << "Fecha de su Art : " << getArt() << endl;
}
