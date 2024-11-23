#ifndef MONOMIO_H
#define MONOMIO_H

struct Monomio {
	int coef;
	int expo;
	Monomio* prox;

	Monomio (int coef, int expo){
		this->coef = coef;
		this->expo = expo;
		prox = nullptr;
	}
};

#endif