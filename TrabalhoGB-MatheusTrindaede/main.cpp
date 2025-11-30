#include <iostream>
#include "Catalogo.h"
#include "Pokemon.h"

using namespace std;

int main() {
    Catalogo pokedex;
    int opcao;

    do {
        cout << "\n=== POKEMON ===\n";
        cout << "1. Capturar Charmander (Fogo)\n";
        cout << "2. Capturar Squirtle (Agua)\n";
        cout << "3. Ver Minha Pokedex\n";
        cout << "4. Testar Ataques (Batalha)\n";
        cout << "5. Evoluir Pokemon\n";
        cout << "6. Salvar Jogo\n";
        cout << "7. Carregar Jogo\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                pokedex.adicionarPokemon(new Charmander());
                break;
            case 2:
                pokedex.adicionarPokemon(new Squirtle());
                break;
            case 3:
                pokedex.listarTodos();
                break;
            case 4: {
                int id;
                pokedex.listarTodos();
                cout << "ID para batalhar: ";
                cin >> id;
                pokedex.batalhar(id);
                break;
            }
            case 5: {
                int id;
                pokedex.listarTodos();
                cout << "ID para evoluir: ";
                cin >> id;
                pokedex.evoluirPokemon(id);
                break;
            }
            case 6:
                pokedex.salvar();
                break;
            case 7:
                pokedex.carregar();
                break;
            case 0:
                cout << "Encerrando...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}