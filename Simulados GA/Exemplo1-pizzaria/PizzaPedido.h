#ifndef PIZZAPEDIDO_H
#define PIZZAPEDIDO_H

#include <string>
#include <iostream>
#include "Pizza.h"
using namespace std;

const int MAX_SABORES = 4; // no máx. 4 sabores por pizza

class PizzaPedido {
private:
    string tamanho;         // P, M ou G
    int nro_sabores;
    Pizza* lista_sabores[MAX_SABORES];
    string status;

public:
    PizzaPedido() {}
    PizzaPedido(string tamanho, int nro_sabores, Pizza* sabores[], string status);

    string getStatus() const;
    void setStatus(string novo);

    void exibir() const;
};

#endif
