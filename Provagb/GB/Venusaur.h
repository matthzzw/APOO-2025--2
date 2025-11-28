#ifndef VENUSAUR_H
#define VENUSAUR_H

#include "PokemonGrama.h"

class Venusaur : public PokemonGrama {
public:
    Venusaur();
    ~Venusaur();

    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
    void imprimirInfo() const override;
};

#endif
