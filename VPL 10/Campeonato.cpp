#include "Campeonato.hpp"

void Campeonato::cadastrar_treinador(std::string nome) {
    Treinador* treinador = new Treinador(nome);
    _treinadores.push_back(treinador);
}

void Campeonato::cadastrar_pokemon_eletrico(int idt, std::string nome, std::string tipo_ataque, double forca_ataque, double potencia_raio) {
    if (idt >= 0 && idt < _treinadores.size()) {
        _treinadores[idt]->cadastrar_pokemon_eletrico(nome, tipo_ataque, forca_ataque, potencia_raio);
    }
}

void Campeonato::cadastrar_pokemon_aquatico(int idt, std::string nome, std::string tipo_ataque, double forca_ataque, double litros_jato) {
    if (idt >= 0 && idt < _treinadores.size()) {
        _treinadores[idt]->cadastrar_pokemon_aquatico(nome, tipo_ataque, forca_ataque, litros_jato);
    }
}

void Campeonato::cadastrar_pokemon_explosivo(int idt, std::string nome, std::string tipo_ataque, double forca_ataque, double temperatura_explosao) {
    if (idt >= 0 && idt < _treinadores.size()) {
        _treinadores[idt]->cadastrar_pokemon_explosivo(nome, tipo_ataque, forca_ataque, temperatura_explosao);
    }
}

void Campeonato::imprimir_informacoes_treinador(int idt) {
    if (idt >= 0 && idt < _treinadores.size()) {
        _treinadores[idt]->imprimir_informacoes();
    } else {
        std::cout << "Treinador não encontrado." << std::endl;
    }
}

void Campeonato::executar_batalha(int idt1, int idpk1, int idt2, int idpk2) {
    if (idt1 >= 0 && idt1 < _treinadores.size() && idt2 >= 0 && idt2 < _treinadores.size()) {
        Treinador* treinador1 = _treinadores[idt1];
        Treinador* treinador2 = _treinadores[idt2];

        Pokemon* pokemon1 = treinador1->usar_pokemon(idpk1);
        Pokemon* pokemon2 = treinador2->usar_pokemon(idpk2);

        if (pokemon1 && pokemon2) {
            std::cout << "### Batalha ###" << std::endl;
            pokemon1->falar_nome();  
            std::cout << " vs. " << std::endl;
            pokemon2->falar_nome(); 

            pokemon1->atacar(pokemon2);

            pokemon2->imprimir_status();
            std::cout << "#########" << std::endl;
        } else {
            std::cout << "Um ou ambos os Pokémons não foram encontrados." << std::endl;
        }
    } else {
        std::cout << "Um ou ambos os treinadores não foram encontrados." << std::endl;
    }
}
