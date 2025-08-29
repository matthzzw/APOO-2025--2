//Nome: Matheus Trindade Teixeira
//Algorítmos de Programação Orientada a Objetos

#include <iostream>
#include <string>
using namespace std;

class FrequenciaCardiaca {
private:
    string primeiroNome;
    string sobrenome;
    int diaNasc;
    int mesNasc;
    int anoNasc;

public:
    // Construtores
    FrequenciaCardiaca();
    FrequenciaCardiaca(string primeiroNome, string sobrenome,
                       int diaNasc, int mesNasc, int anoNasc);

    // Getters
    string getPrimeiroNome();
    string getSobrenome();
    int getDiaNasc();
    int getMesNasc();
    int getAnoNasc();

    // Setters
    void setPrimeiroNome(string primeiroNome);
    void setSobrenome(string sobrenome);
    void setDiaNasc(int dia);
    void setMesNasc(int mes);
    void setAnoNasc(int ano);

    // Métodos
    int obterIdade(int diaAtual, int mesAtual, int anoAtual);
    int obterFrequenciaMaxima(int idade);
    void obterFrequenciaIdeal(int idade);

    
 };