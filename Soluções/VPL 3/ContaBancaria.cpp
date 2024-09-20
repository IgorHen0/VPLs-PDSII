#include <iostream>
#include <iomanip>
#include "ContaBancaria.hpp"

using namespace std;

ContaBancaria::ContaBancaria(int id, string nome) {
    this->saldo = 0;
    this->id = id;
    this->nome = nome;
}

void ContaBancaria::Deposito(float valor){
    saldo += valor;
}

void ContaBancaria::Saque(float valor){
    saldo -= valor;
}

void ContaBancaria::Pix(ContaBancaria* destino, float valor) {
    destino->saldo += valor;
    saldo -= valor;
}

void ContaBancaria::Imprime(){
    cout << id << " " << nome << " " << fixed << setprecision(2) << saldo << endl;
}

