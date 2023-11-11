#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class ArchivosTemplate {

	//funciones genericas de archivos que no impliquen manipular sus propiedades a no ser que sean COMUNES A TODAS  van aca.
		 //***cargar correctamente string de nombre, incluido su .dat , enviar un objeto STRING CON EL CONTENIDO //  ***

public:
	string insertar = "Dar Baja";

	template <typename tipo>
	bool validarDni(string& nombre, tipo& t, int dni) {

		FILE* file;
		file = fopen(nombre.c_str(), "rb");

		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}

		while (fread(&t, sizeof t, 1, file)) {

			if (t.getDni() == dni) {
				fclose(file);
				return false;
			}
		}

		fclose(file);
		return true;
	}

	template <typename tipo>
	int contarRegistros(string& nombre, tipo& t) {

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
				fclose(file);
				return true;
			}
		}
		fclose(file);
		return false;
	}
	
	template <typename tipo>
	bool cargarRegistrodeMovimiento(tipo t) { //validado

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
	bool validarDniAut(string &nombre , tipo &t,int dni) {

		FILE* file;
		file = fopen(nombre.c_str(), "rb");
		
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}

		while (fread(&t, sizeof t, 1, file)) {

			if (t.getDniPersona() == dni) {
				fclose(file);
				return false;
			}
		}

		fclose(file);
		return true;
	}
	
	template <typename tipo>
	bool cargarRegistrodeAutorizacion(tipo& t) {

		string nombre = "Autorizaciones.dat";
		//validar existente
		bool existe = validarDniAut(nombre,t,t.getDniPersona());

		FILE* file;
		file = fopen(nombre.c_str(), "ab");
		bool escribio = false;
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}
		if (existe) {
			escribio = fwrite(&t, sizeof t, 1, file);
		}
		else {
			fclose(file);
			return escribio;
		}
		fclose(file);
		return escribio;

	}

	template <typename tipo>
	bool cargarRegistro(string& nombre, tipo t) {
		int id = t.getId();
		bool existe = Idexistenteono(nombre, t, id);
		int dni = t.getDni();
		bool existeDni = validarDni(nombre, t, dni);

		bool escribio = false;
		FILE* file;
		file = fopen(nombre.c_str(), "ab");
		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return false;
		}
		if (!existe && !existeDni) {
			 escribio = fwrite(&t, sizeof t, 1, file);
		}
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
	tipo ObtenerMovimiento(string& nombre, tipo& t, int pos) {  //validado

		FILE* file;
		file = fopen(nombre.c_str(), "rb");
		t.setObservaciones(insertar);


		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;
			return t;
		}
		fseek(file, sizeof t * pos, 0);
		fread(&t, sizeof t, 1, file);
		fclose(file);

		if (strcmp(t.getObservaciones().c_str(), insertar.c_str()) != 0) {
			return t;
		}
		else {
			t.setObservaciones(insertar);
			return t;
		}

	}

	template <typename tipo>
	tipo ObtenerObjeto(string& nombre, tipo& t, int pos) {  //validado

		FILE* file;
		file = fopen(nombre.c_str(), "rb");
		tipo t2 = t;

		if (file == NULL) {
			cout << "No se pudo abrir el archivo" << endl;

			t2.setEstado(false);

			return t2;
		}
		fseek(file, sizeof t * pos, 0);
		fread(&t, sizeof t, 1, file);

		fclose(file);
		if (t.getEstado()) {
			return t;
		}
		else {
			t2.setEstado(false);

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
				t.mostrar();   //TODAS CLASES  MISMO METODO MOSTRAR, QUE DIRECTAMENTE HAGA EL COUT,asi puede funcionar el template!
			}
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
			if (t.getEstado()) {
				t.mostrarPersona();   //TODAS CLASES  MISMO METODO MOSTRAR, QUE DIRECTAMENTE HAGA EL COUT,asi puede funcionar el template!
			}
		}
		fclose(file);
	}
	
	template <typename tipo>
	bool Bajalogica(string& nombre, tipo& t, int id) { //validado

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

	template <typename tipo>
	tipo obtenerObjetoxDni(string& nombre, tipo& t, int dni) {
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
		t.setEstado(false);

		fclose(file);
		return t;

	}

	template <typename tipo>
	int PosxDni(string& nombre, tipo t, int dni) {
		int tot = contarRegistros(nombre, t);

		for (int x = 0;x < tot;x++) {
			t = ObtenerObjeto(nombre, t, x);
			if (t.getDniPersona() == dni) {
				return x;
			}
		}
		return -1;
	}
	
	template <typename tipo>
	bool BajalogicaxDni(string& nombre, tipo& t, int dni) {

		int pos = PosxDni(nombre, t, dni);
		tipo aux = ObtenerObjeto(nombre, t, pos);

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

	template <typename tipo>
	bool copiaSeguridad(string& nombreoriginal, string& nombrebak, tipo& t) {
		FILE* file;
		file = fopen(nombreoriginal.c_str(), "rb");
		if (file == NULL) {
			return false;
		}
		FILE* filebak;
		filebak = fopen(nombrebak.c_str(), "ab");
		if (filebak == NULL) {
			fclose(file);
			return false;
		}
		//leo primero el original
		int con = 0;
		int totorigi = contarRegistros(nombreoriginal, t);
		for (int x = 0;x < totorigi;x++) {
			t = ObtenerObjeto(nombreoriginal, t, x);
			//copio todo en el bak lo true
			if (t.getEstado() == true) {
				if (fwrite(&t, sizeof t, 1, filebak)) {
					con++;
				}
			}
		}
		//si cuento tantos como se copio, sta ok la carga

		if (con == totorigi) {
			fclose(file);
			fclose(filebak);
			return true;
		}

		return false;

		fclose(file);
		fclose(filebak);
	}
	
	template <typename tipo>
	bool copiaSeguridadMovimiento(string& nombreoriginal, string& nombrebak, tipo& t) {
		FILE* file;
		file = fopen(nombreoriginal.c_str(), "rb");
		if (file == NULL) {
			return false;
		}
		FILE* filebak;
		filebak = fopen(nombrebak.c_str(), "ab");
		if (filebak == NULL) {
			fclose(file);

			return false;
		}
		//leo primero el original
		int con = 0;
		int totorigi = contarRegistros(nombreoriginal, t);
		for (int x = 0;x < totorigi;x++) {
			t = ObtenerMovimiento(nombreoriginal, t, x);
			//copio todo en el bak
			if (fwrite(&t, sizeof t, 1, filebak)) {
				con++;
			}
		}
		//si cuento tantos como se copio, esta ok la carga

		if (con == totorigi) {
			fclose(file);
			fclose(filebak);
			return true;
		}

		return false;

		fclose(file);
		fclose(filebak);
	}

	template <typename tipo>
	void vaciarOriginal(string& nombreori, tipo& t) {
		FILE* file;
		file = fopen(nombreori.c_str(), "rb+");
		while (fread(&t, sizeof t, 1, file)) {
			t.setEstado(false);
			fwrite(&t, sizeof t, 1, file);
		}
		fclose(file);
	}

	template <typename tipo>
	void vaciarOriginalMovimiento(string& nombreori, tipo& t) {
		FILE* file;
		file = fopen(nombreori.c_str(), "rb+");
		while (fread(&t, sizeof t, 1, file)) {
			t.setObservaciones(insertar); // reemplazo
			fwrite(&t, sizeof t, 1, file);
		}
		fclose(file);
	}
	
	template <typename tipo>
	bool restaurarCopiaSeguridadMovimiento(string& nombrebak, string& nombreoriginal, tipo& t) {
		//podria contar cuantos archivos tiene el bak, a partir de ahi 
		// dar de baja todo el original enalguna prop identificativa
		// y copiar todo lo que este de forma normal
		// pero como muestro despues
		// despues al mostrar digo que esa prop identificativa no exista.
		// TENGO QUE PERMITIR LA EXISTENCIA DE ESE TIPIO DE DATO INVALIDO

		FILE* filebak;
		filebak = fopen(nombrebak.c_str(), "rb");
		if (filebak == NULL) {
			return false;
		}
		int totalbak = contarRegistros(nombrebak, t);

		FILE* fileoriginal;
		fileoriginal = fopen(nombreoriginal.c_str(), "wb");
		if (fileoriginal == NULL) {
			fclose(filebak);
			return false;
		}

		vaciarOriginalMovimiento(nombreoriginal, t);
		int con = 0;
		for (int x = 0;x < totalbak;x++) {

			t = ObtenerMovimiento(nombrebak, t, x);
			if (strcmp(t.getObservaciones().c_str(), insertar.c_str()) != 0) { //si es distinto de dar de baja guardo
				bool escribio = fwrite(&t, sizeof t, 1, fileoriginal);
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
		vaciarOriginal(nombreoriginal, t); // pongo todo el original en false


		// COPIO EN EL ORIGINAL TODO ,NO IMPORTA TRUE O FALSE
		int con = 0;
		for (int x = 0;x < totalbak;x++) {

			t = ObtenerObjeto(nombrebak, t, x);
			if (t.getEstado() == true) {
				bool escribe = fwrite(&t, sizeof t, 1, fileoriginal); //yo despues muestro en true las cosas.
				if (escribe) {
					con++;
				}
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
