#ifndef NODO_HISTORIAL_H
#define NODO_HISTORIAL_H
using namespace std;
#include <iostream>
#include <string>
namespace EIF201 {
	struct NodoHistorial {
		std::string cancion;
		NodoHistorial* siguiente;
		NodoHistorial* anterior;



		NodoHistorial(const string& c) :
			cancion(c), siguiente(nullptr), anterior(nullptr) {
			std::cout << "[NodoHistorial creado: " << c << "]";


		}

		~NodoHistorial() {
			std::cout << "[NodoHistorial destruido: " << cancion << "]";

		}

	}

};

#endif