#include <iostream>
#include <vector>
#include "Gestor_Listados.h"
#include "Residente.h"
#include "Persona.h"
#include "Autorizaciones.h"
#include "Proveedor.h"
#include "Empleado.h"
#include "Unidad.h"

using namespace std;
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

			if (toupper(vec[y][0]) > toupper(vec[y + 1][0])) { // si vec en la pos .. en su primer caracter > , compara nros ASCII en mayus para llevar orden ..
				aux = vec[y + 1];
				vec[y + 1] = vec[y];
				vec[y] = aux;
			}

		}

	}

}
void Gestor_Listados::AutorizadosOrdenadosporApellido() {
	
	FILE* file;
	file = fopen(_archivoAutorizados.c_str(), "rb");

	Autorizaciones autorizado(0,0);

	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;

	}

	int total = sizeof(file) / sizeof(autorizado);

	vector <string> vec;
	int con = 0;

	while (fread(&autorizado, sizeof autorizado, 1, file)) {

		vec[con] = autorizado.getApellido();
		
		con++;

	}

	fclose(file);

	// YA TENGO EL VEC CARGADO
	// ahora tengo que pasar todas las primeras letras a toupper para tener mismo todo
	// y despues compararlas em burbujeo tambien , compara por valores ASCII

	burbujeocaracter(vec, total);

	file = fopen(_archivoAutorizados.c_str(), "rb");

	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;

	}
	for (int x = 0;x < total;x++) {


		while (fread(&autorizado, sizeof autorizado, 1, file)) {
			
			if (strcmp(vec[x].c_str(), autorizado.getApellido().c_str())== 0) {
				autorizado.mostrar();
			}
		}
	}
	fclose(file);
	
}

void Gestor_Listados::AutorizadosOrdenadosporDni() {
	//capturar todo 

	Autorizaciones autorizado(0, 0);
	FILE* file;

	file = fopen(_archivoAutorizados.c_str(), "rb");
	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;
	}
	int total = sizeof (file) / sizeof(autorizado); // sizeof de file (tam total ) dividido los autorizados = total registros 
	 
	int *vec = new int [total]; //guardo todo aca
	int con = 0;
	while (fread(&autorizado, sizeof autorizado, 1, file)) {

		vec[con] = autorizado.getDniPersona();
		con++;
	}

	fclose(file);

	//ordenar vec .. por burbujeo
	ordenarburbujeo(vec, total);


	//mostrar

	for (int x = 0;x < total;x++) { //recorro todo y a medida que encutra muestra,

		Autorizaciones autorizado(0, 0);
		FILE* file;
		file = fopen(_archivoAutorizados.c_str(), "rb");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return;
		}
		while (fread(&autorizado, sizeof autorizado, 1, file)) {

			if (autorizado.getDniPersona() == vec[x]) {
				autorizado.mostrar();
			}

		}

		fclose(file);

	}
	delete vec;
}

void Gestor_Listados::ResidentesOrdenadosporIdUnidad() {
	
	Residente res;

	FILE* file;

	file = fopen(_archivoResidentes.c_str(), "rb");
	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;
	}
	int total = sizeof(res) / sizeof(res); 

	int* vec = new int[total]; 
	int con = 0;
	while (fread(&res, sizeof res, 1, file)) {

		vec[con] = res.getUnidad();
		con++;
	}

	fclose(file);

	ordenarburbujeo(vec, total);


	for (int x = 0;x < total;x++) { 

		FILE* file;
		file = fopen(_archivoResidentes.c_str(), "rb");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return;
		}
		while (fread(&res, sizeof res, 1, file)) {

			if (res.getUnidad() == vec[x]) {
				res.mostrar();
			}

		}

		fclose(file);

	}
	delete vec;

}

void Gestor_Listados::ProveedoreOrdenadosporRazonSocial() {
	FILE* file;

	file = fopen(_archivoProveedores.c_str(), "rb");

	Proveedor prov;
	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;

	}

	int total = sizeof(file) / sizeof(prov);

	vector <string> vec;
	int con = 0;

	while (fread(&prov, sizeof prov, 1, file)) {

		vec[con] = prov.getEmpresa();

		con++;

	}

	fclose(file);


	burbujeocaracter(vec, total);

	file = fopen(_archivoProveedores.c_str(), "rb");

	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;

	}
	for (int x = 0;x < total;x++) {


		while (fread(&prov, sizeof prov, 1, file)) {

			if (strcmp(vec[x].c_str(), prov.getEmpresa().c_str()) == 0) {
				prov.mostrar();
			}
		}
	}
	fclose(file);
}

void Gestor_Listados::EmpleadosOrdenadosporDni() {

	Empleado emp;

	FILE* file;

	file = fopen(_archivoEmpleados.c_str(), "rb");
	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;
	}
	int total = sizeof(file) / sizeof(emp); 

	int* vec = new int[total]; 
	int con = 0;
	while (fread(&emp, sizeof emp, 1, file)) {

		vec[con] = emp.getDni();
		con++;
	}

	fclose(file);

	ordenarburbujeo(vec, total);


	for (int x = 0;x < total;x++) { 

		FILE* file;
		file = fopen(_archivoAutorizados.c_str(), "rb");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return;
		}
		while (fread(&emp, sizeof emp, 1, file)) {

			if (emp.getDni(), vec[x]) {
				emp.mostrar();
			}

		}

		fclose(file);

	}
	delete vec;
}
void Gestor_Listados::UnidadesporId() {

	Unidad uni;

	FILE* file;

	file = fopen(_archivoUnidades.c_str(), "rb");
	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;
	}
	int total = sizeof(file) / sizeof(uni); 

	int* vec = new int[total]; 
	int con = 0;
	while (fread(&uni, sizeof uni, 1, file)) {

		vec[con] = uni.getId();
		con++;
	}

	fclose(file);

	ordenarburbujeo(vec, total);

	

	for (int x = 0;x < total;x++) { 

		FILE* file;
		file = fopen(_archivoAutorizados.c_str(), "rb");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return;
		}
		while (fread(&uni, sizeof uni, 1, file)) {

			if (uni.getId() == vec[x]) {
				uni.mostrar();
			}

		}

		fclose(file);

	}
	delete vec;
}
void Gestor_Listados::UnidadesOrdenadasporApellidoFamilia() {
	FILE* file;
	file = fopen(_archivoUnidades.c_str(), "rb");

	Unidad uni;

	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;

	}

	int total = sizeof(file) / sizeof(uni);

	vector <string> vec;
	int con = 0;

	while (fread(&uni, sizeof uni, 1, file)) {

		vec[con] = uni.getApellidoFamilia();

		con++;

	}

	fclose(file);


	burbujeocaracter(vec, total);

	file = fopen(_archivoUnidades.c_str(), "rb");

	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;

	}
	for (int x = 0;x < total;x++) {


		while (fread(&uni, sizeof uni, 1, file)) {

			if (strcmp(vec[x].c_str(), uni.getApellidoFamilia().c_str()) == 0) {
				uni.mostrar();
			}
		}
	}
	fclose(file);
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
		cout << "Seleccione una opción:  ";
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
			cout << "Opción no válida. Intente de nuevo." << endl;
			break;
		}
	}

}
