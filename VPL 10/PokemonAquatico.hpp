#ifndef POKEMONAQUATICO_HPP
#define POKEMONAQUATICO_HPP

#include "Pokemon.hpp"
#include <string>

class PokemonAquatico : public Pokemon {
public:
    PokemonAquatico(std::string nome, std::string tipo_ataque, double forca_ataque, double litros_jato);

    void falar_tipo_ataque();

    double calcular_dano() override;

    double ataque_aquatico();

private:
    double _litros_jato;
};

#endif
