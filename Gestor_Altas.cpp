#include <iostream>
#include <string>
#include "Gestion_General.h"
#include "Fecha_Hora.h"
#include "Gestor_Altas.h"
using namespace std;

void Gestor_Altas::Imprimiraltas() {
	bool a = true;
	while (a) {
		system("cls");
		Fecha_Hora f;
		cout << "------------------------------------------------------------" << endl;

		char opcion;
		cout << "Que desea dar de Alta" << "             " << f.toString() << endl;
		cout << endl;
		cout << "1- Entrada / Salida.  " << endl;
		cout << "2- Visita. " << endl;
		cout << "3- Nuevo Empleado" << endl;
		cout << "4- Nuevo Residente o Inquilino " << endl;
		cout << "5- Nuevo Proveedor " << endl;
		cout << endl;
		cout << "0- Volver Atras. " << endl;
		cout << endl;
		cout << "------------------------------------------------------------" << endl;

		cin >> opcion;
		Gestion_General altas;

		switch (opcion) {
		case '1': {
			 altas.altaEntrada_Salida();
			break;
		}
		case '2':
			altas.altaVisita();
			break;

		case '3':
			altas.altaEmpleado();
			break;
		case '4':
			altas.altaResidente_inquilino();
			break;
		case '5':
			altas.altaProveedor();
			break;
		
		case '0':
			return;
			break;

		default:

			break;
		}


	}
}