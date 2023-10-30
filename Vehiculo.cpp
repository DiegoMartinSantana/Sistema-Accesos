#include <iostream>
#include "Vehiculo.h"
using namespace std;
string Vehiculo::getPatente()
{
	return _patente;
}

string Vehiculo::getTitular()
{
	return _titular;
}

string Vehiculo::getFechaSeguro()
{
	return _fechaseguro.toString();
}

int Vehiculo::getTipo()
{
	return _tipo;
}

void Vehiculo::setPatente(string patente)
{
	strcpy(_patente, patente.c_str());
}

void Vehiculo::setTitular(string titular)
{
	strcpy(_titular, titular.c_str());
}

void Vehiculo::setSeguro(int dia, int mes, int anio)
{
	_fechaseguro.cargar(dia, mes, anio);
}

void Vehiculo::setTipo(int tipo)
{
	if (tipo>0&&tipo<4) {
		_tipo = tipo;
	}
	else {
		tipo = -1;
	}
}
void Vehiculo::cargar()
{
	int dia, mes, anio, tipo;
	string patente, titular;
	cout << "Ingrese los datos del Vehiculo " << endl;

	cout << "Patente: " << endl;
	cin >> patente;
	cout << "Titular: " << endl;
	cin >> titular;
	cout << "Ingrese dia" << endl;
	cin >> dia;
	cout << "Ingrese Mes" << endl;
	cin >> mes;
	cout << "Ingrese Anio" << endl;
	cin >> mes;
	cout << "Ingrese mes" << endl;
	cin >> anio;

	cout << "Ingrese el Tipo de vehiculo: 1- Auto 2- Moto 3- Camioneta " << endl;
	cin >> tipo;;



}

void Vehiculo::mostrar()
{
	cout << "Patente: " << _patente << endl;
	cout << "Titular: " << _titular << endl;
	cout << "Fecha del Seguro: " << endl;
	_fechaseguro.toString(); // sino bool.. que este al dia o no..
	cout << "Tipo: " << _tipo << endl;
}
