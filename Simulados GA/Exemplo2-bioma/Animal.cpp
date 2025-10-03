#include "Animal.h"

Animal::Animal(const string& n) {
    nome = n;
    nomeCientifico = "";
    filo = "";
    classe = "";
    familia = "";
    genero = "";
    especie = "";
    estadoConservacao = 0;
}

string Animal::getNome() const {
    return nome;
}
