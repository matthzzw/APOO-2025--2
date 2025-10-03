#include "Bioma.h"

Bioma::Bioma(const string& n) {
    nome = n;
    qtdFauna = 0;
    qtdFlora = 0;
}

string Bioma::getNome() const {
    return nome;
}

void Bioma::adicionarAnimal(Animal* a) {
    if (qtdFauna < MAX_ANIMAIS) {
        fauna[qtdFauna] = a;
        qtdFauna++;
    }
}

void Bioma::adicionarVegetal(Vegetal* v) {
    if (qtdFlora < MAX_VEGETAIS) {
        flora[qtdFlora] = v;
        qtdFlora++;
    }
}

void Bioma::exibirFauna() const {
    cout << "Fauna do bioma " << nome << ":\n";
    if (qtdFauna == 0) {
        cout << "  (nenhum animal)\n";
    } else {
        for (int i = 0; i < qtdFauna; i++) {
            cout << "  - " << fauna[i]->getNome() << "\n";
        }
    }
    cout << endl;
}

void Bioma::exibirFlora() const {
    cout << "Flora do bioma " << nome << ":\n";
    if (qtdFlora == 0) {
        cout << "  (nenhuma planta)\n";
    } else {
        for (int i = 0; i < qtdFlora; i++) {
            cout << "  - " << flora[i]->getNome() << "\n";
        }
    }
    cout << endl;
}
