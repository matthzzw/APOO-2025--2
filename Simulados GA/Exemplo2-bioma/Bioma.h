#ifndef BIOMA_H
#define BIOMA_H

#include <string>
#include <vector>
#include "Animal.h"
#include "Vegetal.h"
using namespace std;

class Bioma {
private:
    string nome;
    vector<Animal*> fauna;    // armazenamos ponteiros para que o mesmo objeto possa ser referenciado em vários biomas
    vector<Vegetal*> flora;

public:
    Bioma(const string& nome);

    string getNome() const;

    void adicionarAnimal(Animal* a);
    void adicionarVegetal(Vegetal* v);

    void exibirFauna() const;
    void exibirFlora() const;
};

#endif // BIOMA_H
