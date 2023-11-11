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
