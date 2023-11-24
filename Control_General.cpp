#include <iostream>
#include "Control_General.h"
#include "Gestor_Altas.h"
#include "Gestor_Consultas.h"
#include "Gestor_Listados.h"
#include "Gestor_Informes.h"
#include "Gestor_Configuraciones.h"
#include "Gestor_Ayuda.h"
#include "Fecha_Hora.h"
using namespace std;

Control_General::Control_General(int tipo) {
	_tipo = tipo;
}


void Control_General::Acceder() {
	bool a = true;
	char opcion;
	Fecha_Hora f;
	while (a) {

		system("cls");
		cout << "------------------------------------------------------------" << endl;

		if (_tipo ==2) {
			cout << "Bienvenido Admin " <<   "             "  << f.toString()  << endl;
			cout << endl;
		}  
		else {
			cout << "Bienvenido "<<   "                   " << f.toString() << endl;
			cout << endl;
		}

		cout << "Que desea hacer? " << endl;
		cout << endl;
		cout << "1 - Dar de Alta. " << endl;
		cout << "2 - Consultas. " << endl;
		cout << "3 - Informes. " << endl;
		cout << "4 - Listados. " << endl;

		
		cout << "5 - Ayuda. " << endl;
		if (_tipo == 2) {

			//muestro configuraciones
			cout << "6 - Configuraciones. " << endl;
		}
		cout << endl;
		cout << "0 - Salir. " << endl;
		cout << "------------------------------------------------------------" << endl;

		cin >> opcion;

		switch (opcion) {
		case '1': {
			Gestor_Altas alta;
			alta.Imprimiraltas();
		}
			  break;
		case '2': {
			Gestor_Consultas consu;
			consu.Ejecutar();
		}
			  break;
		case '3': {
			Gestor_Informes informes;
			informes.Ejecutar();
		}
			  break;
		case '4': {
			Gestor_Listados list;
			list.Ejecutar();
		}
			  break;
		
		case '5': {
			Gestor_Ayuda ayuda;
			ayuda.Ejecutar();
		}
		case '6': {
			if (_tipo == 2) {
				//llamado configuraciones si el tipo es el 2
				Gestor_Configuraciones config;
				config.Ejecutar();
			}

		}
			  break;
		case '0': {
			a = false;
			return;
			break;
		default:
			break;
			}
		}
	}
}