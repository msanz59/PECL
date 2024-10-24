#ifndef GESTOR_HPP
#define GESTOR_HPP

class Gestor
{
public:
	Gestor();
	~Gestor();
	void genera12Procesos();
	void muestraProcesos();
	void borraProcesosPila();
	void encolarProcesos();
	void muestraProcesosGPUs0y1();
	void muestraProcesosGPUs2y3();
	void borraProcesosColas();
	void enlistarProcesos();
	void muestraProcesosNormal();
	void muestraProcesosTiempoReal();
	void buscarProcesos();
	void buscarProcesoPorNombreUsuario();
	void eliminarProcesoPorPID();
	void cambiarPrioridadProcesoPorPID();
	void reiniciar();

};

#endif // GESTOR_HPP
