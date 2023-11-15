#include "Gestion_General.h"
#include "ArchivosTemplate.h"
#include "Fecha.h"
#include "Autorizaciones.h"
#include "Movimientos.h"
#include "Visita.h"
#include "Empleado.h"
#include "Residente.h"
#include "Proveedor.h"
#include "Utilidades.h"
#include "Unidad.h"
using namespace std;

Utilidades u;
ArchivosTemplate archi;
bool validarInt(int a) {


	return false;
}
int mes, anio;
bool insertarPersona(int id, int dni, Fecha f, bool estado, string apellido, string nombre) {

	Persona p(id, dni, f, estado, apellido, nombre);
	string nombrearchi = "Personas.dat";
	bool a = archi.cargarRegistro(nombrearchi, p);
	return a;
}
void pedirhasta(int& dia, int& mes) {
	Utilidades util;
	cout << "Ingrese hasta que mes esta autorizado (1-12) " << endl;
	cin >> mes;
	util.validarInt(mes);
	util.validarMes(mes);

	cout << "Ingrese hasta que Anio esta autorizado (A partir de 2023)  " << endl;
	cin >> anio;
	util.validarInt(anio);
	while (anio <= 2022 || anio > 2300) {
		cout << "Anio invalido , ingrese nuevamente" << endl;
		cin >> anio;
		util.validarInt(anio);
	}

}
void Gestion_General::altaEntrada_Salida() {
	//Sobre uno ya existente
	//validacion de eso
	system("cls");
	Movimientos movi;
	movi.cargar();
	bool a = archi.cargarRegistrodeMovimiento(movi);
	if (a) {
		cout << " Se ha registrado el Movimiento " << endl;
	}
	else {
		cout << " Ha ocurrido un fallo al  registrar el Movimiento " << endl;

	}
}
void Gestion_General::altaVisita() {
	system("cls");

	Visita visi;
	visi.cargarvisita();


	bool carga = archi.cargarRegistro(u._archivoVisitas, visi); // valido en el template que exista
	if (carga) {
		//genera carga persona
		bool a = insertarPersona(visi.getId(), visi.getDni(), visi.getObjectNacimiento(), visi.getEstado(), visi.getApellidos(), visi.getNombres());
		Movimientos movi(visi.getUnidad(), visi.getDni(), 1, "Entrada Visitante al Recinto", 2); // telefonica
		bool b = archi.cargarRegistrodeMovimiento(movi);

		pedirhasta(mes, anio);

		//GENERA AUTORIZACION
		Autorizaciones autorizado(visi.getDni(), visi.getUnidad(), mes, anio); // carga la autorizacion correspondiente
		autorizado.setHasta(mes, anio);
		bool c = archi.cargarRegistrodeAutorizacion(autorizado);
		if (a && b && c) {
			cout << "Se ha registrado la visita correctamente " << endl;
		}
		if (!a) {
			cout << "Fallo al Registrar Persona " << endl;
		}
		if (!b) {
			cout << "Fallo al registrar Movimiento  " << endl;
		}
		if (!c) {
			cout << "Fallo al registrar Autorizacion  de la visita   " << endl;
		}
	}
	else {
		char op;
		cout << "Ese Id y/o Dni de Visita ya Existe " << endl;
		cout << "Pulse  cualquier tecla para continuar " << endl;
		cin >> op;
		return;
	}
}
void Gestion_General::altaEmpleado() {
	system("cls");

	Empleado emp;
	emp.CargarEmpleado();
	bool carga = archi.cargarRegistro(u._archivoEmpleados, emp);

	if (carga) {
		
		bool a = insertarPersona(emp.getId(), emp.getDni(), emp.getObjectNacimiento(), emp.getEstado(), emp.getApellidos(), emp.getNombres());

		Movimientos movi(0, emp.getDni(), 1, "Se ha registrado un nuevo Empleado", 1); //permanente
		bool b = archi.cargarRegistrodeMovimiento(movi);
		//GENERA AUTORIZACION
		pedirhasta(mes, anio);
		Autorizaciones autorizado(emp.getDni(), 0, mes, anio); // UNIDAD 0 EMPLEADOS Y PROVEEDORES
		bool c = archi.cargarRegistrodeAutorizacion(autorizado);
		if (a && b && c) {
			cout << "Se ha registrado correctamente el Empleado " << endl;
		}
		if (!a) {
			cout << "Fallo al Registrar Persona " << endl;
		}
		if (!b) {
			cout << "Fallo al registrar Movimiento  " << endl;
		}
		if (!c) {
			cout << "Fallo al registrar Autorizacion  del Empleado  " << endl;
		}
	}
	else {
		int op;
		cout << "Ese Id y/o Dni de Empleado ya Existe " << endl;
		cout << "Pulse  cualquier tecla para continuar " << endl;
		cin >> op;
		return;
	}
}
void Gestion_General::altaResidente_inquilino() {
	system("cls");

	Residente resi;
	resi.cargarResidente();
	Unidad uni;
	cout << endl;
	cout << " Cargue la unidad a la que pertenece " << endl;
	cout << endl;
	uni.cargar();
	uni.setId(resi.getUnidad());  // SETEO ID 
	uni.setApellidoFamilia(resi.getApellidos()); // SETEO APELLIDO
	//uni.setBase(false);
	bool d = archi.cargarUnidad(u._archivoUnidades, uni);

	bool carga = archi.cargarRegistro(u._archivoResidentes, resi);
	if (carga) {
		bool a = insertarPersona(resi.getId(), resi.getDni(), resi.getObjectNacimiento(), resi.getEstado(), resi.getApellidos(), resi.getNombres());
		bool b, c;
		if (resi.getPropietario_Inquilino()) {
			Movimientos movi(resi.getUnidad(), resi.getDni(), 1, "Alta nuevo Residente ", 1); //permanente
			b = archi.cargarRegistrodeMovimiento(movi);

			Autorizaciones autorizado(resi.getDni(), resi.getUnidad(), true); // no paso mes y anio x ser residente.
			c = archi.cargarRegistrodeAutorizacion(autorizado);

		}

		else {
			Movimientos movi(resi.getUnidad(), resi.getDni(), 1, "Alta nuevo Inquilino ", 1); //permanente con hasta
			pedirhasta(mes, anio);
			b = archi.cargarRegistrodeMovimiento(movi);
			Autorizaciones autorizado(resi.getDni(), resi.getUnidad(), mes, anio);
			c = archi.cargarRegistrodeAutorizacion(autorizado);
		}
		if (!a) {
			cout << "Fallo al Registrar Persona " << endl;
		}
		if (!b) {
			cout << "Fallo al registrar Movimiento  " << endl;
		}
		if (!c) {
			cout << "Fallo al registrar Autorizacion    " << endl;
		}
		if (!d) {
			cout << "Fallo al registrar Unidad  " << endl;
		}

	}
	else {
		char op;
		cout << "Ese Id y/o Dni de Residente ya Existe " << endl;
		cout << "Pulse  cualquier tecla para continuar " << endl;
		cin >> op;
		return;
	}

}
void Gestion_General::altaProveedor() {
	system("cls");

	Proveedor prov;
	prov.cargarProveedor();
	bool carga = archi.cargarRegistro(u._archivoProveedores, prov);
	if (carga) {

		bool a = insertarPersona(prov.getId(), prov.getDni(), prov.getObjectNacimiento(), prov.getEstado(), prov.getApellidos(), prov.getNombres());
		Movimientos movi(0, prov.getDni(), 1, "Se ha registrado un nuevo Proveedor ", 1); //permanente
		bool b = archi.cargarRegistrodeMovimiento(movi);

		//GENERA AUTORIZACION
		Autorizaciones autorizado(prov.getDni(), 0, mes, anio); // UNIDAD 0 EMPLEADOS Y PROVEEDORES
		bool c = archi.cargarRegistrodeAutorizacion(autorizado);

		if (!a) {
			cout << "Fallo al Registrar Persona " << endl;
		}
		if (!b) {
			cout << "Fallo al registrar Movimiento  " << endl;
		}
		if (!c) {
			cout << "Fallo al registrar Autorizacion del Proveedor  " << endl;
		}
	}
	else {
		char op;
		cout << "Ese Id y/o Dni de Proveedor ya Existe " << endl;
		cout << "Pulse  cualquier tecla para continuar " << endl;
		cin >> op;
		return;
	}

}

void Gestion_General::bajaResidente() {
	system("cls");
	Utilidades util;
	
	int dni;
	cout << "Ingrese Dni del Residente a dar de baja (8 Digitos) " << endl;
	cin >> dni;
	util.validarInt(dni);
	while (util.contarDigitosInt(dni) != 8) {
		cout << "Dni Valido solo de 8 digitos , ingrese nuevamente   " << endl;
		cin >> dni;
		util.validarInt(dni);

	}
	Residente r;

	r = archi.obtenerObjetoxDni(u._archivoResidentes, r, dni); // esto me dvuelve estado false si existe ese dni
	if (r.getEstado()) {
		
		bool baja = archi.Bajalogica(u._archivoResidentes, r, r.getId());

		Autorizaciones a;
		bool baja2 = archi.BajalogicaxDni(u._archivoAutorizados, a, dni);


		if (baja && baja2) {
			Movimientos mov(r.getUnidad(), r.getDni(), 2, " Dada de baja de Residente", 2);
			//DAR BAJA UNIDAD!
			Unidad uni;
			int iduni = r.getUnidad();
			archi.Bajalogica(u._archivoUnidades, uni, r.getUnidad());
			Movimientos movi(r.getUnidad(), r.getDni(), 2, " Dada de baja de su Unidad", 2);
			bool b= archi.cargarRegistrodeMovimiento(movi);
			bool a = archi.cargarRegistrodeMovimiento(mov);
			if (a && b) {
				cout << "Se ha dado de baja el Residente con Dni " << dni << endl;
			}
			else {
				cout << "Error al generar el Movimiento de la Baja " << endl;
			}
		}
		else {
			cout << "No se ha hecho la baja" << endl;
		}
	}
	else {
		char op;
		cout << "Ha ingresado un Dni inexistente " << endl;
		cout << "Ingrese cualquier tecla para continuar " << endl;
		cin >> op;
		return;
	}
}

void Gestion_General::bajaProveedor() {
	system("cls");
	Utilidades util;
	int dni;
	cout << "Ingrese Dni del Proveedor a dar de baja (8 Digitos) " << endl;
	cin >> dni;
	util.validarInt(dni);
	while (util.contarDigitosInt(dni) != 8) {
		cout << "Dni Valido solo de 8 digitos , ingrese nuevamente   " << endl;
		cin >> dni;
		util.validarInt(dni);

	}
	Proveedor p;

	p = archi.obtenerObjetoxDni(u._archivoProveedores, p, dni);
	if (p.getEstado()) {
		bool baja = archi.Bajalogica(u._archivoProveedores, p, p.getId());

		Autorizaciones a;
		bool baja2 = archi.BajalogicaxDni(u._archivoAutorizados, a, dni);


		if (baja && baja2) {
			Movimientos mov(0, p.getDni(), 2, " Dada de baja de Proveedor", 2);
			bool a = archi.cargarRegistrodeMovimiento(mov);
			if (a) {
				cout << "Se ha dado de baja el Proveedor con Dni " << dni << endl;
			}
			else {
				cout << "Error al generar el Movimiento de la Baja " << endl;
			}
		}
		else {
			cout << "No se ha hecho la baja" << endl;
		}
	}
	else {
		char op;
		cout << "Ha ingresado un Dni de Proveedor inexistente " << endl;
		cout << "Ingrese cualquier tecla para continuar " << endl;
		cin >> op;
		return;
	}
}
void Gestion_General::bajaEmpleado() {
	system("cls");
	Utilidades util;
	int dni;
	cout << "Ingrese Dni del Empleado a dar de baja  (8 Digitos) " << endl;
	cin >> dni;
	util.validarInt(dni);
	while (util.contarDigitosInt(dni) != 8) {
		cout << "Dni Valido solo de 8 digitos , ingrese nuevamente  " << endl;
		cin >> dni;
		util.validarInt(dni);
	}

	Empleado e;

	e = archi.obtenerObjetoxDni(u._archivoEmpleados, e, dni);
	if (e.getEstado()) {
		bool baja = archi.Bajalogica(u._archivoEmpleados, e, e.getId());

		Autorizaciones a;
		bool baja2 = archi.BajalogicaxDni(u._archivoAutorizados, a, dni);

		if (baja && baja2) {
			Movimientos mov(0, e.getDni(), 2, " Dada de baja de Empleado", 2);
			bool a = archi.cargarRegistrodeMovimiento(mov);
			if (a) {
				cout << "Se ha dado de baja el empleado con Dni " << dni << endl;
			}
			else {
				cout << "Error al generar el Movimiento de la Baja " << endl;
			}
		}
		else {
			cout << "No se ha hecho la baja" << endl;
		}
	}
	else {
		char op;
		cout << "Ha ingresado un Dni de Empleado inexistente " << endl;
		cout << "Ingrese cualquier tecla para continuar " << endl;
		cin >> op;
		return;

	}
}

void Gestion_General::bajaVisitas() {
	system("cls");
	Utilidades util;
	int dni;
	cout << "Ingrese Dni de la visita a dar de baja (8 Digitos)" << endl;
	cin >> dni;
	util.validarInt(dni);
	while (util.contarDigitosInt(dni) != 8) {
		cout << "Dni Valido solo de 8 digitos , ingrese nuevamente   " << endl;
		cin >> dni;
		util.validarInt(dni);
	}
	Visita v;

	//baja en archivo visitas
	v = archi.obtenerObjetoxDni(u._archivoVisitas, v, dni);
	if (v.getEstado()) {
		bool baja = archi.Bajalogica(u._archivoVisitas, v, v.getId());
		//baja de su autorizacion
		Autorizaciones a;
		bool baja2 = archi.BajalogicaxDni(u._archivoAutorizados, a, dni);


		if (baja && baja2) {
			//genera movimiento de tipo salida, si se cumple la baja
			Movimientos mov(v.getUnidad(), v.getDni(), 2, " Dada de baja de Visita", 2);
			bool a = archi.cargarRegistrodeMovimiento(mov);
			if (a) {
				cout << "Se ha dado de baja la Visita con Dni " << dni << endl;
			}
			else {
				cout << " Fallo al registrar el mobimiento de la baja " << dni << endl;

			}
		}
		else {
			cout << "No se ha hecho la baja" << endl;
		}
	}
	else {
		char op;
		cout << "Ha ingresado un Dni de Visita inexistente " << endl;
		cout << "Ingrese cualquier tecla para continuar " << endl;
		cin >> op;
		return;
	}
}
