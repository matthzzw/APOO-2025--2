#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
using namespace std;

template <typename T>
class Inventario {
private:
    T* lista[100];
    int contador;

public:
    Inventario() : contador(0) {}

    void adicionar(T* p) {
        if (contador < 100)
            lista[contador++] = p;
    }

    T* get(int i) {
        if (i >= 0 && i < contador) return lista[i];
        return nullptr;
    }

    int tamanho() const { return contador; }

    void mostrar() const {
        for (int i = 0; i < contador; i++)
            lista[i]->imprimirInfo();
    }
};

#endif
