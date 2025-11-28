#include "Charmeleon.h"
#include <iostream>
using namespace std;

Charmeleon::Charmeleon()
    : Pokemon("Charmeleon", 2, 80, 25, 12), PokemonFogo("Charmeleon", 80) {}

Charmeleon::~Charmeleon() {}

void Charmeleon::executarAtaqueRapido() {
    cout << "Charmeleon usa Chama Rapida!" << endl;
}

void Charmeleon::executarAtaqueCarregado() {
    cout << "Charmeleon usa Inferno!" << endl;
}

void Charmeleon::imprimirInfo() const {
    cout << "=== Charmeleon ===" << endl;
    PokemonFogo::imprimirInfo();
    cout << "-----------------" << endl;
}
