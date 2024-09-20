#include "HeapInt.hpp"

// Construtor sem parâmetros
HeapInt::HeapInt() {
    value = new int(0);
}

// Construtor com um inteiro como parâmetro
HeapInt::HeapInt(int val) {
    value = new int(val);
}

// Construtor de cópia
HeapInt::HeapInt(const HeapInt& other) {
    value = new int(*other.value);
}

// Destrutor
HeapInt::~HeapInt() {
    delete value;
}

// Sobrecarga do operador de atribuição para um inteiro
HeapInt& HeapInt::operator=(int val) {
    if (value != nullptr) {
        *value = val;
    } else {
        value = new int(val);
    }
    return *this;
}

// Sobrecarga do operador de atribuição para outro HeapInt
HeapInt& HeapInt::operator=(const HeapInt& other) {
    if (this != &other) {
        if (value != nullptr) {
            *value = *other.value;
        } else {
            value = new int(*other.value);
        }
    }
    return *this;
}

// Sobrecarga do operador de soma
HeapInt HeapInt::operator+(const HeapInt& other) const {
    return HeapInt(*value + *other.value);
}

// Sobrecarga do operador de subtração
HeapInt HeapInt::operator-(const HeapInt& other) const {
    return HeapInt(*value - *other.value);
}

// Sobrecarga do operador de igualdade
bool HeapInt::operator==(const HeapInt& other) const {
    return *value == *other.value;
}

// Sobrecarga do operador de entrada
std::istream& operator>>(std::istream& in, HeapInt& obj) {
    in >> *obj.value;
    return in;
}

// Sobrecarga do operador de saída
std::ostream& operator<<(std::ostream& out, const HeapInt& obj) {
    out << *obj.value;
    return out;
}