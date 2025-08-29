//Nome: Matheus Trindade Teixeira
//Algorítmos de Programação Orientada a Objetos


#include <iostream>
#include <string>

using namespace std;

class SmartHouse{ 
public:


//Construtor padrão
    SmartHouse();
    SmartHouse(string luzesLigadas, int tempertaturaDesejada, int alarmeAtivo, bool portaTrancada, string modo);

//Getters 
    string getLuzesLigadas();
    int getTemperaturaDesejda();
    int getAlarmeAtivo();
    bool getPortaTrancada();
    string getModo();

//Setters
    void setLuzesLigadas(string luzesLigadas);
    void setTemperaturaDesejada(int temperaturaDesejada);
    void setAlarmeAtivo(int alarmeAtivo);
    void setPortaTrancada(bool portaTrancada);
    void setModo(string modo);


//Métodos

    string Ligar_DesligarLuz(bool);
    int Ativar_DesativarAlarme(bool);
    int   Trancar_DestrancarPorta(bool);
    bool  Trancar_DestrancarPorta();
    string   Status();
    string AplicarCena();

//Destrutor
     ~SmartHouse();

private:

    //Atributos

     string luzesLigadas;
     int temperaturaDesejada;
     int alarmeAtivo;
     bool portaTrancada;
     string modo;
     

};