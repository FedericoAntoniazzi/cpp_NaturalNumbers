#include "Nodo.h"
template <class tipo>

Nodo<tipo>::Nodo(){
    punt = nullptr;
}

template <class tipo>
Nodo<tipo>::Nodo(tipo x) {
	punt = nullptr;
	info = x;
}

template <class tipo>
tipo Nodo<tipo>::getInfo() {
	return info;
}

template <class tipo>
void Nodo<tipo>::setInfo(tipo x) {
	info = x;
}

template <class tipo>
Nodo<tipo>* Nodo<tipo>::getPunt() {
	return punt;
}

template <class tipo>
void Nodo<tipo>::setPunt(Nodo<tipo>* P) {
	punt = P;
}

template <class tipo>
Nodo<tipo>::~Nodo() {
}
