#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#include "Control_General.h"
#include "Fecha_Hora.h"


int main() {
	
	bool a = true;
	Fecha_Hora f;
	while (a) {
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "Bienvenido al Sistema .                                      " <<f.toString() << endl;
		cout << endl;
		cout << "Elija su metodo de ingreso : " << endl;
		cout << endl;
		cout << endl;
		cout << " 1 - Control Simple  2 - Control Administrador" << endl;
		
		char opingreso;
		cin >> opingreso;
		
		if (opingreso =='1') {
			Control_General control(1);
			control.Acceder();
		}
		else if (opingreso == '2') {
			string clave;
			
			int con = 0;
			
			
			while (clave != "1111" ) {
				con++;
				cout << "Ingrese clave Numerica: " << endl;

				cin >> clave;
				if (clave == "1111") {
					//ingreso a modo admin
					Control_General control(2);
					control.Acceder();
					a = false;
				}
				if (con == 5) {
					cout << "Demasiados intentos, Se cerrara el sistema. " << endl;
					a = false;
					return 0 ;
				}
			}
			
		}
		else { 
			cout << "Opcion Invalida. " << endl;
		}
	}

	return 0;
}