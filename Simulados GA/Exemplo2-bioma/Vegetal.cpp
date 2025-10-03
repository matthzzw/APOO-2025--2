#include "Vegetal.h"

Vegetal::Vegetal(const string& n) {
    nome = n;
    nomeCientifico = "";
    filo = "";
    classe = "";
    familia = "";
    genero = "";
    especie = "";
    estadoConservacao = 0;
}

string Vegetal::getNome() const {
    return nome;
}
