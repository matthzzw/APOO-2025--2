//Nome: Matheus Trindade Teixeira
//Algorítmos de Programação Orientada a Objetos


#include <iostream>
#include <string>

using namespace std;

class AssistenteVirtual{ 
public:


//Construtor padrão
    AssistenteVirtual();
    AssistenteVirtual(string nome, string idioma, float versao, int volume, string micAtivo);

//Getters 
    string getNome();
    string getIdioma();
    float getVersao();
    int getVolume();
    string getMicAtivo();

//Setters
    void setNome(string nome);
    void setIdioma(string idioma);
    void setVersao(float versao);
    void setVolume(int volume);
    void setMicAtivo(string micAtivo);

//Métodos
    string dizerOla();
    string executarComando();
    string definirIdioma();
    string atualizarVersao();
    string RegistrarLembrete();
    string resumoStatus();

//Destrutor
     ~AssistenteVirtual();

private:

    //Atributos

     string nome;
     string idioma;
     float versao;
     int volume;
     string micAtivo;
     


};