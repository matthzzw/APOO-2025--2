#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
using namespace std;

// Classe base abstrata
class Pokemon {
protected:
    string nome;
    int nivel;
    int hp;
    int ataque;
    int defesa;

public:
    // Construtor principal
    Pokemon(const string& n, int lvl, int h, int atk, int def)
        : nome(n), nivel(lvl), hp(h), ataque(atk), defesa(def) {}

    virtual ~Pokemon() {}

    // Métodos virtuais puros (polimorfismo)
    virtual void executarAtaqueRapido() = 0;
    virtual void executarAtaqueCarregado() = 0;
    virtual void imprimirInfo() const {
        cout << "Nome: " << nome << endl;
        cout << "Nivel: " << nivel << endl;
        cout << "HP: " << hp << endl;
        cout << "Ataque: " << ataque << endl;
        cout << "Defesa: " << defesa << endl;
    }
};

#endif
