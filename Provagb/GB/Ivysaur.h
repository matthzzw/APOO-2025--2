#ifndef IVYSAUR_H
#define IVYSAUR_H

#include "PokemonGrama.h"

class Ivysaur : public PokemonGrama {
public:
    Ivysaur();
    ~Ivysaur();

    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
    void imprimirInfo() const override;
};

#endif
