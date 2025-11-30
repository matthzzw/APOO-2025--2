#ifndef CATALOGO_H
#define CATALOGO_H

#include "Pokemon.h"
#include <vector>

class Catalogo {
private:
    vector<Pokemon*> lista;

public:
    ~Catalogo(); 

    void adicionarPokemon(Pokemon* p);
    void listarTodos();
    void batalhar(int indice);
    void evoluirPokemon(int indice);
    
    // Salvamento
    void salvar();
    void carregar();
};

#endif