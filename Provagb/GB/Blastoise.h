#ifndef BLASTOISE_H
#define BLASTOISE_H

#include "PokemonAgua.h"

class Blastoise : public PokemonAgua {
public:
    Blastoise();
    ~Blastoise();

    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
    void imprimirInfo() const override;
};

#endif
