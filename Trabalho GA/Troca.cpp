#include "Troca.h"
#include "Sistema.h" 
#include <iostream>

Troca::Troca() : id(0), solicitante(""), parceiro(""), figurinhaOferecida(0), figurinhaDesejada(0), status(0) {}

Troca::Troca(int id, const std::string& sol, const std::string& parc, int fOferecida, int fDesejada)
    : id(id), solicitante(sol), parceiro(parc), figurinhaOferecida(fOferecida), figurinhaDesejada(fDesejada), status(0) {}

// Exibe os detalhes da troca, usando o objeto Sistema para buscar os nomes dos Pokémon.
void Troca::exibir(const Sistema& sistema) const {
    std::cout << "\nID da Troca: " << id << " | Solicitante: " << solicitante << std::endl;
    std::cout << "  - Oferece: [" << figurinhaOferecida << "] " << sistema.getNomePokemon(figurinhaOferecida) << std::endl;
    std::cout << "  - Deseja:  [" << figurinhaDesejada << "] " << sistema.getNomePokemon(figurinhaDesejada) << std::endl;
    std::cout << "  - Status: ";
    if(status == 0) std::cout << "Aguardando Analise";
    else if(status == 1) std::cout << "Aceita";
    else if(status == 2) std::cout << "Recusada";
    std::cout << std::endl;
}