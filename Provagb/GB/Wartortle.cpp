#include "Wartortle.h"
#include <iostream>
using namespace std;

Wartortle::Wartortle()
    : Pokemon("Wartortle", 2, 80, 20, 15), PokemonAgua("Wartortle", 80) {}

Wartortle::~Wartortle() {}

void Wartortle::executarAtaqueRapido() {
    cout << "Wartortle usa Hidro Bomba!" << endl;
}

void Wartortle::executarAtaqueCarregado() {
    cout << "Wartortle usa Canhao de Agua!" << endl;
}

void Wartortle::imprimirInfo() const {
    cout << "=== Wartortle ===" << endl;
    PokemonAgua::imprimirInfo();
    cout << "-----------------" << endl;
}
