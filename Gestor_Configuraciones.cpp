#include <iostream>

#include "Gestor_Configuraciones.h"
using namespace std;
void Gestor_Configuraciones::Ejecutar() {


	bool a=true;
	while (a) {
		int opc;
		cout << " CONFIGURACION " << endl;
		cout << endl;
		cout << " 1. Realizar una baja  " << endl;
		cout << " 2. Generar copia de seguridad" << endl;
		cout << " 3. Restaurar copia de seguridad" << endl;
		cout << endl;

		cout << " 0. Salir " << endl;
		cin >> opc;
		switch (opc)
		{
		case 1: {
			
			break;
		}
		case 2: {

		}
			break;
		case 3: {

		}
			break;

		case 0:
			a = false;
			return;
				break;
		default:

			break;
		}

	}



}
