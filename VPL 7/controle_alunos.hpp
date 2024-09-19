#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>
#include <vector>

class Aluno {
private:
    std::string nome;
    int matricula;
    std::vector<int> notas;

public:
    Aluno();
    Aluno(std::string nome, int matricula, std::vector<int> notas);

    // Métodos de acesso aos atributos
    std::string getNome() const;
    int getMatricula() const;
    std::vector<int> getNotas() const;

    // Método para calcular a média das notas
    double calcularMedia() const;

    // Método para retornar a nota máxima
    int getNotaMaxima() const;

    // Método para retornar a nota mínima
    int getNotaMinima() const;
};

#endif