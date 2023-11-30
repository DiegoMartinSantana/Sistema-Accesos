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
	cargarPersona(1);
	int unidad;
	int dia, mes, anio;
	int propie;

	cout << "Ingrese Unidad correspondiente a asignar 1-200 : " << endl;
	cin >> unidad;
	//unidad 0 solo emp y prov
	util.validarInt(unidad);
	while (unidad < 1 || unidad >200) {

		cout << "Unidad invalida . Recuerde que la Unidad 0 corresponde a Empleados y Proveedores." << endl;
		cin >> unidad;

		util.validarInt(unidad);
	}

	setUnidad(unidad);
	cout << "Ingrese anio de Ingreso  2022- 2030 : " << endl;
	cin >> anio;
	util.validarInt(anio);
	while (anio < 2022 || anio > 2030) {
		cout << "Anio Invalido " << endl;
		cin >> anio;
		util.validarInt(anio);
	}

	

	cout << "Ingrese mes de Ingreso : " << endl;
	cin >> mes;
	util.validarInt(mes);
	util.validarMes(mes);
	cout << "Ingrese dia de Ingreso : " << endl;
	cin >> dia;
	util.validarInt(dia);
	while (!util.validarDia(dia, mes, anio)) {
		cout << "Dia de Ingreso invalido, ingrese nuevamente : " << endl;
		cin >> dia;
		util.validarInt(dia);
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
		cout << "Unidad del Residente : " << getUnidad()<< endl;
		cout << "Fecha de Ingreso del Residente : " << getIngreso() << endl;
	}
	else {
		cout << "Unidad del Inquilino : " << getUnidad() << endl;
		cout << "Fecha de Ingreso del Inquilino : " << getIngreso() << endl;
	}
	cout << endl;

}