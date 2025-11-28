#include "Charizard.h"
#include <iostream>
using namespace std;

Charizard::Charizard()
    : Pokemon("Charizard", 120, 150, 60, 50),
      PokemonFogo("Charizard", 120, 150, 60, 50),
      PokemonVoador("Charizard", 120, 150, 60, 50) {}

Charizard::~Charizard() {}

void Charizard::executarAtaqueRapido() {
    cout << "Charizard usa Asas Flamejantes!" << endl;
}

void Charizard::executarAtaqueCarregado() {
    cout << "Charizard usa Lança Chamas Voadora!" << endl;
}

void Charizard::voar() {
    cout << "Charizard voa pelos céus!" << endl;
}

void Charizard::imprimirInfo() const {
    cout << "=== Charizard ===" << endl;
    PokemonFogo::imprimirInfo();
    cout << "-----------------" << endl;
}
