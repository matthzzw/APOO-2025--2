#include "SistemaPedidos.h"

SistemaPedidos::SistemaPedidos() {}

void SistemaPedidos::adicionarPizzaCatalogo(Pizza p) {
    catalogo.push_back(p);
}

void SistemaPedidos::exibirCatalogo() const {
    cout << "=== Catálogo de Pizzas ===" << endl;
    for (const auto& pizza : catalogo) {
        pizza.exibirInfo();
    }
}

int SistemaPedidos::adicionarPedido(string tamanho, vector<Pizza> sabores, string status) {
    int maxSabores = 0;
    if (tamanho == "P") maxSabores = 2;
    else if (tamanho == "M") maxSabores = 3;
    else if (tamanho == "G") maxSabores = 4;

    if ((int)sabores.size() > maxSabores) {
        cout << "Erro: Pizza " << tamanho << " pode ter no máximo " << maxSabores << " sabores." << endl;
        return -1;
    }

    // Verifica se mistura doce e salgada
    string categoria = sabores[0].getCategoria();
    for (auto& s : sabores) {
        if (s.getCategoria() != categoria) {
            cout << "Erro: Não é permitido misturar sabores doces e salgados." << endl;
            return -1;
        }
    }

    PizzaPedido pedido(tamanho, sabores, status);
    listaDePedidos.push_back(pedido);
    return listaDePedidos.size();
}

void SistemaPedidos::exibirStatusPedido(int numero) const {
    if (numero > 0 && numero <= (int)listaDePedidos.size()) {
        cout << "Status do Pedido " << numero << ": " 
             << listaDePedidos[numero - 1].getStatus() << endl;
    } else {
        cout << "Pedido não encontrado." << endl;
    }
}

void SistemaPedidos::alterarStatusPedido(int numero, string novoStatus) {
    if (numero > 0 && numero <= (int)listaDePedidos.size()) {
        listaDePedidos[numero - 1].setStatus(novoStatus);
        cout << "Status do Pedido " << numero << " alterado para " << novoStatus << endl;
    } else {
        cout << "Pedido não encontrado." << endl;
    }
}

void SistemaPedidos::exibirListaPedidos() const {
    cout << "=== Lista de Pedidos ===" << endl;
    for (size_t i = 0; i < listaDePedidos.size(); i++) {
        listaDePedidos[i].exibirPedido(i + 1);
    }
}

vector<Pizza> SistemaPedidos::getCatalogo() const {
    return catalogo;
}
