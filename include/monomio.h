#ifndef MONOMIO_H
#define MONOMIO_H

struct Monomio {
	float coef;
	int expo;
	Monomio* prox;

	Monomio (float coef, int expo){
		this->coef = coef;
		this->expo = expo;
		prox = nullptr;
	}
};

#endif