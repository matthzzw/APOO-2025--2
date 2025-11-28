#include "PokemonFogo.h"
#include <iostream>
using namespace std;

PokemonFogo::PokemonFogo(const string& nome, int hp) : Pokemon(nome, hp) {}
PokemonFogo::~PokemonFogo() {}

void PokemonFogo::imprimirInfo() const {
    cout << "[Fogo] ";
    Pokemon::imprimirInfo();
}
