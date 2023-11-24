#include <iostream>
#include "ArchivosTemplate.h"
#include "Utilidades.h"
#include "Fecha.h"
using namespace std;




void Utilidades::validarInt(int &n) {

		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cin >> n;
		}
}
void Utilidades::validarChar(char& a) {
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cin >> a;
	}

}

int Utilidades::contarDigitosInt(int a) {
	// cuento en un whuke y divido x 10. hice ejercicio parecido en progra 1
	int con = 0;
	if (a == 0) {
		return 1;
	}
	else {

		while (a > 0) {
			a = a / 10; // asi elimino los digitos
			con++;
		}
		
	}
	return con;
}
void Utilidades::validarMesActual(int& mes) {
    Fecha actual;
    while (mes>actual.getMes() || mes <1 || mes >12) {

        cout << "Mes invalido , ingrese nuevamente" << endl;
        cin >> mes;
        validarInt(mes);
    }
}
void Utilidades::validarMes(int& mes) {

	while (mes < 1 || mes > 12) {

		cout << "Mes invalido , ingrese nuevamente" << endl;
		cin >> mes;
		validarInt(mes);
	}
}
bool Utilidades::validarDia(int& _dia,int _mes,int _anio) {

    if (_dia > 0 && _dia < 32 && _mes>0 && _mes < 13 && _anio >= 1920) {

        switch (_mes) {
        case 1:
            return true;

            break;

        case 2:
            if (_dia <= 28 && _anio % 4 != 0) {
                return true;
            }

            if (_anio % 4 == 0 && _dia <= 29) {
                return true;
            }
            return false;

            break;

        case 3:
            return true;

            break;
        case 4:
            if (_dia <= 30) {
                return true;
            }
            else {
                return false;
            }

            break;
        case 5:
            return true;
            break;
        case 6:
            if (_dia <= 30) {

                return true;
            }
            else {
                return false;
            }

            break;
        case 7:
            return true;

            break;
        case 8:
            return true;

            break;
        case 9:
            if (_dia <= 30) {
                return true;

            }
            else {
                return false;
            }
            break;
        case 10:
            return true;

            break;

        case 11:
            if (_dia <= 30) {

                return true;

            }
            else {
                return false;

            }
            break;

        case 12:
            return true;

            break;

        default:
            return false;
            break;
        }

    }
    else {
        return false;
    }

}



void Utilidades::validarAnioActual(int& anio,int actual) {
	while (anio < 1920 || anio > actual ){ // nacimiento hasta actual 
		cout << "Anio Invalido " << endl;
		cin >> anio;
		validarInt(anio);
	}

}
void  Utilidades::validarAnio(int& anio) {
	while (anio < 1920 || anio > 2030) { 
		cout << "Anio Invalido " << endl;
		cin >> anio;
		validarInt(anio);
	}
}
bool Utilidades::validarActualPersonaDiaAutorizacion(int _dia, int _mes, int _anio) {

    Fecha f;

    if (_dia < f.getDia() && _dia < 32 && _dia>0  && _mes >0 &&_mes == f.getMes() && _mes < 13 && _anio == f.getAnio()) {

        switch (_mes) {
        case 1:
            return true;

            break;

        case 2:
            if (_dia <= 28 && _anio % 4 != 0) {
                return true;
            }

            if (_anio % 4 == 0 && _dia <= 29) {
                return true;
            }
            return false;

            break;

        case 3:
            return true;

            break;
        case 4:
            if (_dia <= 30) {
                return true;
            }
            else {
                return false;
            }

            break;
        case 5:
            return true;
            break;
        case 6:
            if (_dia <= 30) {

                return true;
            }
            else {
                return false;
            }

            break;
        case 7:
            return true;

            break;
        case 8:
            return true;

            break;
        case 9:
            if (_dia <= 30) {
                return true;

            }
            else {
                return false;
            }
            break;
        case 10:
            return true;

            break;

        case 11:
            if (_dia <= 30) {

                return true;

            }
            else {
                return false;

            }
            break;

        case 12:
            return true;

            break;

        default:
            return false;
            break;
        }

    }
    else {
        return false;
    }
}

bool Utilidades::validarActualDiaAutorizacion(int _dia, int _mes, int _anio) {

    Fecha f;

    if (_dia > f.getDia() && _dia < 32 && _mes == f.getMes() && _mes < 13 && _anio == f.getAnio()) {

        switch (_mes) {
        case 1:
            return true;

            break;

        case 2:
            if (_dia <= 28 && _anio % 4 != 0) {
                return true;
            }

            if (_anio % 4 == 0 && _dia <= 29) {
                return true;
            }
            return false;

            break;

        case 3:
            return true;

            break;
        case 4:
            if (_dia <= 30) {
                return true;
            }
            else {
                return false;
            }

            break;
        case 5:
            return true;
            break;
        case 6:
            if (_dia <= 30) {

                return true;
            }
            else {
                return false;
            }

            break;
        case 7:
            return true;

            break;
        case 8:
            return true;

            break;
        case 9:
            if (_dia <= 30) {
                return true;

            }
            else {
                return false;
            }
            break;
        case 10:
            return true;

            break;

        case 11:
            if (_dia <= 30) {

                return true;

            }
            else {
                return false;

            }
            break;

        case 12:
            return true;

            break;

        default:
            return false;
            break;
        }

    }
    else {
        return false;
    }
}

bool Utilidades::validarDiaAutorizacion(int _dia,int _mes,int _anio) {
   

    if (_dia > 0 && _dia < 32 && _mes>0 && _mes < 13 && _anio >=2023) {

        switch (_mes) {
        case 1:
            return true;

            break;

        case 2:
            if (_dia <= 28 && _anio % 4 != 0) {
                return true;
            }

            if (_anio % 4 == 0 && _dia <= 29) {
                return true;
            }
            return false;

            break;

        case 3:
            return true;

            break;
        case 4:
            if (_dia <= 30) {
                return true;
            }
            else {
                return false;
            }

            break;
        case 5:
            return true;
            break;
        case 6:
            if (_dia <= 30) {

                return true;
            }
            else {
                return false;
            }

            break;
        case 7:
            return true;

            break;
        case 8:
            return true;

            break;
        case 9:
            if (_dia <= 30) {
                return true;

            }
            else {
                return false;
            }
            break;
        case 10:
            return true;

            break;

        case 11:
            if (_dia <= 30) {

                return true;

            }
            else {
                return false;

            }
            break;

        case 12:
            return true;

            break;

        default:
            return false;
            break;
        }

    }
    else {
        return false;
    }


}