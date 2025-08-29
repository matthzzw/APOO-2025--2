//Nome: Matheus Trindade Teixeira
//Algorítmos de Programação Orientada a Objetos


#include <iostream>
#include <string>

using namespace std;

class Anamnese{
public:


//Construtor padrão
    Anamnese();    
    Anamnese(string nome, int idade, float pesoKg, float alturaM, string alergias, string doencasPreExistente, string medicamentosEmUso  );
    

//Getters 
    string getNome();
    int getIdade();
    float getPesoKg();
    float getAlturaM();
    string getAlergias();
    string getDoencasPreExistente();
    string getMedicamentosEmUso();

//Setters
    void setNome(string nome);
    void setIdade(int idade);
    void setPesoKg(float pesoKg);
    void setAlturaM(float alturaM);
    void setAlergias(string alergias);
    void setDoencasPreExistente(string doencasPreExistente);
    void setMedicamentosEmUso(string medicamentosEmUso);

//Métodos
    float calcularIMC();
    string gerarResumo();

//Destrutor
     ~Anamnese();

private:

    //Atributos

     string nome;
     int idade;
     float pesoKg;
     float alturaM;
     string alergias;
     string doencasPreExistente;
     string medicamentosEmUso;



};