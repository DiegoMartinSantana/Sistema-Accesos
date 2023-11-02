#pragma once
#include <string>
#include <iostream>
#include "Movimientos.h"
 class ArchivosMovimientos {
	public :	

	//LEER REGISTRO DEVUELVE OBJETO SEGUN UNA POS
	Movimientos  obtenerRegistro(int pos) {
		FILE* file;

		file = fopen(_nombre.c_str(), "rb");

		if (file == NULL) {
			std::cout << "Error apertura archivo movimientos " << std::endl;
			return; //posible devolver un movimiento estado false. mejor no hacer ninguna carga para evitar cargas dañadas.

		}
		Movimientos mov;
		fseek(file, sizeof mov*pos,0); // ubico desde el inicio en el valor en bytes del mov * su pos
		
		fread(&mov, sizeof mov, 1, file); //lee en dicha pos

		fclose(file);

		return mov;


	}

	int contarRegistros() {

		FILE *file;

		file = fopen(_nombre.c_str(), "rb");
		if (file == NULL) {
			std::cout << "Error apertura archivo movimientos " << std::endl;
			return -1; 
		}
		fseek(file, 0, 2); //posicion el archivo al final! para obtener todo el tam.
		int tam = ftell(file); //FTELL DEVUELVE EL VALOR EN BYTES HASTA DONDE ESTA UBICADO EL ARCHIVO
		return tam / sizeof(Movimientos);
		fclose(file);


	}

//BOOL REGISTROGRABAR

	bool escribirRegistro(const Movimientos& mov) {

		FILE* file;

		file = fopen(_nombre.c_str(), "ab");
		if (file == NULL) {
			std::cout << "Error apertura archivo movimientos " << std::endl;
			return false;
		}
		bool escribio = fwrite(&mov, sizeof mov, 1, file);
		fclose(file);
		return escribio;
	}


private :
	std::string _nombre = "Movimientos.dat";
};
