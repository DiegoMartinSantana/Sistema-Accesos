#include <iostream>
#include <string>
#include "ArchivosTemplate.h"
#include "SubMenus_Config.h"
using namespace std;
void  SubMenus_Config::subMenuBajas() {
	int opc;
	bool a = true;
	while (a) {
		cout << " CONFIGURACION - BAJAS " << endl;
		cout << " ¿Que desea dar de baja? " << endl;
		cout << " Al dar de baja se producira una desautorizacion y dicha Persona no podra volver al Recinto " << endl;
		cout << " sin antes ser dada de Alta" << endl;

		cout << endl;
		cout << " 1. Persona  " << endl;
		cout << " 2. Empleado " << endl;
		cout << " 3. Residente / Inquilino  " << endl;
		cout << " 4. Proveedor  " << endl;
		cout << " 0. Volver " << endl;
		cin >> opc;
		switch (opc)
		{
		case 1: {
			//LAS BAJAS GENERAS MOVIMIENTOS
			//Y GENERAS DESAUTORIZADO

			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			break;
		}
		case 0: {
			a = false;
			return;
			break;
		}
		default:
			break;
		}

	}
}
void SubMenus_Config::subMenuCopiaSeg() {

}
void SubMenus_Config::subMenuRestaurarCopiaSeg() {

}