#include <iostream>
#include <sstream>
#include "Campeonato.hpp"
#include "avaliacao_basica_pokemon.hpp" 

int main() {
    Campeonato campeonato;
    std::string comando;

    while (std::getline(std::cin, comando)) {
        std::istringstream iss(comando);
        char operacao;
        iss >> operacao;

        if (operacao == 't') {
            std::string nome_treinador;
            iss >> nome_treinador;
            campeonato.cadastrar_treinador(nome_treinador); 
        }
        else if (operacao == 'i') {
            int idt;
            iss >> idt;
            campeonato.imprimir_informacoes_treinador(idt);
        }
        else if (operacao == 'e') {
            int idt;
            std::string nome_pokemon, tipo_ataque;
            double forca_ataque, potencia_raio;
            iss >> idt >> nome_pokemon >> tipo_ataque >> forca_ataque >> potencia_raio;
            campeonato.cadastrar_pokemon_eletrico(idt, nome_pokemon, tipo_ataque, forca_ataque, potencia_raio);
        }
        else if (operacao == 'q') {
            int idt;
            std::string nome_pokemon, tipo_ataque;
            double forca_ataque, litros_jato;
            iss >> idt >> nome_pokemon >> tipo_ataque >> forca_ataque >> litros_jato;
            campeonato.cadastrar_pokemon_aquatico(idt, nome_pokemon, tipo_ataque, forca_ataque, litros_jato);
        }
        else if (operacao == 'x') {
            int idt;
            std::string nome_pokemon, tipo_ataque;
            double forca_ataque, temperatura_explosao;
            iss >> idt >> nome_pokemon >> tipo_ataque >> forca_ataque >> temperatura_explosao;
            campeonato.cadastrar_pokemon_explosivo(idt, nome_pokemon, tipo_ataque, forca_ataque, temperatura_explosao);
        }
        else if (operacao == 'h') {
            int idt1, idpk1, idt2, idpk2;
            iss >> idt1 >> idpk1 >> idt2 >> idpk2;
            campeonato.executar_batalha(idt1, idpk1, idt2, idpk2);
        }
        else if (operacao == 'b') {
            avaliacao_basica();
            break; 
        }
        else {
            std::cout << "Comando inválido!" << std::endl;
        }
    }

    system("pause");

    return 0;
}
