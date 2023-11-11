#include <iostream>
#include <cstring>
#include <string>
#include "Empresa.h"
#include "Utilidades.h"
using namespace std;
void Empresa::setEstado(bool estado)
{
	_estado = estado;

}
bool Empresa::getEstado() {
	return _estado;
}
void Empresa::setId(int id) {
	_id = id;
}
int Empresa::getId() {
	return _id;

}
int Empresa::getCuit() const {

	return _cuit;
}
string  Empresa::getRazonSocial() {
	string retornar = _razonSocial;
	return retornar;
}
string Empresa::getDescripcion() {
	string retornar = _descripcion;
	return retornar;
}

void Empresa::setCuit(int cuit) {
	_cuit = cuit;
}
void Empresa::setRazonSocial(string razonSocial) {
	strcpy(_razonSocial, razonSocial.c_str());
}
void Empresa::setDescripcion(string descripcion) {
	strcpy(_descripcion, descripcion.c_str());


}
		
bool Empresa::validarrazonsocial(string razon) {
	FILE* fileempresa;
	Empresa empre;
	fileempresa = fopen("Empresas.dat", "rb");


	if (fileempresa == NULL) {
		cout << "No se pudo abrir el archivo Empresas" << endl;
		return false;
	}

	while (fread(&empre, sizeof empre, 1, fileempresa)) {
		if (strcmp(empre.getRazonSocial().c_str(), razon.c_str()) == 0) {
			fclose(fileempresa);

			return false;

		}
	}
	return true;
	fclose(fileempresa);

}
void Empresa::cargar() {
	string razon, descripcion;
	int cuit;
	Utilidades util;
	cout << "Ingrese Nro de cuit de la Empresa " << endl;
	cin >> cuit;
	util.validarInt(cuit);
	setCuit(cuit);
	cin.ignore();

	cout << "Ingrese razon social de la misma " << endl;
	getline(cin, razon);
	
	setRazonSocial(razon);

	cout << "Ingrese una breve descripcion de la empresa" << endl;
	getline(cin, descripcion);
	setDescripcion(descripcion);



}

string Empresa::mostrarempresastring() {
	string retornar;
	retornar = " Cuit : " + to_string(_cuit) + "\n" + " Razon Social : " + getRazonSocial() + "\n" + " Descripcion : " + getDescripcion();

	return retornar;
}
void Empresa::mostrar() {
	cout << " Cuit : " << to_string(_cuit) << endl;
	cout << " Razon Social : " << getRazonSocial() << endl;
	cout << " Descripcion : " << getDescripcion() << endl;

}
