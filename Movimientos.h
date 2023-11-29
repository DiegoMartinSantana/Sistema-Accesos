#pragma once

#include <iostream>
#include "Persona.h"
#include "Fecha_Hora.h"
class Movimientos
{

	
	public:

		//movimientos constructor por defecto para poder hacer el movimiento automatico !
		Movimientos(int idunidad,int dni, int sentido,std::string observacion,int tipoautorizacion);
		Movimientos();
		
		int  getDni();
		int getUnidad();
		Fecha_Hora getFechayHoraMovimiento();
		bool getSentido();
		std::string getObservaciones();
		std::string getTipoAutorizacion();
		void setDni(int dni);
		void setUnidad(int unidad);
		void setFechayHoraMovimiento(Fecha_Hora fechahora);
		void setSentido(bool sentido); //true entra , false sale.
		void setObservaciones(std::string observaciones);
		void setTipoAutorizacion(int  tipoautorizacion);
		bool cargar();
		void mostrar();
	private:
		int  _idunidad;
		int _dnipersona;
		Fecha_Hora _fechayhora;
		bool _sentido;
		char _observaciones[300];
		int _tipoAutorizacion; // permamente o telefonica
	
	



};

