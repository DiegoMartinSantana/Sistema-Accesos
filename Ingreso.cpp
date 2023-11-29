#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#include "Control_General.h"
#include "Fecha_Hora.h"
#include "ArchivosAutorizacion.h"
#include "Autorizaciones.h"
#include "ArchivosTemplate.h"
#include "Utilidades.h"
#include "Residente.h"
#include "Empleado.h"
#include "Visita.h"



int main() {
	ArchivosTemplate archi;
	ArchivosAutorizacion archiauto;
	Visita visi;
	//visi.setEstado(true);
	//visi.setNombres("Arnaldo");
	//visi.setApellidos("JOSE");
	//visi.setDni(44221100);
	Utilidades ut;
	//archi.cargarRegistro(ut._archivoVisitas, visi); // valido en el template que exista


	//Autorizaciones autorizado(visi.getDni(), visi.getUnidad()); // carga la autorizacion correspondiente
	//autorizado.setHasta(27, 11, 2023);

	//archiauto.cargarRegistrodeAutorizacion(autorizado);

	/*int totalv = archi.contarRegistros(ut._archivoVisitas, visi);
	for (int x = 0;x < totalv;x++) {

		visi = archi.ObtenerObjeto(ut._archivoVisitas, visi, x);
		if (visi.getEstado()) {
			visi.mostrar();
		}
	}*/
	Autorizaciones ar;
	int tota = archi.contarRegistros(ut._archivoAutorizados, ar);

	for (int x = 0;x < tota;x++) {
		ar = archi.ObtenerObjeto(ut._archivoAutorizados, ar, x);
		if (ar.getEstado())
			ar.mostrar();


	}
	system("pause");
	bool a = true;
	Fecha_Hora f;
	while (a) {
		system("cls");
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "Bienvenido al Sistema .                                      " << f.toString() << endl;
		cout << endl;
		cout << "Elija su metodo de ingreso : " << endl;
		cout << endl;
		cout << endl;
		cout << " 1 - Control Simple  2 - Control Administrador" << endl;

		char opingreso;
		cin >> opingreso;

		if (opingreso == '1') {
			Control_General control(1);
			control.Acceder();
		}
		else if (opingreso == '2') {
			string clave;

			int con = 0;


			while (clave != "1111") {
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
					return 0;
				}
			}

		}
		else {
			cout << "Opcion Invalida. " << endl;
		}
	}

	return 0;
}