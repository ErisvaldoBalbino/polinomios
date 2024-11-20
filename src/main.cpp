#include <iostream>
#include "polinomio.cpp"
#include "../include/polinomio.h"

int main(){
	Polinomio p1;
	Polinomio p2;

	p1.inserir(4,2);
	p1.inserir(3,2);

	p2.inserir(-1,1);
	p2.inserir(12,2);

	std::cout << p1 + p2;
	std::cout << p1 - p2;
	std::cout << p1 * p2;

	p1.Simplificar();

	std::cout << p1;
	std::cout << p2;
	std::cout << p1.G();

	return 0;
}