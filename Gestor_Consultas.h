#pragma once
class Gestor_Consultas
{


	void AutorizadosporDni();
	void AutorizadosporApellido();
	void ResidentesporIdUnidad();
	void ResidentesporApellido();
	void ProveedoresporRazonSocial();
	void ProveedoresporDni();
	void EmpleadoporNroLegajo();
	void EmpleadoporApellido();
	void UnidadesporId();

public:
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
	std::string _archivoPersonas = "Personas.dat";



};

