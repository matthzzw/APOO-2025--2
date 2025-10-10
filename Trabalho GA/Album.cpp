#include "Album.h"
#include "Sistema.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Album::Album() : totalFigurinhas(0) {}

// Adiciona uma figurinha à coleção se houver espaço e não for repetida.
void Album::adicionarFigurinha(const Figurinha& f) {
    if (totalFigurinhas >= MAX_FIGURINHAS_ALBUM) {
        cout << "Sua colecao esta cheia!" << endl;
        return;
    }
    for (int i = 0; i < totalFigurinhas; i++) {
        if (figurinhas[i].getNumero() == f.getNumero()) {
            cout << "Figurinha repetida: " << f.getNome() << endl;
            return;
        }
    }
    figurinhas[totalFigurinhas] = f;
    totalFigurinhas++;
}

// Remove uma figurinha do array
bool Album::removerFigurinha(int numero) {
    int indiceParaRemover = -1;
    for (int i = 0; i < totalFigurinhas; i++) {
        if (figurinhas[i].getNumero() == numero) {
            indiceParaRemover = i;
            break;
        }
    }
    if (indiceParaRemover != -1) {
        for (int i = indiceParaRemover; i < totalFigurinhas - 1; i++) {
            figurinhas[i] = figurinhas[i + 1];
        }
        totalFigurinhas--;
        return true;
    }
    return false;
}

//  mostrando o status de cada espaço (vazio, para colar, colado).
void Album::exibirPagina(int pagina, int figPorPagina, const Sistema& sistema) const {
    int inicio = (pagina - 1) * figPorPagina + 1;
    int fim = inicio + figPorPagina - 1;
    cout << "\n--- ALBUM: PAGINA " << pagina << " (Figurinhas " << inicio << " a " << fim << ") ---" << endl;
    
    for (int i = inicio; i <= fim; ++i) { // Para cada espaço na página...
        cout << setw(3) << i << ": ";
        const Figurinha* figEncontrada = nullptr;
        // ...procura no array de figurinhas do usuário se existe uma com aquele número.
        for(int j = 0; j < totalFigurinhas; j++){
            if(figurinhas[j].getNumero() == i){
                figEncontrada = &figurinhas[j];
                break;
            }
        }
        if (figEncontrada != nullptr) { // Se o usuário tem a figurinha...
            if (figEncontrada->getStatus() == 1) { // ...e ela está colada.
                cout << figEncontrada->getNome() << " - Tipo: " << figEncontrada->getTipo() << " [COLADA]" << endl;
            } else { // ...mas não está colada.
                cout << "[COLAR] - Voce possui a figurinha " << figEncontrada->getNome() << endl;
            }
        } else { // Se o usuário não tem a figurinha.
            cout << "X [Vazio]" << endl;
        }
    }
    cout << "------------------------------------------" << endl;
}

// Mostra a lista de figurinhas que o usuário possui e que NÃO estão coladas.
void Album::gerenciarColecao(const Sistema& sistema) const {
    cout << "\n--- MINHA COLECAO (FIGURINHAS DISPONIVEIS) ---" << endl;
    bool encontrou = false;
    for(int i = 0; i < totalFigurinhas; i++){
        if(figurinhas[i].getStatus() != 1){ // Status 0 ou 2
            figurinhas[i].exibir();
            encontrou = true;
        }
    }
    if(!encontrou){
        cout << "Nenhuma figurinha disponivel na colecao (nao coladas ou para troca)." << endl;
    }
    cout << "----------------------------------------------" << endl;
}

// Sorteia 3 figurinhas aleatórias.
void Album::abrirPacote(const Sistema& sistema) {
    cout << "\nAbrindo pacote de 3 novas figurinhas..." << endl;
    for (int i = 0; i < 3; i++) {
        int num = rand() % 151 + 1;
        const PokemonData* pkmData = sistema.getPokemonData(num);
        string nome = (pkmData) ? pkmData->nome : "Pokemon #" + to_string(num);
        string tipo = (pkmData) ? pkmData->tipo : "Desconhecido";
        Figurinha nova(num, nome, tipo, 0);
        cout << "Voce ganhou: ";
        nova.exibir();
        adicionarFigurinha(nova);
    }
}

// Retorna um ponteiro para uma figurinha no array
Figurinha* Album::getFigurinha(int numero) {
    for (int i = 0; i < totalFigurinhas; i++) {
        if (figurinhas[i].getNumero() == numero) {
            return &figurinhas[i];
        }
    }
    return nullptr;
}


int Album::getTotalFigurinhas() const { return totalFigurinhas; }
const Figurinha* Album::getFigurinhas() const { return figurinhas; }