#ifndef POKEMONEXPLOSIVO_HPP
#define POKEMONEXPLOSIVO_HPP

#include "Pokemon.hpp"
#include <string>

class PokemonExplosivo : public Pokemon {
public:
    PokemonExplosivo(std::string nome, std::string tipo_ataque, double forca_ataque, double temperatura_explosao);

    void falar_tipo_ataque();

    double calcular_dano() override;

    double ataque_explosivo();

private:
    double _temperatura_explosao;
};

#endif
