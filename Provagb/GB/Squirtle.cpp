#include "Squirtle.h"
#include <iostream>
using namespace std;

Squirtle::Squirtle()
    : Pokemon("Squirtle", 1, 50, 15, 10), PokemonAgua("Squirtle", 50) {}

Squirtle::~Squirtle() {}

void Squirtle::executarAtaqueRapido() {
    cout << "Squirtle usa Investida!" << endl;
}

void Squirtle::executarAtaqueCarregado() {
    cout << "Squirtle usa Jato de Agua!" << endl;
}

void Squirtle::imprimirInfo() const {
    cout << "=== Squirtle ===" << endl;
    PokemonAgua::imprimirInfo();
    cout << "-----------------" << endl;
}
