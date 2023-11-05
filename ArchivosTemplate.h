#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class ArchivosTemplate {

	//funciones genericas de archivos que no impliquen manipular sus propiedades a no ser que sean COMUNES A TODAS  van aca.
		 //***cargar correctamente string de nombre, incluido su .dat , enviar un objeto STRING CON EL CONTENIDO //  ***


public:
	template <typename tipo>

	int contarRegistros(string& nombre,tipo &t) {

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
	bool Idexistenteono(string& nombre, tipo& t, int id) { //validado

		FILE* file;
		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}
		while (fread(&t, sizeof t, 1, file)) {
			if (t.getId() == id) {
				return true;
			}
		}
		fclose(file);
		return false;
	}
	template <typename tipo>

	bool cargarRegistrodeMovimiento( tipo t) { //validado

		string nombre = "Movimientos.dat";


		FILE* file;
		file = fopen(nombre.c_str(), "ab");
		fseek(file, 0, SEEK_END);
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}
		bool escribio = fwrite(&t, sizeof t, 1, file);

		fclose(file);
		return escribio;
	}
	template <typename tipo>

	
	bool cargarRegistro(string& nombre, tipo t) { //validado


			
		
		FILE* file;
		file = fopen(nombre.c_str(), "ab");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}
		bool escribio = fwrite(&t, sizeof t, 1, file);

		fclose(file);
		return escribio;
	}
	template <typename tipo>

	//buscar objeto y devolver su posicion.
	int BuscarPosxId(string& nombre, tipo& t, int id) {   //validado
		//valida que no se haya ingresado uno inexistente
		bool existe = Idexistenteono(nombre, t, id);
		if (!existe) {
			cout << "Id ingresado inexistente. Ingrese otro porfavor." << endl;
			return -3;
		}
		FILE* file;

		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
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
		cout << "Se abrio pero ocurrio otro tipo de error." << endl;

		return -2;

	}
	template <typename tipo>

	
	tipo ObtenerObjeto(string& nombre, tipo& t, int pos) {  //validado

		//posible validacion que la posicion no sea inexistente. diviendo el total de archivos por el tamaño..

		FILE* file;
		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			tipo t2 = t;

			t2.setEstado(false);

			return t2;
		}
		fseek(file, sizeof t * pos, 0);
		fread(&t, sizeof t, 1, file);

		fclose(file);

		return t;
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
			t.mostrar();   //TODAS CLASES  MISMO METODO MOSTRAR, QUE DIRECTAMENTE HAGA EL COUT,asi puede funcionar el template!

		}
		fclose(file);
	}
	template <typename tipo>

	void LeerMetodoMostrarPersona(string& nombre, tipo& t) { //validado
		FILE* file;

		file = fopen(nombre.c_str(), "rb");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return;
		}

		while (fread(&t, sizeof t, 1, file)) {
			t.mostrarPersona();   //TODAS CLASES  MISMO METODO MOSTRAR, QUE DIRECTAMENTE HAGA EL COUT,asi puede funcionar el template!

		}
		fclose(file);
	}
	template <typename tipo>

	bool Bajalogica(string& nombre, tipo& t, int id) { //validado

		bool existe = Idexistenteono(nombre, t, id);
		if (!existe) {
			cout << "Id ingresado inexistente. Ingrese otro porfavor." << endl;
			return false;
		}
		int pos = BuscarPosxId(nombre, t, id); //uso la posicion . que obtengo a traves de su id.
		tipo aux = ObtenerObjeto(nombre, t, pos); // retorno el objeto a traves de su posicion.

		FILE* f;
		f = fopen(nombre.c_str(), "rb+");
		if (f == NULL) {

			return false;

		}
		fseek(f, (sizeof aux * pos), 0);
		aux.setEstado(false);
		bool escribio = fwrite(&aux, sizeof aux, 1, f);

		fclose(f);
		return escribio;
	}


};
