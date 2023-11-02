#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "Residente.h"
#include <iostream>
using namespace std;

Residente::Residente() {

}
int Residente::getUnidad() const {
    return _unidad;
}

string Residente::getIngreso() {
    string retornar = _ingreso.toString();
    return retornar;
}

bool Residente::getPropietario_Inquilino() const {
    return _propietario_inquilino;
}


void Residente::setUnidad(int unidad) {
    _unidad = unidad;
}

void Residente::setIngreso(int dia, int mes, int anio) {
    _ingreso.cargar(dia, mes, anio);
}

void Residente::setPropietario_Inquilino(bool propietario) {
    _propietario_inquilino = propietario;
}

void Residente::cargarResidente() {
    cargarPersona();
    int unidad;
    int dia, mes, anio;
    bool propie;
    cout << "Ingrese Unidad correspondiente : " << endl;
    cin >> unidad;
    setUnidad(unidad);
    cout << "Ingrese dia de Ingreso : " << endl;
    cin >> dia;
    cout << "Ingrese mes de Ingreso : " << endl;
    cin >> mes;
    cout << "Ingrese anio de Ingreso  : " << endl;
    cin >> anio;

    setIngreso(dia, mes, anio);

    cout << "Ingrese 1 si es Residente , Ingrese 0 si es Inquilino " << endl;
    cin >> propie;

    setPropietario_Inquilino(propie);


}
string Residente::mostrarResidentestring() {
    string retornar = mostrarPersonastring();

    if (getPropietario_Inquilino()) {

        retornar += "Unidad del Residente : " + to_string(getUnidad()) + "\n"
            + " Fecha de Ingreso del Residente : " + getIngreso();
    }
    else {
        retornar += "Unidad del Inquilino : " + to_string(getUnidad()) + "\n"
            + " Fecha de Ingreso del Inquilino : " + getIngreso();


    }
    return retornar;

}
void Residente::mostrar() {

    mostrarPersona();

    if (getPropietario_Inquilino()) {

        cout << "Unidad del Residente : " << to_string(getUnidad()) << endl;
        cout << " Fecha de Ingreso del Residente : " << getIngreso() << endl;
    }
    else {
        cout << "Unidad del Inquilino : " << to_string(getUnidad()) << endl;
        cout << "Fecha de Ingreso del Inquilino : " << getIngreso() << endl;


    }


}