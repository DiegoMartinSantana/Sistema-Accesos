#pragma once
#include <string>
#include <iostream>
#include "Unidad.h"
class ArchivosUnidades{
public:
//LEER REGISTRO DEVUELVE OBJETO SEGUN UNA POS
Unidad  obtenerRegistro(int pos) {
	FILE* file;

	file = fopen(_nombre.c_str(), "rb");

	if (file == NULL) {
		std::cout << "Error apertura archivo Unidades " << std::endl;
		return;

	}
	Unidad uni;
	fseek(file, sizeof uni * pos, 0); 

	fread(&uni, sizeof uni, 1, file); 

	fclose(file);

	return uni;


}

int contarRegistros() {

	FILE* file;

	file = fopen(_nombre.c_str(), "rb");
	if (file == NULL) {
		std::cout << "Error apertura archivo Unidades " << std::endl;
		return -1;
	}
	fseek(file, 0, 2); 
	int tam = ftell(file); 
	return tam / sizeof(Unidad);
	fclose(file);


}



bool escribirRegistro(const Unidad& uni) {

	FILE* file;

	file = fopen(_nombre.c_str(), "ab");
	if (file == NULL) {
		std::cout << "Error apertura archivo Unidades " << std::endl;
		return false;
	}
	bool escribio = fwrite(&uni, sizeof uni, 1, file);
	fclose(file);
	return escribio;
}


private:
	std::string _nombre = "Unidades.dat";
};