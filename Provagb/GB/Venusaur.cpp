#include "Venusaur.h"
#include <iostream>
using namespace std;

Venusaur::Venusaur()
    : Pokemon("Venusaur", 3, 120, 25, 20), PokemonGrama("Venusaur", 120) {}

Venusaur::~Venusaur() {}

void Venusaur::executarAtaqueRapido() {
    cout << "Venusaur usa Chicote de Vinha!" << endl;
}

void Venusaur::executarAtaqueCarregado() {
    cout << "Venusaur usa Folha Navalha!" << endl;
}

void Venusaur::imprimirInfo() const {
    cout << "=== Venusaur ===" << endl;
    PokemonGrama::imprimirInfo();
    cout << "-----------------" << endl;
}
