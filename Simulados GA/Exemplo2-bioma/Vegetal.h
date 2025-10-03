#ifndef VEGETAL_H
#define VEGETAL_H

#include <string>
using namespace std;

class Vegetal {
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
    Vegetal(const string& nome);

    string getNome() const;
};

#endif
