#include "controle_alunos.hpp"
#include <algorithm>

Aluno::Aluno() {}

Aluno::Aluno(std::string nome, int matricula, std::vector<int> notas) : nome(nome), matricula(matricula), notas(notas) {}

std::string Aluno::getNome() const {
    return nome;
}

int Aluno::getMatricula() const {
    return matricula;
}

std::vector<int> Aluno::getNotas() const {
    return notas;
}

double Aluno::calcularMedia() const {
    double soma = 0;
    for (int nota : notas) {
        soma += nota;
    }
    return soma / notas.size();
}

int Aluno::getNotaMaxima() const {
    return *std::max_element(notas.begin(), notas.end());
}

int Aluno::getNotaMinima() const {
    return *std::min_element(notas.begin(), notas.end());
}