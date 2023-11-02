#include <iostream>
#include <string>
#include "ArchivosMovimientos.h"
#include "ArchivosUnidades.h"
#include "Gestor_Informes.h"
#include "Movimientos.h"
#include "Proveedor.h"
using namespace std;


void Gestor_Informes::UnidadesMayor50movs() {
	//mes y anio ingresado 
	int mes, anio;
	cout << "Ingrese Mes " << endl;
	cin >> mes;
	cout << "Ingrese Anio -  2022 en Adelante. " << endl;
	cin >> anio;

	//abrir archivo movimientos
	FILE* filemov;
	Movimientos mov;
	filemov = fopen(_archivoMovimientos.c_str(), "rb");
	if (filemov == NULL) {
		cout << "Error apertura archivo movimientos " << endl;
		return;
	}
	int total = sizeof filemov/ sizeof mov;
	int* vec = new int [total] {}; // inicializo todo en cero
	int* vecidunidad = new int[total]; // en este paralelo guardo las posiciones relativas de idunidad!

	//ubicar  en mes y anio

	int con = 0;

	while (fread(&mov, sizeof mov, 1, filemov)) {
		// por cada unidad contar sus movimientos. osea extraigo el id de unidades. de cada mov y los acumulo, guardo las mayores a 50 en un vec dinamico

		if (mov.getFechayHoraMovimiento().getFecha().getAnio() == anio && mov.getFechayHoraMovimiento().getFecha().getMes() == mes) {
			vec[con]++;
			vecidunidad[con] = mov.getUnidad().getId();
			con++;
		}
	}
	fclose(filemov);

	FILE* fileunidad;
	fileunidad = fopen(_archivoUnidades.c_str(), "rb");

	if (fileunidad == NULL) {
		cout << "No se abrio archivo de unidades" << endl;
		return;
	}
	Unidad uni;


	for (int x = 0;x < total;x++) {

		if (vec[x] > 49) {
			// si es mayor busco el id!
			while (fread(&uni, sizeof uni, 1, fileunidad)) {

				if (uni.getId() == vecidunidad[x]) {
					uni.mostrar();
				}

			}
		}

	}


	delete []vec;
	delete []vecidunidad;
	fclose(fileunidad);
}
void Gestor_Informes::InformeProveedoresIngresados() {

	//mes y anio ingresado 
	int mes1, mes2, anio;
	cout << "Ingrese Primer mes " << endl;
	cin >> mes1; //menor
	cout << "Ingrese Segundo mes " << endl;
	cin >> mes2; // mayor

	//intercambio para que uno qude como mayor y otro menor si hay mal ingreso
	if (mes1 > mes2) {
		int aux = mes1;
		mes1 = mes2;
		mes2 = aux;
	}

	cout << "Ingrese Anio -  2022 en Adelante. " << endl;
	cin >> anio;

	FILE* filemov;
	Movimientos mov;
	filemov = fopen(_archivoMovimientos.c_str(), "rb");
	if (filemov == NULL) {
		cout << "Error apertura archivo movimientos " << endl;
		return;
	}

	FILE* fileprov;
	fileprov = fopen(_archivoProveedores.c_str(), "rb");
	if (fileprov == NULL) {
		cout << " No se pudo abrir archivo Proveedores" << endl;
		return;
	}
	Proveedor prov;
	while (fread(&prov, sizeof prov, 1, fileprov)) {
		// en mi archivo movimientos tengo un dni en la unidad 0 correspondiente a empleados y proveedores!

		while (fread(&mov, sizeof mov, 1, filemov)) {

			if (mov.getFechayHoraMovimiento().getFecha().getAnio() == anio) {

				if (mov.getFechayHoraMovimiento().getFecha().getMes() >= mes1 && mov.getFechayHoraMovimiento().getFecha().getMes() <= mes2) { //  y es menor al segundo mes y mayor al primero ( estoy entre esos )
					if (mov.getUnidad().getId() == 0 && mov.getDni() == prov.getDni()) { // si coinciden los dni y me paro en la unidad "Base"
						//muestro prov 
						prov.mostrar();
					}
				}
			}
		}


	}
	fclose(fileprov);
	fclose(filemov);
}
void Gestor_Informes::UnidadMasMovsHistorico() {

	//buscar en archivo movimientos el id de unidad con mas movimientos comtemplando TODO EL ARCHIVO    

	ArchivosMovimientos archimovs;
	ArchivosUnidades archiuni;

	int totalmovs = archimovs.contarRegistros();
	int totaluni = archiuni.contarRegistros();

	Movimientos auxmovs;
	Unidad auxuni;


	bool a = true;
	int cantidad;
	int cantidadmayor = 0;
	int idmayor;
	int posmayor=0;
	for (int x = 0;x < totaluni;x++) {

		auxuni = archiuni.obtenerRegistro(x);
		cantidad = 0;
		for (int y = 0;y < totalmovs;y++) {

			auxmovs = archimovs.obtenerRegistro(y);


			if (auxmovs.getUnidad().getId() == auxuni.getId()) {
				cantidad++;
			}

		}

		//aca comparo mayores
		if (a) {
			idmayor = auxuni.getId();
			cantidadmayor = cantidad;
			posmayor = x;
			a = false;
		}
		else {
			if (cantidad > cantidadmayor) {
				idmayor = auxuni.getId();
				cantidadmayor = cantidad;
				posmayor = x;

			}
		}
	}

	cout << " La unidad con mas Movimientos historicamente es " << endl;
	archiuni.obtenerRegistro(posmayor).mostrar();


}



void Gestor_Informes::UnidadMenorMovsHistorico() {

}
void Gestor_Informes::MovimientosMensuales() {
	//entre dos Fechas 
	//distincion entrada y salida
}



void Gestor_Informes::Ejecutar() {
	int opcion;
	bool a = true;

	while (a) {

		cout << "Ingrese Informe a ejecutar " << endl;

		cout << "1. Unidades con mas de 50 Movimientos Registrados (Mes y Anio)." << endl;
		cout << "2. Informe de Proveedores Ingresados entre dos fechas a eleccion." << endl;
		cout << "3. Unidad con Mayor Cantidad de Movimientos, Historico." << endl;
		cout << "4. Unidad con Menor Cantidad de Movimientos, Historico." << endl;
		cout << "5. Movimientos Mensuales entre dos fechas a eleccion." << endl;
		cin >> opcion;

		switch (opcion) {
		case 1:

			break;
		case 2:

			break;

		case 3:
			break;
		case 4:

			break;
		case 5:

			break;
		case 0:
			return;
		default:

			break;
		}



	}

}
