#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class ArchivosTemplate {

		 //***cargar correctamente string de nombre, incluido su .dat , enviar un objeto STRING CON EL CONTENIDO //  ***

public:
	
	template <typename tipo>
	bool validarDni(string& nombre, tipo t, int dni) {

		FILE* file;
		file = fopen(nombre.c_str(), "rb");

		if (file == NULL) {
			return false;
		}

		while (fread(&t, sizeof t, 1, file)) {

			if (t.getDni() == dni && t.getEstado()) {
				fclose(file);
				return true;
			}
		}

		fclose(file);
		return false;
	}

	template <typename tipo>
	int contarRegistros(string& nombre, tipo t) {

		FILE* file;

		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			return -1;
		}
		fseek(file, 0, 2);


		int tam = ftell(file);
		int tamf = tam / sizeof t;

		fclose(file);
		return tamf;

	}

	template <typename tipo>
	bool Idexistenteono(string& nombre, tipo t, int id) { //validado

		FILE* file;
		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			return false;
		}
		while (fread(&t, sizeof t, 1, file)) {
			if (t.getId() == id && t.getEstado()) {
				fclose(file);
				return true;
			}
		}

		fclose(file);
		return false;
	}
	
	
	template <typename tipo>
	bool cargarRegistro(string& nombre, tipo& t) {

		int id = t.getId();
		bool existe = Idexistenteono(nombre, t, id);
		int dni = t.getDni();

		bool existeDni = validarDni(nombre, t, dni);

		bool escribio = false;
		if (!existe && !existeDni ){
			FILE* file;

		file = fopen(nombre.c_str(), "ab");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}


		escribio = fwrite(&t, sizeof t, 1, file);
		fclose(file);

	}
		return escribio;
	}
	
	template <typename tipo>
	//buscar objeto y devolver su posicion.
	int BuscarPosxId(string& nombre, tipo t, int id) {   //validado
		//valida que no se haya ingresado uno inexistente
		bool existe = Idexistenteono(nombre, t, id);
		if (!existe) {
			return -3;
		}
		FILE* file;

		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			return -1;
		}
		int con = 0;
		while (fread(&t, sizeof t, 1, file)) {
			if (t.getId() == id) {
				fclose(file);
				return con;
			}
			con++;
		}

		fclose(file);

		return -2;

	}	

	template <typename tipo>
	tipo ObtenerObjeto(string& nombre, tipo t, int pos) {  //validado

		FILE* file;
		file = fopen(nombre.c_str(), "rb");
		tipo t2 = t;
		t2.setEstado(false);


		if (file == NULL) {
			return t;
		}

		fseek(file, sizeof t * pos, 0);

		fread(&t, sizeof t, 1, file);
		
		fclose(file);
		
		if (t.getEstado()) {
			return t;
		}
		else {
			return t2;
		}
	}

	template <typename tipo>
	void LeerMetodoMostrar(string& nombre, tipo& t) { //validado
		FILE* file;

		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return;
		}

		while (fread(&t, sizeof t, 1, file)) {
			if (t.getEstado()) {
				t.mostrar();   
			}
		}
		fclose(file);
	}
	
	template <typename tipo>
	void LeerMetodoMostrarPersona(string& nombre, tipo& t) { //validado
		FILE* file;

		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			return;
		}

		while (fread(&t, sizeof t, 1, file)) {
			if (t.getEstado()) {
				t.mostrarPersona();   //TODAS CLASES  MISMO METODO MOSTRAR, QUE DIRECTAMENTE HAGA EL COUT,asi puede funcionar el template!
			}
		}
		fclose(file);
	}
	
	template <typename tipo>
	bool Bajalogica(string& nombre, tipo t, int id) { //validado

		int pos = BuscarPosxId(nombre, t, id); //uso la posicion . que obtengo a traves de su id.

		FILE* f;
		f = fopen(nombre.c_str(), "rb+");
		if (f == NULL) {

			return false;

		}
		fseek(f, sizeof t * pos, 0);
		t.setEstado(false);

		bool escribio = fwrite(&t, sizeof t, 1, f);

		fclose(f);
		return escribio;
	}

	template <typename tipo>
	tipo obtenerObjetoxDni(string& nombre, tipo t, int dni) {
		FILE* file;
		t.setEstado(false);
		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			return t;
		}

		int tot = contarRegistros(nombre, t);

		for (int x = 0;x < tot;x++) {

			t = ObtenerObjeto(nombre, t, x);
			if (t.getEstado() == true) {
				if (t.getDni() == dni) {
					fclose(file);
					return t;
				}
			}
		}

		fclose(file);
		return t;

	}

	template <typename tipo>
	int PosxDni(string& nombre, tipo t, int dni) {
		int tot = contarRegistros(nombre, t);

		for (int x = 0;x < tot;x++) {
			t = ObtenerObjeto(nombre, t, x);
			if (t.getDni() == dni && t.getEstado()) {
				return x;
			}
		}

		return -1;
	}
	
	template <typename tipo>
	bool BajalogicaxDni(string& nombre, tipo& t, int dni) {

		int pos = PosxDni(nombre, t, dni);
		t = ObtenerObjeto(nombre, t, pos);

		FILE* f;
		f = fopen(nombre.c_str(), "rb+");
		if (f == NULL) {
			return false;
		}
		fseek(f, (sizeof t * pos), 0);
		t.setEstado(false);

		bool escribio = fwrite(&t, sizeof t, 1, f);

		fclose(f);
		return escribio;

	}

	template <typename tipo>
	void copiaSeguridad(string& nombreoriginal, string& nombrebak, tipo& t) {
		FILE* file;
		file = fopen(nombreoriginal.c_str(), "rb");//leo
		if (file == NULL) {
			return;
		}
		FILE* filebak;
		filebak = fopen(nombrebak.c_str(), "wb"); //guardo
		if (filebak == NULL) {
			fclose(file);
			return;
		}

		while (fread(&t, sizeof t, 1, file)) {

			fwrite(&t, sizeof t, 1, filebak);

		}


		fclose(file);
		fclose(filebak);
	}
	
	
	template <typename tipo>
	void vaciarOriginal(string& nombreori, tipo t) {
		FILE* file;
		file = fopen(nombreori.c_str(), "rb+");
		while (fread(&t, sizeof t, 1, file)) {
			t.setEstado(false);
			fwrite(&t, sizeof t, 1, file);
		}
		fclose(file);
	}
	template <typename tipo>

	bool cargarUnidad(string& nombre, tipo& t) {
		int id = t.getId();
		bool existe = Idexistenteono(nombre, t, id);

		bool escribio = false;
		FILE* file;
		file = fopen(nombre.c_str(), "ab");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}


		escribio = fwrite(&t, sizeof t, 1, file);

		fclose(file);
		return escribio;

	}
	


	template <typename tipo>
	bool restaurarCopiaSeguridad(string& nombrebak, string& nombreoriginal, tipo& t) {

		// ABRO RB EL BAK

		FILE* filebak;
		filebak = fopen(nombrebak.c_str(), "rb");
		if (filebak == NULL) {
			return false;
		}
		int totalbak = contarRegistros(nombrebak, t);

		// ABRO WB EL ORIGINAL
		FILE* fileoriginal;
		fileoriginal = fopen(nombreoriginal.c_str(), "wb");
		if (fileoriginal == NULL) {
			fclose(filebak);
			return false;
		}

		//vacio archivo original
		 // pongo todo el original en false
		vaciarOriginal(nombreoriginal, t);

		// COPIO EN EL ORIGINAL TODO ,NO IMPORTA TRUE O FALSE
		int con = 0;
		for (int x = 0;x < totalbak;x++) {

			t = ObtenerObjeto(nombrebak, t, x); //solo devuelve los true!
			 
				bool escribe = fwrite(&t, sizeof t, 1, fileoriginal); //yo despues muestro en true las cosas.
				if (escribe) {
					con++;
				}
		}

		//Y LISTO
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
