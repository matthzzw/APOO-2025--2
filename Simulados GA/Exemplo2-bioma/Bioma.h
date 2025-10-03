#ifndef BIOMA_H
#define BIOMA_H

#include <string>
#include <iostream>
#include "Animal.h"
#include "Vegetal.h"
using namespace std;

const int MAX_ANIMAIS = 20;
const int MAX_VEGETAIS = 20;

class Bioma {
private:
    string nome;
    Animal* fauna[MAX_ANIMAIS];
    Vegetal* flora[MAX_VEGETAIS];
    int qtdFauna;
    int qtdFlora;

public:
    Bioma(const string& nome);

    string getNome() const;

    void adicionarAnimal(Animal* a);
    void adicionarVegetal(Vegetal* v);

    void exibirFauna() const;
    void exibirFlora() const;
};

#endif
