#include "Ivysaur.h"
#include <iostream>
using namespace std;

Ivysaur::Ivysaur()
    : Pokemon("Ivysaur", 2, 80, 18, 15), PokemonGrama("Ivysaur", 80) {}

Ivysaur::~Ivysaur() {}

void Ivysaur::executarAtaqueRapido() {
    cout << "Ivysaur usa Chicote de Vinha!" << endl;
}

void Ivysaur::executarAtaqueCarregado() {
    cout << "Ivysaur usa Folha Navalha!" << endl;
}

void Ivysaur::imprimirInfo() const {
    cout << "=== Ivysaur ===" << endl;
    PokemonGrama::imprimirInfo();
    cout << "-----------------" << endl;
}
