#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <iostream>
using namespace std;

class Pizza {
private:
    string nome;
    string categoria;   // doce ou salgada
    string tipo;        // vegetariana ou com carne
    string ingredientes;

public:
    Pizza() {}
    Pizza(string nome, string categoria, string tipo, string ingredientes);

    string getNome() const;
    string getCategoria() const;

    void exibir() const;
};

#endif
