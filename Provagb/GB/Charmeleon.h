#ifndef CHARMELEON_H
#define CHARMELEON_H

#include "PokemonFogo.h"

class Charmeleon : public PokemonFogo {
public:
    Charmeleon();
    ~Charmeleon();

    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
    void imprimirInfo() const override;
};

#endif
