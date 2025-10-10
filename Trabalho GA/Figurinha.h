#ifndef FIGURINHA_H
#define FIGURINHA_H
#include <string>
#include <iostream>


class Figurinha {
private:
    // Atributos privados 
    int numero;
    std::string nome;
    std::string tipo;
    int status; // 0: na coleção, 1: colada, 2: para troca

public:
    // Construtores
    Figurinha();
    Figurinha(int numero, const std::string& nome, const std::string& tipo, int status);

    // Setters: 
    void setStatus(int newStatus);

    // Getters:
    int getNumero() const;
    std::string getNome() const;
    std::string getTipo() const;
    int getStatus() const;

    
    void exibir() const;
};
#endif