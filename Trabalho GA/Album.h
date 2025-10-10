#ifndef ALBUM_H
#define ALBUM_H
#include "Figurinha.h"
#define MAX_FIGURINHAS_ALBUM 200

class Sistema;

class Album {
private:
    Figurinha figurinhas[MAX_FIGURINHAS_ALBUM]; // Array com as figurinhas que o usuário possui.
    int totalFigurinhas; // Contador de quantas figurinhas estão no array.

public:
    Album();
    void adicionarFigurinha(const Figurinha& f);
    bool removerFigurinha(int numero); 
    void exibirPagina(int pagina, int figPorPagina, const Sistema& sistema) const;
    void gerenciarColecao(const Sistema& sistema) const;
    Figurinha* getFigurinha(int numero); // Retorna ponteiro para uma figurinha específica.
    void abrirPacote(const Sistema& sistema);
    int getTotalFigurinhas() const;
    const Figurinha* getFigurinhas() const;
};
#endif