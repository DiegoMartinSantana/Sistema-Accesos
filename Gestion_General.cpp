#include "Gestion_General.h"
#include "ArchivosTemplate.h"

#include "Movimientos.h"
#include "Visita.h"
#include "Empleado.h"
#include "Residente.h"
#include "Proveedor.h"

using namespace std;

//TODO REGISTRA UN MOVIMIENTO TODO ES UN MOVIMIENTO ALTAS BAJAS TODO
 // Y TODO GFENERA UNA AUTORIZACION

ArchivosTemplate archi;


void Gestion_General::altaEntrada_Salida() {
	Movimientos movi;
	movi.cargar();

	archi.cargarRegistrodeMovimiento(movi);
}
void Gestion_General::altaVisita() {
	Visita visi;
	visi.cargarvisita();
	archi.cargarRegistro(_archivoVisitas, visi);
	Movimientos movi(visi.getUnidad(), visi.getDni(), 1, "Entrada Visitante al Recinto", 2); // telefonica
	archi.cargarRegistrodeMovimiento(movi);

}
void Gestion_General::altaEmpleado() {
	Empleado emp;
	emp.CargarEmpleado();
	archi.cargarRegistro(_archivoEmpleados, emp);
	Movimientos movi(0, emp.getDni(), 1, "Se ha registrado un nuevo Empleado", 1); //permanente
	archi.cargarRegistrodeMovimiento(movi);

}
void Gestion_General::altaResidente_inquilino() {
	
	Residente resi;
	resi.cargarResidente();
	archi.cargarRegistro(_archivoResidentes, resi);
	if (resi.getPropietario_Inquilino()) {
		Movimientos movi(resi.getUnidad(), resi.getDni(), 1, "Alta nuevo Residente ", 1); //permanente
		archi.cargarRegistrodeMovimiento(movi);

	}
	else if(!resi.getPropietario_Inquilino()) {
		Movimientos movi(resi.getUnidad(), resi.getDni(), 1, "Alta nuevo Inquilino ", 1); //permanente
		archi.cargarRegistrodeMovimiento(movi);

	}
}
void Gestion_General::altaProveedor() {
	Proveedor prov;
	prov.cargarProveedor();
	archi.cargarRegistro(_archivoProveedores, prov);
	Movimientos movi(0, prov.getDni(), 1, "Se ha registrado un nuevo Proveedor ", 1); //permanente
	archi.cargarRegistrodeMovimiento(movi);


}