//Matheus Trindade Teixeira
//Algorítmos de Programação Orientada a Objetos

#ifndef FIGURINHA_H
#define FIGURINHA_H

#include <iostream>
#include <string>
using namespace std;

class Figurinha {
private:
    int numero;
    string nomeJogador;
    string time;

public:
    // Construtores
    Figurinha();
    Figurinha(int num, string nome, string t);

    // Getters
    int getNumero();
    string getNomeJogador();
    string getTime();

    // Setters
    void setNumero(int num);
    void setNomeJogador(string nome);
    void setTime(string t);

    // Método para exibir resumo
    string resumo();
};

#endif
