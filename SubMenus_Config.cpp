#include <iostream>
#include <string>

using namespace std;

#include "ArchivosTemplate.h"
#include "ArchivosAutorizacion.h"
#include "ArchivosMovimiento.h"
#include "Gestion_General.h"
#include "SubMenus_Config.h"
#include "Persona.h"
#include "Visita.h"
#include "Empleado.h"
#include "Residente.h"
#include "Proveedor.h"
#include "Autorizaciones.h"
#include "Movimientos.h"
#include "Fecha_Hora.h"
#include "Utilidades.h"
#include "Unidad.h"

ArchivosTemplate archivo;
Utilidades uti;
Gestion_General general;
ArchivosAutorizacion archivoautorizado;
ArchivosMovimiento archivomovimiento;

void  SubMenus_Config::subMenuBajas() {
	char opc;
	Fecha_Hora f;
	bool a = true;
	while (a) {
		system("cls");
		cout << "--------------------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << " CONFIGURACION - BAJAS				" << f.toString() << endl;
		cout << endl;
		cout << " Al dar de baja se producira una desautorizacion y dicha Persona no podra volver al Recinto " << endl;
		cout << " sin antes ser dada de Alta." << endl;
		cout << " Que desea dar de baja? " << endl;
		cout << endl;
		cout << " 1. Visita.  " << endl;
		cout << " 2. Empleado. " << endl;
		cout << " 3. Residente / Inquilino. Se dara de baja la Unidad Asociada" << endl;
		cout << " 4. Proveedor.  " << endl;
		cout << endl;
		cout << " 0. Volver. " << endl;
		cout << endl;

		cout << "--------------------------------------------------------------------------------------------------------------" << endl;

		cin >> opc;
		switch (opc)
		{
		case '1': {
			general.bajaVisitas();
			break;
		}
		case '2': {
			general.bajaEmpleado();
			break;
		}
		case '3': {
			general.bajaResidente();
			break;
		}
		case '4': {
			general.bajaProveedor();
			break;
		}
		case '0': {
			a = false;
			return;
			break;
		}
		default:
			break;
		}

	}
}


void  SubMenus_Config::copiaSegAutorizaciones() {
	Autorizaciones a;
	 archivo.copiaSeguridad(uti._archivoAutorizados, _bakArchivoAutorizados, a);
	
}
void  SubMenus_Config::copiaSegMovimientos() {
	Movimientos m;
	
	 archivomovimiento.copiaSeguridadMovimiento( _bakArchivoMovimientos);
	
}
void  SubMenus_Config::copiaSegResidentes() {
	Residente r;
	Unidad uni;
	archivo.copiaSeguridad(uti._archivoResidentes, _bakArchivoResidentes, r);
	archivo.copiaSeguridad(uti._archivoUnidades, _bakArchivoUnidades, uni);
}
void  SubMenus_Config::copiaSegVisitas() {
	Visita v;
	 archivo.copiaSeguridad(uti._archivoVisitas, _bakArchivoVisitas, v);
	
}
void SubMenus_Config::copiaSegEmpleados() {
	Empleado e;
	 archivo.copiaSeguridad(uti._archivoEmpleados, _bakArchivoEmpleados, e);
	

}
void  SubMenus_Config::copiaSegProveedores() {
	Proveedor p;
	archivo.copiaSeguridad(uti._archivoProveedores, _bakArchivoProveedores, p);
	
}
void SubMenus_Config::copiaSegTodosArchivos() {

	copiaSegAutorizaciones();
		copiaSegMovimientos();
		copiaSegResidentes();
		copiaSegVisitas();
		copiaSegEmpleados();
		copiaSegProveedores();
		

}

void SubMenus_Config::subMenuCopiaSeg() {
	char opc;
	bool a = true;
	system("cls");
	int clave;
	Fecha_Hora f;
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << " PARA ACCEDER A LOS REGISTROS DE RESTAURACION ES NECESARIO REINGRESAR SU CLAVE ADMIN. " << endl;
	cout << " USTED POSEERA TRES INTENTOS :  " << endl;

	bool ok = false;
	for (int x = 0;x < 3;x++) {
		cin >> clave;
		if (clave == 1111) {
			ok = true;
			x = 4;
		}
	}

	system("cls");
	if (ok) {
		while (a) {

			system("cls");
			cout << "----------------------------------------------------------------------------------------" << endl;

			cout << " CONFIGURACION - COPIAS DE SEGURIDAD                                  " << f.toString() << endl;
			cout << " Realizar copia de seguridad de :  " << endl;
			cout << endl;
			cout << " 1. Movimientos. " << endl;
			cout << " 2. Autorizaciones.  " << endl;
			cout << " 3. Residentes y sus Unidades. " << endl;
			cout << " 4. Proveedores. " << endl;
			cout << " 5. Empleados. " << endl;
			cout << " 6. Visitas." << endl;
			cout << " 7. Todas. " << endl;
			cout << endl;
			cout << " 0. Volver." << endl;
			cout << "----------------------------------------------------------------------------------------" << endl;

			cin >> opc;
			switch (opc)
			{
			
			case '1': {
				copiaSegMovimientos();


				break;
			}
			case '2': {
				copiaSegAutorizaciones();

				break;
			}
			case '3': {
				copiaSegResidentes();
				break;
			}
			case '4': {
				copiaSegProveedores();
				break;
			}
			case '5': {
				copiaSegEmpleados();
				break;
			}
			case '6': {
				copiaSegVisitas();
				break;
			}
			case '7': {
				copiaSegTodosArchivos();
				break;
			}
			case '0': {
				a = false;
				return;
				break;
			}
			default:
				break;
			}
		}
	}
}



bool SubMenus_Config::resCopiaSegAutorizaciones() {
	Autorizaciones a;
	if (archivo.restaurarCopiaSeguridad(_bakArchivoAutorizados, uti._archivoAutorizados, a)) {
		return true;
	}
	else {
		return false;
	}
}
bool SubMenus_Config::resCopiaSegMovimientos() {
	Movimientos mov;
	if (archivomovimiento.restaurarCopiaSeguridadMovimiento(_bakArchivoMovimientos)) {
		return true;
	}
	else {
		return false;
	}
}
bool SubMenus_Config::resCopiaSegResidentes() {
	Residente r;
	Unidad uni;
	if (archivo.restaurarCopiaSeguridad(_bakArchivoResidentes, uti._archivoResidentes, r) && archivo.restaurarCopiaSeguridad(_bakArchivoUnidades,uti._archivoUnidades,uni)) {
		
		return true;
	}
	else {
		return false;
	}
}
bool SubMenus_Config::resCopiaSegVisitas() {
	Visita v;
	if (archivo.restaurarCopiaSeguridad(_bakArchivoVisitas, uti._archivoVisitas, v)) {
		return true;
	}
	else {
		return false;
	}
}
bool SubMenus_Config::resCopiaSegEmpleados() {
	Empleado emp;
	if (archivo.restaurarCopiaSeguridad(_bakArchivoEmpleados, uti._archivoEmpleados, emp)) {
		return true;
	}
	else {
		return false;
	}
}
bool SubMenus_Config::resCopiaSegProveedores() {
	Proveedor p;
	if (archivo.restaurarCopiaSeguridad(_bakArchivoProveedores, uti._archivoProveedores, p)) {
		return true;
	}
	else {
		return false;
	}
}

bool SubMenus_Config::resCopiaSegTodosArchivos() {

	if (
		resCopiaSegAutorizaciones() &&
		resCopiaSegProveedores() &&
		resCopiaSegEmpleados() &&
		resCopiaSegVisitas() &&
		resCopiaSegResidentes() &&  
		resCopiaSegMovimientos())
	{
		return true;
	}
	else {
		return false;
	}

}

void SubMenus_Config::subMenuRestaurarCopiaSeg() {
	int opc;
	bool a = true;
	system("cls");
	int clave;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << " PARA ACCEDER A LOS REGISTROS DE RESTAURACION ES NECESARIO REINGRESAR SU CLAVE ADMIN. " << endl;
	cout << " USTED POSEERA TRES INTENTOS :  " << endl;
	bool ok = false;
	for (int x = 0;x < 3;x++) {
		cin >> clave;
		if (clave == 1111) {
			ok = true;
			x = 4;
		}
	}
	Fecha_Hora f;
	system("cls");
	if (ok) {
		while (a) {
			system("cls");

			cout << "----------------------------------------------------------------------------------------" << endl;

			cout << " CONFIGURACION - RESTAURACION DE COPIAS DE SEGURIDAD                     " << f.toString() << endl;
			cout << endl;
			cout << " Restaurar copia de seguridad de :  " << endl;
			cout << endl;
			cout << " 1. Movimientos. " << endl;
			cout << " 2. Autorizaciones.  " << endl;
			cout << " 3. Residentes y sus unidades. " << endl;
			cout << " 4. Proveedores. " << endl;
			cout << " 5. Empleados. " << endl;
			cout << " 6. Visitas." << endl;
			cout << " 7. Todas. " << endl;
			cout << endl;
			cout << " 0. Volver. " << endl;
			cout << "----------------------------------------------------------------------------------------" << endl;

			cin >> opc;
			switch (opc)
			{
			
			case 2: {
				if (resCopiaSegMovimientos()) {
					cout << "Se ha restaurado  la copia de seguridad de los Movimientos. " << endl;
				}
				else {
					cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
				}
				break;
			}
			case 3: {
				if (resCopiaSegAutorizaciones()) {
					cout << "Se ha restaurado  la copia de seguridad de las Autorizaciones. " << endl;
				}
				else {
					cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
				}
				break;
			}
			case 4: {
				if (resCopiaSegResidentes()) {
					cout << "Se ha restaurado  la copia de seguridad de los Residentes existentes. " << endl;
				}
				else {
					cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
				}
				break;
			}
			case 5: {
				if (resCopiaSegProveedores()) {
					cout << "Se ha restaurado  la copia de seguridad de los Proveedores. " << endl;
				}
				else {
					cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
				}
				break;
			}
			case 6: {
				if (resCopiaSegEmpleados()) {
					cout << "Se ha restaurado  la copia de seguridad de los Empleados. " << endl;
				}
				else {
					cout << "Se ha producido un error al realizar la copia de seguridad. " << endl;
				}
				break;
			}
			case 7: {
				if (resCopiaSegVisitas()) {
					cout << "Se ha restaurado  la copia de seguridad de las Visitas. " << endl;
				}
				else {
					cout << "Se ha producido un error al realizar la copia de seguridad." << endl;
				}
				break;
			}
			case 8: {
				if (resCopiaSegTodosArchivos()) {
					cout << "Se ha restaurado  la copia de seguridad de Todos los Archivos Mencionados. " << endl;
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
}