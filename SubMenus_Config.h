#pragma once
#include <string>
class SubMenus_Config
{

public:
	void  subMenuBajas();
	void subMenuCopiaSeg();
	void subMenuRestaurarCopiaSeg();

private:
	

	//Seguridad
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
	bool resCopiaSegPersonas();
	bool resCopiaSegAutorizaciones();
	bool resCopiaSegMovimientos();
	bool resCopiaSegResidentes();
	bool resCopiaSegVisitas();
	bool resCopiaSegEmpleados();
	bool resCopiaSegProveedores();
	bool resCopiaSegTodosArchivos();


};

