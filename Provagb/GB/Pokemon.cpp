#include "Pokemon.h"
#include <iostream>
using namespace std;

Pokemon::Pokemon(const string& n, int lvl, int h, int atk, int def)
    : nome(n), nivel(lvl), hp(h), ataque(atk), defesa(def) {}

Pokemon::Pokemon(const string& n, int h)
    : nome(n), nivel(1), hp(h), ataque(10), defesa(10) {}

Pokemon::~Pokemon() {}

void Pokemon::imprimirInfo() const {
    cout << "Nome: " << nome << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "HP: " << hp << endl;
    cout << "Ataque: " << ataque << endl;
    cout << "Defesa: " << defesa << endl;
}

string Pokemon::getNome() const { return nome; }
int Pokemon::getNivel() const { return nivel; }
int Pokemon::getHp() const { return hp; }
int Pokemon::getAtaque() const { return ataque; }
int Pokemon::getDefesa() const { return defesa; }
