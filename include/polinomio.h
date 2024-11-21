#ifndef POLINOMIO_H
#define POLINOMIO_H

#include "monomio.h"
#include <string>

struct Polinomio {
	Monomio* head;

	Polinomio (){
		this->head = nullptr;
	}

	void inserir(int coef, int expo);
	void Simplificar();
	int G() const;
	int T() const;
	float Avaliar(int variavel) const;
	std::string P() const;
	friend Polinomio operator+(const Polinomio& poli1, const Polinomio& poli2);
	friend Polinomio operator-(const Polinomio& poli1, const Polinomio& poli2);
	friend Polinomio operator*(const Polinomio& poli1, const Polinomio& poli2);
	friend std::ostream& operator<<(std::ostream& os, const Polinomio& poli);
	~Polinomio();
};

#endif