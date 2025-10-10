#ifndef SISTEMA_H
#define SISTEMA_H

#include "Usuario.h"
#include "Troca.h"
#include <string>

#define MAX_USUARIOS 50
#define MAX_TROCAS 100
#define MAX_POKEMONS 200

struct PokemonData {
    int numero;
    std::string nome;
    std::string tipo;
};

class Sistema {
private:
    Usuario usuarios[MAX_USUARIOS];
    int totalUsuarios;
    Troca trocas[MAX_TROCAS];
    int totalTrocas;
    PokemonData nomesPokemons[MAX_POKEMONS];
    int totalPokemons;

    Usuario* usuarioLogado;

    void carregarDados();
    void salvarDados();
    void carregarUsuarios();
    void carregarFigurinhas();
    void carregarNomesPokemons();
    void carregarTrocas();
    void salvarUsuarios();
    void salvarFigurinhas();
    void salvarTrocas();

    void menuPrincipal();
    void menuGerenciarAlbum();
    void menuGerenciarColecao();

    void criarNovoUsuario();
    void acessarAlbum();
    void verAlbum();
    void abrirPacote();
    void colarFigurinha();
    void disponibilizarParaTroca();
    void proporTroca();
    void revisarTrocas();

    Usuario* findUsuario(const std::string& nome);
    Troca* findTroca(int id);

public:
    Sistema();
    const PokemonData* getPokemonData(int numero) const;
    
    std::string getNomePokemon(int numero) const; 
};

#endif