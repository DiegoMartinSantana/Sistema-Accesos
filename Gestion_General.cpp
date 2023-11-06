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
ArchivosTemplate archiauto;
int mes, anio;
void insertarPersona(int id, int dni,Fecha f, bool estado ,string apellido , string nombre ) {

	Persona p(id, dni, f, estado, apellido, nombre);
	ArchivosTemplate archipersona;
	string nombrearchi = "Personas.dat";
	archipersona.cargarRegistro(nombrearchi,p);

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
	ArchivosTemplate archiauto;
	Autorizaciones autorizado(visi.getDni(), visi.getUnidad(),mes,anio); // carga la autorizacion correspondiente
	archiauto.cargarRegistro(_archivoAutorizados, autorizado);

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
	ArchivosTemplate archiauto;
	Autorizaciones autorizado(emp.getDni(),0,mes,anio); // UNIDAD 0 EMPLEADOS Y PROVEEDORES
	archiauto.cargarRegistro(_archivoAutorizados, autorizado);

}
void Gestion_General::altaResidente_inquilino() {
	
	Residente resi;
	resi.cargarResidente();
	insertarPersona(resi.getId(), resi.getDni(), resi.getObjectNacimiento(), resi.getEstado(), resi.getApellidos(), resi.getNombres());

	archi.cargarRegistro(_archivoResidentes, resi);
	if (resi.getPropietario_Inquilino()) {
		Movimientos movi(resi.getUnidad(), resi.getDni(), 1, "Alta nuevo Residente ", 1); //permanente
		archi.cargarRegistrodeMovimiento(movi);

		ArchivosTemplate archiauto;
		Autorizaciones autorizado(resi.getDni(), resi.getUnidad(), true); // no paso mes y anio x ser residente.
		archiauto.cargarRegistro(_archivoAutorizados, autorizado);
	}
	else  {
		Movimientos movi(resi.getUnidad(), resi.getDni(), 1, "Alta nuevo Inquilino ", 1); //permanente con hasta
		pedirhasta(mes, anio);

		archi.cargarRegistrodeMovimiento(movi);
		ArchivosTemplate archiauto;
		Autorizaciones autorizado(resi.getDni(), resi.getUnidad(), mes, anio);
		archiauto.cargarRegistro(_archivoAutorizados, autorizado);
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
	ArchivosTemplate archiauto;
	Autorizaciones autorizado(prov.getDni(), 0, mes, anio); // UNIDAD 0 EMPLEADOS Y PROVEEDORES
	archiauto.cargarRegistro(_archivoAutorizados, autorizado);
}