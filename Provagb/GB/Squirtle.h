#ifndef SQUIRTLE_H
#define SQUIRTLE_H

#include "PokemonAgua.h"

class Squirtle : public PokemonAgua {
public:
    Squirtle();
    ~Squirtle();

    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
    void imprimirInfo() const override;
};

#endif
