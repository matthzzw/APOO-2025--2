
#include "FreqCardiaca.h"
using namespace std;

int main() {
    string nome, sobrenome;
    int dia, mes, ano;
    int diaAtual, mesAtual, anoAtual;

    cout << "Primeiro nome: ";
    cin >> nome;
    cout << "Sobrenome: ";
    cin >> sobrenome;
    cout << "Data de nascimento (dia mes ano): ";
    cin >> dia >> mes >> ano;

    cout << "Data atual (dia mes ano): ";
    cin >> diaAtual >> mesAtual >> anoAtual;

    FrequenciaCardiaca pessoa(nome, sobrenome, dia, mes, ano);

    int idade = pessoa.obterIdade(diaAtual, mesAtual, anoAtual);
    int freqMax = pessoa.obterFrequenciaMaxima(idade);

    cout << "\n=== Resultado ===\n";
    cout << "Nome completo: " << pessoa.getPrimeiroNome() << " " << pessoa.getSobrenome() << endl;
    cout << "Data de nascimento: " << pessoa.getDiaNasc() << "/" << pessoa.getMesNasc() << "/" << pessoa.getAnoNasc() << endl;
    cout << "Idade: " << idade << " anos" << endl;
    cout << "Frequencia cardiaca maxima: " << freqMax << " bpm" << endl;
    pessoa.obterFrequenciaIdeal(idade);

    return 0;
}
