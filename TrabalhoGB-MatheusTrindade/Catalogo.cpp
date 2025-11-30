#include "Catalogo.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept> 

Catalogo::~Catalogo() {
    for (Pokemon* p : lista) {
        delete p;
    }
    lista.clear();
}

void Catalogo::adicionarPokemon(Pokemon* p) {
    lista.push_back(p);
    cout << "Pokemon capturado com sucesso!\n";
}

void Catalogo::listarTodos() {
    cout << "\n--- POKEDEX ---\n";
    if (lista.empty()) {
        cout << "Nenhum pokemon capturado.\n";
        return;
    }
    for (size_t i = 0; i < lista.size(); i++) {
        cout << "[" << i << "]";
        lista[i]->exibirDados();
        cout << endl;
    }
}

void Catalogo::batalhar(int indice) {
    if (indice >= 0 && indice < lista.size()) {
        cout << "\n--- INICIANDO BATALHA ---\n";
      
        lista[indice]->executarAtaqueRapido();
        lista[indice]->executarAtaqueCarregado();
        cout << "------------------------\n";
    } else {
        cout << "Indice invalido!\n";
    }
}

void Catalogo::evoluirPokemon(int indice) {
    if (indice >= 0 && indice < lista.size()) {
        lista[indice]->evoluir();
    } else {
        cout << "Indice invalido!\n";
    }
}

//save
void Catalogo::salvar() {
    ofstream arquivo("save_game.csv");
    try {
        if (!arquivo.is_open()) {
            throw runtime_error("Nao foi possivel criar o arquivo de save.");
        }
        
        for (Pokemon* p : lista) {
            // Formato: TIPO,NOME,NIVEL
            arquivo << p->getTipoSave() << "," << p->getNome() << "," << p->getNivel() << endl;
        }
        cout << "Jogo salvo com sucesso em 'save_game.csv'!\n";
        arquivo.close();
    } 
    catch (exception& e) {
        cerr << "ERRO AO SALVAR: " << e.what() << endl;
    }
}

void Catalogo::carregar() {
    ifstream arquivo("save_game.csv");
    string linha, tipo, nome, nivelStr;

    try {
        if (!arquivo.is_open()) {
            cout << "Nenhum arquivo de save encontrado.\n";
            return;
        }

        // Limpa lista atual
        for (Pokemon* p : lista) delete p;
        lista.clear();

        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            getline(ss, tipo, ',');
            getline(ss, nome, ',');
            getline(ss, nivelStr, ',');

            int nivel = stoi(nivelStr);

            // Recriação dos objetos baseada no tipo salvo
            if (tipo == "FOGO") {
                adicionarPokemon(new Charmander(nome, nivel));
            } else if (tipo == "AGUA") {
                adicionarPokemon(new Squirtle(nome, nivel));
            }
        }
        cout << "Jogo carregado com sucesso!\n";
        arquivo.close();
    } 
    catch (exception& e) {
        cerr << "ERRO AO CARREGAR: " << e.what() << endl;
    }
}