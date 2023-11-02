#include <iostream>
#include <vector>
#include "ArchivosTemplate.h"
#include "Gestor_Listados.h"
#include "Residente.h"
#include "Persona.h"
#include "Autorizaciones.h"
#include "Proveedor.h"
#include "Empleado.h"
#include "Unidad.h"

using namespace std;
bool compararcadenas(string a, string b) {

	if (strcmp(a.c_str(), b.c_str()) == 0) {
		return true;
	}
	else {
		return false;
	}

}
void ordenarburbujeo(int* vec, int& total) {
	int aux;
	for (int x = 0;x < total;x++) {

		for (int y = 0;x < (total - 1);x++) {

			if (vec[y] > vec[y + 1]) {
				aux = vec[y + 1];
				vec[y + 1] = vec[y];
				vec[y] = aux;
			}

		}

	}
}
void burbujeocaracter(vector <string> vec, int total) {

	string aux;


	for (int x = 0;x < total;x++) {

		for (int y = 0;x < (total - 1);x++) {

			if (toupper(vec[x][0]) > toupper(vec[y + 1][0])) { // si vec en la pos .. en su primer caracter > , compara nros ASCII en mayus para llevar orden ..
				aux = vec[y + 1];
				vec[y + 1] = vec[y];
				vec[y] = aux;
			}

		}

	}

}
void Gestor_Listados::AutorizadosOrdenadosporApellido() {

	Autorizaciones autorizado(0,0);
	ArchivosTemplate archiauto;


	int total = archiauto.contarRegistros(_archivoAutorizados, autorizado);

	vector <string> vec;

	for (int x = 0;x < total;x++) {
		vec[x] = archiauto.ObtenerObjeto(_archivoAutorizados, autorizado, x).getApellido();

	}

	// YA TENGO EL VEC CARGADO con todos los apellidos
	// ahora tengo que pasar todas las primeras letras a toupper para tener mismo todo
	// y despues compararlas em burbujeo tambien , compara por valores ASCII
	//lo hago en esta func, trabaja con toupper y vector
	burbujeocaracter(vec, total);


	for (int x = 0;x < total;x++) {

		for (int y = 0;y < total;y++) {

			autorizado = archiauto.ObtenerObjeto(_archivoAutorizados, autorizado, x);

			if (compararcadenas(vec[x], autorizado.getApellido())) {
				autorizado.mostrar();
			}
		}
	}
	vec.clear(); //libero la memoria
}

void Gestor_Listados::AutorizadosOrdenadosporDni() {
	//capturar todo 
	Autorizaciones autorizado(0,0);

	ArchivosTemplate archiauto;
	int total = archiauto.contarRegistros(_archivoAutorizados, autorizado);


	int* vec = new int[total]; //guardo todo aca
	for (int x = 0;x < total;x++) {
		vec[x] = archiauto.ObtenerObjeto(_archivoAutorizados, autorizado, x).getDniPersona();
	}

	//ordenar vec .. por burbujeo
	ordenarburbujeo(vec, total);

	//mostrar

	for (int x = 0;x < total;x++) { //recorro todo y a medida que encuentra muestra

		autorizado = archiauto.ObtenerObjeto(_archivoAutorizados, autorizado, x);
		for (int y = 0;y < total;y++) {

			if (autorizado.getDniPersona() == vec[x]) {
				autorizado.mostrar();
			}

		}


	}
	delete[] vec;
}

void Gestor_Listados::ResidentesOrdenadosporIdUnidad() {

	Residente res;

	ArchivosTemplate archires;

	int total = archires.contarRegistros(_archivoResidentes, res);

	int* vec = new int[total];
	int con = 0;
	for (int x = 0;x < total;x++) {
		vec[x] = archires.ObtenerObjeto(_archivoResidentes, res, x).getUnidad();
	}

	ordenarburbujeo(vec, total);


	for (int x = 0;x < total;x++) {

		res = archires.ObtenerObjeto(_archivoResidentes, res, x);

		for (int y = 0;y < total;y++) {

			if (res.getUnidad() == vec[x]) {
				res.mostrar();
			}
		}

	}
	delete[]vec;

}

void Gestor_Listados::ProveedoreOrdenadosporRazonSocial() {

	Proveedor prov;
	ArchivosTemplate archiprov;

	int total = archiprov.contarRegistros(_archivoProveedores, prov);

	vector <string> vec;

	for (int x = 0;x < total;x++) {
		vec[x] = archiprov.ObtenerObjeto(_archivoProveedores, prov, x).getEmpresa();

	}

	burbujeocaracter(vec, total);

	for (int x = 0;x < total;x++) {
		prov = archiprov.ObtenerObjeto(_archivoProveedores, prov, x);

		for (int y = 0;y < total;y++) {
			if (compararcadenas(vec[x], prov.getEmpresa())) {
				prov.mostrar();
			}
		}
	}
	vec.clear();
}

void Gestor_Listados::EmpleadosOrdenadosporDni() {

	Empleado emp;

	ArchivosTemplate archiemp;

		int total = archiemp.contarRegistros(_archivoEmpleados, emp);


	int* vec = new int[total];
	for (int x = 0; x < total; x++)
	{
		emp = archiemp.ObtenerObjeto(_archivoEmpleados, emp, x);
		vec[x] = emp.getDni();
	}

	ordenarburbujeo(vec, total);

	for (int x = 0;x < total;x++) {
		emp = archiemp.ObtenerObjeto(_archivoEmpleados, emp, x);

		for (int y = 0;y < total;y++) {

			if (emp.getDni() == vec[x]) {
				emp.mostrar();
			}

		}

	}
	delete[] vec;
}
void Gestor_Listados::UnidadesporId() {

	Unidad uni;
	ArchivosTemplate archiuni;

	int total = archiuni.contarRegistros(_archivoUnidades, uni);

	int* vec = new int[total];
	for (int x = 0;x < total;x++) {
		vec[x] = archiuni.ObtenerObjeto(_archivoUnidades, uni, x).getId();

	}

	ordenarburbujeo(vec, total);

	for (int x = 0;x < total;x++) {
		uni = archiuni.ObtenerObjeto(_archivoUnidades, uni, x);

		for (int y = 0;y < total;y++) {

			if (vec[x] == uni.getId()) {
				uni.mostrar();
			}
		}

	}

	delete[]vec;
}
void Gestor_Listados::UnidadesOrdenadasporApellidoFamilia() {

	Unidad uni;
	ArchivosTemplate archiuni;

	int total = archiuni.contarRegistros(_archivoUnidades, uni);

	vector <string> vec;

	for (int x = 0;x < total;x++) {
		vec[x] = archiuni.ObtenerObjeto(_archivoUnidades, uni, x).getApellidoFamilia();
	}

	burbujeocaracter(vec, total);

	for (int x = 0;x < total;x++) {

		uni = archiuni.ObtenerObjeto(_archivoUnidades, uni, x);
		for (int y = 0;y < total;y++) {
			if (compararcadenas(vec[x], uni.getApellidoFamilia())) {
				uni.mostrar();
			}
		}
	}
	vec.clear();
}
void Gestor_Listados::Ejecutar() {

	int opcion;
	bool a = true;
	while (a) {
		system("cls");
		cout << "Opciones para Listar :" << endl;
		cout << "1. Autorizados Ordenados por Apellido - ALFABETICAMENTE" << endl;
		cout << "2. Autorizados Ordenados por DNI" << endl;
		cout << "3. Residentes Ordenados por Id Unidad " << endl;
		cout << "4. Proveedor Ordenados por Razon Social " << endl;
		cout << "5. Empleados Ordenados por DNI " << endl;
		cout << "6. Unidades Ordenadas por Id ( menor a mayor ) " << endl;
		cout << "7. Unidades Ordenadas por Apellido de la Familia - ALFABETICAMENTE  " << endl;

		cout << "0. Salir" << endl;
		cout << "Seleccione una opci�n:  ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			AutorizadosOrdenadosporApellido();
			break;
		case 2:
			AutorizadosOrdenadosporDni();
			break;
		case 3:
			ResidentesOrdenadosporIdUnidad();
			break;
		case 4:
			ProveedoreOrdenadosporRazonSocial();
			break;
		case 5:
			EmpleadosOrdenadosporDni();
			break;
		case 6:
			UnidadesporId();
			break;
		case 7:
			UnidadesOrdenadasporApellidoFamilia();
			break;
		case 0:
			cout << "Saliendo del programa." << endl;
			a = false;
		default:
			cout << "Opci�n no v�lida. Intente de nuevo." << endl;
			break;
		}
	}

}
