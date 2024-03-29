#include <iostream>
#include <string>

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
#include "ArchivosAutorizacion.h"
#include "ArchivosMovimiento.h"
using namespace std;

Utilidades u;
ArchivosTemplate archi;
ArchivosAutorizacion archiauto;
ArchivosMovimiento archimov;


void pedirhasta(int& dia, int& mes, int& anio) {
	Utilidades util;

	

	Fecha actual;


	cout << "Ingrese hasta que Anio esta autorizado (A partir de 2023)  " << endl;
	cin >> anio;
	util.validarInt(anio);
	
		
		while (anio < actual.getAnio() || anio>2300) {

			cout << "Anio Invalido, Ingrese nuevamente : " << endl;
			cin >> anio;
			util.validarInt(anio);


		}
	
	cout << "Ingrese hasta que mes esta autorizado (1-12) " << endl;
	cin >> mes;
	util.validarInt(mes);
	if (anio==actual.getAnio()) {
		while (mes < actual.getMes() || mes < 1 || mes >12) {
			cout << "Mes Invalido, Ingrese nuevamente : " << endl;
			cin >> mes;
			util.validarInt(mes);
			
		}
	}
	else {

		while (mes < 1 || mes >12) {
			cout << "Mes Invalido, Ingrese nuevamente : " << endl;
			cin >> mes;
			util.validarInt(mes);

		}

	}

	cout << "Ingrese Dia : " << endl;
	cin >> dia;
	util.validarInt(dia);
	if (mes==actual.getMes()&& anio==actual.getAnio()) {
		//si estoy en el mes actual 

		while (!util.validarActualDiaAutorizacion(dia, mes, anio) || dia < 1 || dia >31) {
			cout << "Dia invalido , Ingrese nuevamente : " << endl;
			cin >> dia;
			util.validarInt(dia);

		}

	}
	else {
		while (!util.validarDiaAutorizacion(dia, mes, anio) || dia < 1 || dia >31) {
			cout << "Dia invalido , Ingrese nuevamente : " << endl;
			cin >> dia;
			util.validarInt(dia);

		}
	}

}
void Gestion_General::altaEntrada_Salida() {

	system("cls");
	Movimientos movi;
	bool reg = movi.cargar();
	bool a;

	if (reg) {
		 a = archimov.cargarRegistrodeMovimiento(movi);
	}
	else {
		return;
	}
	if (a && reg) {
		
		cout << "Se ha registrado el Movimiento del dni : " << movi.getDni() <<  endl;
		cout << endl;
		system("pause");

	}
	else {
		cout << endl;

		cout << "Ha ocurrido un fallo al  registrar el Movimiento " << endl;
		cout << endl;

		system("pause");
	}
}
void Gestion_General::altaVisita() {
	system("cls");

	Visita visi;
	visi.cargarvisita();
	int dia, mes, anio;


	bool carga = archi.cargarRegistro(u._archivoVisitas, visi); // valido en el template que exista
	if (carga) {
		Movimientos movi(visi.getUnidad(), visi.getDni(), 1, "Entrada Visitante al Recinto", 2); // telefonica
		bool b = archimov.cargarRegistrodeMovimiento(movi);

		pedirhasta(dia, mes, anio);

		//GENERA AUTORIZACION
		Autorizaciones autorizado(visi.getDni(), visi.getUnidad(),false, mes, anio); // carga la autorizacion correspondiente

		//*****
		autorizado.setHasta(15,2,2022);  

		// ****
		bool c = archiauto.cargarRegistrodeAutorizacion(autorizado);
		if (b && c) {
			cout << endl;

			cout << "Se ha registrado la visita "<< visi.getNombres() << " " << visi.getApellidos() << " correctamente " << endl;
			cout << endl;

			system("pause");

		}

		if (!b) {

			cout << "Fallo al registrar Movimiento  " << endl;
			cout << endl;

			system("pause");

		}
		if (!c) {
			cout << endl;

			cout << "Fallo al registrar Autorizacion  de la visita   " << endl;
			cout << endl;

			system("pause");

		}
	}
	else {
		cout << endl;
		cout << "Ese Id y/o Dni de Visita ya Existe " << endl;
		cout << endl;
		system("pause");


	}
}
void Gestion_General::altaEmpleado() {
	system("cls");

	Empleado emp;
	emp.CargarEmpleado();
	bool carga = archi.cargarRegistro(u._archivoEmpleados, emp);

	if (carga) {
		Movimientos movi(0, emp.getDni(), 1, "Se ha registrado un nuevo Empleado", 1); //permanente
		bool b = archimov.cargarRegistrodeMovimiento(movi);
		//GENERA AUTORIZACION
		int dia, mes, anio;

		pedirhasta(dia, mes, anio);

		Autorizaciones autorizado(emp.getDni(), 0,false,mes,anio); // UNIDAD 0 EMPLEADOS Y PROVEEDORES
		autorizado.setHasta(dia,mes,anio);


		bool c = archiauto.cargarRegistrodeAutorizacion(autorizado);
		if (b && c) {
			cout << endl;
			
			cout << "Se ha registrado correctamente el Empleado :  "<< emp.getApellidos() << " Dni : " << emp.getDni()  << endl;
			cout << endl;
			system("pause");

		}
		if (!b) {
			cout << endl;
			cout << "Fallo al registrar Movimiento  " << endl;
			cout << endl;
			system("pause");

		}
		if (!c) {
			cout << endl;

			cout << "Fallo al registrar Autorizacion  del Empleado  " << endl;
			cout << endl;
			system("pause");

		}
	}
	else {
		cout << endl;

		cout << "Ese Id y/o Dni de Empleado ya Existe " << endl;
		cout << endl;
		system("pause");

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
		bool b, c;
		int dia, mes, anio;

		if (resi.getPropietario_Inquilino()) {
			Movimientos movi(resi.getUnidad(), resi.getDni(), 1, "Alta nuevo Residente ", 1); //permanente
			b = archimov.cargarRegistrodeMovimiento(movi);

			Autorizaciones autorizado(resi.getDni(), resi.getUnidad(), true); // no paso hasta x ser residente.
			c = archiauto.cargarRegistrodeAutorizacion(autorizado);

		}

		else {
			Movimientos movi(resi.getUnidad(), resi.getDni(), 1, "Alta nuevo Inquilino ", 1); //permanente con hasta
			pedirhasta(dia, mes, anio);
			b = archimov.cargarRegistrodeMovimiento(movi);
			Autorizaciones autorizado(resi.getDni(), resi.getUnidad(),true ,mes, anio);

			autorizado.setHasta(dia, mes, anio);

			c = archiauto.cargarRegistrodeAutorizacion(autorizado);
		}

		if (!b) {
			cout << endl;
			cout << "Fallo al registrar Movimiento  " << endl;
			cout << endl;
			system("pause");

		}
		if (!c) {
			cout << endl;
			cout << "Fallo al registrar Autorizacion    " << endl;
			cout << endl;
			system("pause");

		}
		if (!d) {
			cout << endl;
			cout << "Fallo al registrar Unidad  " << endl;
			cout << endl;
			system("pause");
			
		}
		if (b && c && d) {
			cout << endl;
			cout << "Se ha registrado correctamente al Residente : " << resi.getNombres() << " " << resi.getApellidos() << endl;
			cout << endl;
			cout << endl;
			system("pause");

		}
	}
	else {
		cout << endl;

		cout << "Ese Id y/o Dni de Residente ya Existe " << endl;
		cout << endl;
		system("pause");
		return;
	}

}
void Gestion_General::altaProveedor() {
	system("cls");

	Proveedor prov;
	prov.cargarProveedor();
	bool carga = archi.cargarRegistro(u._archivoProveedores, prov);
	if (carga) {
		Movimientos movi(0, prov.getDni(), 1, "Se ha registrado un nuevo Proveedor ", 1); //permanente
		bool b = archimov.cargarRegistrodeMovimiento(movi);
		int dia, mes, anio;
		//GENERA AUTORIZACION
		pedirhasta(dia, mes, anio);
		Autorizaciones autorizado(prov.getDni(),0,false, mes, anio); // UNIDAD 0 EMPLEADOS Y PROVEEDORES
		autorizado.setHasta(dia, mes, anio);

		bool c = archiauto.cargarRegistrodeAutorizacion(autorizado);

		if (!b) {
			cout << endl;

			cout << "Fallo al registrar Movimiento  " << endl;
			cout << endl;
			system("pause");

		}
		if (!c) {
			cout << endl;

			cout << "Fallo al registrar Autorizacion del Proveedor  " << endl;
			cout << endl;
			system("pause");

		}
		if (b && c) {

			cout << endl;
			cout << "Se ha registrado correctamente al proveedor : " << prov.getNombres()<< " " << prov.getApellidos() << ", Perteneciente a : " << prov.getEmpresa() << endl;
			cout << endl;
			system("pause");
		}
	}
	else {
		cout << endl;

		cout << "Ese Id y/o Dni de Proveedor ya Existe " << endl;
		cout << endl;
		system("pause");

		return;
	}

}

void Gestion_General::bajaResidente() {
	system("cls");
	Utilidades util;

	int dni;
	cout << "Ingrese Dni del Residente a dar de baja (7-8 Digitos) " << endl;
	cin >> dni;
	util.validarInt(dni);
	while (util.contarDigitosInt(dni) < 7 || util.contarDigitosInt(dni) > 8) {
		cout << "Dni Valido solo de 7-8 digitos , ingrese nuevamente   " << endl;
		cin >> dni;
		util.validarInt(dni);

	}
	Residente r;

	r = archi.obtenerObjetoxDni(u._archivoResidentes, r, dni); // esto me dvuelve estado false si existe ese dni
	if (r.getEstado()) {

		bool baja = archi.BajalogicaxDni(u._archivoResidentes, r, r.getDni());

		Autorizaciones a;
		bool baja2 = archiauto.bajaLogicaAut(r.getDni());


		if (baja && baja2) {
			Movimientos mov(r.getUnidad(), r.getDni(), 2, " Dada de baja de Residente", 2);
			//DAR BAJA UNIDAD!
			Unidad uni;
			int iduni = r.getUnidad();
			archi.Bajalogica(u._archivoUnidades, uni, r.getUnidad());
			Movimientos movi(r.getUnidad(), r.getDni(), 2, " Dada de baja de su Unidad", 2);
			bool b = archimov.cargarRegistrodeMovimiento(movi); // son dos distintos.
			bool a = archimov.cargarRegistrodeMovimiento(mov);
			if (a && b) {
				cout << endl;

				cout << "Se ha dado de baja el Residente con Dni " << dni << endl;
				cout << endl;
				system("pause");

			}
			else {
				cout << endl;

				cout << "Error al generar el Movimiento de la Baja " << endl;
				cout << endl;
				system("pause");

			}
		}
		
	}
	else {
		cout << endl;

		cout << "Ha ingresado un Dni inexistente " << endl;
		cout << endl;
		system("pause");
		return;
	}
}

void Gestion_General::bajaProveedor() {
	system("cls");
	Utilidades util;
	int dni;
	cout << "Ingrese Dni del Proveedor a dar de baja (7-8 Digitos) " << endl;
	cin >> dni;
	util.validarInt(dni);
	while (util.contarDigitosInt(dni) < 7 || util.contarDigitosInt(dni) > 8) {
		cout << "Dni Valido solo de 7-8 digitos , ingrese nuevamente   " << endl;
		cin >> dni;
		util.validarInt(dni);

	}
	Proveedor p;

	p = archi.obtenerObjetoxDni(u._archivoProveedores, p, dni);
	if (p.getEstado()) {
		bool baja = archi.BajalogicaxDni(u._archivoProveedores, p, p.getDni());

		Autorizaciones a;
		bool baja2 = archiauto.bajaLogicaAut(p.getDni());


		if (baja && baja2) {
			Movimientos mov(0, p.getDni(), 2, " Dada de baja de Proveedor", 2);
			bool a = archimov.cargarRegistrodeMovimiento(mov);
			if (a) {
				cout << endl;

				cout << "Se ha dado de baja el Proveedor con Dni " << dni << endl;
				cout << endl;
				system("pause");

			}
			else {
				cout << endl;

				cout << "Error al generar el Movimiento de la Baja " << endl;
				cout << endl;
				system("pause");

			}
		}
		
	}
	else {
		cout << endl;

		cout << "Ha ingresado un Dni de Proveedor inexistente " << endl;
		cout << endl;
		system("pause");
		return;
	}
}
void Gestion_General::bajaEmpleado() {
	system("cls");
	Utilidades util;
	int dni;
	cout << "Ingrese Dni del Empleado a dar de baja  (7-8 Digitos) " << endl;
	cin >> dni;
	util.validarInt(dni);
	while (util.contarDigitosInt(dni) < 7 || util.contarDigitosInt(dni) > 8) {
		cout << "Dni Valido solo de 7-8 digitos , ingrese nuevamente  " << endl;
		cin >> dni;
		util.validarInt(dni);
	}

	Empleado e;

	e = archi.obtenerObjetoxDni(u._archivoEmpleados, e, dni);
	if (e.getEstado()) {
		bool baja = archi.BajalogicaxDni(u._archivoEmpleados, e, e.getDni());

		Autorizaciones a;
		bool baja2 = archiauto.bajaLogicaAut(e.getDni());

		if (baja && baja2) {
			Movimientos mov(0, e.getDni(), 2, " Dada de baja de Empleado", 2);
			bool a = archimov.cargarRegistrodeMovimiento(mov);
			if (a) {
				cout << endl;
				cout << "Se ha dado de baja el empleado con Dni " << dni << endl;
				cout << endl;
				system("pause");

			}
			else {
				cout << endl;

				cout << "Error al generar el Movimiento de la Baja " << endl;
				cout << endl;
				system("pause");

			}
		}
		
	}
	else {
		cout << endl;

		cout << "Ha ingresado un Dni de Empleado inexistente " << endl;
		cout << endl;
		system("pause");
		return;

	}
}

void Gestion_General::bajaVisitas() {
	system("cls");
	Utilidades util;
	int dni;
	cout << "Ingrese Dni de la visita a dar de baja (7-8 Digitos)" << endl;
	cin >> dni;
	util.validarInt(dni);
	while (util.contarDigitosInt(dni) < 7 || util.contarDigitosInt(dni) > 8) {
		cout << "Dni Valido solo de 7-8 digitos , ingrese nuevamente   " << endl;
		cin >> dni;
		util.validarInt(dni);
	}
	Visita v;

	//baja en archivo visitas
	v = archi.obtenerObjetoxDni(u._archivoVisitas, v, dni);
	if (v.getEstado()) {
		bool baja = archi.BajalogicaxDni(u._archivoVisitas, v, v.getDni());
		//baja de su autorizacion
		Autorizaciones a;
		bool baja2 = archiauto.bajaLogicaAut( v.getDni());


		if (baja && baja2) {
			//genera movimiento de tipo salida, si se cumple la baja
			Movimientos mov(v.getUnidad(), v.getDni(), 2, " Dada de baja de Visita", 2);
			bool a = archimov.cargarRegistrodeMovimiento(mov);
			if (a) {
				cout << endl;

				cout << "Se ha dado de baja la Visita con Dni " << dni << endl;
				cout << endl;
				system("pause");

			}
			else {
				cout << endl;

				cout << "Fallo al registrar el mobimiento de la baja " << dni << endl;
				cout << endl;
				system("pause");


			}
		}
		
	}
	else {
		cout << endl;

		cout << "Ha ingresado un Dni de Visita inexistente " << endl;
		cout << endl;
		system("pause");
		return;
	}
}
