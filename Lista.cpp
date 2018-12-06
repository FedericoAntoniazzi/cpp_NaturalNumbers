#include<iostream>

#include "Lista.h"

using namespace std;

//------------------------------------------------------//
//						Costruttore						//
//------------------------------------------------------//
//Inizializza il puntatore di inizio lista a nullptr    //

template <class tipo>
Lista<tipo>::Lista() {

	//Puntatore inizializzato a nulla
	//Condizione di lista vuota
	L = nullptr;
}

//------------------------------------------------------//
//			    		Distruttore	  				    //
//------------------------------------------------------//
template <class tipo>
Lista<tipo>::~Lista() {
}

//------------------------------------------------------//
//					Inserisci in testa					//
//------------------------------------------------------//
//Inserisce un elemento in testa alla lista 			//

template <class tipo>
void Lista<tipo>::InserisciInTesta(tipo x) {

	//Nodo temporaneo
	Nodo<tipo> *p = new Nodo<tipo>(x);
	//Il nodo appena creato sarà il primo nodo della lista
	p->setPunt(L);
	//Inizio lista spostato al primo nodo
	L = p;
}

//------------------------------------------------------//
//					Inserisci in coda					//
//------------------------------------------------------//
//Inserisce un elemento alla fine della lista			//

template <class tipo>
void Lista<tipo>::InserisciInCoda(tipo x) {

	//Creazione del nodo
	Nodo<tipo> *temp = new Nodo<tipo>(x);

	//Copia di L
	Nodo<tipo> *p = L;

	if (L != nullptr) {
		while (p->getPunt() != 0) {
			p = p->getPunt();
		}

		p->setPunt(temp);
		temp->setPunt(0);
	}
	else
		L = temp;
}

//------------------------------------------------------//
//				   Inserimento ordinato	  				//
//------------------------------------------------------//
//Inserisce in ordine crescente un elemento nella lista //
//	NB: Utilizzare esclusivamente questo metodo.		//
//		NON Utilizzare altri metodi di Inserimento		//

template <class tipo>
void Lista<tipo>::Inserisci(tipo x) {

	//Puntatore ad un nuovo nodo
	Nodo<tipo> *p = new Nodo<tipo>(x);

	//Se la lista è vuota o contiene un solo elemento
	if (L == 0 || x < L->getInfo()) {

		//Aggiunge l'elemento alla coda
		p->setPunt(L);
		L = p;

	}
	else {

		//Dichiarazione dei due nodi per scorrere la lista
		Nodo<tipo> *prec = nullptr;
		Nodo<tipo> *succ = L;

		//Sposta i puntatori fino a quando il campo info del nodo succ
		//è minore di x AND non arriva a fine lista
		//NB: Uscita per due condizioni distinte
		while (x > succ->getInfo() && succ->getPunt() != 0) {
			//Sposta i puntatori
			prec = succ;
			succ = succ->getPunt();
		}

		//Se è uscito perchè x è maggiore del precedente e
		//	minore del nodo successivo
//#################### CONDIZIONE DI UGUALE ####################//
		if (x > prec->getInfo() && x < succ->getInfo()) {
			//inserisce il nodo fra prec e succ
			prec->setPunt(p);
			p->setPunt(succ);

			//Se è uscito perchè ha raggiunto la fine della lista
		}
		else {
			//Inserisce il nodo in coda
			succ->setPunt(p);
		}
	}
}

//------------------------------------------------------//
//			    		 Visualizza	  				    //
//------------------------------------------------------//
//Stampa il contenuto della lista						//
//Separa i vari numeri con degli spazi					//

template <class tipo>
void Lista<tipo>::Visualizza() {

	//Nodo temporaneo per scorrere la lista
	Nodo<tipo> *p = L;

	//Fino a quando p non punta a nullptr
	//Ultimo nodo incluso
	while (p != nullptr)

		cout << p->getInfo() << " ";
	p = p->getPunt();
}


//------------------------------------------------------//
//			    		  Elimina	  				    //
//------------------------------------------------------//
//Elimina un nodo										//
//	NB: Eliminazione fisica	quella POTENTE				//

template <class tipo>
void Lista<tipo>::Elimina(tipo x) {

	//Nodo temporaneo per scorrere la Lista
	Nodo<int> *prec = L;

	//lista vuota
	if (prec == nullptr) {
		cout << "Lista vuota.";
		return;
	}

	//un solo elemento
	if (prec->getPunt() == nullptr) {
		L = nullptr;
		delete prec;
		return;
	}

	//Primo elemento
	if (prec->getInfo() == x) {
		L = L->getPunt();
		delete prec;
		return;
	}

	//Puntatore utilizzato per scorrere la lista
	//Posizione successiva a prec
	Nodo<tipo>* succ = prec->getPunt();

	//Scorre la lista fino a quando non trova x AND
	//	non si trova a fine lista
	//NB: Due casi di uscita
	while (succ->getInfo() != x && succ->getPunt() != nullptr) {
		prec = succ;
		succ = succ->getPunt();
	}

	//Se è uscito perchè ha trovato x
	if (succ != nullptr) {

		prec->setPunt(succ->getPunt());
		delete succ;
		//Se è uscito perchè ha raggiunto il fine lista
	}
	else {
		//Controlla l'ultimo nodo
		if (succ->getInfo() == x) {
			delete succ;
		}
		else {
			cout << "Elemento non trovato.";
		}
	}
}

//---------------------------------//
template <class tipo>
void Lista<tipo>::EliminaTesta() {
	Nodo<tipo> *P = L;
	if (P->getPunt() != 0) {
		L = P->getPunt();
		delete P;
	}
}

//--------------------------------//
template <class tipo>
void Lista<tipo>::EliminaInCoda() {

	Nodo<tipo>* suc = L;
	Nodo<tipo>* prec = nullptr;

	//Scorre avanti. Alla fine avrà l'ultimo nodo da eliminare e il penultimo
	//che avrà in Punt zerò poiché diventerà l'ultimo.
	while (suc->getPunt() != 0) {
		prec = suc;
		suc = suc->getPunt();
	}

	prec->setPunt(0);
	delete suc;
}

//------------------------------------------------------//
//			    		  Modifica	  				    //
//------------------------------------------------------//
//Modifica l'informazione n1 con l'informazione n2		//
//  NB:	SOLO la prima occorrenza						//

template <class tipo>
void Lista<tipo>::Modifica(tipo n1, tipo n2) {

	//Nodo temporaneo per scorrere la Lista
	Nodo<tipo> *p = L;

	//Se la lista ha elementi
//######################RIDONDANZA#######################//
	//if (L != 0) {
	//Fino a quando non si raggiunge il fine Lista
	while (p != nullptr) {

		//Se trova il contenuto desiderato
		if (p->getInfo() == n1) {

			//Lo sostituisce
			p->setInfo(n2);
			break;
		}
		else {

			//Sposta p al prossimo nodo
			p = p->getPunt();
		}
	}
}

//------------------------------------------------------//
//			    		  Ricerca	  				    //
//------------------------------------------------------//
//Ricerca un valore all'interno della lista				//
//Ritorna il puntatore al Nodo							//

template <class tipo>
Nodo<tipo>* Lista<tipo>::Ricerca(tipo x) {

	//Nodi per scorrere la Lista
	Nodo<tipo> *succ = L;
	Nodo<tipo> *prec = nullptr;

	//Se la lista è vuota
	if (L == nullptr) {

		cout << "Lista vuota.";
		return nullptr;

	}
	else {

		//Scorre la lista fino a quando:
		//	non raggiunge il fine lista
		//	non trova l'Elemento
		while (succ != nullptr && succ->getInfo() != x) {
			prec = succ;
			succ = succ->getPunt();
		}
		//#######################CHIEDERE#########################//
		return prec;
	}
}

//------------------------------------------------------//
//			    		  Inverti	  				    //
//------------------------------------------------------//
//Inverte la lista -> Modifica la lista attuale			//

template <class tipo>
void Lista<tipo>::Inverti() {

	//Puntatori per scorrere la Lista
	Nodo<tipo> *prec = L;
	Nodo<tipo> *succ = L->getPunt();

	L = succ->getPunt();

	//Fino a fine Lista
	while (L != nullptr) {
		//Inverte il nodo
		succ = succ->setPunt(prec);

		//Prosegue con la lista
		prec = succ;
		succ = L;
		L = L->getPunt();
	}

	succ->setPunt(prec);
	L = succ;
}

//------------------------------------------------------//
//			    		getListPointer 				    //
//------------------------------------------------------//
//semplicemente ritorna L, altrimenti inacessibile
template<class tipo>
Nodo<tipo>* Lista<tipo>::getListPointer() {
	return L;
}
