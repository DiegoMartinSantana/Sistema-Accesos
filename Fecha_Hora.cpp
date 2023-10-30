#include "Fecha_Hora.h"
#include "Fecha.h"
#include "Horario.h"

#include<iostream>
using namespace std;


Fecha_Hora::Fecha_Hora()
{
    _fecha = Fecha();
    _horario = Horario();

}

Fecha_Hora::Fecha_Hora(int seg, int minuto, int hora, int dia, int mes, int anio) {

    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
    _horario.setSegundo(seg);
    _horario.setMinuto(minuto);
    _horario.setHora(hora);


}

Fecha_Hora::Fecha_Hora(Fecha fecha, Horario horario) {

    setHorario(horario);
    setFecha(fecha);


}


std::string Fecha_Hora::toString() {
    string fecha, horario, devolver;

    fecha = _fecha.toString();
    horario = _horario.toString();
    devolver = "LA FECHA ES " + fecha + "  Y LA HORA ES : " + horario;
    return devolver;

}

void Fecha_Hora::setFecha(int dia, int mes, int anio) {
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);

}
void Fecha_Hora::setHorario(int seg, int minuto, int hora) {
    _horario = Horario(seg, minuto, hora);


}

void Fecha_Hora::setFecha(Fecha fecha) {

    _fecha.setDia(fecha.getDia());
    _fecha.setMes(fecha.getMes());
    _fecha.setAnio(fecha.getAnio());



}

void Fecha_Hora::setHorario(Horario horario) {
    _horario.cargar(horario.getSegundo(), horario.getMinuto(), horario.getHora());
}

Fecha Fecha_Hora::getFecha() { return _fecha; }
Horario Fecha_Hora::getHorario() { return _horario; }

