#pragma once
#include <string>
class SubMenus_Config
{

public:
	void  subMenuBajas();
	void subMenuCopiaSeg();
	void subMenuRestaurarCopiaSeg();

private:
	//originales
	std::string _archivoVisitas = "Visitas.dat";
	std::string _archivoMovimientos = "Movimientos.dat";
	std::string _archivoEmpleados = "Empleados.dat";
	std::string _archivoResidentes = "Residentes.dat";
	std::string _archivoProveedores = "Proveedor.dat";
	std::string _archivoAutorizados = "Autorizados.dat";
	std::string _archivoEmpresas = "Empresas.dat";
	std::string _archivoUnidades = "Unidades.dat";
	std::string _archivoPersonas = "Personas.dat";

	//Seguridad
	// std::string _archivoVisitas = "Visitas.dat";
	std::string _bakArchivoMovimientos = "Movimientos.bak";
	std::string _bakArchivoEmpleados = "Empleados.bak";
	std::string _bakArchivoResidentes = "Residentes.bak";
	std::string _bakArchivoProveedores = "Proveedor.bak";
	std::string _bakArchivoAutorizados = "Autorizados.bak";
	std::string _bakArchivoVisitas = "Visitas.bak";

	std::string _bakArchivoEmpresas = "Empresas.bak";
	std::string _bakArchivoUnidades = "Unidades.bak";
	std::string _bakArchivoPersonas = "Personas.bak";
	
	//copias seg

	bool copiaSegPersonas();
	bool copiaSegAutorizaciones();
	bool copiaSegMovimientos();
	bool copiaSegResidentes();
	bool copiaSegVisitas();
	bool copiaSegEmpleados();
	bool copiaSegProveedores();
	bool copiaSegTodosArchivos();

	//restauracion



};

