#ifndef SISTEMA_PEDIDOS_H
#define SISTEMA_PEDIDOS_H
#include <iostream>
#include <vector>
#include "Pizza.h"
#include "PizzaPedido.h"
using namespace std;

class SistemaPedidos {
private:
    vector<Pizza> catalogo;
    vector<PizzaPedido> listaDePedidos;

public:
    SistemaPedidos();

    void adicionarPizzaCatalogo(Pizza p);
    void exibirCatalogo() const;

    int adicionarPedido(string tamanho, vector<Pizza> sabores, string status);
    void exibirStatusPedido(int numero) const;
    void alterarStatusPedido(int numero, string novoStatus);
    void exibirListaPedidos() const;

    vector<Pizza> getCatalogo() const;
};

#endif
