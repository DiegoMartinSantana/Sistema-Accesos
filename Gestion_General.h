#pragma once
#include <string>
class Gestion_General
{
	//aca tendre las altas , bajas  TODO
public:
	//altas
	void altaEntrada_Salida();
	void altaVisita();
	void altaEmpleado();
	void altaResidente_inquilino();
	void altaProveedor();
	//consultas

private:

	std::string _archivoVisitas = "Visitas.dat";
	std::string _archivoMovimientos = "Movimientos.dat";
	std::string _archivoEmpleados = "Empleados.dat";
	std::string _archivoResidentes = "Residentes.dat";
	std::string _archivoProveedores= "Proveedor.dat";


};

