#pragma once

#include <iostream>
#include "Persona.h"
#include "Unidad.h"
#include "Fecha_Hora.h"
class Movimientos
{

	
	public:

		//movimientos constructor por defecto para poder hacer el movimiento automatico !
		Movimientos(int idunidad,int dni, int sentido,std::string observacion,int tipoautorizacion);
		Movimientos();
		
		int  getDni();
		Unidad getUnidad();
		Fecha_Hora getFechayHoraMovimiento();
		int getSentido();
		std::string getObservaciones();
		std::string getTipoAutorizacion();
		bool getEstado();
		void setDni(int dni);
		void setUnidad(Unidad unidad);
		void setFechayHoraMovimiento(Fecha_Hora fechahora);
		void setSentido(bool sentido); //true entra , false sale.
		void setObservaciones(std::string observaciones);
		void setTipoAutorizacion(int  tipoautorizacion);
		void setEstado(bool estado);
		void cargar();
		void mostrar();
	private:
		Unidad _unidad;
		int _dnipersona;
		Fecha_Hora _fechayhora;
		int _sentido;
		char _observaciones[300];
		int _tipoAutorizacion; // permamente o telefonica
		bool _estado;
	



};

