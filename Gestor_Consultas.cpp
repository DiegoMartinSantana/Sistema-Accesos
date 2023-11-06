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

using namespace std;
string retornarapellidoxdni(int dni) {

	ArchivosTemplate archipersona;
	Persona p;
	string ret;
	string nombrearchi = "Personas.dat";
	int totp = archipersona.contarRegistros(nombrearchi, p);

	for (int x = 0;x < totp;x++) {
		p = archipersona.ObtenerObjeto(nombrearchi, p, x);
		if (p.getDni() == dni) {

		ret =p.getApellidos();
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
int  mostrarrazonessociales(vector <string>& vec) {
	Empresa empre;
	ArchivosTemplate architem;
	string archi = "Empresas.dat";
	int totempresas = architem.contarRegistros(archi, empre);
	//uso biblioteca vector.
	bool a = true;

	for(int x=0;x<totempresas;x++){


		if (a) {
			vec[x] = (empre.getRazonSocial()); // push back añade.. pero asi llevo mejor control yo.
			a = false;
		}
		else {
			//compara con todas aca.
			if (comparar(empre.getRazonSocial(), vec)) {
				vec[x] = (empre.getRazonSocial());
			}
		}

	}

	int razon;

	cout << "Ingrese la Razon social a buscar " << endl;
	cin >> razon;

	int opcion;

	for (int x = 0;x < vec.size();x++) {
		int c = x + 1;
		cout << c << " - " << vec[x] << endl;

	}
	cin >> opcion;
	opcion=opcion-1;
	return opcion - 1;
	// segun lo que retorne sera a buscar.. pero es un int.. asique mejor que reciba el vector (equivale a su posicion el int retornado)
}

void Gestor_Consultas::AutorizadosporDni() {
	int dni;
	cout << "Ingrese Dni " << endl;
	cin >> dni;

	Autorizaciones autorizado;
	ArchivosTemplate archiauto;

	int total = archiauto.contarRegistros(_archivoAutorizados, autorizado);

	for (int x = 0;x < total;x++) {

		autorizado = archiauto.ObtenerObjeto(_archivoAutorizados, autorizado, x);
		if (autorizado.getDniPersona() == dni) {
			autorizado.mostrar();

			return;
		}
	}

	cout << "No se ha encontrado ninguna Persona Autorizada junto a ese Dni" << endl;

}

void Gestor_Consultas::AutorizadosporApellido() {
	string apellido;
	cin.ignore();
	cout << "Ingrese Apellido " << endl;
	getline(cin, apellido);
	Autorizaciones autorizado;
	ArchivosTemplate archiauto;

	int total = archiauto.contarRegistros(_archivoAutorizados, autorizado);
	//sigo tenienod nombre y apellido pero en el registro personas .. no como propiedad
	//entonces lo busco por coincidencia dentro del for!
	
	for (int x = 0;x < total;x++) {

		autorizado = archiauto.ObtenerObjeto(_archivoAutorizados, autorizado, x);
		string autoapellido = retornarapellidoxdni(autorizado.getDniPersona());
		int igual = strcmp(apellido.c_str(), autoapellido.c_str());
		if (igual == 0) {
			autorizado.mostrar();
			
			return;
		}
	}
	
	cout << "No se ha encontrado ninguna Persona Autorizada con ese apellido" << endl;

}
void Gestor_Consultas::ResidentesporIdUnidad() {

	int id;
	cout << "Ingrese Id Unidad " << endl;
	cin >> id;

	Residente res;
	ArchivosTemplate archires;

	int total = archires.contarRegistros(_archivoResidentes, res);

	bool a = false;
	for (int x = 0;x < total;x++) {
		res = archires.ObtenerObjeto(_archivoResidentes, res, 0);
		if (res.getUnidad() == id) {
			a = true;
			res.mostrar();
		}

	}
	if (!a) {
		cout << "No se ha encontrado ningun residente junto a ese id " << endl;
	}
}
void Gestor_Consultas::ResidentesporApellido() {
	string apellido;
	cin.ignore();
	cout << "Ingrese Apellido " << endl;
	getline(cin, apellido);

	Residente res;
	ArchivosTemplate archires;

	int total = archires.contarRegistros(_archivoResidentes, res);

	bool a = false;
	for (int x = 0;x < total;x++) {
		res = archires.ObtenerObjeto(_archivoResidentes, res, 0);
		int igual = strcmp(apellido.c_str(), res.getApellidos().c_str());
		if (igual == 0) {
			res.mostrar();
			a = true;
		}
	}
	
	if (!a) {
		cout << "No se ha encontrado ningun residente con ese apellido" << endl;
	}
}
void Gestor_Consultas::ProveedoresporRazonSocial() {

	//mostrar razones sociales existentes
	//1 
	vector <string > vec;
	int opc = mostrarrazonessociales(vec); // ahora esta cargado el vector y se que razon social trabajar!

 // realziar busqueda 
	//2
	ArchivosTemplate archiprov;
	Proveedor prov;
	
	bool a = true;
	int total = archiprov.contarRegistros(_archivoProveedores, prov);
	for (int x = 0;x < total;x++) {

		prov = archiprov.ObtenerObjeto(_archivoProveedores, prov, x);
		if (strcmp(vec[opc].c_str(), prov.getEmpresa().c_str()) == 0) {
			prov.mostrar();
			a = false;
		}
	}
	if (a) { cout << "No hay ningun proveedor con esa razon social " << endl; }

}

void Gestor_Consultas::ProveedoresporDni() {
	int dni;
	cout << "Ingrese Dni " << endl;
	cin >> dni;
	ArchivosTemplate archiprov;
	Proveedor prov;

	int total = archiprov.contarRegistros(_archivoProveedores, prov);
	for (int x = 0;x < total;x++) {
		prov = archiprov.ObtenerObjeto(_archivoProveedores, prov, x);
		if (prov.getDni() == dni) {
			prov.mostrar();
			return;
		}
	}
	
	cout << "No se ha encontrado ningun proveedor con dicho Dni" << endl;
}
void Gestor_Consultas::EmpleadoporNroLegajo() {

	int nrolegajo;
	cout << "Ingrese Numero de Legajo " << endl;
	cin >> nrolegajo;
	ArchivosTemplate archiemp;
	Empleado emp;
	int totemp = archiemp.contarRegistros(_archivoEmpleados, emp);
	for (int x = 0;x < totemp;x++) {

		if (emp.getLegajo() == nrolegajo) {
			emp.mostrar();
			return;
		}
	}
	cout << "No existe ningun empleado con ese numero de legajo " << endl;
	return;
	
}
void Gestor_Consultas::EmpleadoporApellido() {
	
	string apellido;
	cin.ignore();
	cout << "Ingrese Apellido " << endl;
	getline(cin, apellido);
	ArchivosTemplate archiemp;
	Empleado emp;
	int totemp = archiemp.contarRegistros(_archivoEmpleados, emp);

	for (int x = 0;x < totemp;x++) {

		if (strcmp(apellido.c_str(),emp.getApellidos().c_str()) == 0) {
			emp.mostrar();
			//podria haber mas de un empelado x apellido
		}
	}
	

	return;

}

void Gestor_Consultas::UnidadesporId() {
	Unidad uni;
	int id;
	cout << "Ingrese Id de la Unidad" << endl;
	cin >> id;


	FILE* file;
	file = fopen(_archivoUnidades .c_str(), "rb");
	if (file == NULL) {
		cout << "No se abrio archivo Empleados" << endl;
		return;
	}
	while (fread(&uni, sizeof uni, 1, file)) {

		if (id == uni.getId()) {

			uni.mostrar();
			fclose(file);
			return;
		}
	}

	cout << "No se ha encontrado una unidad bajo ese Id" << endl;
	fclose(file);
	return;


}
void Gestor_Consultas::Ejecutar() {

	
	bool a = true;
	while (a) {
		int opcion;

		cout << " Seleccione su Consulta " << endl;
		cout << endl;
		cout << "1- Autorizados por Dni " << endl;
		cout << "2- Autorizados por Apellido " << endl;
		cout << endl;
		cout << "3- Residentes por Id Unidad" << endl;
		cout << "4- Residentes por Apellido" << endl;
		cout << endl;
		cout << "5- Proveedores por Razon Social " << endl;
		cout << "6- Proveedores por Cuit " << endl;
		cout << endl;
		cout << "7- Empleado por Numero Legajo" << endl;
		cout << "8- Empleado por Apellido" << endl;
		cout << endl;
		cout << "9- Unidades por Id" << endl;
		cout << endl;
		cin >> opcion;

		switch (opcion) {
		case 1: 
			AutorizadosporDni();
			break;
		case 2:
			AutorizadosporApellido();
			break;
		case 3:
			ResidentesporIdUnidad();
			break;
		case 4:
			ResidentesporApellido();
			break;
		case 5:
			ProveedoresporRazonSocial();
			break;
		case 6:
			ProveedoresporDni();
			break;
		case 7:
			EmpleadoporNroLegajo();
			break;
		case 8:
			EmpleadoporApellido();
			break;
		case 9:
			UnidadesporId();
			break;
		default:
			cout << "Opción no válida" << endl;
			break;
		}


	}
}