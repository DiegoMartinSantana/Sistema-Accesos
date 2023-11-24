#include <iostream>
#include <vector>
#include "ArchivosTemplate.h"
#include "ArchivosAutorizacion.h"
#include "ArchivosMovimiento.h"
#include "Gestor_Listados.h"
#include "Residente.h"
#include "Persona.h"
#include "Autorizaciones.h"
#include "Movimientos.h"
#include "Proveedor.h"
#include "Empleado.h"
#include "Unidad.h"
#include "Fecha_Hora.h"
#include "Utilidades.h"
using namespace std;
Utilidades ut;

void ordenarburbujeo(int* vec, int& total) {
	int aux;
	for (int x = 0;x < total;x++) {

		for (int y = 0;y < (total - 1);y++) {

			if (vec[y] > vec[y + 1]) {
				aux = vec[y + 1];
				vec[y + 1] = vec[y];
				vec[y] = aux;
			}

		}

	}
}

void burbujeocaracter(vector <string>& vec, int total) {

	string aux;
	for (int x = 0;x < total;x++) {

		for (int y = 0;y < (total - 1);y++) {

			if (toupper(vec[y][0]) > toupper(vec[y + 1][0])) { // si vec en la pos .. en su primer caracter > , compara nros ASCII en mayus para llevar orden ..
				aux = vec[y + 1];
				vec[y + 1] = vec[y];
				vec[y] = aux;
			}
		}
	}
}
string retornarapellido(int dni) {

	ArchivosTemplate archipersona;
	Persona p;
	string nombrearchi = "Personas.dat";
	int totp = archipersona.contarRegistros(nombrearchi, p);

	for (int x = 0;x < totp;x++) {
		p = archipersona.ObtenerObjeto(nombrearchi, p, x);
		if (p.getDni() == dni) {

			return p.getApellidos();
		}

	}
	return "Invalido ";
}

void Gestor_Listados::UnidadesOrdenadasporApellidoFamilia() {
	system("cls");

	Unidad uni;
	ArchivosTemplate archiuni;

	int total = archiuni.contarRegistros(ut._archivoUnidades, uni);

	vector <string> vec;
	vec.resize(total); // importante. sino me da error por querer acceder a lugar inexistente.

	for (int x = 0;x < total;x++) {
		vec[x] = archiuni.ObtenerObjeto(ut._archivoUnidades, uni, x).getApellidoFamilia();
	}

	burbujeocaracter(vec, total);

	for (int x = 0;x < total;x++) {

		for (int y = 0;y < total;y++) {
			uni = archiuni.ObtenerObjeto(ut._archivoUnidades, uni, y);

			if (vec[x] == uni.getApellidoFamilia()) {
				cout << "Apellido :  " << uni.getApellidoFamilia() << endl;
				cout << "Id uni : " << uni.getId() << endl;
				cout << endl;
			}
		}
	}
	vec.clear();
	cout << endl;
	system("pause");
}
void Gestor_Listados::AutorizadosOrdenadosporApellido() {
	system("cls");

	Autorizaciones autorizado(0, 0);
	ArchivosTemplate archiauto;


	int total = archiauto.contarRegistros(ut._archivoAutorizados, autorizado);

	vector <string> vec;
	vec.resize(total); // le paso el tamaño! 

	for (int x = 0;x < total;x++) {

		vec[x] = retornarapellido(archiauto.ObtenerObjeto(ut._archivoAutorizados, autorizado, x).getDniPersona());

	}

	// YA TENGO EL VEC CARGADO con todos los apellidos
	// ahora tengo que pasar todas las primeras letras a toupper para tener mismo todo
	// y despues compararlas em burbujeo tambien , compara por valores ASCII
	//lo hago en esta func, trabaja con toupper y vector
	burbujeocaracter(vec, total);


	for (int x = 0;x < total;x++) {

		for (int y = 0;y < total;y++) {

			autorizado = archiauto.ObtenerObjeto(ut._archivoAutorizados, autorizado, y);
			string ape = retornarapellido(autorizado.getDniPersona());
			if (vec[x]== ape) {
				cout << "Apellido : " << ape << endl;
				cout << "Dni :" << autorizado.getDniPersona() << endl;
				cout << endl;
			}
		}
	}
	cout << endl;
	system("pause");
	vec.clear(); //libero la memoria
}
void Gestor_Listados::ProveedoreOrdenadosporRazonSocial() {
	system("cls");

	Proveedor prov;
	ArchivosTemplate archiprov;

	int total = archiprov.contarRegistros(ut._archivoProveedores, prov);

	vector <string> vec;
	vec.resize(total);

	for (int x = 0;x < total;x++) {
		vec[x] = archiprov.ObtenerObjeto(ut._archivoProveedores, prov, x).getEmpresa();

	}

	burbujeocaracter(vec, total);

	for (int x = 0;x < total;x++) {

		for (int y = 0;y < total;y++) {
			prov = archiprov.ObtenerObjeto(ut._archivoProveedores, prov, y);
			
				if (vec[x] == prov.getEmpresa()) {
					prov.mostrar();
					cout << endl;

				}
			
		}
	}
	cout << endl;
	system("pause");
	vec.clear();
}

void Gestor_Listados::AutorizadosOrdenadosporDni() {
	//capturar todo 
	system("cls");

	Autorizaciones autorizado(0, 0);

	ArchivosTemplate archiauto;
	int total = archiauto.contarRegistros(ut._archivoAutorizados, autorizado);


	int* vec = new int[total]; //guardo todo aca
	for (int x = 0;x < total;x++) {
		vec[x] = archiauto.ObtenerObjeto(ut._archivoAutorizados, autorizado, x).getDniPersona();
	}

	//ordenar vec .. por burbujeo
	ordenarburbujeo(vec, total);

	//mostrar

	for (int x = 0;x < total;x++) { //recorro todo y a medida que encuentra muestra

		for (int y = 0;y < total;y++) {
			autorizado = archiauto.ObtenerObjeto(ut._archivoAutorizados, autorizado, y); // guarda aca en y, porque compara contra TODOS VS LA POS DEL VEC EN FOR SUPERIOR
			if (autorizado.getDniPersona() == vec[x]) {
				cout << "Dni del autorizado " << autorizado.getDniPersona() << endl;
				cout << "Unidad perteneciente " << autorizado.getIdUnidad() << endl;
			}
		}

	}
	cout << endl;
	system("pause");
	delete[] vec;
}

void Gestor_Listados::ResidentesOrdenadosporIdUnidad() {
	system("cls");

	Residente res;

	ArchivosTemplate archires;

	int total = archires.contarRegistros(ut._archivoResidentes, res);

	int* vec = new int[total];
	for (int x = 0;x < total;x++) {
		res = archires.ObtenerObjeto(ut._archivoResidentes, res, x);
		vec[x] = res.getUnidad();
	}

	ordenarburbujeo(vec, total);


	for (int x = 0;x < total;x++) {


		for (int y = 0;y < total;y++) {
			res = archires.ObtenerObjeto(ut._archivoResidentes, res, y);

			if (res.getUnidad() == vec[x]) {
				cout << " Id unidad : " << res.getUnidad() << endl;
				cout << " Apellido Familia : " << res.getApellidos() << endl;
			}
		}

	}
	cout << endl;
	system("pause");
	delete[]vec;

}


void Gestor_Listados::EmpleadosOrdenadosporDni() {

	Empleado emp;

	ArchivosTemplate archiemp;

	int total = archiemp.contarRegistros(ut._archivoEmpleados, emp);

	int* vec = new int[total];
	for (int x = 0; x < total; x++)
	{
		emp = archiemp.ObtenerObjeto(ut._archivoEmpleados, emp, x);
		vec[x] = emp.getDni();
	}
	
	ordenarburbujeo(vec, total);

	for (int x = 0;x < total;x++) {

		for (int y = 0;y < total;y++) {
			emp = archiemp.ObtenerObjeto(ut._archivoEmpleados, emp, y);

			if (emp.getDni() == vec[x]) {
				cout << endl;
				cout << "Dni : " << emp.getDni() << endl;
				cout << "Nombre : " << emp.getApellidosyNombres() << endl;
				cout << endl;

			}

		}

	}
	cout << endl;
	system("pause");
	delete[] vec;

}
void Gestor_Listados::UnidadesporId() {
	system("cls");

	Unidad uni;
	ArchivosTemplate archiuni;

	int total = archiuni.contarRegistros(ut._archivoUnidades, uni);

	int* vec = new int[total];
	for (int x = 0;x < total;x++) {
		vec[x] = archiuni.ObtenerObjeto(ut._archivoUnidades, uni, x).getId();

	}

	ordenarburbujeo(vec, total);

	for (int x = 0;x < total;x++) {

		for (int y = 0;y < total;y++) {
			uni = archiuni.ObtenerObjeto(ut._archivoUnidades, uni, y);

			if (vec[x] == uni.getId()) {
				cout << " Id unidad : " << uni.getId() << endl;
				cout << " Apellido Familia : " << uni.getApellidoFamilia() << endl;

			}
		}

	}
	cout << endl;
	system("pause");
	delete[]vec;
	
}

void Gestor_Listados::MovimientosDiaHoy() {

	//comparo vs la fecha del sistema!
	system("cls");

	Fecha fSistema;
	Movimientos mov;
	ArchivosTemplate archi;
	int totalmov = archi.contarRegistros(ut._archivoMovimientos, mov);
	ArchivosMovimiento archimov;
	for (int x = 0;x < totalmov;x++) {
		mov = archimov.ObtenerMovimiento(x);

		if (mov.getFechayHoraMovimiento().getFecha().getAnio() == fSistema.getAnio()) {

			if (mov.getFechayHoraMovimiento().getFecha().getMes() == fSistema.getMes()) {
				
				if (mov.getFechayHoraMovimiento().getFecha().getDia() == fSistema.getDia()) {
					mov.mostrar();
				}

			}
		}
	}
	cout << endl;
	system("pause");

}
void Gestor_Listados::Ejecutar() {
	Fecha_Hora f;

	char opcion;
	bool a = true;
	while (a) {
		system("cls");
		cout << "----------------------------------------------------------------------------------------" << endl;

		cout << "Opciones para Listar :                                               " << f.toString() <<  endl;
		cout << endl;
		cout << "1. Autorizados Ordenados por Apellido - ALFABETICAMENTE." << endl;
		cout << "2. Autorizados Ordenados por DNI." << endl;
		cout << "3. Residentes Ordenados por Id Unidad. " << endl;
		cout << "4. Proveedor Ordenados por Razon Social. " << endl;
		cout << "5. Empleados Ordenados por DNI. " << endl;
		cout << "6. Unidades Ordenadas por Id ( menor a mayor ). " << endl;
		cout << "7. Unidades Ordenadas por Apellido de la Familia - ALFABETICAMENTE.  " << endl;
		cout << "8. Listado de Todos los Movimientos Registrados el Dia de hoy." << endl;
		cout << endl;
		cout << "0. Volver." << endl;
		cout << endl;
		cout << "Seleccione una opción:  " << endl;
		cout << "----------------------------------------------------------------------------------------" << endl;

		cin >> opcion;

		switch (opcion) {
		case '1':
			AutorizadosOrdenadosporApellido();
			break;
		case '2':
			AutorizadosOrdenadosporDni();
			break;
		case '3':
			ResidentesOrdenadosporIdUnidad();
			break;
		case '4':
			ProveedoreOrdenadosporRazonSocial();
			break;
		case '5':
			EmpleadosOrdenadosporDni();
			break;
		case '6':
			UnidadesporId();
			break;
		case '7':
			UnidadesOrdenadasporApellidoFamilia();
			break;
		case '8':
			MovimientosDiaHoy();
			break;
		case '0':
			a = false;
			return;
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
			break;
		}
	}

}
