#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
#include "polinomio.cpp"

Polinomio StringParaPolinomio(const std::string& linha) {
    Polinomio result;

    std::istringstream str(linha);
    int coef;
    int expo;

    while (str >> coef >> expo) {
        result.inserir(coef, expo);
    }

    return result;
}

int main() {
    std::ifstream arquivo("src/arquivo.txt");

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao carregar o arquivo!" << std::endl;
        std::cout << "Pressione Enter para sair...";
        std::cin.get(); // Espera uma entrada
        return 1;
    }

    std::string linha;

    while (std::getline(arquivo, linha)) {
        if (linha == "+") {
            std::cout << "Soma" << std::endl;

            // Lê os dois polinômios
            std::getline(arquivo, linha);
            Polinomio p1 = StringParaPolinomio(linha);

            std::getline(arquivo, linha);
            Polinomio p2 = StringParaPolinomio(linha);

            std::cout << "(" << p1 << ") + (" << p2 << ")" << std::endl;
            std::cout << "Resultado: " << p1 + p2 << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }
        else if (linha == "-") {
            std::cout << "Subtracao" << std::endl;

            std::getline(arquivo, linha);
            Polinomio p1 = StringParaPolinomio(linha);

            std::getline(arquivo, linha);
            Polinomio p2 = StringParaPolinomio(linha);

            std::cout << "(" << p1 << ") - (" << p2 << ")" << std::endl;
            std::cout << "Resultado: " << p1 - p2 << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }
        else if (linha == "*") {
            std::cout << "Multiplicacao" << std::endl;

            std::getline(arquivo, linha);
            Polinomio p1 = StringParaPolinomio(linha);

            std::getline(arquivo, linha);
            Polinomio p2 = StringParaPolinomio(linha);

            std::cout << "(" << p1 << ") * (" << p2 << ")" << std::endl;
            std::cout << "Resultado: " << p1 * p2 << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }
        else if (linha == "g" || linha == "G") {
            std::cout << "Grau do polinomio" << std::endl;

            std::getline(arquivo, linha);
            Polinomio p = StringParaPolinomio(linha);

            std::cout << ""<<p<<"" << std::endl;
            std::cout << "Grau = " << p.G() << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }
        else if (linha == "p" || linha == "P") {
            std::cout << "Representacao textual do polinomio" << std::endl;

            std::getline(arquivo, linha);
            Polinomio p = StringParaPolinomio(linha);

            std::cout << ""<<p<<"" << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }
        else if (linha == "a" || linha == "A") {
            std::cout << "Avaliando o polinomio para x = ";

            std::getline(arquivo, linha);
            int x = std::stoi(linha);

            std::getline(arquivo, linha);
            Polinomio p = StringParaPolinomio(linha);

            std::cout << x << std::endl;
            std::cout << ""<<p<<"" << std::endl;
            std::cout << "Resultado: " << p.Avaliar(x) << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }
        else if (linha == "s" || linha == "S") {
            std::cout << "Simplificando o polinomio " << std::endl;

            std::getline(arquivo, linha);
            Polinomio p = StringParaPolinomio(linha);

            std::cout << ""<<p<<"" << std::endl;

            p.Simplificar();

            std::cout << "Resultado: " << p << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }
        else if (linha == "t" || linha == "T") {
            std::cout << "Tamanho do polinomio " << std::endl;

            std::getline(arquivo, linha);
            Polinomio p = StringParaPolinomio(linha);

            std::cout << ""<<p<<"" << std::endl;

            std::cout << "Tamanho: " << p.T() << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }
        else {
            std::cerr << "Essa operacao nao existe: " << linha << std::endl;
        }
    }

    arquivo.close();
    return 0;
}
