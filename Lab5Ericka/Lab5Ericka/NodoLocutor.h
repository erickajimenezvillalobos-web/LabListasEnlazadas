#ifndef NODO_LOCUTOR_H
#define NODO_LOCUTOR_H

#include <iostream>
#include <string>

using namespace std;

namespace EIF201 {
	struct NodoLocutor {
		string nombre;
		int turnosAsignados; //nuevo contador
		NodoLocutor* siguiente; //en listas circulares, el ultimo apunta al primero
		NodoLocutor* anterior; //nuevo puntero para rotacion inversa

		NodoLocutor(string nombre)
			:nombre(nombre), turnosAsignados(0), siguiente(nullptr), anterior(nullptr) {

		}
	};
}

#endif
