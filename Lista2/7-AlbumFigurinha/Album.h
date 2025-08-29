#ifndef ALBUM_H
#define ALBUM_H

#include "Figurinha.h"
#include <iostream>
using namespace std;

class Album {
private:
    Figurinha figurinhas[100];
    int total;

public:
    Album();

    void adicionar(Figurinha f);
    bool possui(int numero);
    int quantidade();
    void listar();
};

#endif
