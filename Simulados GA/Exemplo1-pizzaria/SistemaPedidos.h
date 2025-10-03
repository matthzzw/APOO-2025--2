#ifndef SISTEMAPEDIDOS_H
#define SISTEMAPEDIDOS_H

#include "Pizza.h"
#include "PizzaPedido.h"

const int MAX_CATALOGO = 20;
const int MAX_PEDIDOS = 50;

class SistemaPedidos {
private:
    Pizza catalogo[MAX_CATALOGO];
    int qtdCatalogo;

    PizzaPedido pedidos[MAX_PEDIDOS];
    int qtdPedidos;

public:
    SistemaPedidos();

    void adicionarPizzaCatalogo(Pizza p);
    void exibirCatalogo() const;

    int adicionarPedido(PizzaPedido pedido);
    void exibirPedidos() const;

    void alterarStatus(int numero, string novo);
    void exibirStatus(int numero) const;
};

#endif
