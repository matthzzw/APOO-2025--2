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
    int estadoConservacao; // 0 = desconhecido

public:
    // construtor que inicializa apenas o nome; outros campos ficam vazios/zero
    Animal(const string& nome);

    // getters / setters simples (só o necessário)
    string getNome() const;
    void setNome(const string& n);

    // outros setters/getters poderiam ser adicionados se necessário
};

#endif // ANIMAL_H
