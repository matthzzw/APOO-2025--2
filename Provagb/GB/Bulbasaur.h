#ifndef BULBASAUR_H
#define BULBASAUR_H

#include "PokemonGrama.h"

class Bulbasaur : public PokemonGrama {
public:
    Bulbasaur();
    ~Bulbasaur();

    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
    void imprimirInfo() const override;
};

#endif
