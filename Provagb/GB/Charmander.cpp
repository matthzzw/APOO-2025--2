#include "Charizard.h"
#include <iostream>
using namespace std;

Charizard::Charizard()
    : Pokemon("Charizard", 3, 120, 35, 20), PokemonFogo("Charizard", 120) {}

Charizard::~Charizard() {}

void Charizard::executarAtaqueRapido() {
    cout << "Charizard usa Asa de Fogo!" << endl;
}

void Charizard::executarAtaqueCarregado() {
    cout << "Charizard usa Ataque de Fogo!" << endl;
}

void Charizard::imprimirInfo() const {
    cout << "=== Charizard ===" << endl;
    PokemonFogo::imprimirInfo();
    cout << "-----------------" << endl;
}
