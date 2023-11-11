#include <iostream>
#include <cstring>
#include "Utilidades.h"
#include "Persona.h"
#include "Fecha.h"
#include "Residente.h"
using namespace std;

Residente::Residente() {

}
int Residente::getUnidad() const {
	return _unidad;
}

string Residente::getIngreso() {
	string retornar = _ingreso.toString();
	return retornar;
}

bool Residente::getPropietario_Inquilino() const {
	return _propietario_inquilino;
}


void Residente::setUnidad(int unidad) {
	_unidad = unidad;
}

void Residente::setIngreso(int dia, int mes, int anio) {
	_ingreso.cargar(dia, mes, anio);
}

void Residente::setPropietario_Inquilino(bool propietario) {
	_propietario_inquilino = propietario;
}

void Residente::cargarResidente() {
	Utilidades util;
	cargarPersona();
	int unidad;
	int dia, mes, anio;
	int propie;

	cout << "Ingrese Unidad correspondiente 1-200 : " << endl;
	cin >> unidad;
	//unidad 0 solo emp y prov
	util.validarInt(unidad);
	while (unidad < 1 && unidad >200) {

		cout << "Unidad invalida . Recuerde que la Unidad 0 corresponde a Empleados y Proveedores." << endl;
		cin >> unidad;

		util.validarInt(unidad);
	}

	setUnidad(unidad);

	cout << "Ingrese dia de Ingreso : " << endl;
	cin >> dia;
	util.validarInt(dia);
	while (util.contarDigitosInt(dia) > 2) {
		cout << "No existen dias de mas de dos digitos.  " << endl;
		cin >> dia;
		util.validarInt(dia);
	}

	cout << "Ingrese mes de Ingreso : " << endl;
	cin >> mes;
	util.validarInt(mes);
	while (util.contarDigitosInt(mes) > 2) {
		cout << "No existen meses de mas de dos digitos. " << endl;
		cin >> mes;
		util.validarInt(mes);
	}
	cout << "Ingrese anio de Ingreso  : " << endl;
	cin >> anio;
	util.validarInt(anio);
	while (util.contarDigitosInt(anio) > 4) {
		cout << "No existen anios de mas de cuatro digitos. " << endl;
		cin >> anio;
		util.validarInt(anio);
	}

	setIngreso(dia, mes, anio);

	cout << "Ingrese 1 si es Residente ( Propietario ) , Ingrese 0 si es Inquilino (Alquila) " << endl;
	cin >> propie;
	util.validarInt(propie);
	while (propie <0 || propie > 1 ) {
		cout << "Dato invalido, ingrese nuevamente" << endl;
		cin >> propie;
		util.validarInt(propie);

	}
	if (propie == 1) {
		setPropietario_Inquilino(true);
	}
	else {
		setPropietario_Inquilino(false);

	}

}
string Residente::mostrarResidentestring() {
	string retornar = mostrarPersonastring();

	if (getPropietario_Inquilino()) {

		retornar += "Unidad del Residente : " + to_string(getUnidad()) + "\n"
			+ " Fecha de Ingreso del Residente : " + getIngreso();
	}
	else {
		retornar += "Unidad del Inquilino : " + to_string(getUnidad()) + "\n"
			+ " Fecha de Ingreso del Inquilino : " + getIngreso();


	}
	return retornar;

}
void Residente::mostrar() {

	mostrarPersona();

	if (getPropietario_Inquilino()) {
		cout << "Unidad del Residente : " << to_string(getUnidad()) << endl;
		cout << " Fecha de Ingreso del Residente : " << getIngreso() << endl;
	}
	else {
		cout << "Unidad del Inquilino : " << to_string(getUnidad()) << endl;
		cout << "Fecha de Ingreso del Inquilino : " << getIngreso() << endl;
	}

}