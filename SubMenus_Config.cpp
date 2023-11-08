#include <iostream>
#include <string>
#include "ArchivosTemplate.h"

#include "SubMenus_Config.h"
#include "Persona.h"
#include "Visita.h"
#include "Empleado.h"
#include "Residente.h"
#include "Proveedor.h"
#include "Autorizaciones.h"
#include "Movimientos.h"
using namespace std;


ArchivosTemplate archivo;

void SubMenus_Config::bajaResidente() {
	int dni;
	cout << "Ingrese Dni del Residente a dar de baja " << endl;
	cin >> dni;

	Residente r;

	r = archivo.obtenerObjetoxDni(_archivoResidentes, r, dni);
	bool baja = archivo.Bajalogica(_archivoResidentes, r, r.getId());

	Autorizaciones a;
	bool baja2 = archivo.BajalogicaxDni(_archivoAutorizados, a, dni);


	if (baja && baja2) {
		Movimientos mov(0, r.getDni(), 2, " Dada de baja de Residente", 2);
		archivo.cargarRegistro(_archivoMovimientos, mov);
		cout << "Se ha dado el Residente con Dni " << dni << endl;
	}
	else {
		cout << "No se ha hecho la baja" << endl;
	}
}

void SubMenus_Config::bajaProveedor() {
	int dni;
	cout << "Ingrese Dni del Proveedor a dar de baja " << endl;
	cin >> dni;

	Proveedor p;

	p = archivo.obtenerObjetoxDni(_archivoProveedores, p, dni);
	bool baja = archivo.Bajalogica(_archivoProveedores, p, p.getId());

	Autorizaciones a;
	bool baja2 = archivo.BajalogicaxDni(_archivoAutorizados, a, dni);


	if (baja && baja2) {
		Movimientos mov(0, p.getDni(), 2, " Dada de baja de Proveedor", 2);
		archivo.cargarRegistro(_archivoMovimientos, mov);
		cout << "Se ha dado de baja el Proveedor con Dni " << dni << endl;
	}
	else {
		cout << "No se ha hecho la baja" << endl;
	}
}
void SubMenus_Config::bajaEmpleado() {

	int dni;
	cout << "Ingrese Dni del Empleado a dar de baja " << endl;
	cin >> dni;

	Empleado e;

	e = archivo.obtenerObjetoxDni(_archivoEmpleados, e, dni);
	bool baja = archivo.Bajalogica(_archivoEmpleados, e, e.getId());
	
	Autorizaciones a;
	bool baja2 = archivo.BajalogicaxDni(_archivoAutorizados, a, dni);


	if (baja && baja2) {
		Movimientos mov(0, e.getDni(), 2, " Dada de baja de Empleado", 2);
		archivo.cargarRegistro(_archivoMovimientos, mov);
		cout << "Se ha dado de baja el empleado con Dni " << dni << endl;
	}
	else {
		cout << "No se ha hecho la baja" << endl;
	}
}

void SubMenus_Config::bajaVisitas() {
	int dni;
	cout << "Ingrese Dni de la visita a dar de baja " << endl;
	cin >> dni;

	Visita v;
	//baja en archivo visitas
	v = archivo.obtenerObjetoxDni(_archivoVisitas, v, dni);
	bool baja = archivo.Bajalogica(_archivoVisitas, v, v.getId());
	//baja de su autorizacion
	Autorizaciones a;
	bool baja2 = archivo.BajalogicaxDni(_archivoAutorizados, a, dni);


	if (baja && baja2) {
		//genera movimiento de tipo salida, si se cumple la baja
		Movimientos mov(v.getUnidad(), v.getDni(), 2, " Dada de baja de Visita", 2);
		archivo.cargarRegistro(_archivoMovimientos, mov);
		cout << "Se ha dado de baja la Visita con Dni " << dni << endl;

	}
	else {
		cout << "No se ha hecho la baja" << endl;

	}

}

void  SubMenus_Config::subMenuBajas() {
	int opc;
	bool a = true;
	while (a) {
		cout << " CONFIGURACION - BAJAS " << endl;
		cout << " ¿Que desea dar de baja? " << endl;
		cout << " Al dar de baja se producira una desautorizacion y dicha Persona no podra volver al Recinto " << endl;
		cout << " sin antes ser dada de Alta" << endl;

		cout << endl;
		cout << " 1. Visita  " << endl;
		cout << " 2. Empleado " << endl;
		cout << " 3. Residente / Inquilino  " << endl;
		cout << " 4. Proveedor  " << endl;
		cout << " 0. Volver " << endl;
		cin >> opc;
		switch (opc)
		{
		case 1: {
			bajaVisitas();
			break;
		}
		case 2: {
			bajaEmpleado();
			break;
		}
		case 3: {
			bajaResidente();
			break;
		}
		case 4: {
			bajaProveedor();
			break;
		}
		case 0: {
			a = false;
			return;
			break;
		}
		default:
			break;
		}

	}
}

bool SubMenus_Config::copiaSegPersonas() {
	Persona p;
	bool cp = archivo.copiaSeguridad(_archivoPersonas, _bakArchivoPersonas,p);
	if (cp) {
		return true;
	}
	else {
		return false;
	}
}
bool SubMenus_Config::copiaSegAutorizaciones() {
	Autorizaciones a;
	bool cp = archivo.copiaSeguridad(_archivoAutorizados, _bakArchivoAutorizados, a);
	if (cp) {
		return true;
	}
	else {
		return false;
	}
}
bool SubMenus_Config::copiaSegMovimientos() {
	Movimientos m;
	bool cp = archivo.copiaSeguridadMovimiento(_archivoMovimientos, _bakArchivoMovimientos, m);
	if (cp) {
		return true;
	}
	else {
		return false;
	}
}
bool SubMenus_Config::copiaSegResidentes() {
	Residente r;
	bool cp = archivo.copiaSeguridad(_archivoResidentes, _bakArchivoResidentes, r);
	if (cp) {
		return true;
	}
	else {
		return false;
	}
}
bool SubMenus_Config::copiaSegVisitas() {
	Visita v;
	bool cp = archivo.copiaSeguridad(_archivoVisitas, _bakArchivoVisitas, v);
	if (cp) {
		return true;
	}
	else {
		return false;
	}
}
bool SubMenus_Config::copiaSegEmpleados() {
	Empleado e;
	bool cp = archivo.copiaSeguridad(_archivoEmpleados, _bakArchivoEmpleados, e);
	if (cp) {
		return true;
	}
	else {
		return false;
	}

}
bool SubMenus_Config::copiaSegProveedores() {
	Proveedor p;
	bool cp = archivo.copiaSeguridad(_archivoProveedores, _bakArchivoProveedores , p);
	if (cp) {
		return true;
	}
	else {
		return false;
	}
}
bool SubMenus_Config::copiaSegTodosArchivos() {
	if (		// SI TODAS DEVUELVEN TRUE
		copiaSegPersonas() &&
		copiaSegAutorizaciones() &&
		copiaSegMovimientos() &&
		copiaSegResidentes() &&
		copiaSegVisitas() &&
		copiaSegEmpleados() &&
		copiaSegProveedores()
		) {
		return true;
	}
	else {
		return false;
	}

}

void SubMenus_Config::subMenuCopiaSeg() {
	int opc;
	bool a = true;
	while (a) {
		cout << " CONFIGURACION - COPIAS DE SEGURIDAD " << endl;
		cout << " Realizar copia de seguridad de :  " << endl;
		cout << endl;
		cout << " 1. Todas las Personas que hayan ingresado en el Recinto historicamente " << endl;
		cout << " 2. Movimientos " << endl;
		cout << " 3. Autorizaciones  " << endl;
		cout << " 4. Residentes  " << endl;
		cout << " 5. Proveedores " << endl;
		cout << " 6. Empleados " << endl;
		cout << " 7. Visitas" << endl;
		cout << " 8. Todas. " << endl;

		cout << " 0. Volver " << endl;
		cin >> opc;
		switch (opc)
		{
		case 1: {
			if (copiaSegPersonas()) {
				cout << "Se ha realizado la copia de seguridad de las Personas. " << endl;
			}
			else {
				cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
			}
			break;
		}
		case 2: {
			if (copiaSegMovimientos()) {
				cout << "Se ha realizado la copia de seguridad de los Movimientos. " << endl;
			}
			else {
				cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
			}
			break;
		}
		case 3: {
			if (copiaSegAutorizaciones()) {
				cout << "Se ha realizado la copia de seguridad de las Autorizaciones. " << endl;
			}
			else {
				cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
			}
			break;
		}
		case 4: {
			if (copiaSegResidentes()) {
				cout << "Se ha realizado la copia de seguridad de los Residentes existentes. " << endl;
			}
			else {
				cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
			}
			break;
		}
		case 5: {
			if (copiaSegProveedores()) {
				cout << "Se ha realizado la copia de seguridad de los Proveedores. " << endl;
			}
			else {
				cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
			}
			break;
		}
		case 6: {
			if (copiaSegEmpleados()) {
				cout << "Se ha realizado la copia de seguridad de los Empleados. " << endl;
			}
			else {
				cout << "Se ha producido un error al realizar la copia de seguridad. " << endl;
			}
			break;
		}
		case 7: {
			if (copiaSegVisitas()) {
				cout << "Se ha realizado la copia de seguridad de las Visitas. " << endl;
			}
			else {
				cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
			}
			break;
		}
		case 8: {
			if (copiaSegTodosArchivos()) {
				cout << "Se ha realizado la copia de seguridad de Todos los Archivos Mencionados. " << endl;
			}
			else {
				cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
			}
			break;
		}
		case 0: {
			a = false;
			return;
			break;
		}
		default:
			break;
		}

	}
}


void SubMenus_Config::subMenuRestaurarCopiaSeg() {

}