#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>

using namespace std;


class Pokemon {
protected:
    string nome;
    int nivel;

public:
    Pokemon();
    Pokemon(string n, int niv);
    virtual ~Pokemon();

    virtual void executarAtaqueRapido() = 0;
    virtual void executarAtaqueCarregado() = 0;
    
    virtual void evoluir() = 0;
    virtual void exibirDados();

    string getNome() const;
    int getNivel() const;
    virtual string getTipoSave() const = 0;
};

// Classe fogo
class PokemonFogo : public Pokemon {
public:
    PokemonFogo(string n, int niv);
    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
    string getTipoSave() const override;
};

// Classe água
class PokemonAgua : public Pokemon {
public:
    PokemonAgua(string n, int niv);
    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
    string getTipoSave() const override;
};

// Classe charmander
class Charmander : public PokemonFogo {
public:
    Charmander(string n = "Charmander", int niv = 5);
    void evoluir() override;
    
    
    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
};

//Classe squirtle
class Squirtle : public PokemonAgua {
public:
    Squirtle(string n = "Squirtle", int niv = 5);
    void evoluir() override;
    
    
    void executarAtaqueRapido() override;
    void executarAtaqueCarregado() override;
};

#endif