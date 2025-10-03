#include "Pizza.h"

Pizza::Pizza() {}

Pizza::Pizza(string n, string c, string t, string ing)
    : nome(n), categoria(c), tipo(t), ingredientes(ing) {}

string Pizza::getNome() const { return nome; }
string Pizza::getCategoria() const { return categoria; }
string Pizza::getTipo() const { return tipo; }
string Pizza::getIngredientes() const { return ingredientes; }

void Pizza::exibirInfo() const {
    cout << "Pizza: " << nome << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Ingredientes: " << ingredientes << endl;
    cout << "----------------------------------------" << endl;
}
