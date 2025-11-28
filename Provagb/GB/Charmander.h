#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "PokemonFogo.h"

class Charmander : public PokemonFogo {
public:
    Charmander();
    ~Charmander();

    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
    void imprimirInfo() const override;
};

#endif
