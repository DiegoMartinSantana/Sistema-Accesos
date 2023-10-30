#pragma once
#include "Fecha.h"
#include "horario.h"
class Fecha_Hora
{
    public:
        Fecha getFecha();
        Horario getHorario();
        void setFecha(Fecha fecha);
        void setHorario(Horario horario);
        void setFecha(int dia, int mes, int anio);
        void setHorario(int segundo, int minuto, int hora);
        Fecha_Hora();
        Fecha_Hora(Fecha fecha, Horario horario);
        Fecha_Hora(int dia, int mes, int anio, int segundo, int minuto, int hora);
        std::string toString();
    private:
        Fecha _fecha;
        Horario _horario;
    };


