#pragma once

#include"Nodo.h"

template<class tipo>
class Lista {


private:

	Nodo<tipo> * L;

public:

	//------------------------------//
	//			Costruttori			//
	//------------------------------//
	//Costruttore di default
	Lista();

	//------------------------------//
	//			Distruttore			//
	//------------------------------//
	//Distruttore
	~Lista();

	//------------------------------//
	//			Inserimenti			//
	//------------------------------//

	//Inserisce un nodo all'inzio
	void InserisciInTesta(tipo);
	//Inserisce un nodo alla fine
	void InserisciInCoda(tipo);
	//Inserisce un nodo in maniera ordinata
	void Inserisci(tipo);

	//Modifica un elemento con un altro
	void Modifica(tipo, tipo);

	//------------------------------//
	//			EliminaCose			//
	//------------------------------//
	//Ricerca un nodo e lo elimina
	void Elimina(tipo);
	//Elimina il nodo in testa
	void EliminaTesta();
	//Elimina l'ultimo Nodo
	void EliminaInCoda();

	//------------------------------//
	// 			Operazioni		    //
	//------------------------------//

	//Ricerca un dato
	//Restituisce il puntatore al quel nodo
	Nodo<tipo> * Ricerca(tipo);

	//Inverte la lista
	void Inverti();

	//------------------------------//
	//			Visualizza			//
	//------------------------------//

	//Stampa la lista
	void Visualizza();

	//Ritorna il puntatore di inizio lista
	Nodo<tipo>* getListPointer();
};
