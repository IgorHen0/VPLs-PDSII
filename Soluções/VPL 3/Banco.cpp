#include <iostream>
#include <string>
#include "Banco.hpp"

Banco::Banco(){
    numContas = 0; 
    for(int i=0; i<MAXCONTAS; i++)
        contas[i] = nullptr;
}

ContaBancaria* Banco::CriaConta(int id, std::string nome){
    if(Pesquisa(id) != nullptr)
        return nullptr;

    contas[numContas] = new ContaBancaria(id, nome);
    return contas[numContas++];    
}

ContaBancaria* Banco::Pesquisa(int id){
    ContaBancaria *cb = nullptr;
    
    for(int i=0; i<numContas; i++) {
        if(contas[i]->id == id) {
            cb = contas[i];
            break;
        }
    }
    return cb;
}
       
void Banco::ListaContas(){
    for(int i=0; i<numContas; i++) {
        contas[i]->Imprime();
    }
}

