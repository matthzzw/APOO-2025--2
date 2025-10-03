#include "PizzaPedido.h"

PizzaPedido::PizzaPedido() {}

PizzaPedido::PizzaPedido(string t, vector<Pizza> sabores, string s)
    : tamanho(t), lista_sabores(sabores), status(s) {
    nro_sabores = sabores.size();
}

string PizzaPedido::getTamanho() const { return tamanho; }
int PizzaPedido::getNumeroSabores() const { return nro_sabores; }
string PizzaPedido::getStatus() const { return status; }
void PizzaPedido::setStatus(string novoStatus) { status = novoStatus; }

void PizzaPedido::exibirPedido(int numero) const {
    cout << "Pedido Nº " << numero << endl;
    cout << "Tamanho: " << tamanho << endl;
    cout << "Nº de Sabores: " << nro_sabores << endl;
    cout << "Sabores: ";
    for (size_t i = 0; i < lista_sabores.size(); i++) {
        cout << lista_sabores[i].getNome();
        if (i < lista_sabores.size() - 1) cout << ", ";
    }
    cout << endl;
    cout << "Status: " << status << endl;
    cout << "========================================" << endl;
}
