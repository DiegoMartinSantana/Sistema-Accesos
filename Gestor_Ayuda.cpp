#include <iostream>
#include <string>
#include "Gestor_Ayuda.h"
using namespace std;
void Gestor_Ayuda::infGeneral() {
	system("cls");
	char o;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "El Sistema de Accesos le permitira llevar el control del Recinto, registrando las entradas y salidas en el mismo " << endl;
	cout << "en forma de movimiento." << endl;
	cout << "Todo movimiento que se registre por primera vez implicara la Alta de una Persona ," << endl;
	cout << "que a su vez implicara la carga de una Autorizacion. " << endl;
	cout << endl;
	cout << "El sistema esta diseniado para trabajar con un maximo de 200 Unidades, en las cuales la unidad 0 sera perteneciente" << endl;
	cout << "a los empleados y proveedores del recinto." << endl;
	cout << endl;

	cout << "Usted podra consultar en forma de listado los movimientos, empleados, proveedores, unidades " << endl;
	cout << "y autorizados por distintos filtros. " << endl;
	cout << "Tambien podra pedir informes entre fechas a eleccion ,y consultar cuales son las unidades " << endl;
	cout << "que mas movimientos registraron, en caso de querer indagar alguna actividad. " << endl;
	cout << endl;

	cout << "En caso de que usted vea inconvenientes con alguna persona que se le ha sido otorgada el alta , si usted posee" << endl;
	cout << "el modo administrador podra dar la baja de forma inmediata, " << endl;
	cout << "si usted se arrepiente de la misma podra restaurar los archivos , siempre y cuando haya generado la copia de seguridad." << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	system("pause");

}
void Gestor_Ayuda::comunicarErrores() {
	system("cls");
	cout << " ---------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "En caso de presentarse errores en el sistema le pedimos porfavor que los comunique al siguiente E-mail: " << endl;
	cout << "diego.santana@alumnos.frgp.utn.edu.ar" << endl;
	cout << endl;
	cout << " ---------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	system("pause");
}
void Gestor_Ayuda::consideraciones() {
	system("cls");
	char o;
	cout << endl;
	cout << "                                 ************ IMPORTANTE ************" << endl;

	cout << endl;
	cout << " - Prestar atencion a la carga de datos, el sistema no le permitira registrar datos incorrectos, pero " << endl;
	cout << "    la informacion en los mismos es su responsabilidad. " << endl;
	cout << " - Si va a realizar una baja asegurese de haber generado una copia de seguridad de la misma. " << endl;
	cout << " - La unidad 0 es perteneciente a los empleados y proveedores." << endl;
	cout << endl;
	cout << "                               ***********************************" << endl;

	cout << endl;
	system("pause");

}
void Gestor_Ayuda::Ejecutar() {

	char opc;
	bool a = true;
	while (a)
	{
		system("cls");

		cout << "---------------------------------------------------------" << endl;
		cout << endl;

		cout << "1 - Informacion General del Sistema.  " << endl;
		cout << endl;

		cout << "2 - Consideraciones Importantes a tener en cuenta  " << endl;
		cout << endl;

		cout << "3 - Comunicacion de Errores  " << endl;
		cout << endl;
		cout << "0 - Volver.  " << endl;
		cout << endl;

		cout << "---------------------------------------------------------" << endl;

		cin >> opc;
		switch (opc) {
		case '1': {
			infGeneral();
		}
				break;
		case '2': {
			consideraciones();
		}
				break;
		case '3': {
			comunicarErrores();
		}
				break;
		case '0': {
			a = false;
			return;
		}
				break;
		default:

			break;

		}
	}
}
