#pragma once
#include <string>
class Gestor_Informes
{

public:

	void UnidadesMayor50movs();
	void InformeProveedoresIngresados();
	void UnidadMasMovsHistorico();
	void UnidadMenorMovsHistorico();
	void MovimientosMensuales();


	void Ejecutar();

private:
	std::string _archivoVisitas = "Visitas.dat";
	std::string _archivoMovimientos = "Movimientos.dat";
	std::string _archivoEmpleados = "Empleados.dat";
	std::string _archivoResidentes = "Residentes.dat";
	std::string _archivoProveedores = "Proveedor.dat";
	std::string _archivoAutorizados = "Autorizados.dat";
	std::string _archivoEmpresas = "Empresas.dat";
	std::string _archivoUnidades = "Unidades.dat";
};

