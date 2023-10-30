#include <iostream>
#include "Control_General.h"
#include "Gestor_Altas.h"
#include "Gestor_Consultas.h"
#include "Gestor_Listados.h"
using namespace std;

Control_General::Control_General(int tipo) {
	_tipo = tipo;
}


void Control_General::Acceder() {
	bool a = true;
	int opcion;

	while (a) {
		system("cls");
		if (_tipo == 2) {
			cout << endl;
			cout << "Bienvenido Admin " << endl;
			cout << endl;
		}
		else {
			cout << endl;
			cout << "Bienvenido " << endl;
			cout << endl;
		}

		cout << "¿Que desea hacer? " << endl;
		cout << endl;
		cout << "1 - Dar de Alta " << endl;
		cout << "2 - Consultas " << endl;
		cout << "3 - Informes " << endl;
		cout << "4 - Listados " << endl;

		if (_tipo == 2) {

			//muestro configuraciones
			cout << "5 - Configuraciones " << endl;


		}

		cout << "0 - Salir " << endl;

		cin >> opcion;


		switch (opcion) {
		case 1: {
			Gestor_Altas alta;
			alta.Imprimiraltas();
		}
			  break;
		case 2: {
			Gestor_Consultas consu;
			consu.Ejecutar();
		}
			  break;
		case 3: {

		}
			  break;
		case 4: {
			Gestor_Listados list;
			list.Ejecutar();
		}
			  break;
		case 5: {
			if (_tipo == 2) {
				//llamado configuraciones 
			}

		}
			  break;
		case 0: {
			return;
			break;

		}

		}


	}

}