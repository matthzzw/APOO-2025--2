#ifndef PIZZA_PEDIDO_H
#define PIZZA_PEDIDO_H
#include <iostream>
#include <string>
#include <vector>
#include "Pizza.h"
using namespace std;

class PizzaPedido {
private:
    string tamanho;             // P, M, G
    int nro_sabores;
    vector<Pizza> lista_sabores;
    string status;              // Recebido, Em preparo, Pronto, Entregue

public:
    PizzaPedido();
    PizzaPedido(string tamanho, vector<Pizza> sabores, string status);

    string getTamanho() const;
    int getNumeroSabores() const;
    string getStatus() const;
    void setStatus(string novoStatus);

    void exibirPedido(int numero) const;
};

#endif
