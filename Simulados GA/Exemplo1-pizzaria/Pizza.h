#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <string>
using namespace std;

class Pizza {
private:
    string nome;
    string categoria; // Doce ou Salgada
    string tipo;      // Vegetariana ou Com Carne
    string ingredientes;

public:
    Pizza();
    Pizza(string nome, string categoria, string tipo, string ingredientes);

    string getNome() const;
    string getCategoria() const;
    string getTipo() const;
    string getIngredientes() const;

    void exibirInfo() const;
};

#endif
