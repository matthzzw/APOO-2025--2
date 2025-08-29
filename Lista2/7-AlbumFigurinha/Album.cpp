#include "Album.h"

Album::Album() {
    total = 0;
}

void Album::adicionar(Figurinha f) {
    if (total < 100) {
        figurinhas[total] = f;
        total++;
    } else {
        cout << "Album cheio!" << endl;
    }
}

bool Album::possui(int numero) {
    for (int i = 0; i < total; i++) {
        if (figurinhas[i].getNumero() == numero)
            return true;
    }
    return false;
}

int Album::quantidade() {
    return total;
}

void Album::listar() {
    for (int i = 0; i < total; i++) {
        cout << figurinhas[i].resumo() << endl;
    }
}
