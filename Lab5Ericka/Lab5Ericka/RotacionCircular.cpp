#include "RotacionCircular.h"
#include <iostream>

namespace EIF201 {

	RotacionCircular::RotacionCircular()
		: cabeza(nullptr), cola(nullptr), actual(nullptr), cantidad(0) {
	}


	NodoLocutor* RotacionCircular::getCabeza() const {
		return (cola != nullptr) ? cola->siguiente : nullptr;
	}

	RotacionCircular::~RotacionCircular() {
		if (cola == nullptr) {
			return;
		}
		NodoLocutor* cabeza = cola->siguiente;
		cola->siguiente = nullptr;
		NodoLocutor* actual = cabeza;
		while (actual != nullptr) {
			NodoLocutor* siguiente = actual->siguiente;
			delete actual;
			actual = siguiente;
		}
		cola = nullptr;
		cout << "[RotacionCircular Destruida" << endl;
	}

	void RotacionCircular::insertarAlFinal(const string& nombre) {
		NodoLocutor* nuevo = new NodoLocutor(nombre);
		if (cabeza == nullptr) {
			cabeza = nuevo;
			cola = nuevo;
			actual = nuevo;
			nuevo->siguiente = cabeza;
		}
		else {
			cola->siguiente = nuevo;
			nuevo->siguiente = cabeza;
			cola = nuevo;
		}
		cantidad++;
	}

	void RotacionCircular::insertarAlInicio(const string& nombre) {
		NodoLocutor* nuevo = new NodoLocutor(nombre);
		if (cola == nullptr) {
			nuevo->siguiente = nuevo;
			cola = nuevo;
		}
		else {
			nuevo->siguiente = cola->siguiente; //nuevo->sig = vieja cabeza
			cola->siguiente = nuevo; //cola ahora apunta a nuevo
			//cola no cambia solo cambia cabeza
		}
		cantidad++;
	}

	bool RotacionCircular::insertarDespuesDe(const string& referencia, const string& nuevo_nombre) {
		if (cola == nullptr) {
			return false;
		}
		NodoLocutor* cabeza = getCabeza();
		NodoLocutor* actual = cabeza;
		do {
			if (actual->nombre == referencia) {
				NodoLocutor* nuevo = new NodoLocutor(nuevo_nombre);
				nuevo->siguiente = actual->siguiente;
				actual->siguiente = nuevo;
				if (actual == cola) {
					cola = nuevo; //si era cola, el nuevo es la nueva cola
				}
				cantidad++;
				return true;
			}
			actual = actual->siguiente;
		} while (actual != cabeza);
		return false;
	}

	bool RotacionCircular::existeLocutor(const string& nombre) const {
		if (cabeza == nullptr) {
			return false;
		}
		NodoLocutor* temp = cabeza;

		//se recorre la lista circular
		do {
			//se compara el nombre del nodo actual
			if (temp->nombre == nombre) {
				return true;
			}
			temp = temp->siguiente;
		} while (temp != cabeza); //se termina al volver a la cabeza
		return false; //el ciclo termina si no se encuentra
	}

	int RotacionCircular::obtenerPosicion(const string& nombre) const {
		if (cola == nullptr) {
			return -1;
		}
		NodoLocutor* cabeza = getCabeza();
		NodoLocutor* actual = cabeza;
		int pos = 0;
		do {
			if (actual->nombre == nombre) {
				return pos;
			}
			actual = actual->siguiente;
			pos++;
		} while (actual != cabeza);
		return -1;
	}

	string RotacionCircular::turnoActual() const {
		if (cola == nullptr) {
			return "";
		}
		return getCabeza()->nombre;
	}

	bool RotacionCircular::eliminarLocutor(const string& nombre) {
		if (cola == nullptr) {
			return false;
		}
		NodoLocutor* cabeza = getCabeza();
		NodoLocutor* actual = cabeza;
		NodoLocutor* previo = cola; //el recorrido comienza con previo = cola
		do {
			if (actual->nombre == nombre) {
				if (actual == cola && actual == cabeza) {
					//unico nodo de la lista
					cola == nullptr;
				}
				else {
					previo->siguiente = actual->siguiente; //saltar al actual
					if (actual == cola) {
						cola = previo; //si era la cola, actualizar
					}
					delete actual;
					actual = nullptr;
					cantidad--;
					return true;
				}
			}
			previo = actual;
			actual = actual->siguiente;
		} while (actual != cabeza);
		return false;
	}

	bool RotacionCircular::eliminarTurnoActual() {
		if (cola == nullptr) {
			return false;
		}
		//la cabeza es quien tiene el turno actual
		return eliminarLocutor(getCabeza()->nombre);
	}

	void RotacionCircular::imprimirEstadisticas() const {
		if (cabeza == nullptr) {
			cout << "La lista esta vacia." << endl;
			return;
		}

		NodoLocutor* temp = cabeza;
		do {
			cout << "Locutor: " << temp->nombre
				<< " | Turnos: " << temp->turnosAsignados << endl;
			temp = temp->siguiente;
		} while (temp != cabeza);
	}

	string RotacionCircular::locutorMasActivo() const {
		if (cabeza == nullptr) {
			return "Nadie";
		}
		NodoLocutor* temp = cabeza;
		NodoLocutor* masActivo = cabeza;

		do {
			if (temp->turnosAsignados > masActivo->turnosAsignados) {
				masActivo = temp;
			}
			temp = temp->siguiente;
		} while (temp != cabeza);
		return masActivo->nombre;
	}

	string RotacionCircular::siguiente() {
		if (cabeza == nullptr) {
			return "Lista Vacia";
		}
		actual->turnosAsignados++;
		string nombreLocutor = actual->nombre;

		actual = actual->siguiente;
		return nombreLocutor;
	}

	void RotacionCircular::simularTurnos(int n) {
		if (cabeza == nullptr) {
			cout << "No hay locutores para simular turnos." << endl;
			return;
		}
		for (int i = 0; i < n; i++) {
			cout << "Turno de: " << actual->nombre << endl;

			actual->turnosAsignados++;
			actual = actual->siguiente;
		}
	}

	void RotacionCircular::imprimirRotacion() const {
		if (cola == nullptr) {
			cout << "Rotacion vacia." << endl;
			return;
		}
		NodoLocutor* cabeza = getCabeza();
		NodoLocutor* actual = cabeza;
		cout << "Rotacion: ";
		do {
			cout << actual->nombre;
			actual = actual->siguiente;
			if (actual != cabeza) {
				cout << " -> ";
			}
		} while (actual != cabeza);
		cout << " -> (inicio)" << endl;
	}

	int RotacionCircular::getCantidad() const {
		return cantidad;
	}

	bool RotacionCircular::estaVacia() const {
		return cola == nullptr;
	}
}
