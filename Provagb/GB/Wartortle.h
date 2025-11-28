#ifndef WARTORTLE_H
#define WARTORTLE_H

#include "PokemonAgua.h"

class Wartortle : public PokemonAgua {
public:
    Wartortle();
    ~Wartortle();

    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
    void imprimirInfo() const override;
};

#endif
