#include "Bulbasaur.h"
#include <iostream>
using namespace std;

Bulbasaur::Bulbasaur()
    : Pokemon("Bulbasaur", 1, 50, 12, 12), PokemonGrama("Bulbasaur", 50) {}

Bulbasaur::~Bulbasaur() {}

void Bulbasaur::executarAtaqueRapido() {
    cout << "Bulbasaur usa Chicote de Vinha!" << endl;
}

void Bulbasaur::executarAtaqueCarregado() {
    cout << "Bulbasaur usa Folha Navalha!" << endl;
}

void Bulbasaur::imprimirInfo() const {
    cout << "=== Bulbasaur ===" << endl;
    PokemonGrama::imprimirInfo();
    cout << "-----------------" << endl;
}
