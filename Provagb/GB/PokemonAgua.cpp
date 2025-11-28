#include "PokemonAgua.h"
#include <iostream>
using namespace std;

PokemonAgua::PokemonAgua(const string& nome, int hp) : Pokemon(nome, hp) {}
PokemonAgua::~PokemonAgua() {}

void PokemonAgua::imprimirInfo() const {
    cout << "[Água] ";
    Pokemon::imprimirInfo();
}
