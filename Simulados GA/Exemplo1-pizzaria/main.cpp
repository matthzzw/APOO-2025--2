#include <iostream>
#include "SistemaPedidos.h"
using namespace std;

int main() {
    SistemaPedidos sistema;

    // Catálogo (10 sabores)
    sistema.adicionarPizzaCatalogo(Pizza("Margherita","Salgada","Vegetariana","Muçarela, Tomate, Manjericão"));
    sistema.adicionarPizzaCatalogo(Pizza("Pepperoni","Salgada","Com Carne","Pepperoni, Muçarela"));
    sistema.adicionarPizzaCatalogo(Pizza("Quatro Queijos","Salgada","Vegetariana","Muçarela, Gorgonzola, Parmesão, Provolone"));
    sistema.adicionarPizzaCatalogo(Pizza("Portuguesa","Salgada","Com Carne","Presunto, Muçarela, Ovo, Ervilhas, Azeitonas"));
    sistema.adicionarPizzaCatalogo(Pizza("Calabresa","Salgada","Com Carne","Calabresa, Muçarela"));
    sistema.adicionarPizzaCatalogo(Pizza("Frango com Catupiry","Salgada","Com Carne","Frango, Catupiry, Muçarela"));
    sistema.adicionarPizzaCatalogo(Pizza("Banana Caramelizada","Doce","Vegetariana","Banana, Creme de Leite Condensado, Canela"));
    sistema.adicionarPizzaCatalogo(Pizza("Chocolate com Morango","Doce","Vegetariana","Chocolate, Morango"));
    sistema.adicionarPizzaCatalogo(Pizza("Vegetariana","Salgada","Vegetariana","Milho, Ervilhas, Pimentão, Tomate Cereja, Muçarela"));
    sistema.adicionarPizzaCatalogo(Pizza("Supreme","Salgada","Com Carne","Pepperoni, Calabresa, Muçarela, Cebola, Pimentão, Azeitonas"));

    sistema.exibirCatalogo();

    // Criando alguns pedidos de teste
    Pizza* sabores1[2] = { new Pizza("Margherita","Salgada","Vegetariana",""), new Pizza("Calabresa","Salgada","Com Carne","") };
    PizzaPedido p1("M",2,sabores1,"Entregue");
    sistema.adicionarPedido(p1);

    Pizza* sabores2[2] = { new Pizza("Banana Caramelizada","Doce","Vegetariana",""), new Pizza("Chocolate com Morango","Doce","Vegetariana","") };
    PizzaPedido p2("P",2,sabores2,"Pronto");
    sistema.adicionarPedido(p2);

    Pizza* sabores3[3] = { new Pizza("Vegetariana","Salgada","Vegetariana",""), new Pizza("Supreme","Salgada","Com Carne",""), new Pizza("Pepperoni","Salgada","Com Carne","") };
    PizzaPedido p3("G",3,sabores3,"Entregue");
    sistema.adicionarPedido(p3);

    sistema.exibirPedidos();

    sistema.exibirStatus(2);
    sistema.alterarStatus(2,"Entregue");
    sistema.exibirStatus(2);

    return 0;
}
