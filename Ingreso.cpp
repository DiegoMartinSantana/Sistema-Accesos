#include <iostream>
#include <cstring>
#include <string>
#include "Control_General.h"
using namespace std;

int main() {
	bool a = true;
	while (a) {
		cout << "Bienvenido al Sistema . " << endl;
		cout << "Elija su metodo de ingreso . " << endl;
		cout << " 1 - Control Simple  2 - Control Administrador" << endl;
		//posible pedido de nombre  y pasaje en consola..
		//mostrar horario de la consola.
		// opcion cerrar todo.

		int opingreso;
		cin >> opingreso;

		if (opingreso == 1) {
			Control_General control(1);
			control.Acceder();
		}
		else if (opingreso == 2) {
			int  clave = 0;
			int con = 0;
			while (clave != 1111) {
				con++;
				cout << "Ingrese clave " << endl;
				cin >> clave;
				if (clave == 1111) {
					//ingreso a modo admin
					Control_General control(2);
					control.Acceder();
					a = false;
				}
				if (con == 5) {
					cout << "Demasiados intentos, Se cerrara el sistema " << endl;
					a = false;
				}
			}
			
		}
	}
	return 0;
}