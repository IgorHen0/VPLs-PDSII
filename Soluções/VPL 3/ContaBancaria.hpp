#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>

struct ContaBancaria{
    int id;
    float saldo;
    std::string nome;

    ContaBancaria(int id, std::string nome);
    void Deposito(float valor);
    void Saque(float valor);
    void Pix(ContaBancaria* destino, float valor);
    void Imprime();
};

#endif
