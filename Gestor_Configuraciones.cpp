#include <iostream>
#include "Gestor_Configuraciones.h"
#include "SubMenus_Config.h"
#include "Fecha_Hora.h"
using namespace std;
void Gestor_Configuraciones::Ejecutar() {

	char opc;
	bool a=true;
	SubMenus_Config config;
	Fecha_Hora f;

	while (a) {
		system("cls");
		cout << "------------------------------------------------------------" << endl;
		cout << endl;
		cout << " CONFIGURACION " << "              " << f.toString()<<  endl;
		cout << endl;
		cout << " 1. Realizar una baja.  " << endl;
		cout << " 2. Generar copia de seguridad." << endl;
		cout << " 3. Restaurar copia de seguridad." << endl;
		cout << endl;
		cout << " 0. Salir. " << endl;
		cout << endl;
		cout << "------------------------------------------------------------" << endl;

		cin >> opc;
		switch (opc)
		{
		case '1': {
			config.subMenuBajas();
			break;
		}
		case '2': {
			config.subMenuCopiaSeg();
		}
			break;
		case '3': {
			config.subMenuRestaurarCopiaSeg();
		}
			break;

		case '0':
			a = false;
			return;
				break;
		default:

			break;
		}

	}



}
