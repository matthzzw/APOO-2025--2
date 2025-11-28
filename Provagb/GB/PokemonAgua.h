#ifndef POKEMONAGUA_H
#define POKEMONAGUA_H

#include "Pokemon.h"

// Classe de água
class PokemonAgua : virtual public Pokemon {
protected:
    int nivelAgua;

public:
    PokemonAgua(const string& n, int h)
        : Pokemon(n, 1, h, 15, 10), nivelAgua(1) {} // inicializa Pokemon base virtualmente

    virtual ~PokemonAgua() {}

    void imprimirInfo() const override {
        cout << "Tipo: Agua" << endl;
        Pokemon::imprimirInfo();
        cout << "Nivel Agua: " << nivelAgua << endl;
    }
};

#endif
