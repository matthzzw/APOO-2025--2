#include "Figurinha.h"

// Construtores
Figurinha::Figurinha() {
    numero = 0;
    nomeJogador = "";
    time = "";
}

Figurinha::Figurinha(int num, string nome, string t) {
    numero = num;
    nomeJogador = nome;
    time = t;
}

// Getters
int Figurinha::getNumero() { return numero; }
string Figurinha::getNomeJogador() { return nomeJogador; }
string Figurinha::getTime() { return time; }

// Setters
void Figurinha::setNumero(int num) { numero = num; }
void Figurinha::setNomeJogador(string nome) { nomeJogador = nome; }
void Figurinha::setTime(string t) { time = t; }

// Resumo
string Figurinha::resumo() {
    return "Numero: " + to_string(numero) + ", Jogador: " + nomeJogador + ", Time: " + time;
}