#ifndef HEAPINT_HPP
#define HEAPINT_HPP

#include <iostream>

class HeapInt {
private:
    int* value;

public:
    // Construtor sem parâmetros
    HeapInt();

    // Construtor com um inteiro como parâmetro
    HeapInt(int val);

    // Construtor de cópia
    HeapInt(const HeapInt& other);

    // Destrutor
    ~HeapInt();

    // Sobrecarga do operador de atribuição para um inteiro
    HeapInt& operator=(int val);

    // Sobrecarga do operador de atribuição para outro HeapInt
    HeapInt& operator=(const HeapInt& other);

    // Sobrecarga do operador de soma
    HeapInt operator+(const HeapInt& other) const;

    // Sobrecarga do operador de subtração
    HeapInt operator-(const HeapInt& other) const;

    // Sobrecarga do operador de igualdade
    bool operator==(const HeapInt& other) const;

    // Sobrecarga do operador de entrada
    friend std::istream& operator>>(std::istream& in, HeapInt& obj);

    // Sobrecarga do operador de saída
    friend std::ostream& operator<<(std::ostream& out, const HeapInt& obj);
};

#endif // HEAPINT_HPP