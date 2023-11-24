#include <iostream>
#include "Fecha.h"
#include <ctime>

Fecha::Fecha() {
    time_t t = time(NULL);
    struct tm* f = localtime(&t);
    _dia = (*f).tm_mday; // Indirecciona f y accede a tm_mday
    _mes = f->tm_mon + 1; // Indirecciona f y accede a tm_mon
    _anio = f->tm_year + 1900;
    _diaSemana = f->tm_wday;
}
Fecha::Fecha(int dia, int mes, int anio) {
    cargar(dia, mes, anio);
    _diaSemana = -1;
}
int Fecha::getDia() {
    return _dia;
}
int Fecha::getMes() {
    return _mes;
}
int Fecha::getAnio() {
    return _anio;
}
void Fecha::setDia(int dia) {
    _dia = dia;
}
void Fecha::setMes(int mes) {
    _mes = mes;
}
void Fecha::setAnio(int anio) {
    _anio = anio;
}
void Fecha::cargar(int dia, int mes, int anio) {

    if (dia > 0 && dia < 32 && mes>0 && mes < 13 && anio >0) {

        switch (mes) {
        case 1:
            _dia = dia;
            _mes = mes;
            _anio = anio;

            break;

        case 2:
            if (dia <= 28 && anio % 4 != 0) {
                _dia = dia;
                _mes = mes;
                _anio = anio;
            }

            if (anio % 4 == 0 && dia <= 29) {
                _dia = dia;
                _mes = mes;
                _anio = anio;
            }

            break;

        case 3:
            _dia = dia;
            _mes = mes;
            _anio = anio;

            break;
        case 4:
            if (dia <= 30) {

                _dia = dia;
                _mes = mes;
                _anio = anio;
            }

            break;
        case 5:

            _dia = dia;
            _mes = mes;
            _anio = anio;
            break;
        case 6:
            if (dia <= 30) {

                _dia = dia;
                _mes = mes;
                _anio = anio;
            }

            break;
        case 7:
            _dia = dia;
            _mes = mes;
            _anio = anio;
            break;
        case 8:
            _dia = dia;
            _mes = mes;
            _anio = anio;
            break;
        case 9:
            if (dia <= 30) {

                _dia = dia;
                _mes = mes;
                _anio = anio;
            }
            break;
        case 10:
            _dia = dia;
            _mes = mes;
            _anio = anio;
            break;

        case 11:
            if (dia <= 30) {

                _dia = dia;
                _mes = mes;
                _anio = anio;
            }
            break;

        case 12:
            _dia = dia;
            _mes = mes;
            _anio = anio;
            break;

        default:
            std::cout << "FECHA INVALIDA , ASIGNACION POR DEFECTO : 1/1/2023";
            _dia = 01;
            _mes = 01;
            _anio = 2023;
            system("pause");
            break;
        }

    }

}




std::string Fecha::toString() {
    std::string valorADevolver;
    valorADevolver = std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
    return valorADevolver;
}
std::string Fecha::getNombreDia() {
    std::string nombres[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
    if (_diaSemana >= 0 && _diaSemana <= 6) {
        return nombres[_diaSemana];
    }
    return "";
}
