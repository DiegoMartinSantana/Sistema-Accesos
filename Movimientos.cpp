#include <iostream>
#include <cstring>
#include "Gestion_General.h"
#include "Gestor_Altas.h"
#include "Movimientos.h"
#include "Utilidades.h"
#include "Fecha_Hora.h"
#include "Residente.h"
#include "Proveedor.h"
#include "Empleado.h"
#include "Visita.h"
#include "Unidad.h"
#include "Utilidades.h"
#include "Autorizaciones.h"
#include "ArchivosTemplate.h"
#include "ArchivosAutorizacion.h"
#include "ArchivosMovimiento.h"
using namespace std;

Movimientos::Movimientos(int idunidad, int dni, int sentido, std::string observacion, int tipoautorizacion) {
	setUnidad(idunidad);
	setDni(dni);
	_fechayhora = Fecha_Hora(); // la del sistema
	setSentido(sentido);
	setObservaciones(observacion);
	setTipoAutorizacion(tipoautorizacion);

}
Movimientos::Movimientos() {

}


int Movimientos::getDni()
{
	return _dnipersona;
}

int  Movimientos::getUnidad()
{
	return _idunidad;
}

Fecha_Hora Movimientos::getFechayHoraMovimiento()
{
	return _fechayhora;
}

bool Movimientos::getSentido()
{
	return _sentido;
}

string Movimientos::getObservaciones()
{
	return _observaciones;
}

string  Movimientos::getTipoAutorizacion()
{
	string tipo;
	if (_tipoAutorizacion == 1) {
		tipo = "Permanente";
	}
	else if (_tipoAutorizacion == 2) {
		tipo = "Telefonica";
	}
	return tipo;
}


void Movimientos::setDni(int dni)
{
	_dnipersona = dni;
}

void Movimientos::setUnidad(int unidad)
{
	_idunidad = unidad;
}

void Movimientos::setFechayHoraMovimiento(Fecha_Hora fechahora)
{
	_fechayhora = fechahora;
}

void Movimientos::setObservaciones(std::string observaciones)
{
	strcpy(_observaciones, observaciones.c_str());
}

void Movimientos::setTipoAutorizacion(int tipo)
{
	if (tipo == 1) {
		_tipoAutorizacion = tipo;
	}
	else if (tipo == 2) {
		_tipoAutorizacion = tipo;
	}
	else {
		_tipoAutorizacion = -1;
	}

}


void  Movimientos::setSentido(bool sentido)
{
	_sentido = sentido;
}
int validarDnisinMensaje(int dni) {
	Residente r;
	Visita v;
	Empleado emp;
	Proveedor prov;

	bool exister, existev, existeprov, existeemp;
	ArchivosTemplate temp;
	Utilidades u;
	exister = temp.validarDni(u._archivoResidentes, r, dni);
	existev = temp.validarDni(u._archivoVisitas, v, dni);
	existeprov = temp.validarDni(u._archivoProveedores, prov, dni);
	existeemp = temp.validarDni(u._archivoEmpleados, emp, dni);


	if (exister) {

		return 1;
	}
	else if (existev) {

		return 2;

	}
	else if (existeprov) {

		return 4;

	}
	else if (existeemp) {

		return 3;
	}
	else {
		return 0;
	}


}
int validarDni(int dni) {
	//true si existe. 
	//recorro todos
	Residente r;
	Visita v;
	Empleado emp;
	Proveedor prov;

	bool exister, existev, existeprov, existeemp;
	ArchivosTemplate temp;
	Utilidades u;
	exister = temp.validarDni(u._archivoResidentes, r, dni);
	existev = temp.validarDni(u._archivoVisitas, v, dni);
	existeprov = temp.validarDni(u._archivoProveedores, prov, dni);
	existeemp = temp.validarDni(u._archivoEmpleados, emp, dni);


	if (exister) {
		cout << endl;
		cout << "Residente registrado." << endl;
		cout << endl;
		return 1;
	}
	else if (existev) {
		cout << endl;
		cout << "Visitante registrado." << endl;
		cout << endl;
		return 2;

	}
	else if (existeprov) {
		cout << endl;
		cout << "Proveedor registrado." << endl;
		cout << endl;
		return 4;

	}
	else if (existeemp) {
		cout << endl;
		cout << "Empleado registrado." << endl;
		cout << endl;
		return 3;
	}
	else {
		return 0;
	}


}
int  buscarUnidadResidente(int dni) {

	ArchivosTemplate a;
	Utilidades u;
	Unidad uni;
	int cantreg = a.contarRegistros(u._archivoUnidades, uni);
	Residente r;
	int cantres = a.contarRegistros(u._archivoResidentes, r);

	r = a.obtenerObjetoxDni(u._archivoResidentes, r, dni);

	for (int x = 0;x < cantreg;x++) {
		uni = a.ObtenerObjeto(u._archivoUnidades, uni, x);

		if (uni.getEstado() && r.getUnidad() == uni.getId() && r.getEstado()) {

			return r.getUnidad();
		}

	}

}

bool Movimientos::cargar()
{
	Utilidades util;

	int sentido;
	string Observaciones;
	int tipo, dni, id;
	cout << "Ingrese Dni (7-8 Digitos) : " << endl;
	cin >> dni;
	util.validarInt(dni);
	int con = 0;
	//valido existencia del dni y autorizacion valida del dni.
	int vali = validarDni(dni);
	while (util.contarDigitosInt(dni) < 7 || util.contarDigitosInt(dni) > 8 || vali == 0) {
		if (util.contarDigitosInt(dni) < 7 || util.contarDigitosInt(dni) > 8) {
			cout << "Recuerde que solo se puede ingresar un Dni de 7 u 8 Cifras, ingrese nuevamente : " << endl;
		}
		else {
			cout << "Dni inexistente, Ingrese uno ya Registrado para generar el Movimiento : " << endl;

		}
		cin >> dni;
		util.validarInt(dni);
		vali = validarDni(dni);

	}

	bool autorizacionv = util.validarAutorizacion(dni);
	if (autorizacionv) {
		cout << endl;
		cout << "Posee Autorizacion para entrar al Recinto.   " << endl;
		cout << endl;

	}
	else {
		cout << endl;
		cout << "Se ha vencido la autorizacion. Debera generar un nuevo Alta para ingresar al Recinto. " << endl;
		ArchivosTemplate archi;
		ArchivosAutorizacion archiauto;
		//mi validar dni me indica en donde existe ese! asique a partir de ese genero la baja logica de autorizacion y su archivo

		Gestion_General bajas;
		ArchivosMovimiento archimovi;
		Utilidades u;
		switch (validarDnisinMensaje(dni)) {

		case 1: {
			Residente r;

			r = archi.obtenerObjetoxDni(u._archivoResidentes, r, dni); // esto me dvuelve estado false si existe ese dni
			if (r.getEstado()) {

				bool baja = archi.Bajalogica(u._archivoResidentes, r, r.getId());

				Autorizaciones a;
				bool baja2 = archiauto.bajaLogicaAut(dni);


				if (baja && baja2) {
					Movimientos mov(r.getUnidad(), r.getDni(), 2, " Dada de baja de Residente", 2);
					//DAR BAJA UNIDAD!
					Unidad uni;
					int iduni = r.getUnidad();
					archi.Bajalogica(u._archivoUnidades, uni, r.getUnidad());
					bool ag = archimovi.cargarRegistrodeMovimiento(mov);
					if (ag) {
						cout << endl;

						cout << "Se ha dado de baja el Residente con Dni " << dni << endl;
						cout << endl;

					}
				}
			}
			break;

		}
		case 2: {
			Visita v;

			//baja en archivo visitas
			v = archi.obtenerObjetoxDni(u._archivoVisitas, v, dni);
			if (v.getEstado()) {
				bool baja = archi.Bajalogica(u._archivoVisitas, v, v.getId());
				//baja de su autorizacion
				Autorizaciones a;
				bool baja2 = archiauto.bajaLogicaAut(dni);


				if (baja && baja2) {
					//genera movimiento de tipo salida, si se cumple la baja
					Movimientos mov(v.getUnidad(), v.getDni(), 2, " Dada de baja de Visita", 2);
					bool af = archimovi.cargarRegistrodeMovimiento(mov);
					if (af) {
						cout << endl;
						cout << "Se ha dado de baja la Visita con Dni " << dni << endl;
						cout << endl;

					}

				}
			}
			break;
		}
		case 3: {
			Empleado e;

			e = archi.obtenerObjetoxDni(u._archivoEmpleados, e, dni);
			if (e.getEstado()) {
				bool baja = archi.Bajalogica(u._archivoEmpleados, e, e.getId());

				Autorizaciones a;
				bool baja2 = archiauto.bajaLogicaAut(dni);

				if (baja && baja2) {
					Movimientos mov(0, e.getDni(), 2, " Dada de baja de Empleado", 2);
					bool ad = archimovi.cargarRegistrodeMovimiento(mov);
					if (ad) {
						cout << endl;
						cout << "Se ha dado de baja el empleado con Dni " << dni << endl;
						cout << endl;

					}

				}

			}
			break;
		}
		case 4: {
			Proveedor p;
			p = archi.obtenerObjetoxDni(u._archivoProveedores, p, dni);
			if (p.getEstado()) {
				bool baja = archi.Bajalogica(u._archivoProveedores, p, p.getId());

				Autorizaciones a;
				bool baja2 = archiauto.bajaLogicaAut(dni);


				if (baja && baja2) {
					Movimientos mov(0, p.getDni(), 2, " Dada de baja de Proveedor", 2);
					bool ar = archimovi.cargarRegistrodeMovimiento(mov);
					if (ar) {
						cout << endl;

						cout << "Se ha dado de baja el Proveedor con Dni " << dni << endl;
						cout << endl;

					}
				}

			}
			break;

		}

		}


		cout << endl;
		system("pause");
		return false;
	}
	cout << "Ingrese el sentido 1- Entrada 2-Salida" << endl;

	cin >> sentido;

	util.validarInt(sentido);

	while (sentido < 1 || sentido > 2) {
		cout << "Sentido no Valido.  " << endl;
		cout << "Ingrese el sentido 1- Entrada 2-Salida" << endl;

		cin >> sentido;
		util.validarInt(sentido);
	}
	bool a = false;
	if (vali == 1) {
		a = true;
		id = buscarUnidadResidente(dni);
	}
	if (vali == 3 || vali == 4) {
		char  va;
		if (sentido == 1) {
			cout << "Se dirige hacia  la Unidad Central (0) ? : " << endl;
		}
		else {
			cout << "Sale desde la Unidad Central (0) ? : " << endl;

		}
		cout << "S - Si, N - No " << endl;
		cin >> va;
		util.validarChar(va);
		switch (va)
		{
		case 's': {
			id = 0;
			a = true;
			break;
		}
		case 'S': {
			id = 0;
			a = true;
			break;

		}
		case 'n': {
			a = false;
			break;

		}
		case 'N': {
			a = false;
			break;
		}
		default:
			break;
		}
		while (va != 's' && va != 'S' && va != 'n' && va != 'N') {
			if (sentido == 1) {
				cout << "Respuesta invalida, Se dirige hacia  la Unidad Central (0) ? : " << endl;
			}
			else {
				cout << "Respuesta invalida, Sale desde la Unidad Central (0) ? : " << endl;

			}
			cout << "S - Si, N - No " << endl;
			cin >> va;
			util.validarChar(va);

			switch (va)
			{
			case 's': {
				id = 0;
				a = true;
				break;

			}
			case 'S': {
				id = 0;
				a = true;
				break;
			}
			case 'n': {
				a = false;
			}
			case 'N': {
				a = false;
				break;
			}
			default:
				break;
			}

		}

	}
	if (!a) {//valido existencia del id de unidad en mi archivo de unidades, no puede visitar una que no exista
		// 
		//si ingresa un residente , tiene que ir a su UNIDAD
		if (sentido == 1) {
			cout << "Ingrese el Id de Unidad hacia la que se dirige :  " << endl;
		}
		else {
			cout << "Ingrese el Id de unidad del que proviene:  " << endl;

		}
		cin >> id;
		util.validarInt(id);
		while (id < 1 || id> 200) {

			cout << "Unidad invalida." << endl;
			cin >> id;
			util.validarInt(id);

		}
	}


	cout << "Ingrese el tipo de autorizacion " << endl;
	cout << "1- Permanente 2- Telefonica " << endl;

	cin >> tipo;
	util.validarInt(tipo);

	while (tipo < 1 || tipo >2) {
		cout << "Tipo no valido - Ingrese el tipo de autorizacion nuevamente. " << endl;
		cout << "1- Permanente 2- Telefonica " << endl;
		cin >> tipo;
		util.validarInt(tipo);
	}


	cin.ignore();
	cout << "Observaciones" << endl;
	getline(cin, Observaciones);
	cout << endl;
	if (sentido == 1) {
		setSentido(true);
	}
	else {
		setSentido(false);
	}
	if (sentido == 1) {
		setTipoAutorizacion(tipo);
	}
	else {
		setTipoAutorizacion(tipo);
	}

	Fecha_Hora actual;
	setObservaciones(Observaciones);
	setFechayHoraMovimiento(actual);
	setDni(dni);
	setUnidad(id);
}

void Movimientos::mostrar() {
	cout << endl;

	cout << "Dni : " << getDni() << endl;
	cout << "Id de Unidad : " << getUnidad() << endl;

	if (getSentido()) {
		cout << "Sentido :  Entrada." << endl;
	}
	else {
		cout << "Sentido :  Salida. " << endl;

	}
	cout << "Fecha  y hora : " << getFechayHoraMovimiento().toString() << endl;

	cout << "Observaciones : " << getObservaciones() << endl;
	cout << endl;

}

