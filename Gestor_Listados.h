#pragma once
class Gestor_Listados
{
	void AutorizadosOrdenadosporApellido();
	void AutorizadosOrdenadosporDni();

	void ResidentesOrdenadosporIdUnidad();

	void ProveedoreOrdenadosporRazonSocial();

	void EmpleadosOrdenadosporDni();
	void UnidadesporId();
	void UnidadesOrdenadasporApellidoFamilia();

public:
	void Ejecutar();
private:
	std::string _archivoEmpleados = "Empleados.dat";
	std::string _archivoResidentes = "Residentes.dat";
	std::string _archivoProveedores = "Proveedor.dat";
	std::string _archivoUnidades = "Unidades.dat";
	std::string _archivoAutorizados = "Autorizados.dat";

};

