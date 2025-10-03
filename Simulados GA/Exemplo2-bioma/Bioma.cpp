#include "Bioma.h"
#include <iostream>
using namespace std;

Bioma::Bioma(const string& n) {
    nome = n;
}

string Bioma::getNome() const {
    return nome;
}

void Bioma::adicionarAnimal(Animal* a) {
    if (a != nullptr)
        fauna.push_back(a);
}

void Bioma::adicionarVegetal(Vegetal* v) {
    if (v != nullptr)
        flora.push_back(v);
}

void Bioma::exibirFauna() const {
    cout << "Fauna do bioma " << nome << ":\n";
    if (fauna.empty()) {
        cout << "  (nenhum animal registrado)\n";
    } else {
        for (size_t i = 0; i < fauna.size(); ++i) {
            cout << "  - " << fauna[i]->getNome() << "\n";
        }
    }
    cout << endl;
}

void Bioma::exibirFlora() const {
    cout << "Flora do bioma " << nome << ":\n";
    if (flora.empty()) {
        cout << "  (nenhuma planta registrada)\n";
    } else {
        for (size_t i = 0; i < flora.size(); ++i) {
            cout << "  - " << flora[i]->getNome() << "\n";
        }
    }
    cout << endl;
}
