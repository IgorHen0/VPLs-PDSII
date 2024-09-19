#ifndef TREINADOR_HPP
#define TREINADOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include "PokemonEletrico.hpp"
#include "PokemonAquatico.hpp"
#include "PokemonExplosivo.hpp"

class Treinador{

    public:

        Treinador(std::string nome);

        void cadastrar_pokemon_eletrico(std::string nome, std::string tipo_ataque, double forca_ataque, double potencia_raio);
        void cadastrar_pokemon_aquatico(std::string nome, std::string tipo_ataque, double forca_ataque, double litros_jato);
        void cadastrar_pokemon_explosivo(std::string nome, std::string tipo_ataque, double forca_ataque, double temperatura_explosao);
        void imprimir_informacoes();

        Pokemon* usar_pokemon(int idpk);
    
    private:
        std::string _nome;
        std::vector<Pokemon*> _pokemons;
};

#endif