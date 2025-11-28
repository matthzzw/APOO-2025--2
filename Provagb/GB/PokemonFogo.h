#ifndef POKEMONFOGO_H
#define POKEMONFOGO_H

#include "Pokemon.h"

// Classe base para Pokémon do tipo Fogo
class PokemonFogo : virtual public Pokemon {
public:
    PokemonFogo(const string& nome, int hp);
    virtual ~PokemonFogo();

    void imprimirInfo() const override;
};

#endif
