#include "HistorialDoble.h"
#include "RotacionCircular.h"
using namespace EIF201;

int main() {

	//modulo A - HistorialDoble
	cout << "\nMODULO A: HistorialDoble" << endl;
	{
		HistorialDoble h;

		//insercion
		h.insertarAlFinal("rock1");
		h.insertarAlFinal("pop7");
		h.insertarAlFinal("jazz3");
		h.insertarAlInicio("clas5");
		h.insertarEnPosicion("folk2", 2);
		h.insertarAntesDe("jazz3", "bosa1");
		h.insertarDespuesDe("pop7", "soul4");
		h.imprimirCronologico();
		//esperando: clas5 <-> rock1 <-> folk2 <-> bosa1 <-> pop7 <-> soul4 <-> jazz3
		h.imprimirInverso();
		//esperando: jazz3 <-> bosa1 <-> soul4 <-> pop7 <-> folk2 <-> rock1 <-> clas5

		//busqueda
		cout << "Posicion jazz3: " << h.obtenerEnPosicion(6);
		cout << "Cancion en posicion 0: " << h.obtenerEnPosicion(0);
		cout << "jazz3 existe: " << (h.existeCancion("jazz3") ? "si" : "no") << endl;
		cout << "Posicion desde final pop7: " << h.obtenerPosicionDesdeElFinal("pop7") << endl;

		//eliminacion
		h.eliminarPrimera("bosa1");
		h.eliminarCabeza();
		h.eliminarCola();
		h.eliminarEnPosicion(1);
		h.eliminarUltima("pop7");
		h.imprimirCronologico();
		//esperando: rock1 <-> soul4
		cout << "----- FIN DEL MODULO A -----" << endl;
		//destructor libera rock1 y soul4
	}

	//MODULO B- RotacionCircular
	cout << "\nMODULO B: RotacionCircular" << endl;
	{
		RotacionCircular r;

		//insercion
		r.insertarAlFinal("Maria");
		r.insertarAlFinal("Carlos");
		r.insertarAlFinal("Adrianna");
		r.insertarAlInicio("Diego");
		r.insertarDespuesDe("Carlos", "Elena");
		r.imprimirRotacion();


		cout << "Carlos existe: " << (r.existeLocutor("Carlos") ? "si" : "no") << endl;
		cout << "Posicion Carlos: " << r.obtenerPosicion("Carlos") << endl;
		cout << "Turno actual: " << r.turnoActual() << endl;

		r.simularTurnos(7);
		r.imprimirEstadisticas();
		cout << "Locutor mas activo: " << r.locutorMasActivo() << endl;

		r.eliminarLocutor("Carlos");
		r.eliminarTurnoActual();
		r.imprimirRotacion();

		cout << "Cantidad: " << r.getCantidad() << endl;

		r.eliminarLocutor("Adrianna");
		while (!r.estaVacia()) {
			r.eliminarTurnoActual();
		}
		cout << "Vacia: " << (r.estaVacia() ? "si" : "no") << endl;
		cout << "Siguiente vacia: " << r.siguiente() << "´" << endl;
	}
	return 0;
}

