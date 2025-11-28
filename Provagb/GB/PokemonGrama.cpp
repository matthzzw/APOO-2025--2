#include "PokemonGrama.h"
#include <iostream>
using namespace std;

PokemonGrama::PokemonGrama(const string& nome, int nivel, int hp, int atk, int def)
    : Pokemon(nome, nivel, hp, atk, def), nivelGrama(nivel) {}

PokemonGrama::PokemonGrama(const string& nome, int hp)
    : Pokemon(nome, hp), nivelGrama(1) {}

PokemonGrama::~PokemonGrama() {}

void PokemonGrama::imprimirInfo() const {
    cout << "[Tipo Grama] ";
    Pokemon::imprimirInfo();
    cout << "Nivel Grama: " << nivelGrama << endl;
}
