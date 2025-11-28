#include "Blastoise.h"
#include <iostream>
using namespace std;

Blastoise::Blastoise()
    : Pokemon("Blastoise", 3, 120, 25, 20), PokemonAgua("Blastoise", 120) {}

Blastoise::~Blastoise() {}

void Blastoise::executarAtaqueRapido() {
    cout << "Blastoise usa Jato de Agua!" << endl;
}

void Blastoise::executarAtaqueCarregado() {
    cout << "Blastoise usa Canhao Hidraulico!" << endl;
}

void Blastoise::imprimirInfo() const {
    cout << "=== Blastoise ===" << endl;
    PokemonAgua::imprimirInfo();
    cout << "-----------------" << endl;
}
