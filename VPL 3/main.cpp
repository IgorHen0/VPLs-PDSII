#include <iostream>
#include "ContaBancaria.hpp"
#include "Banco.hpp"

using namespace std;

int main() {

  Banco meuBanco;
  char comando;
  int id,idDest;
  string nome;
  float valor;
  ContaBancaria *cb, *cbDest;

  cin >> comando;
  while(comando != 'T'){
    switch (comando)
    {
    case 'C':
      cin>> id >> nome;
      cb = meuBanco.CriaConta(id, nome);
      if ( cb == nullptr)
        cout << "ERRO: conta repetida" << endl;
      else
        cout << "conta criada" << endl;
      break;
    case 'D':
      cin>> id >> valor;
      cb = meuBanco.Pesquisa(id);
      if ( cb == nullptr)
        cout << "ERRO: conta inexistente" << endl;
      else {
        cb->Deposito(valor);
        cout << "deposito efetuado" << endl;
      }
      break;
    case 'S':
      cin>> id >> valor;
      cb = meuBanco.Pesquisa(id);
      if ( cb == nullptr)
        cout << "ERRO: conta inexistente" << endl;
      else {
        cb->Saque(valor);
        cout << "saque efetuado" << endl;
      }
      break;
    case 'P':
      cin>> id >> idDest >> valor;
      cb = meuBanco.Pesquisa(id);
      cbDest = meuBanco.Pesquisa(idDest);
      if ( (cb == nullptr) || (cbDest == nullptr) )
        cout << "ERRO: conta inexistente" << endl;
      else {
        cb->Pix(cbDest, valor);
        cout << "pix efetuado" << endl;
      }
      break;

    case 'I':
      meuBanco.ListaContas();
      break;
    }

    cin >> comando;
  
  }
  return 0;
}