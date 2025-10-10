#ifndef TROCA_H
#define TROCA_H
#include <string>

class Sistema; 

//  armazena os dados de uma proposta de troca entre usuários.
class Troca {
public:
    int id;
    std::string solicitante;
    std::string parceiro;
    int figurinhaOferecida;
    int figurinhaDesejada;
    int status; // 0: aguardando, 1: aceita, 2: recusada

    Troca();
    Troca(int id, const std::string& sol, const std::string& parc, int fOferecida, int fDesejada);
    void exibir(const Sistema& sistema) const;
};
#endif