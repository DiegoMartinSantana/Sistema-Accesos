#include <iostream>
#include <string>
#include "ArchivosTemplate.h"
#include "Persona.h"
#include "Autorizaciones.h"
#include "Residente.h"
#include "Proveedor.h"
#include "Empleado.h"
#include "Visita.h"
#include "Utilidades.h"

using namespace std;
Autorizaciones::Autorizaciones(int id) {

    
    
}
Autorizaciones::Autorizaciones(int dni, int iduni, bool residente ,int mes, int anio) { // si es residente significa que no pase mes y anio
    setDniPersona(dni);
    setUnidad(iduni);
    _hasta.cargar(1, mes, anio);
    _residente = residente;
}

void Autorizaciones::setEstado(bool estado) {
    _estado = estado;
}
bool Autorizaciones::getEstado() {
    return _estado;
}
Fecha Autorizaciones::getFechaHasta(){

    return _hasta;
}

int Autorizaciones::getDniPersona()
{
    return _dniPersona;
}

int Autorizaciones::getIdUnidad()
{
    return _idUnidad;
}

bool Autorizaciones::getResidente()
{
    return _residente;
}

string Autorizaciones::getHasta()
{
    return _hasta.toString();
}


void Autorizaciones::setDniPersona(int dni)
{
    _dniPersona = dni;
}

void Autorizaciones::setUnidad(int id)
{
    _idUnidad = id;
}

void Autorizaciones::setResidente(bool res)
{
    _residente =res ;
}

void Autorizaciones::setHasta( int dia,int mes ,int anio )
{
    _hasta.cargar(dia, mes, anio);

}


string nombreyapellido(int dni) {
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
        if (emp.getDni() == dni &&  emp.getEstado()) {

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

            string nombreape =r.getApellidosyNombres();
            return nombreape;
        }
    }
    return "Invalido";

}
void Autorizaciones::mostrar()
{
    cout << endl;
    cout << "Id Unidad : " << getIdUnidad() << endl;
    cout << "Dni : " << getDniPersona() << endl;
   
    cout << "Nombre y Apellido : " << nombreyapellido(getDniPersona()) << endl;

    if (_residente) {
        cout << "Autorizacion Permanente  " << endl;
    }
    else {
        cout << "Autorizado hasta : " << _hasta.toString() << endl;
    }
    cout << endl;

    
}



