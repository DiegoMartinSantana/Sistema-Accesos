#include <iostream>
#include <cstring>
using namespace std;

#include "Movimientos.h"
#include "Utilidades.h"
#include "Fecha_Hora.h"
#include "Residente.h"
#include "Proveedor.h"
#include "Empleado.h"
#include "Visita.h"
#include "Unidad.h"
#include "Utilidades.h"
#include "ArchivosTemplate.h"

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
bool AutorizacionValida(int dni) {

	return false;
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
		cout << "Residente registrado" << endl;
		cout << endl;
		return 1;
	}
	if (existev) {
		cout << endl;
		cout << "Visitante registrado" << endl;
		cout << endl;
		return 2;

	}
	if (existeprov) {
		cout << endl;
		cout << "Proveedor registrado" << endl;
		cout << endl;
		return 4;

	}
	if (existeemp) {
		cout << endl;
		cout << "Empleado registrado;" << endl;
		cout << endl;
		return 3;
	}
	return 0;

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

		if (r.getUnidad() == uni.getId()) {

			return r.getUnidad();
		}

	}

}

void Movimientos::cargar()
{
	Utilidades util;



	/*
	*** IMPORTANTE ***
	*
	* REALIAR VALIDACION AUTORIZACIONES
	* VALIDO SI POSEE AUTORIZACION ESE DNI, DE NO SER ASI,
	* SI POSEE : INFORMO SI ESTA VENCIDA O NO. SI VENCIDA ENTONCES AVISO  Y
	CONSULTO SI QUIERE GENERARLA NUEVAMENTE O NO.
	SI ESTA VALIDA LE DOY INGRESO  O SALIDA DEL RECINTO Y GENERO MOVIMIENTO A ESE DNI



	*/

	int sentido;
	string Observaciones;
	int tipo, dni, id;
	cout << "Ingrese Dni (8 Digitos) : " << endl;
	cin >> dni;
	util.validarInt(dni);
	//valido existencia del dni y autorizacion valida del dni.
	while (util.contarDigitosInt(dni) != 8 || validarDni(dni) == 0) {
		cout << "Dni ingresado invalido o inexistente, ingrese nuevamente : " << endl;
		cin >> dni;
		util.validarInt(dni);

	}
	/* FALTA AUTORIZACION ACA*/
		//AUTORIZACION SI TIENE VALIDA

	
	//valido existencia del id de unidad en mi archivo de unidades, no puede visitar una que no exista
	// 
	//si ingresa un residente , tiene que ir a su UNIDAD
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
	if (validarDni(dni) == 1) {
		a = true;
		id = buscarUnidadResidente(dni);
	}
	if (validarDni(dni) == 3 || validarDni(dni) == 4) {
		char  va;
		if (sentido == 1) {
			cout << "Se dirige hacia  la Unidad Central (0) ? : " << endl;
		}
		else {
			cout << "Sale desde la Unidad Central (0) ? : " << endl;

		}
		cout << "S - Si, N - No " << endl;
		cin >> va;
		switch (va)
		{
		case 's': {
			id = 0;
			a = true;
		}
		case 'S': {
			id = 0;
			a = true;
		}
		case 'n': {
			a = false;
		}
		case 'N': {
			a = false;
		}
		default:
			break;
		}


	}
	if (!a) {
		if (sentido == 1) {
			cout << "Ingrese el Id de Unidad hacia la que se dirige :  " << endl;
		}
		else {
			cout << "Ingrese el Id de unidad del que proviene:  " << endl;

		}
		cin >> id;
		util.validarInt(id);
		while (id < 1 || id> 200) {

			cout << "Unidad inexistente." << endl;
			cin >> id;
			util.validarInt(id);

		}
	}

	

	cin.ignore();

	cout << "Ingrese el tipo de autorizacion " << endl;
	cout << "1- Permanente 2- Telefonica " << endl;
	if (sentido == 1) {
		cin >> tipo;
		util.validarInt(tipo);

		while (tipo < 1 || tipo >2) {
			cout << "Tipo no valido - Ingrese el tipo de autorizacion nuevamente. " << endl;
			cout << "1- Permanente 2- Telefonica " << endl;
			cin >> tipo;
			util.validarInt(tipo);
		}

	}
	cin.ignore();
	cout << "Observaciones" << endl;
	getline(cin, Observaciones);

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
		setTipoAutorizacion(2);
	}

	Fecha_Hora actual;
	setObservaciones(Observaciones);
	setFechayHoraMovimiento(actual);
	setDni(dni);
	setUnidad(id);
}

void Movimientos::mostrar()
{
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
	cout << "Tipo Autorizacion : " << getTipoAutorizacion() << endl;
	cout << "Observaciones : " << getObservaciones() << endl;
	cout << endl;

}
