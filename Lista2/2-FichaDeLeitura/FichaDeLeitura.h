//Nome: Matheus Trindade Teixeira
//Algorítmos de Programação Orientada a Objetos


#include <iostream>
#include <string>

using namespace std;

class FichaLeitura{
public:

//Construtor padrão

FichaLeitura();
FichaLeitura(string titulo, string autor, int anoPublicacao, int nPagina, int pagAtual, string lido, int nota0a5);

//Destrutor

~FichaLeitura();

//Getters

    string getautor();
    string gettitulo();
    int getanoPublicacao();
    int getnPagina();
    int getpagAtual();
    string getlido();
    int getnota0a5();


//Setters

    void settitulo(string titulo);
    void setanoPublicacao(int anoPublicacao);
    void setpagAtual(int pagAtual);
    void setlido(string lido);
    void setnota0a5(int nota0a5);

//Métodos

    string iciarLeitura();
    string marcarLido();
    string avancarPagina();
    string avaliar(int nota0a5);
    float percentualLido();
    string resumo();

private:

 //Atributos
    string autor;
    string titulo;
    int anoPublicacao;
    int nPagina;
    int pagAtual;
    string lido;
    int nota0a5;





};