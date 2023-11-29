#pragma once
#include <string>
class Utilidades
{
public : 
	void validarInt(int &n);
	int contarDigitosInt(int a);
	void validarChar(char& a);
	bool validarDia(int& _dia,int _mes,int _anio);
	void validarMes(int& mes);
	void validarMesActual(int& mes);
	bool validarActualPersonaDiaAutorizacion(int _dia, int _mes, int _anio);

	void validarAnio(int& anio);
	bool validarDiaAutorizacion(int _dia, int _mes, int _anio);
	bool validarActualDiaAutorizacion(int _dia, int _mes, int _anio);
	bool validarAutorizacion(int dni);

	void validarAnioActual(int& anio,int actual);

	std::string _archivoVisitas = "Visitas.dat";
	std::string _archivoMovimientos = "Movimientos.dat";
	std::string _archivoEmpleados = "Empleados.dat";
	std::string _archivoResidentes = "Residentes.dat";
	std::string _archivoProveedores = "Proveedor.dat";
	std::string _archivoAutorizados = "Autorizados.dat";
	std::string _archivoEmpresas = "Empresas.dat";
	std::string _archivoUnidades = "Unidades.dat";


};

