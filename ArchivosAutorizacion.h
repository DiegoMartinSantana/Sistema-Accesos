#pragma once
#include <cstring>
#include <iostream>
#include "ArchivosTemplate.h"
#include "Autorizaciones.h"
using namespace std;

class ArchivosAutorizacion {
	ArchivosTemplate archivosg;
	string nombre = "Autorizados.dat";
public:

	bool validarDniAut(int dni) {
		Autorizaciones autor;
		FILE* file;
		file = fopen(nombre.c_str(), "rb");

		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}

		while (fread(&autor, sizeof autor, 1, file)) {

			if (autor.getDniPersona() == dni) {
				fclose(file);
				return false;
			}
		}

		fclose(file);
		return true;
	}

	bool cargarRegistrodeAutorizacion(Autorizaciones aut) {

		string nombre = "Autorizados.dat";
		//validar existente
		bool existe = validarDniAut(aut.getDniPersona());

		FILE* file;
		file = fopen(nombre.c_str(), "ab");
		bool escribio = false;
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}
		if (existe) {
			escribio = fwrite(&aut, sizeof aut, 1, file);
		}
		else {
			fclose(file);
			return escribio;
		}
		fclose(file);
		return escribio;

	}

};