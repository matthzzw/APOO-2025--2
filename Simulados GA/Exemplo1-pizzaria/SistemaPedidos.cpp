#include "SistemaPedidos.h"
#include <iostream>
using namespace std;

SistemaPedidos::SistemaPedidos() {
    qtdCatalogo = 0;
    qtdPedidos = 0;
}

void SistemaPedidos::adicionarPizzaCatalogo(Pizza p) {
    if (qtdCatalogo < MAX_CATALOGO) {
        catalogo[qtdCatalogo++] = p;
    }
}

void SistemaPedidos::exibirCatalogo() const {
    cout << "=== Catálogo de Pizzas ===" << endl;
    for (int i = 0; i < qtdCatalogo; i++) {
        catalogo[i].exibir();
    }
    cout << endl;
}

int SistemaPedidos::adicionarPedido(PizzaPedido pedido) {
    if (qtdPedidos < MAX_PEDIDOS) {
        pedidos[qtdPedidos] = pedido;
        qtdPedidos++;
        return qtdPedidos; // número do pedido
    }
    return -1; // falha
}

void SistemaPedidos::exibirPedidos() const {
    cout << "=== Lista de Pedidos ===" << endl;
    for (int i = 0; i < qtdPedidos; i++) {
        cout << "Pedido #" << (i + 1) << ": ";
        pedidos[i].exibir();
    }
    cout << endl;
}

void SistemaPedidos::alterarStatus(int numero, string novo) {
    if (numero > 0 && numero <= qtdPedidos) {
        pedidos[numero - 1].setStatus(novo);
    }
}

void SistemaPedidos::exibirStatus(int numero) const {
    if (numero > 0 && numero <= qtdPedidos) {
        cout << "Status do pedido #" << numero << ": "
             << pedidos[numero - 1].getStatus() << endl;
    }
}
