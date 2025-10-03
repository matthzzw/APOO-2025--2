#include "Pizza.h"

Pizza::Pizza(string n, string c, string t, string ing) {
    nome = n;
    categoria = c;
    tipo = t;
    ingredientes = ing;
}

string Pizza::getNome() const {
    return nome;
}

string Pizza::getCategoria() const {
    return categoria;
}

void Pizza::exibir() const {
    cout << "Pizza: " << nome
         << " | Categoria: " << categoria
         << " | Tipo: " << tipo
         << " | Ingredientes: " << ingredientes << endl;
}
