#include "HistorialDoble.h"

namespace EIF201 {
	HistorialDoble::HistorialDoble()
		: cabeza(nullptr), cola(nullptr), cantidad(0) {
	}

	HistorialDoble::~HistorialDoble() {
		if (cabeza == nullptr) {
			return;
		}
		cola->siguiente = nullptr;

		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			NodoHistorial* temp = actual->siguiente;
			delete actual;
			actual = temp;
		}
		cabeza = nullptr;
		cola = nullptr;
		cantidad = 0;
		cout << "[HistorialDoble destruido]" << endl;
	}

	void HistorialDoble::insertarAlInicio(const string& cancion) {
		NodoHistorial* nuevo = new NodoHistorial(cancion);

		if (cabeza == NULL) {
			cabeza = nuevo;
			cola = nuevo;

			cabeza->siguiente = cabeza;
			cabeza->anterior = cabeza;
		}
		else {
			nuevo->siguiente = cabeza;
			nuevo->anterior = cola;

			cola->siguiente = nuevo;
			cabeza = nuevo;
		}
		cout << "[NodoHistorial creado: " << cancion << " ]" << endl;
	}

	void HistorialDoble::insertarAlFinal(const string& cancion) {
		NodoHistorial* nuevo = new NodoHistorial(cancion);
		if (cola == nullptr) {
			cabeza = nuevo;
			cola = nuevo;

			cabeza->siguiente = cabeza;
			cabeza->anterior = cabeza;
		}
		else {
			nuevo->anterior = cola;
			nuevo->siguiente = cabeza;

			cola->siguiente = nuevo;
			cabeza->anterior = nuevo;
			cola = nuevo;
		}
		cantidad++;
		cout << "[NodoHistorial creado: " << cancion << " ]" << endl;

	}

	void HistorialDoble::insertarEnPosicion(const string& cancion, int pos) {
		if (pos <= 0) {
			insertarAlInicio(cancion);
			return;
		}
		if (pos >= cantidad) {
			insertarAlFinal(cancion);
			return;
		}

		NodoHistorial* nuevo = new NodoHistorial(cancion);
		NodoHistorial* actual = cabeza;

		for (int i = 0; i < pos; i++) {
			actual = actual->siguiente;
		}
		// 'actual' es el nodo que quedara despues del nuevo

		NodoHistorial* previo = actual->anterior;
		nuevo->siguiente = actual; //nuevo -> actual
		nuevo->anterior = previo; //precio <- nuevo
		previo->siguiente = nuevo; //previo -> nuevo (reemplaza a actual)
		actual->anterior = nuevo; //nuevo <- actual
		cantidad++;
	}

	bool HistorialDoble::insertarAntesDe(const string& referencia, const string& nueva) {
		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			if (actual->cancion == referencia) {
				if (actual == cabeza) {
					insertarAlInicio(nueva);
				}
				else {
					NodoHistorial* nuevo = new NodoHistorial(nueva);
					NodoHistorial* previo = actual->anterior;
					nuevo->siguiente = actual;
					nuevo->anterior = previo;
					previo->siguiente = nuevo;
					actual->anterior = nuevo;
					cantidad++;
				}
				return true;
			}
			actual = actual->siguiente;
		}
		return false; //referencia no encontrada
	}

	bool HistorialDoble::insertarDespuesDe(const string& referencia, const string& nueva) {
		if (cabeza == nullptr) {
			return false;
		}
		NodoHistorial* actual = cabeza;

		do {
			if (actual->cancion == referencia) {
				if (actual == cola) {
					insertarAlFinal(nueva);
				}
				else {
					NodoHistorial* nuevo = new NodoHistorial(nueva);
					NodoHistorial* siguiente = actual->siguiente;

					nuevo->anterior = actual;
					nuevo->siguiente = siguiente;
					actual->siguiente = nuevo;
					siguiente->anterior = nuevo;

					cantidad++;
				}
				return true;
			}
			actual = actual->siguiente;
		} while (actual != cabeza);
		return false;
	}

	bool HistorialDoble::existeCancion(const string& cancion) const {
		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			if (actual->cancion == cancion) {
				return true;
			}
			actual = actual->siguiente;
		}
		return false;
	}

	int HistorialDoble::obtenerPosicion(const string& cancion) const {
		NodoHistorial* actual = cabeza;
		int pos = 0;
		while (actual != nullptr) {
			if (actual->cancion == cancion) {
				return pos;
			}
			actual = actual->siguiente;
			pos++;
		}
		return -1;
	}

	string HistorialDoble::obtenerEnPosicion(int pos) const {
		if (pos < 0 || pos >= cantidad) {
			return "";
		}
		NodoHistorial* actual = cabeza;
		for (int i = 0; i < pos; i++) {
			actual = actual->siguiente;
		}
		return actual->cancion;
	}

	int HistorialDoble::obtenerPosicionDesdeElFinal(const string& cancion) const {
		NodoHistorial* actual = cola;
		int pos = 0;
		while (actual != nullptr) {
			if (actual->cancion == cancion) {
				return pos;
			}
			actual = actual->anterior;
			pos++;
		}
		return -1;
	}

	bool HistorialDoble::eliminarPrimera(const string& cancion) {
		if (cabeza == nullptr) {
			return false;
		}
		NodoHistorial* actual = cabeza;

		do {
			if (actual->cancion == cancion) {
				if (cantidad == 1) {
					cabeza = nullptr;
					cola = nullptr;
				}
				else {
					actual->anterior->siguiente = actual->siguiente;
					actual->siguiente->anterior = actual->anterior;

					if (actual == cabeza) {
						cabeza = actual->siguiente;
					}
					if (actual == cola) {
						cola = actual->anterior;
					}
				}
				delete actual;
				cantidad--;
				return true;
			}
			actual = actual->siguiente;
		} while (actual != cabeza);

		return false;
	}

	bool HistorialDoble::eliminarUltima(const string& cancion) {
		if (cola == nullptr) {
			return false;
		}
		NodoHistorial* actual = cola;

		do {
			if (actual->cancion == cancion) {
				if (cantidad == 1) {
					cabeza = nullptr;
					cola = nullptr;
				}
				else {
					actual->anterior->siguiente = actual->siguiente;
					actual->siguiente->anterior = actual->anterior;

					if (actual == cabeza) {
						cabeza = actual->siguiente;
					}
					if (actual == cola) {
						cola = actual->anterior;
					}
				}
				delete actual;
				cantidad--;
				return true;
			}
			actual = actual->anterior;
		} while (actual != cola);
		return false;
	}


	bool HistorialDoble::eliminarEnPosicion(int pos) {
		if (pos < 0 || pos >= cantidad) {
			return false;
		}
		if (pos == 0) {
			return eliminarCabeza();
		}
		if (pos == cantidad - 1) {
			return eliminarCola();
		}

		NodoHistorial* actual = cabeza;
		for (int i = 0; i < pos; i++) {
			actual = actual->siguiente;
		}

		actual->anterior->siguiente = actual->siguiente;
		actual->siguiente->anterior = actual->anterior;
		delete actual;
		actual = nullptr;
		cantidad--;
		return true;
	}

	bool HistorialDoble::eliminarCabeza() {
		if (cabeza == nullptr) {
			return false;
		}
		return eliminarPrimera(cabeza->cancion);
	}

	bool HistorialDoble::eliminarCola() {
		if (cola == nullptr) {
			return false;
		}
		return eliminarPrimera(cola->cancion);
	}

	void HistorialDoble::imprimirCronologico() const {
		if (cabeza == nullptr) {
			cout << "Historial vacio" << endl;
			return;
		}

		NodoHistorial* actual = cabeza;
		cout << "Cronologico: ";

		do {
			cout << actual->cancion;
			actual = actual->siguiente;
			if (actual != cabeza) {
				cout << " <-> ";
			}
		} while (actual != cabeza);

		cout << " (Circular)" << endl;
	}

	void HistorialDoble::imprimirInverso() const {
		if (cola == nullptr) {
			cout << "Historial vacio" << endl;
			return;
		}

		NodoHistorial* temp = cola;
		cout << "Inverso: ";
		do {
			cout << temp->cancion;
			temp = temp->anterior;
			if (temp != cola) {
				cout << " <-> ";
			}
		} while (temp != cola);
		cout << " (Circular)" << endl;
	}

	int HistorialDoble::getCantidad() const {
		return cantidad;
	}

	bool HistorialDoble::estaVacia() const {
		return cabeza == nullptr;
	}
}