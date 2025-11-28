#ifndef CHARIZARD_H
#define CHARIZARD_H

#include "PokemonFogo.h"

class Charizard : public PokemonFogo {
public:
    Charizard();
    ~Charizard();

    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
    void imprimirInfo() const override;
};

#endif
