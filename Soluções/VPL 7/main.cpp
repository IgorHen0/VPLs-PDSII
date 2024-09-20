#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <iomanip> 
#include "controle_alunos.hpp"

int main() {
    std::vector<Aluno> alunos;
    std::string nome;
    int matricula;
    int nota;

    // Leitura dos dados dos alunos
    while (true) {
        std::getline(std::cin, nome);
        if (nome == "END") break;
        std::cin >> matricula;
        std::vector<int> notas;
        while (true) {
            std::cin >> nota;
            if (nota == -1) break;
            notas.push_back(nota);
        }
        std::cin.ignore(); // Limpar o buffer do teclado
        alunos.emplace_back(nome, matricula, notas);
    }

    // Ordena os alunos pelo nome
    std::sort(alunos.begin(), alunos.end(), [](const Aluno& a, const Aluno& b) {
        return a.getNome() < b.getNome();
    });

    // Impressão do relatório
    for (const Aluno& aluno : alunos) {
        std::cout << aluno.getMatricula() << " " << aluno.getNome() << " ";
        for (int nota : aluno.getNotas()) {
            std::cout << nota << " ";
        }
        std::cout << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << aluno.calcularMedia() << " " << aluno.getNotaMaxima() << " " << aluno.getNotaMinima() << std::endl;
    }


    return 0;
}