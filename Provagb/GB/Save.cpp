#include "Save.h"
#include <iostream>
using namespace std;

void salvarPokemonCSV(Pokemon** pokemons, int tamanho, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir arquivo " << nomeArquivo << endl;
        return;
    }

    // Cabeçalho CSV
    arquivo << "Nome,Nivel,HP,Ataque,Defesa,Tipo" << endl;

    for (int i = 0; i < tamanho; i++) {
        if (pokemons[i]) {
            arquivo << pokemons[i]->getNome() << ","
                    << pokemons[i]->getNivel() << ","
                    << pokemons[i]->getHP() << ","
                    << pokemons[i]->getAtaque() << ","
                    << pokemons[i]->getDefesa() << ","
                    << pokemons[i]->getTipo() << endl;
        }
    }

    arquivo.close();
    cout << "Pokemons salvos em " << nomeArquivo << endl;
}
