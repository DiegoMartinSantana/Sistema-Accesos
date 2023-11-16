#include <iostream>

#include "Utilidades.h"
using namespace std;

void Utilidades::validarInt(int &n) {

		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> n;
		}
}
void Utilidades::validarChar(char& a) {
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cin >> a;
	}

}

int Utilidades::contarDigitosInt(int a) {
	// cuento en un whuke y divido x 10. hice ejercicio parecido en progra 1
	int con = 0;
	if (a == 0) {
		return 1;
	}
	else {

		while (a > 0) {
			a = a / 10; // asi elimino los digitos
			con++;
		}
		
	}
	return con;
}

void Utilidades::validarMes(int& mes) {

	while (mes < 1 || mes > 12) {

		cout << "Mes invalido , ingrese nuevamente" << endl;
		cin >> mes;
		validarInt(mes);
	}
}void Utilidades::validarDia(int& dia) {
	while (dia < 1 || dia >31) {
		cout << "Dia Invalido " << endl;
		cin >> dia;
		validarInt(dia);
	}
}
void Utilidades::validarAnioActual(int& anio,int actual) {
	while (anio < 1920 || anio > actual ){ // nacimiento hasta actual 
		cout << "Anio Invalido " << endl;
		cin >> anio;
		validarInt(anio);
	}

}
void  Utilidades::validarAnio(int& anio) {
	while (anio < 1930 || anio > 2030) { 
		cout << "Anio Invalido " << endl;
		cin >> anio;
		validarInt(anio);
	}
}
