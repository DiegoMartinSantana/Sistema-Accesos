#include "Gestion_General.h"
#include "ArchivosTemplate.h"
#include "Fecha.h"
#include "Autorizaciones.h"
#include "Movimientos.h"
#include "Visita.h"
#include "Empleado.h"
#include "Residente.h"
#include "Proveedor.h"

using namespace std;

//TODO REGISTRA UN MOVIMIENTO TODO ES UN MOVIMIENTO ALTAS BAJAS TODO


  ArchivosTemplate archi;

int mes, anio;
void insertarPersona(int id, int dni,Fecha f, bool estado ,string apellido , string nombre ) {

	Persona p(id, dni, f, estado, apellido, nombre);
	string nombrearchi = "Personas.dat";
	archi.cargarRegistro(nombrearchi,p);

}
void pedirhasta(int& dia, int& mes) {

	cout << "Ingrese hasta que mes esta autorizado (1-12) " << endl;
	if (mes > 0 && mes < 13) {
		cout << "Mes invalido , ingrese nuevamente" << endl;
		cin >> mes;
	}
	cout << "Ingrese hasta que Anio esta autorizado (A partir de 2023)  " << endl;
	cin >> anio;
	if (anio > 2022 && anio < 2300) {
		cout << "Anio invalido , ingrese nuevamente" << endl;
		cin >> anio;
	}
}

void Gestion_General::altaEntrada_Salida() {
	//Sobre uno ya existente
	//validacion de eso

	Movimientos movi;
	movi.cargar();
	archi.cargarRegistrodeMovimiento(movi);

}
void Gestion_General::altaVisita() {

	Visita visi;
	visi.cargarvisita();
	archi.cargarRegistro(_archivoVisitas, visi);
	//genera carga persona
	insertarPersona(visi.getId(), visi.getDni(), visi.getObjectNacimiento(),visi.getEstado(),visi.getApellidos(), visi.getNombres());
	Movimientos movi(visi.getUnidad(), visi.getDni(), 1, "Entrada Visitante al Recinto", 2); // telefonica
	archi.cargarRegistrodeMovimiento(movi);
	pedirhasta(mes, anio);

	//GENERA AUTORIZACION
	Autorizaciones autorizado(visi.getDni(), visi.getUnidad(),mes,anio); // carga la autorizacion correspondiente
	archi.cargarRegistro(_archivoAutorizados, autorizado);

}
void Gestion_General::altaEmpleado() {
	Empleado emp;
	emp.CargarEmpleado();

	insertarPersona(emp.getId(), emp.getDni(), emp.getObjectNacimiento(), emp.getEstado(), emp.getApellidos(), emp.getNombres());


	archi.cargarRegistro(_archivoEmpleados, emp);
	Movimientos movi(0, emp.getDni(), 1, "Se ha registrado un nuevo Empleado", 1); //permanente
	archi.cargarRegistrodeMovimiento(movi);
	//GENERA AUTORIZACION
	pedirhasta(mes,anio);
	Autorizaciones autorizado(emp.getDni(),0,mes,anio); // UNIDAD 0 EMPLEADOS Y PROVEEDORES
	archi.cargarRegistro(_archivoAutorizados, autorizado);

}
void Gestion_General::altaResidente_inquilino() {
	
	Residente resi;
	resi.cargarResidente();
	insertarPersona(resi.getId(), resi.getDni(), resi.getObjectNacimiento(), resi.getEstado(), resi.getApellidos(), resi.getNombres());

	archi.cargarRegistro(_archivoResidentes, resi);
	if (resi.getPropietario_Inquilino()) {
		Movimientos movi(resi.getUnidad(), resi.getDni(), 1, "Alta nuevo Residente ", 1); //permanente
		archi.cargarRegistrodeMovimiento(movi);

		Autorizaciones autorizado(resi.getDni(), resi.getUnidad(), true); // no paso mes y anio x ser residente.
		archi.cargarRegistro(_archivoAutorizados, autorizado);
	}
	else  {
		Movimientos movi(resi.getUnidad(), resi.getDni(), 1, "Alta nuevo Inquilino ", 1); //permanente con hasta
		pedirhasta(mes, anio);

		archi.cargarRegistrodeMovimiento(movi);
		Autorizaciones autorizado(resi.getDni(), resi.getUnidad(), mes, anio);
		archi.cargarRegistro(_archivoAutorizados, autorizado);
	}
	//GENERA AUTORIZACION


}
void Gestion_General::altaProveedor() {
	Proveedor prov;
	prov.cargarProveedor();

	insertarPersona(prov.getId(), prov.getDni(), prov.getObjectNacimiento(), prov.getEstado(), prov.getApellidos(), prov.getNombres());
	archi.cargarRegistro(_archivoProveedores, prov);
	Movimientos movi(0, prov.getDni(), 1, "Se ha registrado un nuevo Proveedor ", 1); //permanente
	archi.cargarRegistrodeMovimiento(movi);

	//GENERA AUTORIZACION
	Autorizaciones autorizado(prov.getDni(), 0, mes, anio); // UNIDAD 0 EMPLEADOS Y PROVEEDORES
	archi.cargarRegistro(_archivoAutorizados, autorizado);
}

void Gestion_General::bajaResidente() {
	int dni;
	cout << "Ingrese Dni del Residente a dar de baja " << endl;
	cin >> dni;

	Residente r;

	r = archi.obtenerObjetoxDni(_archivoResidentes, r, dni);
	bool baja = archi.Bajalogica(_archivoResidentes, r, r.getId());

	Autorizaciones a;
	bool baja2 = archi.BajalogicaxDni(_archivoAutorizados, a, dni);


	if (baja && baja2) {
		Movimientos mov(0, r.getDni(), 2, " Dada de baja de Residente", 2);
		archi.cargarRegistro(_archivoMovimientos, mov);
		cout << "Se ha dado el Residente con Dni " << dni << endl;
	}
	else {
		cout << "No se ha hecho la baja" << endl;
	}
}

void Gestion_General::bajaProveedor() {
	int dni;
	cout << "Ingrese Dni del Proveedor a dar de baja " << endl;
	cin >> dni;

	Proveedor p;

	p = archi.obtenerObjetoxDni(_archivoProveedores, p, dni);
	bool baja = archi.Bajalogica(_archivoProveedores, p, p.getId());

	Autorizaciones a;
	bool baja2 = archi.BajalogicaxDni(_archivoAutorizados, a, dni);


	if (baja && baja2) {
		Movimientos mov(0, p.getDni(), 2, " Dada de baja de Proveedor", 2);
		archi.cargarRegistro(_archivoMovimientos, mov);
		cout << "Se ha dado de baja el Proveedor con Dni " << dni << endl;
	}
	else {
		cout << "No se ha hecho la baja" << endl;
	}
}
void Gestion_General::bajaEmpleado() {

	int dni;
	cout << "Ingrese Dni del Empleado a dar de baja " << endl;
	cin >> dni;

	Empleado e;

	e = archi.obtenerObjetoxDni(_archivoEmpleados, e, dni);
	bool baja = archi.Bajalogica(_archivoEmpleados, e, e.getId());

	Autorizaciones a;
	bool baja2 = archi.BajalogicaxDni(_archivoAutorizados, a, dni);


	if (baja && baja2) {
		Movimientos mov(0, e.getDni(), 2, " Dada de baja de Empleado", 2);
		archi.cargarRegistro(_archivoMovimientos, mov);
		cout << "Se ha dado de baja el empleado con Dni " << dni << endl;
	}
	else {
		cout << "No se ha hecho la baja" << endl;
	}
}

void Gestion_General::bajaVisitas() {
	int dni;
	cout << "Ingrese Dni de la visita a dar de baja " << endl;
	cin >> dni;

	Visita v;
	//baja en archivo visitas
	v = archi.obtenerObjetoxDni(_archivoVisitas, v, dni);
	bool baja = archi.Bajalogica(_archivoVisitas, v, v.getId());
	//baja de su autorizacion
	Autorizaciones a;
	bool baja2 = archi.BajalogicaxDni(_archivoAutorizados, a, dni);


	if (baja && baja2) {
		//genera movimiento de tipo salida, si se cumple la baja
		Movimientos mov(v.getUnidad(), v.getDni(), 2, " Dada de baja de Visita", 2);
		archi.cargarRegistro(_archivoMovimientos, mov);
		cout << "Se ha dado de baja la Visita con Dni " << dni << endl;

	}
	else {
		cout << "No se ha hecho la baja" << endl;

	}

}