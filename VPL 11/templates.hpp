// vetor.hpp
#ifndef VETOR_HPP
#define VETOR_HPP

#include <iostream>

template <typename T>
class Vetor {
private:
    T* elementos;
    int tamanho_maximo;
    int numero_elementos;

public:
    // Construtor que recebe um inteiro n como parâmetro e cria um vetor de tamanho máximo igual a n
    Vetor(int n) : tamanho_maximo(n), numero_elementos(0) {
        elementos = new T[tamanho_maximo];
    }

    // Construtor de cópia
    Vetor(const Vetor& outro) : tamanho_maximo(outro.tamanho_maximo), numero_elementos(outro.numero_elementos) {
        elementos = new T[tamanho_maximo];
        for (int i = 0; i < numero_elementos; ++i) {
            elementos[i] = outro.elementos[i];
        }
    }

    // Destrutor
    ~Vetor() {
        delete[] elementos;
    }

    // Método SetElemento que recebe um inteiro i e um elemento x e coloca o elemento na posição i do vetor
    void SetElemento(int i, const T& x) {
        if (i >= 0 && i < tamanho_maximo) {
            elementos[i] = x;
        }
    }

    // Método GetElemento que recebe um inteiro i e retorna o elemento que está na posição i do vetor
    T GetElemento(int i) const {
        if (i >= 0 && i < numero_elementos) {
            return elementos[i];
        }
        throw std::out_of_range("Índice fora do intervalo válido");
    }

    // Método AdicionaElemento que recebe um elemento x e coloca o elemento na última posição do vetor
    void AdicionaElemento(const T& x) {
        if (numero_elementos < tamanho_maximo) {
            elementos[numero_elementos++] = x;
        }
    }

    // Método Imprime que imprime todos os elementos do Vetor com um espaço entre cada um deles
    void Imprime() const {
        for (int i = 0; i < numero_elementos; ++i) {
            std::cout << elementos[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // VETOR_HPP