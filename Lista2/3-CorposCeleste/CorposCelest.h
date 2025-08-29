//Nome: Matheus Trindade Teixeira
//Algorítmos de Programação Orientada a Objetos


#include <iostream>
#include <string>

using namespace std;

class CorposCeleste{ 
public:


//Construtor padrão
    CorposCeleste();
    CorposCeleste(string nome, string tipo, float massaKg, float raioKM);


//Getters 
    string getNome();
    string getTipo();
    float getMassaKg();
    float getRaioKm();

//Setters
    void setNome(string nome);
    void setTipo(string tipo);
    void setMassaKg(float massaKg);
    void setRaioKm(float raioKm);

//Métodos
    float calcularDensidade();
    float calcularGravidade();
    string descricao();

//Destrutor
     ~CorposCeleste();

private:

    //Atributos

     string nome;
     string tipo;
     float massaKg;
     float raioKm;


};