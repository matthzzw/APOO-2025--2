#include "Pokemon.h"

Pokemon::Pokemon() : nome("Desconhecido"), nivel(1) {}
Pokemon::Pokemon(string n, int niv) : nome(n), nivel(niv) {}
Pokemon::~Pokemon() {}

void Pokemon::exibirDados() { cout << " | " << nome << " (Lvl " << nivel << ")"; }
string Pokemon::getNome() const { return nome; }
int Pokemon::getNivel() const { return nivel; }

// TIPO FOGO 
PokemonFogo::PokemonFogo(string n, int niv) : Pokemon(n, niv) {}
string PokemonFogo::getTipoSave() const { return "FOGO"; }
void PokemonFogo::executarAtaqueRapido() { cout << nome << " usou Arranhar!" << endl; }
void PokemonFogo::executarAtaqueCarregado() { cout << nome << " usou Brasa!" << endl; }

//  TIPO AGUA 
PokemonAgua::PokemonAgua(string n, int niv) : Pokemon(n, niv) {}
string PokemonAgua::getTipoSave() const { return "AGUA"; }
void PokemonAgua::executarAtaqueRapido() { cout << nome << " usou Investida!" << endl; }
void PokemonAgua::executarAtaqueCarregado() { cout << nome << " usou Jato de Agua!" << endl; }

// CHARMANDER E EVOLUÇÕES 
Charmander::Charmander(string n, int niv) : PokemonFogo(n, niv) {}

void Charmander::evoluir() {
    if (nome == "Charmander") {
        nome = "Charmeleon"; nivel += 16;
        cout << "Charmander evoluiu para Charmeleon!\n";
    } else if (nome == "Charmeleon") {
        nome = "Charizard"; nivel += 36;
        cout << "Charmeleon evoluiu para Charizard!\n";
    } else {
        cout << nome << " ja esta no maximo!\n";
    }
}

// Ataque Rápido Personalizado
void Charmander::executarAtaqueRapido() {
    if (nome == "Charmander") cout << "Charmander usou ARRANHAO!" << endl;
    else if (nome == "Charmeleon") cout << "Charmeleon usou MORDIDA!" << endl;
    else if (nome == "Charizard") cout << "Charizard usou ATAQUE DE ASA!" << endl;
}

// Ataque Carregado personalizado
void Charmander::executarAtaqueCarregado() {
    if (nome == "Charmander") cout << "Charmander usou BRASA!" << endl;
    else if (nome == "Charmeleon") cout << "Charmeleon usou LANCA-CHAMAS!" << endl;
    else if (nome == "Charizard") cout << "Charizard usou FOGO SAGRADO!!!" << endl;
}

//  SQUIRTLE E EVOLUÇÕES 
Squirtle::Squirtle(string n, int niv) : PokemonAgua(n, niv) {}

void Squirtle::evoluir() {
    if (nome == "Squirtle") {
        nome = "Wartortle"; nivel += 16;
        cout << "Squirtle evoluiu para Wartortle!\n";
    } else if (nome == "Wartortle") {
        nome = "Blastoise"; nivel += 36;
        cout << "Wartortle evoluiu para Blastoise!\n";
    } else {
        cout << nome << " ja esta no maximo!\n";
    }
}

// Ataque Rápido personalizado
void Squirtle::executarAtaqueRapido() {
    if (nome == "Squirtle") cout << "Squirtle usou BOLHAS!" << endl;
    else if (nome == "Wartortle") cout << "Wartortle usou MORDIDA!" << endl;
    else if (nome == "Blastoise") cout << "Blastoise usou CABECADA!" << endl;
}

// Ataque Carregado personalizado
void Squirtle::executarAtaqueCarregado() {
    if (nome == "Squirtle") cout << "Squirtle usou JATO DE AGUA!" << endl;
    else if (nome == "Wartortle") cout << "Wartortle usou HIDRO BOMBA!" << endl;
    else if (nome == "Blastoise") cout << "Blastoise usou CANHAO HIDRO!!!" << endl;
}