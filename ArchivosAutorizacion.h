#pragma once
#include <cstring>
#include <iostream>
#include "ArchivosTemplate.h"
#include "Autorizaciones.h"
#include "Utilidades.h"
using namespace std;

class ArchivosAutorizacion {
	ArchivosTemplate archivosg;
	string nombre = "Autorizados.dat";
	Utilidades ut;
public:
	Autorizaciones obtenerAutorizacion(int pos = -1) {
		Autorizaciones aut;
		FILE* file;
		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			 aut.setEstado(false);

			return aut;

		}
		
		if (pos != -1) {
			//busco por pos si es disnto de -1
			int con = 0;
			while (fread(&aut, sizeof aut, 1, file)) {

				if (aut.getEstado() && ut.validarAutorizacion(aut.getDniPersona())) {
					if (con == pos) {

						fclose(file);
						return aut;
					}
				}
				con++;// validar aca con utilidades el hasta!
			}


			fclose(file);

			return aut;

		}

	}
	int contarRegistrosAut() {
		Autorizaciones aut;
		FILE* file;

		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			return -1;
		}
		int con = 0;
		while (fread(&aut, sizeof aut, 1, file)) {
			if (aut.getEstado() && ut.validarAutorizacion(aut.getDniPersona())) {
				con++;
			}
		}



		fclose(file);
		return con;
	}
	int posxDniaut(int dni) {
		int tot = contarRegistrosAut();
		Autorizaciones t;
		for (int x = 0;x < tot;x++) {
			t = obtenerAutorizacion(x);
			if (t.getDniPersona() == dni && t.getEstado()) {
				return x;
			}
		}

		return -1;

	}
	bool bajaLogicaAut(int dni) {
		Autorizaciones ar;
	

		FILE* f;
		f = fopen(nombre.c_str(), "rb+");
		if (f == NULL) {

			return false;

		}
		//busco el dni
		Autorizaciones a;
		int pos = posxDniaut(dni);
		a =obtenerAutorizacion(pos);

		fseek(f, (sizeof a * pos), 0);

		a.setEstado(false);

		bool escribio = fwrite(&a, sizeof a, 1, f);

		fclose(f);
		return escribio;

	}
	bool validarDniAut(int dni) {
		Autorizaciones autor;
		FILE* file;
		file = fopen(nombre.c_str(), "rb");

		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}

		while (fread(&autor, sizeof autor, 1, file)) {

			if (autor.getDniPersona() == dni && autor.getEstado()) {
				fclose(file);
				return false;
			}
		}

		fclose(file);
		return true;
	}

	bool cargarRegistrodeAutorizacion(Autorizaciones aut) {

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