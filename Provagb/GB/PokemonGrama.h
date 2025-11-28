#ifndef POKEMONGRAMA_H
#define POKEMONGRAMA_H

#include "Pokemon.h"

class PokemonGrama : virtual public Pokemon {
protected:
    int nivelGrama;

public:
    PokemonGrama(const string& n, int h)
        : Pokemon(n, 1, h, 12, 12), nivelGrama(1) {}

    virtual ~PokemonGrama() {}

    void imprimirInfo() const override {
        cout << "Tipo: Grama" << endl;
        Pokemon::imprimirInfo();
        cout << "Nivel Grama: " << nivelGrama << endl;
    }
};

#endif
