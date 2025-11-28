#ifndef POKEMONVOADOR_H
#define POKEMONVOADOR_H

#include "Pokemon.h"

class PokemonVoador : virtual public Pokemon {
protected:
    int nivelVoador;
public:
    PokemonVoador(const string& nome, int nivel, int hp, int atk, int def);
    PokemonVoador(const string& nome, int hp);
    virtual ~PokemonVoador();
};

#endif
