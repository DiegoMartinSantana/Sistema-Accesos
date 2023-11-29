#include <iostream>
#include <vector>
#include "ArchivosTemplate.h"
#include "ArchivosAutorizacion.h"
#include "ArchivosMovimiento.h"
#include "Gestor_Listados.h"
#include "Residente.h"
#include "Persona.h"
#include "Autorizaciones.h"
#include "Movimientos.h"
#include "Proveedor.h"
#include "Empleado.h"
#include "Unidad.h"
#include "Fecha_Hora.h"
#include "Visita.h"
#include "Utilidades.h"
using namespace std;
Utilidades ut;

void ordenarburbujeo(int* vec, int& total) {
	int aux;
	for (int x = 0;x < total;x++) {

		for (int y = 0;y < (total - 1);y++) {

			if (vec[y] > vec[y + 1]) {
				aux = vec[y + 1];
				vec[y + 1] = vec[y];
				vec[y] = aux;
			}

		}

	}
}

void burbujeocaracter(vector <string>& vec, int total) {

	string aux;
	for (int x = 0;x < total;x++) {

		for (int y = 0;y < (total - 1);y++) {

			if (toupper(vec[y][0]) > toupper(vec[y + 1][0])) { // si vec en la pos .. en su primer caracter > , compara nros ASCII en mayus para llevar orden ..
				aux = vec[y + 1];
				vec[y + 1] = vec[y];
				vec[y] = aux;
			}
		}
	}
}
string retornarapellido(int dni) {

	int tote, totprov, totr, totv;
	ArchivosTemplate archi;
	Empleado emp; Visita v; Proveedor prov; Residente r;
	Utilidades uti;
	tote = archi.contarRegistros(uti._archivoEmpleados, emp);
	totv = archi.contarRegistros(uti._archivoVisitas, v);
	totprov = archi.contarRegistros(uti._archivoProveedores, prov);
	totr = archi.contarRegistros(uti._archivoResidentes, r);

	for (int x = 0;x < tote;x++) {

		emp = archi.ObtenerObjeto(uti._archivoEmpleados, emp, x);
		if (emp.getDni() == dni && emp.getEstado()) {

			string nombreape = emp.getApellidosyNombres();
			return nombreape;
		}
	}

	for (int x = 0;x < totv;x++) {

		v = archi.ObtenerObjeto(uti._archivoVisitas, v, x);
		if (v.getDni() == dni && v.getEstado()) {

			string nombreape = v.getApellidosyNombres();
			return nombreape;
		}
	}

	for (int x = 0;x < totprov;x++) {

		prov = archi.ObtenerObjeto(uti._archivoProveedores, prov, x);
		if (prov.getDni() == dni && prov.getEstado()) {

			string nombreape = prov.getApellidosyNombres();
			return nombreape;
		}
	}
	for (int x = 0;x < totr;x++) {

		r = archi.ObtenerObjeto(uti._archivoResidentes, r, x);
		if (r.getDni() == dni && r.getEstado()) {

			string nombreape = r.getApellidosyNombres();
			return nombreape;
		}
	}
	ArchivosAutorizacion archiaut;
	int totaut = archiaut.contarRegistrosAut();
	Autorizaciones a;


}

void Gestor_Listados::UnidadesOrdenadasporApellidoFamilia() {
	system("cls");

	Unidad uni;
	ArchivosTemplate archiuni;

	int total = archiuni.contarRegistros(ut._archivoUnidades, uni);

	vector <string> vec;
	vec.resize(total); // importante. sino me da error por querer acceder a lugar inexistente.

	for (int x = 0;x < total;x++) {
		if (archiuni.ObtenerObjeto(ut._archivoUnidades, uni, x).getEstado())
			vec[x] = archiuni.ObtenerObjeto(ut._archivoUnidades, uni, x).getApellidoFamilia();
	}

	burbujeocaracter(vec, total);

	for (int x = 0;x < total;x++) {

		for (int y = 0;y < total;y++) {
			uni = archiuni.ObtenerObjeto(ut._archivoUnidades, uni, y);

			if (vec[x] == uni.getApellidoFamilia()) {
				cout << endl;

				cout << "Apellido :  " << uni.getApellidoFamilia() << endl;
				cout << "Id unidad : " << uni.getId() << endl;
				cout << "Observaciones : " << uni.getObservaciones() << endl;
				cout << "Telefono : " << uni.getNroTelefono() << endl;
				cout << endl;
			}
		}
	}
	vec.clear();
	cout << endl;
	system("pause");
}



void Gestor_Listados::AutorizadosOrdenadosporDni() {
	//capturar todo 
	system("cls");

	Autorizaciones autorizado;

	ArchivosTemplate archiauto;
	int total = archiauto.contarRegistros(ut._archivoAutorizados, autorizado);

	Utilidades u;
	int* vec = new int[total]; //guardo todo aca
	for (int x = 0;x < total;x++) {
		autorizado = archiauto.ObtenerObjeto(ut._archivoAutorizados, autorizado, x);
		if (autorizado.getEstado()) {
			if (u.validarAutorizacion(autorizado.getDniPersona())) {
				vec[x] = autorizado.getDniPersona();
			}
		}
	}
	//agrego residentes! 
	Residente resi;
	int tot = archiauto.contarRegistros(ut._archivoResidentes, resi);


	int* vec2 = new int[tot];
	for (int x = 0;x < tot;x++) {

		resi = archiauto.ObtenerObjeto(ut._archivoResidentes, resi, x);
		if (resi.getEstado()) {

			if (resi.getPropietario_Inquilino() == 2) {
				if (ut.validarAutorizacion(resi.getDni())){
					vec2[x] = resi.getDni();
				}

			}
			vec2[x] = resi.getDni();


		}
	}


	//ordenar vec .. por burbujeo
	ordenarburbujeo(vec, total);
	ordenarburbujeo(vec2, tot);
	//mostrar
	cout << endl;
	cout << endl;

	cout << "RESIDENTES :  " << endl;
	cout << endl;
	cout << endl;


	for (int x = 0;x < tot;x++) {

		for (int y = 0;y < tot;y++) {
			resi = archiauto.ObtenerObjeto(ut._archivoResidentes,resi, y); 
			if (resi.getDni() == vec2[x] && resi.getEstado()) {
				cout << endl;
				resi.mostrar();

				cout << endl;

			}
		}

	}






	cout << endl;
	cout << endl;
	cout << "NO RESIDENTES : " << endl;
	cout << endl;
	cout << endl;

	for (int x = 0;x < total;x++) { //recorro todo y a medida que encuentra muestra

		for (int y = 0;y < total;y++) {
			autorizado = archiauto.ObtenerObjeto(ut._archivoAutorizados, autorizado, y); // guarda aca en y, porque compara contra TODOS VS LA POS DEL VEC EN FOR SUPERIOR
			if (autorizado.getDniPersona() == vec[x] && autorizado.getEstado()&& u.validarAutorizacion(autorizado.getDniPersona())) {
				cout << endl;

				autorizado.mostrar();
				cout << "Posee autorizacion hasta el : " << autorizado.getHasta() << endl;
				cout << endl;

			}
		}

	}
	cout << endl;
	system("pause");
	delete[] vec;
	delete[] vec2;

}

void Gestor_Listados::ResidentesOrdenadosporIdUnidad() {
	system("cls");

	Residente res;

	ArchivosTemplate archires;

	int total = archires.contarRegistros(ut._archivoResidentes, res);

	int* vec = new int[total];
	for (int x = 0;x < total;x++) {
		res = archires.ObtenerObjeto(ut._archivoResidentes, res, x);
		if (res.getEstado()) {

			vec[x] = res.getUnidad();
		}
	}

	ordenarburbujeo(vec, total);


	for (int x = 0;x < total;x++) {


		for (int y = 0;y < total;y++) {
			res = archires.ObtenerObjeto(ut._archivoResidentes, res, y);

			if (res.getUnidad() == vec[x] && res.getEstado()) {
				cout << endl;

				res.mostrar();
				cout << endl;

			}
		}

	}
	cout << endl;
	system("pause");
	delete[]vec;

}


void Gestor_Listados::EmpleadosOrdenadosporDni() {
	system("cls");

	Empleado emp;

	ArchivosTemplate archiemp;

	int total = archiemp.contarRegistros(ut._archivoEmpleados, emp);
	
	int* vec = new int[total];
	for (int x = 0; x < total; x++) {
		emp = archiemp.ObtenerObjeto(ut._archivoEmpleados, emp, x);
		if (emp.getEstado() && ut.validarAutorizacion(emp.getDni()))
			vec[x] = emp.getDni();
	}

	ordenarburbujeo(vec, total);

	for (int x = 0;x < total;x++) {

		for (int y = 0;y < total;y++) {
			emp = archiemp.ObtenerObjeto(ut._archivoEmpleados, emp, y);

			if (emp.getDni() == vec[x] && emp.getEstado() && ut.validarAutorizacion(emp.getDni())) {
				cout << endl;
				emp.mostrar();
				cout << endl;

			}

		}

	}
	cout << endl;
	system("pause");
	delete[] vec;

}
void Gestor_Listados::UnidadesporId() {
	system("cls");

	Unidad uni;
	ArchivosTemplate archiuni;

	int total = archiuni.contarRegistros(ut._archivoUnidades, uni);

	int* vec = new int[total];
	for (int x = 0;x < total;x++) {
		if (archiuni.ObtenerObjeto(ut._archivoUnidades, uni, x).getEstado())
			vec[x] = archiuni.ObtenerObjeto(ut._archivoUnidades, uni, x).getId();

	}

	ordenarburbujeo(vec, total);

	for (int x = 0;x < total;x++) {

		for (int y = 0;y < total;y++) {
			uni = archiuni.ObtenerObjeto(ut._archivoUnidades, uni, y);

			if (vec[x] == uni.getId() && uni.getEstado()) {
				cout << endl;

				cout << "Id unidad : " << uni.getId() << endl;
				cout << "Apellido Familia : " << uni.getApellidoFamilia() << endl;
				cout << "Observaciones : " << uni.getObservaciones() << endl;
				cout << "Telefono : " << uni.getNroTelefono() << endl;
				cout << endl;

			}
		}

	}
	cout << endl;
	system("pause");
	delete[]vec;

}

void Gestor_Listados::MovimientosDiaHoy() {

	//comparo vs la fecha del sistema!
	system("cls");
	int con = 0;
	Fecha fSistema;
	Movimientos mov;
	ArchivosTemplate archi;
	int totalmov = archi.contarRegistros(ut._archivoMovimientos, mov);
	ArchivosMovimiento archimov;
	for (int x = 0;x < totalmov;x++) {
		mov = archimov.ObtenerMovimiento(x);

		if (mov.getFechayHoraMovimiento().getFecha().getAnio() == fSistema.getAnio()) {

			if (mov.getFechayHoraMovimiento().getFecha().getMes() == fSistema.getMes()) {

				if (mov.getFechayHoraMovimiento().getFecha().getDia() == fSistema.getDia()) {
					cout << endl;

					mov.mostrar();
					cout << endl;
					con++;
				}

			}
		}
	}
	if (con == 0) {
		cout << "No hay movimientos Registrados el dia de  hoy." << endl;
	}
	cout << endl;

	system("pause");

}
void Gestor_Listados::ProveedoreOrdenadosporRazonSocial() {
	system("cls");

	Proveedor prov;
	ArchivosTemplate archiprov;

	int total = archiprov.contarRegistros(ut._archivoProveedores, prov);

	vector <string> vec;
	vec.resize(total);

	for (int x = 0;x < total;x++) {
		vec[x] = archiprov.ObtenerObjeto(ut._archivoProveedores, prov, x).getEmpresa();

	}

	burbujeocaracter(vec, total);

	for (int x = 0;x < total;x++) {

		for (int y = 0;y < total;y++) {
			prov = archiprov.ObtenerObjeto(ut._archivoProveedores, prov, y);

			if (vec[x] == prov.getEmpresa() && prov.getEstado() && ut.validarAutorizacion(prov.getDni())) {
				cout << endl;
				prov.mostrar();
				cout << endl;

			}

		}
	}
	cout << endl;
	system("pause");
	vec.clear();
}
void Gestor_Listados::VisitasxDni() {

	system("cls");

	Visita v;

	ArchivosTemplate archiv;

	int total = archiv.contarRegistros(ut._archivoVisitas ,v);

	int* vec = new int[total];
	for (int x = 0; x < total; x++) {
		v = archiv.ObtenerObjeto(ut._archivoVisitas, v, x);
		if (v.getEstado() && ut.validarAutorizacion(v.getDni()))
			vec[x] = v.getDni();
	}

	ordenarburbujeo(vec, total);

	for (int x = 0;x < total;x++) {

		for (int y = 0;y < total;y++) {
			v = archiv.ObtenerObjeto(ut._archivoVisitas, v, y);

			if (v.getDni() == vec[x] && v.getEstado() && ut.validarAutorizacion(v.getDni())) {
				cout << endl;
				v.mostrar();
				cout << endl;

			}

		}

	}
	cout << endl;
	system("pause");
	delete[] vec;


}

void Gestor_Listados::Ejecutar() {
	Fecha_Hora f;

	char opcion;
	bool a = true;
	while (a) {
		system("cls");
		cout << "----------------------------------------------------------------------------------------" << endl;

		cout << "Opciones para Listar :                                               " << f.toString() << endl;
		cout << endl;
		cout << "1. Autorizados Ordenados por DNI." << endl;
		cout << endl;

		cout << "2. Residentes Ordenados por Id Unidad. " << endl;
		cout << endl;

		cout << "3. Proveedor Ordenados por Razon Social. " << endl;
		cout << endl;
		cout << "4. Empleados Ordenados por DNI. " << endl;
		cout << endl;
		cout << "5. Unidades Ordenadas por Id ( menor a mayor ). " << endl;
		cout << "6. Unidades Ordenadas por Apellido de la Familia - ALFABETICAMENTE.  " << endl;
		cout << endl;
		cout << "7. Listado de Todos los Movimientos Registrados el Dia de hoy." << endl;
		cout << endl;
		cout << "8. Listado de Visitas Ordenadas por Dni." << endl;
		cout << endl;
		cout << "0. Volver." << endl;
		cout << endl;
		cout << "Seleccione una opcion:  " << endl;
		cout << "----------------------------------------------------------------------------------------" << endl;

		cin >> opcion;

		switch (opcion) {

		case '1':
			AutorizadosOrdenadosporDni();
			break;
		case '2':
			ResidentesOrdenadosporIdUnidad();
			break;
		case '3':
			ProveedoreOrdenadosporRazonSocial();
			break;
		case '4':
			EmpleadosOrdenadosporDni();
			break;
		case '5':
			UnidadesporId();
			break;
		case '6':
			UnidadesOrdenadasporApellidoFamilia();
			break;
		case '7':
			MovimientosDiaHoy();
			break;
		case '8':
			VisitasxDni();
			break;
		case '0':
			a = false;
			return;
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
			break;
		}
	}

}
