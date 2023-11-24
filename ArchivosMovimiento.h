#pragma once
#include <cstring>
#include <iostream>
#include "ArchivosTemplate.h"
#include "Movimientos.h"
using namespace std;

class ArchivosMovimiento
{
	ArchivosTemplate archivosg;
	Movimientos mov;
	string nombre = "Movimientos.dat";
	string insertar = "Dar Baja";

public:

	bool cargarRegistrodeMovimiento(Movimientos movi) {

		FILE* file;
		file = fopen(nombre.c_str(), "ab");
		fseek(file, 0, SEEK_END);
		if (file == NULL) {
			return false;
		}
		bool escribio = fwrite(&movi, sizeof movi, 1, file);

		fclose(file);
		return escribio;
	}

	Movimientos  ObtenerMovimiento(int pos) {

		FILE* file;
		file = fopen(nombre.c_str(), "rb");
		mov.setObservaciones(insertar);


		if (file == NULL) {
			return mov;
		}
		fseek(file, sizeof mov * pos, 0);
		fread(&mov, sizeof mov, 1, file);
		fclose(file);

		if (strcmp(mov.getObservaciones().c_str(), insertar.c_str()) == 0) {
			mov.setObservaciones(insertar);

			return mov;
		}
		return mov;

	}

	void vaciarOriginalMovimiento() {
		FILE* file;
		file = fopen(nombre.c_str(), "rb+");
		while (fread(&mov, sizeof mov, 1, file)) {
			mov.setObservaciones(insertar); // reemplazo
			fwrite(&mov, sizeof mov, 1, file);
		}
		fclose(file);
	}
	void copiaSeguridadMovimiento(string& nombrebak) {
		FILE* file;
		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			return;
		}
		FILE* filebak;
		filebak = fopen(nombrebak.c_str(), "wb");
		if (filebak == NULL) {
			fclose(file);

			return;
		}

		while (fread(&mov, sizeof mov, 1, file)) {

			fwrite(&mov, sizeof mov, 1, filebak);

		}


		fclose(file);
		fclose(filebak);
	}
	bool restaurarCopiaSeguridadMovimiento(string& nombrebak) {

		FILE* filebak;
		filebak = fopen(nombrebak.c_str(), "rb");
		if (filebak == NULL) {
			return false;
		}
		int totalbak = archivosg.contarRegistros(nombrebak, mov);

		FILE* fileoriginal;
		fileoriginal = fopen(nombre.c_str(), "wb");
		if (fileoriginal == NULL) {
			fclose(filebak);
			return false;
		}
		//pone todo en false
		vaciarOriginalMovimiento();
		int con = 0;
		for (int x = 0;x < totalbak;x++) {

			mov = ObtenerMovimiento(x);
			if (strcmp(mov.getObservaciones().c_str(), insertar.c_str()) != 0) { //si es distinto de dar de baja guardo
				bool escribio = fwrite(&mov, sizeof mov, 1, fileoriginal);
				if (escribio) {
					con++;
				}
			}
		}

		fclose(filebak);
		fclose(fileoriginal);
		if (con == totalbak) {
			return true;
		}
		else {
			return false;
		}
	}

};

