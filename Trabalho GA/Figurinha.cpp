#include "Figurinha.h"

// Construtor padrão: 
Figurinha::Figurinha() : numero(0), nome(""), tipo(""), status(0) {}

// Construtor específico: 
Figurinha::Figurinha(int numero, const std::string& nome, const std::string& tipo, int status)
    : numero(numero), nome(nome), tipo(tipo), status(status) {}

void Figurinha::setStatus(int newStatus) { this->status = newStatus; }
int Figurinha::getNumero() const { return numero; }
std::string Figurinha::getNome() const { return nome; }
std::string Figurinha::getTipo() const { return tipo; }
int Figurinha::getStatus() const { return status; }

// Imprime os detalhes da figurinha de forma formatada.
void Figurinha::exibir() const {
    std::cout << "[" << numero << "] " << nome << " - Tipo: " << tipo;
    if (status == 0) std::cout << " (Na colecao)";
    else if (status == 1) std::cout << " (Colada)";
    else if (status == 2) std::cout << " (Para troca)";
    std::cout << std::endl;
}