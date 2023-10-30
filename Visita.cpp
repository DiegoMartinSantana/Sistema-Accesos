#include<iostream>

#include "Persona.h"
#include "Visita.h"
#include <cstring>



using namespace std;

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

	cout << "Nombre: " << getNombres() << endl;
	cout << "Apellido: " << getApellidos() << endl;
	cout << "Documento: " << getDni() << endl;
}
void Visita::cargarvisita() {

	cargarPersona();
	int unidad;
	bool familiar;
	cout << "Ingrese el numero de unidad que visita " << endl;
	cin >> unidad;

	setUnidad(unidad);
	cout << "Ingrese 1 si es familiar. 0 Si no lo es." << endl;
	cin >> familiar;
	setFamiliar(familiar);

}

