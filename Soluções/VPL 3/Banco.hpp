#ifndef BANCO_H
#define BANCO_H

#include <string>
#include "ContaBancaria.hpp"

const int MAXCONTAS = 20;

struct Banco{
    int numContas;
    ContaBancaria *contas[MAXCONTAS];

    Banco();
    ContaBancaria* CriaConta(int id, std::string nome);
    ContaBancaria* Pesquisa(int id);
    void ListaContas();
};

#endif
