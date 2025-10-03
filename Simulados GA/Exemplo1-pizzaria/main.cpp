#include <iostream>
#include "SistemaPedidos.h"
using namespace std;

int main() {
    SistemaPedidos sistema;

    // Catálogo de pizzas (Tabela 1)
    sistema.adicionarPizzaCatalogo(Pizza("Margherita", "Salgada", "Vegetariana", "Muçarela, Tomate, Manjericão"));
    sistema.adicionarPizzaCatalogo(Pizza("Pepperoni", "Salgada", "Com Carne", "Pepperoni, Muçarela"));
    sistema.adicionarPizzaCatalogo(Pizza("Quatro Queijos", "Salgada", "Vegetariana", "Muçarela, Gorgonzola, Parmesão, Provolone"));
    sistema.adicionarPizzaCatalogo(Pizza("Portuguesa", "Salgada", "Com Carne", "Presunto, Muçarela, Ovo, Ervilhas, Azeitonas"));
    sistema.adicionarPizzaCatalogo(Pizza("Calabresa", "Salgada", "Com Carne", "Calabresa, Muçarela"));
    sistema.adicionarPizzaCatalogo(Pizza("Frango com Catupiry", "Salgada", "Com Carne", "Frango, Catupiry, Muçarela"));
    sistema.adicionarPizzaCatalogo(Pizza("Banana Caramelizada", "Doce", "Vegetariana", "Banana, Creme de Leite Condensado, Canela"));
    sistema.adicionarPizzaCatalogo(Pizza("Chocolate com Morango", "Doce", "Vegetariana", "Chocolate, Morango"));
    sistema.adicionarPizzaCatalogo(Pizza("Vegetariana", "Salgada", "Vegetariana", "Milho, Ervilhas, Pimentão, Tomate Cereja, Muçarela"));
    sistema.adicionarPizzaCatalogo(Pizza("Supreme", "Salgada", "Com Carne", "Pepperoni, Calabresa, Muçarela, Cebola, Pimentão, Azeitonas"));
    sistema.adicionarPizzaCatalogo(Pizza("Bacon", "Salgada", "Com Carne", "Bacon, Muçarela"));
    sistema.adicionarPizzaCatalogo(Pizza("Mussarela", "Salgada", "Vegetariana", "Muçarela, Tomate"));

    // Criar pedidos (Tabela 2)
    vector<Pizza> catalogo = sistema.getCatalogo();

    // Função auxiliar para buscar pizza pelo nome
    auto buscaPizza = [&](string nome) {
        for (auto& p : catalogo)
            if (p.getNome() == nome) return p;
        return Pizza(); // pizza vazia
    };

    sistema.adicionarPedido("M", {buscaPizza("Margherita"), buscaPizza("Calabresa")}, "Entregue");
    sistema.adicionarPedido("P", {buscaPizza("Banana Caramelizada"), buscaPizza("Chocolate com Morango")}, "Pronto");
    sistema.adicionarPedido("G", {buscaPizza("Vegetariana"), buscaPizza("Supreme"), buscaPizza("Pepperoni")}, "Entregue");
    sistema.adicionarPedido("P", {buscaPizza("Frango com Catupiry")}, "Em preparo");
    sistema.adicionarPedido("G", {buscaPizza("Quatro Queijos"), buscaPizza("Frango com Catupiry"), buscaPizza("Portuguesa"), buscaPizza("Bacon")}, "Pronto");
    sistema.adicionarPedido("M", {buscaPizza("Margherita"), buscaPizza("Calabresa"), buscaPizza("Pepperoni")}, "Em preparo");
    sistema.adicionarPedido("G", {buscaPizza("Bacon")}, "Recebido");
    sistema.adicionarPedido("P", {buscaPizza("Margherita"), buscaPizza("Calabresa")}, "Em preparo");
    sistema.adicionarPedido("G", {buscaPizza("Mussarela"), buscaPizza("Portuguesa")}, "Em preparo");
    sistema.adicionarPedido("M", {buscaPizza("Quatro Queijos"), buscaPizza("Margherita"), buscaPizza("Frango com Catupiry")}, "Recebido");

    // Exibir todos os pedidos
    sistema.exibirListaPedidos();

    return 0;
}
