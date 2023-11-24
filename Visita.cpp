#include<iostream>
#include <cstring>
#include "Persona.h"
#include "Visita.h"
#include "Utilidades.h"


using namespace std;
Visita::Visita() {

}

void Visita::setUnidad(int unidad) {
	_unidad = unidad;
}

void Visita::setFamiliar(bool es) {
	_familiar = es;
}

int Visita::getUnidad()const {
	return _unidad;
}
bool Visita::getFamiliar()const {
	return _familiar;
}

string Visita::mostrarvisitastring() {

	string retornar = mostrarPersonastring();

	string familia;
	if (_familiar) {
		familia = " Posee familia dentro del recinto. ";
	}
	else {

		familia = "No posee familia dentro del recinto.";
	}

	retornar += " Numero unidad de la visita : " + to_string(_unidad) + "\n"
		+ "La visita " + familia;

	return retornar;
}
void Visita::mostrar() {
	cout << endl;

	cout << "Nombre: " << getNombres() << endl;
	cout << "Apellido: " << getApellidos() << endl;
	cout << "Documento: " << getDni() << endl;
	if (getFamiliar()) {
		cout << "Posee familia dentro del Recinto" << endl;
	}
	cout << endl;

}
void Visita::cargarvisita() {
	Utilidades util;
	cargarPersona(2);
	int unidad;
	int familiar;
	cout << "Ingrese el numero de unidad que visita (1-200)" << endl;
	cin >> unidad;
	util.validarInt(unidad);
	while (unidad < 1 || unidad>200) {
		cout << "Unidad invalida, ingrese nuevamente " << endl;
		cin >> unidad;
		util.validarInt(unidad);

	}
	setUnidad(unidad);

	cout << "Ingrese 1 si es familiar. 0 Si no lo es." << endl;
	cin >> familiar;
	util.validarInt(familiar);
	while (familiar < 0 || familiar >1) {
		cout << "Dato incorrecto , ingrese nuevamente " << endl;
		cin >> familiar;
		util.validarInt(familiar);
	}

	if (familiar == 1) {
		setFamiliar(true);
	}
	else {
		setFamiliar(false);
	}
	setEstado(true);
}

