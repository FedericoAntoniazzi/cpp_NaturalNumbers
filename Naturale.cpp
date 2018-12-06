#include "Naturale.h"
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

//------------------------------------------------------//
//                     Costruttore						//
//------------------------------------------------------//
Naturale::Naturale() {
    numero.InserisciInTesta(0);
}

Naturale::Naturale(int n) {
	numero.InserisciInTesta(n);
}

//Costruttore di copia
Naturale::Naturale(const Naturale& nat){
    numero = nat.numero;
}


Naturale::~Naturale() {}

bool ValidoInput(int x) {
	return x >= 0;
	//&& x != floor(x));
}

//------------------------------------------------------//
// 	                    friend							//
//------------------------------------------------------//

//------------------------------//
//              Input			//
//------------------------------//

istream & operator>>(istream &cin, Naturale &nat) {

    //Numero inserito dall'utente
    int n;
    do {

        cin >> n;

        //Controllo
    } while (!(ValidoInput(n)));

    //Scansiona tutte le cifre del numero
    //Le inserisce in testa alla lista

    if(n == 0){
        return cin;
    }

    nat.numero.Elimina(0);

    while (n != 0) {

        //Ottiene la prima cifra del numero
        //Inserisce in testa la cifra ottenuta
        nat.numero.InserisciInCoda(n % 10);

        //Sposta la seconda cifra in prima posizione
        n /= 10;

    }

	return cin;
}

//------------------------------//
//            Output			//
//------------------------------//

ostream &operator<<(ostream &cout, Naturale &nat) {

	Nodo<int>* p = nat.numero.getListPointer();
	int per = 1;
	//Contiene la lista
	int enne = 0;

	//Finchè il puntatore non punta a nullptr
	while (p != nullptr) {
		//Riceve il numero dal nodo
		enne += (p->getInfo()*per);
		per *= 10;
		//Sposta p al nodo successivo
		p = p->getPunt();
	}

	//Stampa la stringa
	cout << enne << endl;

	return cout;
}



Naturale Naturale::operator= (const Naturale &nuovo) {

    //Azzera la lista
    Zero();

    //Rimuove lo zero di default
    numero.Elimina(0);

    Nodo<int>* p = numero.getListPointer();

    //Finchè la lista non è vuota
    while (p != nullptr) {

        //Copia la lista
        numero.InserisciInCoda(p->getInfo());

        p = p->getPunt();

    }

    return *this;

}



//------------------------------//
//              +				//
//------------------------------//
Naturale operator+(Naturale &n1, Naturale &n2) {

	//Se n1 contiene solo 0
	if (n1.numero.getListPointer()->getInfo() == 0 && n1.numero.getListPointer()->getPunt() == nullptr) {
		return n2;
	}

    //Se n2 contiene solo 0
    if (n2.numero.getListPointer()->getInfo() == 0 && n2.numero.getListPointer()->getPunt() == nullptr) {
        return n1;
    }


    //while(!n1.isZero() && !)



	//Fino a quando non arriva alla fine di una Lista
	while (!n2.isZero()) {
        n1++;
        n2--;
    }

	return n1;
}



//Prefisso
void Naturale::operator--(int) {

    Nodo<int> *p = numero.getListPointer();

    //Caso lista vuota
    if(p == nullptr) {
        return;
    }

    //Zero come unico elemento
    if(p->getPunt()== nullptr && p->getInfo()==0){
        return;
    }

    //Se è diverso da 0 si decrementa di uno
    if (p->getInfo() != 0) {

        p->setInfo(p->getInfo() - 1);

        //Caso 0
        //Ci sono riporti
    } else {

        //Fino a quando il valore è 0
        //Viene settato a 9
        //La lista finisce con un numero diverso da 0 -> Non serve controllo
        while (p->getInfo() == 0) {
            p->setInfo(9);
            p = p->getPunt();
        }

        //Numero diverso da 1 e da 0
        //Diverso da 0 perchè uscito dal while
        if(p->getInfo() != 1){
            p->setInfo( p->getInfo() - 1 );

            //Caso == 1
        }else{

            //Se l'ultimo nodo della lista vale 1
            if(p->getPunt() == nullptr){
                numero.EliminaInCoda();
                //Ha altri elementi in coda
            }else{
                //Lo imposta a 0
                p->setInfo( p->getInfo() - 1 );
            }
        }
    }
}



//Postfisso
void Naturale::operator--() {

    Nodo<int> *p = numero.getListPointer();

    //Caso lista vuota
    if(p == nullptr) {
        return;
    }

    //Zero come unico elemento
    if(p->getPunt()== nullptr && p->getInfo()==0){
        return;
    }

    //Se è diverso da 0 si decrementa di uno
    if (p->getInfo() != 0) {

        p->setInfo(p->getInfo() - 1);

        //Caso 0
        //Ci sono riporti
    } else {

        //Fino a quando il valore è 0
        //Viene settato a 9
        //La lista finisce con un numero diverso da 0 -> Non serve controllo
        while (p->getInfo() == 0) {
            p->setInfo(9);
            p = p->getPunt();
        }

        //Numero diverso da 1 e da 0
        //Diverso da 0 perchè uscito dal while
        if(p->getInfo() != 1){
            p->setInfo( p->getInfo() - 1 );

            //Caso == 1
        }else{

            //Se l'ultimo nodo della lista vale 1
            if(p->getPunt() == nullptr){
                numero.EliminaInCoda();
                //Ha altri elementi in coda
            }else{
                //Lo imposta a 0
                p->setInfo( p->getInfo() - 1 );
            }
        }
    }
}



//Prefisso
void Naturale::operator++(int) {

    Nodo<int>* p = numero.getListPointer();

    //Caso lista vuota
    if(p == nullptr) {
        return;
    }

    //Se è diverso da 9 si incrementa di 1
    if (p->getInfo() != 9) {

        p->setInfo(p->getInfo() + 1);

        //Caso 9
        //Ci sono riporti
    } else {

        //Tutti i numeri == 9 vengono settati 0
        //Se l'ultimo elemento == 9 --> Setta 0 e aggiungi 1 in coda
        //Se l'ultimo elemento != 9 --> Incrementa di 1

        //Tutti i numeri == 9 vengono settati a 0
        //Si ferma al penultimo elemento -> Segue gestione
        while ( p->getPunt() != nullptr && p->getInfo() == 9) {
            p->setInfo(0);
            p = p->getPunt();
        }

        //Ultimo elemento
        if( p->getInfo() == 9){

            p->setInfo( 0 );
            numero.InserisciInCoda(1);


            //Diverso da 9
        }else{

            p->setInfo( p->getInfo()+1 );

        }
    }
}



//Postfisso
void Naturale::operator++() {

    Nodo<int>* p = numero.getListPointer();

    //Caso lista vuota
    if(p == nullptr) {
        return;
    }

    //Se è diverso da 9 si incrementa di 1
    if (p->getInfo() != 9) {

        p->setInfo(p->getInfo() + 1);

        //Caso 9
        //Ci sono riporti
    } else {

        //Tutti i numeri == 9 vengono settati 0
        //Se l'ultimo elemento == 9 --> Setta 0 e aggiungi 1 in coda
        //Se l'ultimo elemento != 9 --> Incrementa di 1

        //Tutti i numeri == 9 vengono settati a 0
        //Si ferma al penultimo elemento -> Segue gestione
        while ( p->getPunt() != nullptr && p->getInfo() == 9) {
            p->setInfo(0);
            p = p->getPunt();
        }

        //Ultimo elemento
        if( p->getInfo() == 9){

            p->setInfo( 0 );
            numero.InserisciInCoda(1);


            //Diverso da 9
        }else{

            p->setInfo( p->getInfo()+1 );

        }
    }
}


//------------------------------//
//              *				//
//------------------------------//
Naturale operator*(Naturale & n1, Naturale & n2)

    while (!n2.isZero()) {
        n1 + n1;
        n2--;
    }

    return n1;
}

Naturale operator*(Naturale &n1, int n2){
    while(n2!=0){
        n1+n1;
        n2--;
    }
    return n1;
}



//Quello che imposta a zero il numerino KAWAIIII
void Naturale::Zero() {
	Nodo<int>* p = numero.getListPointer();
	while (p->getPunt() != nullptr) {
		numero.EliminaTesta();
		p = numero.getListPointer();
	}
	p->setInfo(0);
}

//Quello che mostra se il numero è zero o no
bool Naturale::isZero() {
	Nodo<int>* p = numero.getListPointer();
	return (p->getInfo() == 0 && p->getPunt() == nullptr);
}

//Calcola sullo stesso naturale il fattoriale
Naturale Naturale::operator !() {
    Nodo<int>* p = numero.getListPointer();
    if (p->getPunt() == 0 && (p->getInfo() == 0 || p->getInfo() == 1)) {
        this->Zero();
        this->operator++(1);
    }
    p = p->getPunt();
    Naturale copy = *this;
    this->operator--(1);
    return (*this) * copy;
}
