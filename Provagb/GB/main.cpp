#include <iostream>
#include "Squirtle.h"
#include "Wartortle.h"
#include "Blastoise.h"
#include "Charmander.h"
#include "Charmeleon.h"
#include "Charizard.h"
#include "Bulbasaur.h"
#include "Ivysaur.h"
#include "Venusaur.h"
#include "Save.h"

using namespace std;

int main() {
    const int qtd = 9;
    Pokemon* pokedex[qtd];

    // Criar Pokémons
    pokedex[0] = new Squirtle();
    pokedex[1] = new Wartortle();
    pokedex[2] = new Blastoise();
    pokedex[3] = new Charmander();
    pokedex[4] = new Charmeleon();
    pokedex[5] = new Charizard();
    pokedex[6] = new Bulbasaur();
    pokedex[7] = new Ivysaur();
    pokedex[8] = new Venusaur();

    int opc;
    do {
        cout << "\n===== POKEDEX =====\n";
        cout << "1. Mostrar todos os Pokémons\n";
        cout << "2. Executar ataque rápido de um Pokémon\n";
        cout << "3. Executar ataque carregado de um Pokémon\n";
        cout << "4. Salvar Pokémons em CSV\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> opc;

        switch(opc) {
            case 1:
                for(int i = 0; i < qtd; i++) {
                    pokedex[i]->imprimirInfo();
                }
                break;
            case 2: {
                int i;
                cout << "Escolha índice (0-" << qtd-1 << "): ";
                cin >> i;
                if(i >= 0 && i < qtd) pokedex[i]->executarAtaqueRapido();
                break;
            }
            case 3: {
                int i;
                cout << "Escolha índice (0-" << qtd-1 << "): ";
                cin >> i;
                if(i >= 0 && i < qtd) pokedex[i]->executarAtaqueCarregado();
                break;
            }
            case 4:
                salvarPokemonCSV(pokedex, qtd, "pokemons.csv");
                break;
        }

    } while(opc != 0);

    // Liberar memória
    for(int i = 0; i < qtd; i++) {
        delete pokedex[i];
    }

    return 0;
}
