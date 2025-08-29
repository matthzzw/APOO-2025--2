#include "FreqCardiaca.h"
using namespace std;

// Construtor padrão
FrequenciaCardiaca::FrequenciaCardiaca() {
    primeiroNome = "";
    sobrenome = "";
    diaNasc = 1;
    mesNasc = 1;
    anoNasc = 2000;
}

// Construtor com parâmetros
FrequenciaCardiaca::FrequenciaCardiaca(string primeiroNome, string sobrenome,
                                       int diaNasc, int mesNasc, int anoNasc) {
    this->primeiroNome = primeiroNome;
    this->sobrenome = sobrenome;
    this->diaNasc = diaNasc;
    this->mesNasc = mesNasc;
    this->anoNasc = anoNasc;
}

// Getters
string FrequenciaCardiaca::getPrimeiroNome() { return primeiroNome; }
string FrequenciaCardiaca::getSobrenome() { return sobrenome; }
int FrequenciaCardiaca::getDiaNasc() { return diaNasc; }
int FrequenciaCardiaca::getMesNasc() { return mesNasc; }
int FrequenciaCardiaca::getAnoNasc() { return anoNasc; }

// Setters
void FrequenciaCardiaca::setPrimeiroNome(string primeiroNome) { this->primeiroNome = primeiroNome; }
void FrequenciaCardiaca::setSobrenome(string sobrenome) { this->sobrenome = sobrenome; }
void FrequenciaCardiaca::setDiaNasc(int dia) { this->diaNasc = dia; }
void FrequenciaCardiaca::setMesNasc(int mes) { this->mesNasc = mes; }
void FrequenciaCardiaca::setAnoNasc(int ano) { this->anoNasc = ano; }

// Métodos
int FrequenciaCardiaca::obterIdade(int diaAtual, int mesAtual, int anoAtual) {
    int idade = anoAtual - anoNasc;
    if (mesAtual < mesNasc || (mesAtual == mesNasc && diaAtual < diaNasc)) {
        idade--;
    }
    return idade;
}

int FrequenciaCardiaca::obterFrequenciaMaxima(int idade) {
    return 220 - idade;
}

void FrequenciaCardiaca::obterFrequenciaIdeal(int idade) {
    int maxima = obterFrequenciaMaxima(idade);
    int minAlvo = maxima * 50 / 100;
    int maxAlvo = maxima * 85 / 100;
    cout << "Faixa ideal: " << minAlvo << " - " << maxAlvo << " bpm" << endl;
}
