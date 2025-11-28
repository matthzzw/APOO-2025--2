#include "PokemonGrama.h"
#include <iostream>
using namespace std;

PokemonGrama::PokemonGrama(const string& nome, int hp) : Pokemon(nome, hp) {}
PokemonGrama::~PokemonGrama() {}

void PokemonGrama::imprimirInfo() const {
    cout << "[Grama] ";
    Pokemon::imprimirInfo();
}
