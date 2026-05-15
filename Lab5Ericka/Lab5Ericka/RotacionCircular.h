#ifndef ROTACION_CIRCULAR_H
#define ROTACION_CIRCULAR_H

#include "NodoLocutor.h"

namespace EIF201 {
	class RotacionCircular {
	private:
		NodoLocutor* cola;//invariante: cola->siguiente == cabeza (si no es nullptr)
		NodoLocutor* cabeza;
		NodoLocutor* actual;
		int cantidad;

		//metodo auxiliar privado: retorna la cabeza de forma segura
		NodoLocutor* getCabeza() const;

	public:
		RotacionCircular();
		~RotacionCircular();


		//insercion: incorpora un locutor al final de la rotacion (antes de la cabeza)
		void insertarAlFinal(const string& nombre);

		//incorpora un locutor al inicio (se convierte en la nueva cabeza)
		void insertarAlInicio(const string& nombre);

		//inserta un nuevo locutor justo despues del locutor de referencia. Retorna false si la referencia no existe
		bool insertarDespuesDe(const string& referenca, const string& nuevo_nombre);

		//busqueda: verifica si un locutr existe en la rotacion
		bool existeLocutor(const string& nombre) const;

		//retorna la posicion (0-indexed). Retorna -1 si no existe
		int obtenerPosicion(const string& nombre) const;

		//retorna el nombre del locutor que tiene el turno actual (cabeza)
		string turnoActual() const;

		//eliminacion: elimina unun locutor de la rotacion por nombre
		bool eliminarLocutor(const string& nombre);

		//elmina al locutor que tiene el turno actual (cabeza)
		bool eliminarTurnoActual();

		//avanza al siguiente turno y retorna el nombre del nuevo turno activo
		string siguiente();

		void imprimirEstadisticas() const;

		string locutorMasActivo() const;

		//simula n turnos imprimiendo que locutor corresponde a cada uno
		void simularTurnos(int n);

		//imprime la rotacion completa empezando desde la cabeza
		void imprimirRotacion() const;

		int getCantidad() const;
		bool estaVacia() const;
	};
}



#endif

