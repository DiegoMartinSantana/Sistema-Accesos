#include <iostream>
#include <vector>
#include <string>
#include "ArchivosTemplate.h"
#include "Gestor_Consultas.h"
#include "Persona.h"
#include "Autorizaciones.h"
#include "Residente.h"
#include "Proveedor.h"
#include "Empleado.h"
#include "Empresa.h" 
#include "Unidad.h"
#include "Utilidades.h"
#include "Fecha_Hora.h"
using namespace std;
Utilidades utilidad;
void pasarMayus(string& nombre) {
	for (int x = 0;x < nombre.length();x++) {
		nombre[x] = toupper(nombre[x]);
	}
}
string retornarapellidoxdni(int dni) {

	ArchivosTemplate archipersona;
	Persona p;
	string ret;
	string nombrearchi = "Personas.dat";
	int totp = archipersona.contarRegistros(nombrearchi, p);

	for (int x = 0;x < totp;x++) {
		p = archipersona.ObtenerObjeto(nombrearchi, p, x);
		if (p.getDni() == dni) {

			ret = p.getApellidos();
			return ret;
		}

	}
	ret = "Invalido";

	return ret;
}
bool comparar(const string compare, vector<string>& vec) { // mas facil pasarle el con y listo..
	for (int x = 0;x < vec.size();x++)
	{
		if (strcmp(compare.c_str(), vec[x].c_str()) == 0) { // si la que recibe es igual una existente en el vector
			return false;
		}

	}
	return true;
}

//muestra las razones sociales existentes para hacer la consulta


void Gestor_Consultas::AutorizadosporDni() {
	system("cls");

	int dni;
	cout << "Ingrese Dni ( 8 digitos ) " << endl;
	cin >> dni;
	utilidad.validarInt(dni);
	while (utilidad.contarDigitosInt(dni) != 8) {
		cout << "Dni Valido solo de 8 digitos , ingrese nuevamente   " << endl;
		cin >> dni;
		utilidad.validarInt(dni);
	}

	Autorizaciones autorizado;
	ArchivosTemplate archiauto;

	int total = archiauto.contarRegistros(utilidad._archivoAutorizados, autorizado);

	for (int x = 0;x < total;x++) {

		autorizado = archiauto.ObtenerObjeto(utilidad._archivoAutorizados, autorizado, x);
		if (autorizado.getDniPersona() == dni) {
			autorizado.mostrar();
			system("pause");

			return;
		}
	}

	cout << "No se ha encontrado ninguna Persona Autorizada junto a ese Dni" << endl;

}

void Gestor_Consultas::AutorizadosporApellido() {
	system("cls");

	string apellido;
	cin.ignore();
	cout << "Ingrese Apellido " << endl;
	getline(cin, apellido);
	Autorizaciones autorizado;
	ArchivosTemplate archiauto;

	int total = archiauto.contarRegistros(utilidad._archivoAutorizados, autorizado);
	//sigo tenienod nombre y apellido pero en el registro personas .. no como propiedad
	//entonces lo busco por coincidencia dentro del for!

	for (int x = 0;x < total;x++) {

		autorizado = archiauto.ObtenerObjeto(utilidad._archivoAutorizados, autorizado, x);
		string autoapellido = retornarapellidoxdni(autorizado.getDniPersona());
		pasarMayus(autoapellido);
		pasarMayus(apellido);

		int igual = strcmp(apellido.c_str(), autoapellido.c_str());
		if (igual == 0) {
			autorizado.mostrar();
			system("pause");

			return;
		}
	}

	cout << "No se ha encontrado ninguna Persona Autorizada con ese apellido" << endl;
	system("pause");

}
void Gestor_Consultas::ResidentesporIdUnidad() {
	system("cls");

	int id;
	cout << "Ingrese Id Unidad (1-200) " << endl;
	cin >> id;
	utilidad.validarInt(id);

	while (id < 1 || id > 200) {
		cout << "Id invalido , Ingrese de nuevo " << endl;
		cin >> id;
		utilidad.validarInt(id);
	}

	Residente res;
	ArchivosTemplate archires;

	int total = archires.contarRegistros(utilidad._archivoResidentes, res);

	bool a = false;
	for (int x = 0;x < total;x++) {
		res = archires.ObtenerObjeto(utilidad._archivoResidentes, res, 0);
		if (res.getUnidad() == id) {
			a = true;
			res.mostrar();
			system("pause");

			return;
		}

	}
	if (!a) {
		cout << "No se ha encontrado ningun residente junto a ese id " << endl;
	}
	system("pause");

}
void Gestor_Consultas::ResidentesporApellido() {
	system("cls");

	string apellido;
	cin.ignore();
	cout << "Ingrese Apellido " << endl;
	getline(cin, apellido);

	Residente res;
	ArchivosTemplate archires;

	int total = archires.contarRegistros(utilidad._archivoResidentes, res);

	bool a = false;
	for (int x = 0;x < total;x++) {
		res = archires.ObtenerObjeto(utilidad._archivoResidentes, res, x);
		string aperes = res.getApellidos();

		pasarMayus(aperes);
		pasarMayus(apellido);

		int igual = strcmp(apellido.c_str(), aperes.c_str());
		if (igual == 0) {
			res.mostrar();
			a = true;
		}
	}

	if (!a) {
		cout << "No se ha encontrado ningun residente con ese apellido" << endl;
	}
	system("pause");

}


void Gestor_Consultas::ProveedoresporDni() {
	system("cls");

	int dni;
	cout << "Ingrese Dni (8 Digitos)  " << endl;
	cin >> dni;
	utilidad.validarInt(dni);
	while (utilidad.contarDigitosInt(dni) != 8) {
		cout << "Dni Valido solo de 8 digitos , ingrese nuevamente   " << endl;
		cin >> dni;
		utilidad.validarInt(dni);
	}

	ArchivosTemplate archiprov;
	Proveedor prov;

	int total = archiprov.contarRegistros(utilidad._archivoProveedores, prov);
	for (int x = 0;x < total;x++) {
		prov = archiprov.ObtenerObjeto(utilidad._archivoProveedores, prov, x);
		if (prov.getDni() == dni) {
			prov.mostrar();
			system("pause");

			return;
		}
	}

	cout << "No se ha encontrado ningun proveedor con dicho Dni" << endl;
	system("pause");

}
void Gestor_Consultas::EmpleadoporNroLegajo() {
	system("cls");

	int nrolegajo;
	cout << "Ingrese Numero de Legajo 1-100" << endl;
	cin >> nrolegajo;
	utilidad.validarInt(nrolegajo);

	while (nrolegajo< 1|| nrolegajo> 100) { // nacimiento hasta actual 
		cout << "Legajo Invalido " << endl;
		cin >> nrolegajo;
		utilidad.validarInt(nrolegajo);
	}
	ArchivosTemplate archiemp;
	Empleado emp;
	int totemp = archiemp.contarRegistros(utilidad._archivoEmpleados, emp);
	for (int x = 0;x < totemp;x++) {
		emp = archiemp.ObtenerObjeto(utilidad._archivoEmpleados, emp, x);

		if (emp.getLegajo() == nrolegajo) {
			emp.mostrar();
			system("pause");

			return;
		}
	}
	cout << "No existe ningun empleado con ese numero de legajo " << endl;
	system("pause");

	return;

}
void Gestor_Consultas::EmpleadoporApellido() {
	system("cls");

	string apellido;
	cin.ignore();
	cout << "Ingrese Apellido " << endl;
	getline(cin, apellido);
	ArchivosTemplate archiemp;
	Empleado emp;
	int totemp = archiemp.contarRegistros(utilidad._archivoEmpleados, emp);

	for (int x = 0;x < totemp;x++) {
		emp = archiemp.ObtenerObjeto(utilidad._archivoEmpleados, emp, x);

		string apeemp = emp.getApellidos();
		pasarMayus(apeemp);
		pasarMayus(apellido);
		if (strcmp(apellido.c_str(),apeemp.c_str()) == 0) {
			emp.mostrar();
			//podria haber mas de un empelado x apellido
		}
	}
	system("pause");

	return;
}

void Gestor_Consultas::UnidadesporId() {
	system("cls");

	Unidad uni;
	int id;
	cout << "Ingrese Id de la Unidad (0-200) " << endl;
	cin >> id;

	utilidad.validarInt(id);
	while (id < 0 || id > 200) {
		cout << "Id invalido , Ingrese de nuevo " << endl;
		cin >> id;
		utilidad.validarInt(id);

	}

	FILE* file;
	file = fopen(utilidad._archivoUnidades.c_str(), "rb");
	if (file == NULL) {
		cout << "No se abrio archivo Empleados" << endl;
		return;
	}
	while (fread(&uni, sizeof uni, 1, file)) {

		if (id == uni.getId()) {

			uni.mostrar();
			fclose(file);
			system("pause");

			return;
		}
	}

	cout << "No se ha encontrado una unidad bajo ese Id" << endl;
	system("pause");
	fclose(file);
	return;


}
void Gestor_Consultas::Ejecutar() {

	Fecha_Hora f;

	bool a = true;
	while (a) {
		system("cls");

		char opcion;
		cout << "----------------------------------------------------------------------" << endl;

		cout << " Seleccione su Consulta " << "                   " << f.toString()<< endl;
		cout << endl;
		cout << "1- Autorizados por Dni " << endl;
		cout << "2- Autorizados por Apellido " << endl;
		cout << endl;
		cout << "3- Residentes por Id Unidad" << endl;
		cout << "4- Residentes por Apellido" << endl;
		cout << endl;
		cout << "5- Proveedores por Dni" << endl;
		cout << endl;
		cout << "6- Empleado por Numero Legajo" << endl;
		cout << "7- Empleado por Apellido" << endl;
		cout << endl;
		cout << "8- Unidades por Id" << endl;
		cout << endl;
		cout << "0- Volver" << endl;
		cout << "----------------------------------------------------------------------" << endl;

		cin >> opcion;

		switch (opcion) {
		case '1':
			AutorizadosporDni();
			break;
		case '2':
			AutorizadosporApellido();
			break;
		case '3':
			ResidentesporIdUnidad();
			break;
		case '4':
			ResidentesporApellido();
			break;
		
		case '5':
			ProveedoresporDni();
			break;
		case '6':
			EmpleadoporNroLegajo();
			break;
		case '7':
			EmpleadoporApellido();
			break;
		case '8':
			UnidadesporId();
			break;
		case '0':
			return;
			break;
		default:
			cout << "Opción no válida" << endl;
			break;
		}


	}
}