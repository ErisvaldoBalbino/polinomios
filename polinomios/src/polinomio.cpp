#include "../include/polinomio.h"
#include <iostream>
#include <cmath>
#include <string>

/** Insere um monômio no polinômio em ordem decrescente de expoente.
 *  - Se o coeficiente for 0, o monômio não será inserido.
 *
 * @param coef O coeficiente do monômio.
 * @param expo O expoente do monômio.
 *
 * Exemplo:
 *   Se o polinômio atual for 3x^2 e inserir(2, 3) for chamado,
 *   o resultado será 2x^3 + 3x^2 + x.
 */
void Polinomio::inserir(int coef, int expo){
	if (coef == 0) return;

	Monomio* novoMonomio = new Monomio(coef, expo);
	Monomio* temp = head;

	if (head == nullptr || expo > head->expo)
	{
		novoMonomio->prox = head;
		head = novoMonomio;
	}
	else 
	{
		while (temp->prox != nullptr && temp->prox->expo > expo){
			temp = temp->prox;
		}
		novoMonomio->prox = temp->prox;
		temp->prox = novoMonomio;
	}
}

/** Simplifica o polinômio.
 *  - Agrupa monômios com expoentes iguais somando seus coeficientes.
 *  - Remove monômios com coeficiente zero.
 */
void Polinomio::Simplificar() {
	if (head == nullptr) return;

	Monomio* atual = head;
	Monomio* anterior = nullptr;

	// agrupar monomios com o mesmo expoente
	atual = head;
	while (atual != nullptr && atual->prox != nullptr) {
		if (atual->expo == atual->prox->expo) {
			atual->coef += atual->prox->coef;

			// Eliminar o monômio redundante
			Monomio* redundante = atual->prox;
			atual->prox = atual->prox->prox;
			delete redundante;
		} else {
			atual = atual->prox;
		}
	}

	// remover monomios com coeficiente zero
	atual = head;
	anterior = nullptr;
	while (atual != nullptr) {
		if (atual->coef == 0) {
			if (anterior != nullptr) {
				anterior->prox = atual->prox;
			} else {
				head = atual->prox;
			}
			Monomio* remover = atual;
			atual = atual->prox;
			delete remover;
		} else {
			anterior = atual;
			atual = atual->prox;
		}
	}
}

/** Retorna o grau de um polinômio.
 * - Os monômios já estão ordenados, então não é necessário percorrer
 *   o polinômio, apenas retornar o expoente do head.
 *
 * @return O grau do polinômio, ou 0 se o polinômio estiver vazio.
 *
 */
int Polinomio::G() const{
	if (head == nullptr) return 0;

	return head->expo;
}

/** Retorna a quantidade de termos no polinômio.
 *  - Percorre a lista encadeada e conta o número de monômios.
 *
 * @return Número de monômios no polinômio.
 *
 */

int Polinomio::T() const{
	if (head == nullptr) return 0;

	int contador = 0;
	Monomio* atual = head;

	while(atual != nullptr){
		contador++;
		atual = atual->prox;
	}

	return contador;
}

/** Avalia o polinômio para um valor fornecido de variável.
 *  - Substitui a variável pelo valor fornecido e calcula o resultado.
 *
 * @param variavel Valor da variável para avaliação.
 * @return O valor do polinômio avaliado.
 *
 */
float Polinomio::Avaliar(int variavel) const{
	float resultado = 0;

	Monomio* atual = head;

	while(atual != nullptr){
		resultado += atual->coef * pow(variavel, atual->expo);
		atual = atual->prox;
	}

	return resultado;

}

/** Retorna uma representação textual do polinômio.
 *  - Constrói uma string com os monômios.
 *
 * @return Representação textual do polinômio.
 *
 */

std::string Polinomio::P() const {
	if (head == nullptr) {
		return "Não existem termos!";
	}

	Monomio* atual = head;
	std::string resultado;
	bool primeiro = true;

	while (atual != nullptr) {
		if (atual->coef >= 0 && !primeiro) {
			resultado += " + ";
		} else if (atual->coef < 0 && !primeiro) {
			resultado += " ";
		}

		if (atual->coef != 1 || atual->expo == 0) {
			resultado += std::to_string(atual->coef);
		}

		if (atual->expo != 0) {
			resultado += "x";
			if (atual->expo != 1) {
				resultado += "^" + std::to_string(atual->expo);
			}
		}

		primeiro = false;
		atual = atual->prox;
	}

	return resultado;
}

/** Realiza a soma de dois polinômios.
 *  - Percorre os monômios de ambos os polinômios, somando os coeficientes
 *    dos termos com expoentes iguais.
 *  - Insere os monômios resultantes no novo polinômio.
 *
 * @param poli1 Primeiro polinômio.
 * @param poli2 Segundo polinômio.
 * @return Um novo polinômio com o resultado da soma.
 *
 */

Polinomio operator+(const Polinomio& poli1, const Polinomio& poli2){
	Polinomio resultado;

	Monomio* p1 = poli1.head;
	Monomio* p2 = poli2.head;

	while(p1 != nullptr && p2 != nullptr){
		if (p1->expo == p2->expo)
		{
			resultado.inserir(p1->coef + p2->coef, p1->expo);
			p1 = p1->prox;
			p2 = p2->prox;
		}
		else if (p1->expo > p2->expo)
		{
			resultado.inserir(p1->coef, p1->expo);
			p1 = p1->prox;
		}
		else if (p1->expo < p2->expo)
		{
			resultado.inserir(p2->coef, p2->expo);
			p2 = p2->prox;
		}
	}

	while(p1 != nullptr){
		resultado.inserir(p1->coef, p1->expo);
		p1 = p1->prox;
	}

	while(p2 != nullptr){
		resultado.inserir(p2->coef, p2->expo);
		p2 = p2->prox;
	}

	return resultado;
}

/** Realiza a subtração de dois polinômios.
 *  - Percorre os monômios de ambos os polinômios, subtraindo os coeficientes
 *    dos termos com expoentes iguais.
 *  - Insere os monômios resultantes no novo polinômio.
 *
 * @param poli1 Primeiro polinômio.
 * @param poli2 Segundo polinômio.
 * @return Um novo polinômio com o resultado da soma.
 *
 */

Polinomio operator-(const Polinomio& poli1, const Polinomio& poli2){
	Polinomio resultado;

	Monomio* p1 = poli1.head;
	Monomio* p2 = poli2.head;

	while(p1 != nullptr && p2 != nullptr){
		if (p1->expo == p2->expo)
		{
			resultado.inserir(p1->coef - p2->coef, p1->expo);
			p1 = p1->prox;
			p2 = p2->prox;
		}
		else if (p1->expo > p2->expo)
		{
			resultado.inserir(p1->coef, p1->expo);
			p1 = p1->prox;
		}
		else if (p1->expo < p2->expo)
		{
			resultado.inserir(p2->coef, p2->expo);
			p2 = p2->prox;
		}
	}

	while(p1 != nullptr){
		resultado.inserir(p1->coef, p1->expo);
		p1 = p1->prox;
	}

	while(p2 != nullptr){
		resultado.inserir(p2->coef, p2->expo);
		p2 = p2->prox;
	}

	return resultado;
}

/** Realiza a multiplicação de dois polinômios.
 *  - Multiplica cada monômio do primeiro polinômio por todos
 *    os monômios do segundo.
 *  - Os expoentes são somados e os coeficientes multiplicados.
 *  - Insere os monômios resultantes no novo polinômio.
 *
 * @param poli1 Primeiro polinômio.
 * @param poli2 Segundo polinômio.
 * @return Um novo polinômio com o produto.
 *
 */

Polinomio operator*(const Polinomio& poli1, const Polinomio& poli2){
	Polinomio resultado;

	Monomio* p1 = poli1.head;
	Monomio* p2 = poli2.head;

	while(p1 != nullptr){
		while(p2 != nullptr){
			resultado.inserir(p1->coef * p2->coef, p1->expo + p2->expo);
			p2 = p2->prox;
		}
		p1 = p1->prox;
		p2 = poli2.head;
	}

	resultado.Simplificar();
	return resultado;
}

/** Representa o polinômio como uma string em um stream de saída.
 *  - Usa a função `P()` para gerar a string e a insere no stream.
 *
 * @param os Stream de saída.
 * @param poli Polinômio.
 * @return O stream de saída com o polinômio formatado.
 *
 */
std::ostream& operator<<(std::ostream& os, const Polinomio& poli){
	os << poli.P();
	return os;
}

Polinomio::~Polinomio() {
	while (head != nullptr) {
		Monomio* temp = head;
		head = head->prox;
		delete temp;
	}
}
