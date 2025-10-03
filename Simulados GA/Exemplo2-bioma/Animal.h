#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
private:
    string nome;
    string nomeCientifico;
    string filo;
    string classe;
    string familia;
    string genero;
    string especie;
    int estadoConservacao;

public:
    Animal(const string& nome);

    string getNome() const;
};

#endif
