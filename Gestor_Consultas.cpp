#include <iostream>
#include <vector>
#include <string>
#include "Gestor_Consultas.h"
#include "Persona.h"
#include "Autorizaciones.h"
#include "Residente.h"
#include "Proveedor.h"
#include "Empleado.h"
#include "Empresa.h" 
#include "Unidad.h"

using namespace std;

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
	FILE* fileempresa;
	Empresa empre;
	fileempresa = fopen("Empresas.dat", "rb");


	if (fileempresa == NULL) {
		cout << "No se pudo abrir el archivo Empresas" << endl;
		return false;
	}

	//uso biblioteca vector.
	bool a = true;
	int con = 0;
	while (fread(&empre, sizeof empre, 1, fileempresa)) {

		if (a) {
			vec[con] = (empre.getRazonSocial()); // push back añade.. pero asi llevo mejor control yo.
			a = false;
		}
		else {
			//compara con todas aca.
			if (comparar(empre.getRazonSocial(), vec)) {
				vec[con] = (empre.getRazonSocial());
			}
		}
		con++;

	}

	fclose(fileempresa);
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

	Autorizaciones autorizado(0,0);
	FILE* file;
	file = fopen(_archivoAutorizados.c_str(), "rb");
	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;
	}
	while (fread(&autorizado, sizeof autorizado, 1, file)) {

		if (autorizado.getDniPersona() == dni) {
			autorizado.mostrar();
			fclose(file);
			return;
		}

	}
	cout << "No se ha encontrado ninguna Persona Autorizada junto a ese Dni" << endl;


	fclose(file);
	
}
void Gestor_Consultas::AutorizadosporApellido() {
	string apellido;
	cin.ignore();
	cout << "Ingrese Apellido " << endl;
	getline(cin, apellido);

	Autorizaciones autorizado(0,0);
	FILE* file;
	file = fopen(_archivoAutorizados.c_str(), "rb");
	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;
	}
	while (fread(&autorizado, sizeof autorizado, 1, file)) {

		int igual = strcmp(apellido.c_str(), autorizado.getApellido().c_str());
		if (igual == 0) {
			autorizado.mostrar();
			fclose(file);
			return;
		}

	}
	cout << "No se ha encontrado ninguna Persona Autorizada con ese apellido" << endl;




	fclose(file);


}
void Gestor_Consultas::ResidentesporIdUnidad() {

	int id;
	cout << "Ingrese Id Unidad " << endl;
	cin >> id;

	Residente res;
	FILE* file;
	file = fopen(_archivoResidentes.c_str(), "rb");
	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;
	}
	bool a = false;
	while (fread(&res, sizeof res, 1, file)) {

		if (res.getUnidad() == id) {
			a = true;
			res.mostrar();
		}

	}
	if (!a) {
		cout << "No se ha encontrado ningun residente junto a ese id " << endl;
	}

	fclose(file);

}
void Gestor_Consultas::ResidentesporApellido() {
	string apellido;
	cin.ignore();
	cout << "Ingrese Apellido " << endl;
	getline(cin, apellido);

	Residente res;
	FILE* file;
	file = fopen(_archivoResidentes.c_str(), "rb");
	if (file == NULL) {
		cout << "No se pudo abrir el archivo" << endl;
		return;
	}
	bool a = false;

	while (fread(&res, sizeof res, 1, file)) {
		int igual = strcmp(apellido.c_str(), res.getApellidos().c_str());
		if (igual == 0) {
			res.mostrar();
			fclose(file);
			a = true;
		}


	}
	if (!a) {
		cout << "No se ha encontrado ningun residente con ese apellido" << endl;
	}

	fclose(file);

}
void Gestor_Consultas::ProveedoresporRazonSocial() {
	


	//mostrar razones sociales existentes
	//1 
	vector <string > vec;
	int opc = mostrarrazonessociales(vec); // ahora esta cargado el vector y se que razon social trabajar!

 // realziar busqueda 
	//2
	FILE* fileprov;
	Proveedor prov;
	fileprov = fopen(_archivoProveedores.c_str(), "rb");


	if (fileprov == NULL) {
		cout << "No se pudo abrir el archivo proveedores" << endl;
		return;
	}
	bool a = true;
	while (fread(&prov, sizeof prov, 1, fileprov)) {

		if(strcmp(vec[opc].c_str(), prov.getEmpresa().c_str()) == 0){
			prov.mostrar();
			a = false;
		}
	}
	if (a) { cout << "No hay ningun proveedor con esa razon social " << endl; }
	fclose(fileprov);

}

void Gestor_Consultas::ProveedoresporCuit() {
	int dni;
	cout << "Ingrese Dni " << endl;
	cin >> dni;

	FILE* fileprov;
	Proveedor prov;
	fileprov = fopen(_archivoProveedores.c_str(), "rb");


	if (fileprov == NULL) {
		cout << "No se pudo abrir el archivo proveedores" << endl;
		return;
	}

	while (fread(&prov, sizeof prov, 1, fileprov)) {
		if (prov.getDni()==dni) {
			prov.mostrar();
			fclose(fileprov);
			return;
		}
	}
	cout << "No se ha encontrado ningun proveedor con dicho Dni" << endl;
	fclose(fileprov);
}
void Gestor_Consultas::EmpleadoporNroLegajo() {
	int nrolegajo;
	cout << "Ingrese Numero de Legajo " << endl;
	cin >> nrolegajo;
	FILE* file;
	file = fopen(_archivoEmpleados.c_str(), "rb");
	if (file == NULL) {
		cout << "No se abrio archivo Empleados" << endl;
		return;
	}
	Empleado emp;
	while(fread(&emp,sizeof emp,1,file)){
		if (emp.getLegajo()==nrolegajo) {
			emp.mostrar();
			fclose(file);
			return;

		}
	}
	cout << "No existe ningun empleado con ese numero de legajo " << endl;
	fclose(file);
	return;
	
}
void Gestor_Consultas::EmpleadoporApellido() {
	
	string apellido;
	cin.ignore();
	cout << "Ingrese Apellido " << endl;
	getline(cin, apellido);

	FILE* file;
	file = fopen(_archivoEmpleados.c_str(), "rb");
	if (file == NULL) {
		cout << "No se abrio archivo Empleados" << endl;
		return;
	}
	Empleado emp;
	while (fread(&emp, sizeof emp, 1, file)) {
		
		if (strcmp(apellido.c_str(),emp.getApellidos().c_str()) == 0) {
			emp.mostrar();
		}
	}
	

	fclose(file);
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
			ProveedoresporCuit();
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