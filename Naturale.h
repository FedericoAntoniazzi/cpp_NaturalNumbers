#pragma once
#include"Lista.h"
#include"Lista.cpp"
#include"Nodo.h"
#include"Nodo.cpp"
#include<iostream>

class Naturale {

	//------------------------------//
	//			Operatori			//
	//------------------------------//

	friend istream & operator>>(istream&, Naturale&);

	friend ostream & operator<<(ostream&, Naturale&);

	friend Naturale operator +(Naturale&, Naturale&);

	friend Naturale operator*(Naturale&, Naturale&);
	friend Naturale operator*(Naturale&, int);

	//friend void operator ^(Naturale&, Naturale);

private:
	Lista <int>numero;

public:
	//------------------------------//
	//	    	Costruttore   		//
	//------------------------------//
	Naturale();

	Naturale(int);

	Naturale(const Naturale& other);

	//------------------------------//
	//			Distruttore			//
	//------------------------------//
	~Naturale();

	//------------------------------//
	//			Operatori			//
	//------------------------------//
	void operator ++(int);
    void operator ++();
	void operator --(int);
    void operator --();

	//Copia la lista in un'altra
	//Naturale operator =(Naturale&);
    Naturale operator =(const Naturale&);

	//Azzera tutta la lista
	void Zero();

	//Controlla se il numero è zero
	bool isZero();

	//Fattoriale del naturale
	Naturale operator !();
};
