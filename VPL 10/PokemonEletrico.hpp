#ifndef POKEMONELETRICO_HPP
#define POKEMONELETRICO_HPP

#include "Pokemon.hpp"
#include <string>

class PokemonEletrico : public Pokemon {
public:
    PokemonEletrico(std::string nome, std::string tipo_ataque, double forca_ataque, double potencia_raio);

    void falar_tipo_ataque();

    double calcular_dano() override;

    double ataque_eletrico();

private:
    double _potencia_raio;
};

#endif
