#pragma once
#include <string>
class Horario
{

    public:
        int getSegundo();
        int getMinuto();
        int getHora();
        void setSegundo(int segundo);
        void setMinuto(int minuto);
        void setHora(int hora);
        Horario();
        Horario(int segundo, int minuto, int hora);
        std::string toString();
        void cargar(int seg, int minuto, int hora);
    private:
        int _hora, _minuto, _segundo;

    };


