#include "PizzaPedido.h"

PizzaPedido::PizzaPedido(string t, int n, Pizza* sabores[], string s) {
    tamanho = t;
    nro_sabores = n;
    for (int i = 0; i < n && i < MAX_SABORES; i++) {
        lista_sabores[i] = sabores[i];
    }
    status = s;
}

string PizzaPedido::getStatus() const {
    return status;
}

void PizzaPedido::setStatus(string novo) {
    status = novo;
}

void PizzaPedido::exibir() const {
    cout << "Pedido: " << tamanho
         << " | Sabores: ";
    for (int i = 0; i < nro_sabores; i++) {
        cout << lista_sabores[i]->getNome();
        if (i < nro_sabores - 1) cout << ", ";
    }
    cout << " | Status: " << status << endl;
}
