#include <iostream>
#include <string>
#include "ArchivosTemplate.h"
#include "Gestor_Informes.h"
#include "Movimientos.h"
#include "Proveedor.h"
#include "Utilidades.h"
#include "Unidad.h"
#include "Fecha_Hora.h"
using namespace std;
Utilidades utili;
bool movimientoValido(Movimientos& mov) {
	string s = "Dar Baja";

	if (strcmp(mov.getObservaciones().c_str(), s.c_str()) != 0) {
		return true;
	}
	return false;
}
void Gestor_Informes::UnidadesMayor50movs() {
	//mes y anio ingresado 
	int mes, anio;
	cout << "Ingrese Mes " << endl;
	cin >> mes;
	utili.validarInt(mes);
	utili.validarMes(mes);
	cout << "Ingrese Anio -  2022 hasta el actual " << endl;
	cin >> anio;
	Fecha actual;
	utili.validarInt(anio);
	while (anio<2022 || anio > actual.getAnio()) {
		cout << "Todavia no hay registros para ese anio. " << endl;
		cin >> anio;
		utili.validarInt(anio);
	}

	//abrir archivo movimientos
	ArchivosTemplate archimov;
	Movimientos mov;
	int total = archimov.contarRegistros(utili._archivoMovimientos, mov);

	int* vec = new int [total] {}; // inicializo todo en cero

	int* vecidunidad = new int[total]; // en este paralelo guardo las posiciones relativas de idunidad!

	for (int x = 0;x < total;x++) {
		// por cada unidad contar sus movimientos. osea extraigo el id de unidades. de cada mov y los acumulo, guardo todos
		mov = archimov.ObtenerMovimiento(utili._archivoMovimientos, mov, x);
		if (movimientoValido(mov)) {
			if (mov.getFechayHoraMovimiento().getFecha().getAnio() == anio && mov.getFechayHoraMovimiento().getFecha().getMes() == mes) {
				vec[x]++;
				vecidunidad[x] = mov.getUnidad();
			}
		}

	}

	ArchivosTemplate archiunidades;
	Unidad uni;
	int totaluni = archiunidades.contarRegistros(utili._archivoUnidades, uni);

	for (int x = 0;x < total;x++) { //rcorro movimientos

		if (vec[x] > 49) {
			// si es mayor busco el id!
			for (int y = 0;y < totaluni;y++) {	//recorro unidades

				if (uni.getId() == vecidunidad[x]) {
					uni.mostrar();	//si coinciden los id de unidades muestro!
				}

			}
		}

	}
	cout << endl;
	system("pause");
	delete[]vec;
	delete[]vecidunidad;
}
void Gestor_Informes::InformeProveedoresIngresados() {

	//mes y anio ingresado 
	int mes1, mes2, anio;
	cout << "Ingrese Primer mes " << endl;
	cin >> mes1; //menor
	utili.validarInt(mes1);
	utili.validarMes(mes1);

	cout << "Ingrese Segundo mes " << endl;
	cin >> mes2; // mayor
	utili.validarInt(mes2);
	utili.validarMes(mes2);

	//intercambio para que uno qude como mayor y otro menor si hay mal ingreso
	if (mes1 > mes2) {
		int aux = mes1;
		mes1 = mes2;
		mes2 = aux;
	}

	cout << "Ingrese Anio -  2022 en Adelante. " << endl;
	cin >> anio;
	Fecha actual;
	utili.validarInt(anio);
	while (anio<2022 || anio > actual.getAnio()) {
		cout << "Todavia no hay registros para ese anio. " << endl;
		cin >> anio;
		utili.validarInt(anio);
	}

	ArchivosTemplate archimov;
	ArchivosTemplate archiprov;
	Movimientos mov;
	Proveedor prov;

	int totalmovs = archimov.contarRegistros(utili._archivoMovimientos, mov);
	int totalprovs = archiprov.contarRegistros(utili._archivoProveedores, prov);

	for (int x = 0;x < totalprovs;x++) {
		// en mi archivo movimientos tengo un dni en la unidad 0 correspondiente a empleados y proveedores!
		prov = archiprov.ObtenerObjeto(utili._archivoProveedores, prov, x);
		for (int y = 0;y < totalmovs;y++) {

			mov = archimov.ObtenerMovimiento(utili._archivoMovimientos, mov, y);
			if (movimientoValido(mov)) {

				if (mov.getFechayHoraMovimiento().getFecha().getAnio() == anio) {

					if (mov.getFechayHoraMovimiento().getFecha().getMes() >= mes1 && mov.getFechayHoraMovimiento().getFecha().getMes() <= mes2) { //  y es menor al segundo mes y mayor al primero ( estoy entre esos )
						if (mov.getUnidad() == 0 && mov.getDni() == prov.getDni()) { // si coinciden los dni y me paro en la unidad "Base"
							//muestro prov 
							prov.mostrar();
						}
					}
				}
			}
		}


	}
	cout << endl;
	system("pause");
}
void Gestor_Informes::UnidadMasMovsHistorico() {

	//buscar en archivo movimientos el id de unidad con mas movimientos comtemplando TODO EL ARCHIVO    

	ArchivosTemplate archimovs;
	ArchivosTemplate archiuni;

	Movimientos movs;
	Unidad uni;
	int totalmovs = archimovs.contarRegistros(utili._archivoMovimientos, movs);
	int totaluni = archiuni.contarRegistros(utili._archivoUnidades, uni);

	bool a = true;
	int cantidad;
	int cantidadmayor = 0;
	int idmayor;
	int posmayor = 0;
	for (int x = 0;x < totaluni;x++) {

		uni = archiuni.ObtenerObjeto(utili._archivoUnidades, uni, x);
		cantidad = 0;
		for (int y = 0;y < totalmovs;y++) {

			movs = archimovs.ObtenerMovimiento(utili._archivoMovimientos, movs, y);

			if (movimientoValido(movs)) {

				if (movs.getUnidad() == uni.getId()) {
					cantidad++;
				}

			}
		}

		//aca comparo mayores
		if (a) {
			idmayor = uni.getId();
			cantidadmayor = cantidad;
			posmayor = x;
			a = false;
		}
		else {
			if (cantidad > cantidadmayor) {
				idmayor = uni.getId();
				cantidadmayor = cantidad;
				posmayor = x;

			}
		}
	}

	cout << " La unidad con mas Movimientos historicamente es " << endl;
	archiuni.ObtenerObjeto(utili._archivoUnidades, uni, posmayor).mostrar(); // le paso la posicion mayor y muestro el object
	cout << endl;
	system("pause");
}

void Gestor_Informes::UnidadMenorMovsHistorico() {
	ArchivosTemplate archimovs;
	ArchivosTemplate archiuni;

	Movimientos movs;
	Unidad uni;
	int totalmovs = archimovs.contarRegistros(utili._archivoMovimientos, movs);
	int totaluni = archiuni.contarRegistros(utili._archivoUnidades, uni);

	bool a = true;
	int cantidad;
	int cantidadmenor = 0;
	int idmenor;
	int posmenor = 0;
	for (int x = 0;x < totaluni;x++) {

		uni = archiuni.ObtenerObjeto(utili._archivoUnidades, uni, x);
		cantidad = 0;
		for (int y = 0;y < totalmovs;y++) {

			movs = archimovs.ObtenerMovimiento(utili._archivoMovimientos, movs, y);

			if (movimientoValido(movs)) {

				if (movs.getUnidad() == uni.getId()) {
					cantidad++;
				}
			}
		}

		//aca comparo menores
		if (a) {
			idmenor = uni.getId();
			cantidadmenor = cantidad;
			posmenor = x;
			a = false;
		}
		else {
			if (cantidad < cantidadmenor) {
				idmenor = uni.getId();
				cantidadmenor = cantidad;
				posmenor = x;

			}
		}
	}

	cout << " La unidad con menos Movimientos historicamente es " << endl;
	archiuni.ObtenerObjeto(utili._archivoUnidades, uni, posmenor).mostrar();
	cout << endl;
	system("pause");

}

void Gestor_Informes::MovimientosMensuales() {
	//entre dos Fechas 
	//distincion entrada y salida
	int mes1, mes2, anio;
	cout << "Ingrese Primer mes " << endl;
	cin >> mes1; //menor
	utili.validarInt(mes1);
	utili.validarMes(mes1);
	cout << "Ingrese Segundo mes " << endl;
	cin >> mes2; // mayor
	utili.validarInt(mes2);
	utili.validarMes(mes2);

	if (mes1 > mes2) {
		int aux = mes1;
		mes1 = mes2;
		mes2 = aux;
	}

	cout << "Ingrese Anio -  2022 en Adelante. " << endl;
	cin >> anio;
	utili.validarInt(anio);
	Fecha actual;
	while (anio<2022 || anio > actual.getAnio()) {
		cout << "Todavia no hay registros para ese anio. " << endl;
		cin >> anio;
		utili.validarInt(anio);
	}

	//ENTRADAS (   1- Entrada )
	Movimientos mov;
	ArchivosTemplate archimovs;
	int total = archimovs.contarRegistros(utili._archivoMovimientos, mov);
	cout << "Entradas  : " << endl;

	for (int x = 0;x < total;x++) {
		cout << endl;
		mov = archimovs.ObtenerMovimiento(utili._archivoMovimientos, mov, x);
		if (movimientoValido(mov)) {

			if (mov.getSentido() == 1) { // si es una entrada 
				if (mov.getFechayHoraMovimiento().getFecha().getAnio() == anio) {

					if (mov.getFechayHoraMovimiento().getFecha().getMes() >= mes1 && mov.getFechayHoraMovimiento().getFecha().getMes() <= mes2) { //  y es menor al segundo mes y mayor al primero ( estoy entre esos )
						mov.mostrar();
					}
				}
			}
		}
	}
	cout << "Salidas  : " << endl;

	cout << endl;
	for (int x = 0;x < total;x++) {
		cout << endl;
		mov = archimovs.ObtenerMovimiento(utili._archivoMovimientos, mov, x);
		if (movimientoValido(mov)) {

			if (mov.getSentido() == false
				) { // si es una salida
				if (mov.getFechayHoraMovimiento().getFecha().getAnio() == anio) {

					if (mov.getFechayHoraMovimiento().getFecha().getMes() >= mes1 && mov.getFechayHoraMovimiento().getFecha().getMes() <= mes2) { //  y es menor al segundo mes y mayor al primero ( estoy entre esos )
						mov.mostrar();
					}
				}
			}
		}
	}
	cout << endl;
	system("pause");
}



void Gestor_Informes::Ejecutar() {
	char opcion;
	bool a = true;
	Fecha_Hora f;

	while (a) {
		system("cls");

		cout << "-------------------------------------------------------------------------------------" << endl;

		cout << "Ingrese Informe a ejecutar :                                    " <<  f.toString()<<  endl;
		cout << endl;
		cout << "1. Unidades con mas de 50 Movimientos Registrados (Mes y Anio)." << endl;
		cout << "2. Informe de Proveedores Ingresados entre dos fechas a eleccion." << endl;
		cout << "3. Unidad con Mayor Cantidad de Movimientos, Historico." << endl;
		cout << "4. Unidad con Menor Cantidad de Movimientos, Historico." << endl;
		cout << "5. Movimientos Mensuales entre dos fechas a eleccion." << endl;
		cout << endl;
		cout << "0. Volver. " << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;

		cin >> opcion;

		switch (opcion) {
		case '1':
			UnidadesMayor50movs();
			break;
		case '2':
			InformeProveedoresIngresados();
			break;

		case '3':
			UnidadMasMovsHistorico();
			break;
		case '4':
			UnidadMenorMovsHistorico();
			break;
		case '5':
			MovimientosMensuales();
			break;
		case '0':

			return;
		default:

			break;
		}
	}
}
