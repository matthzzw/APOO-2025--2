#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Bioma.h"
#include "Animal.h"
#include "Vegetal.h"

using namespace std;

int main() {
    // 1) criar 6 biomas
    vector<Bioma> biomas = {
        Bioma("Amazonia"),
        Bioma("Mata Atlantica"),
        Bioma("Cerrado"),
        Bioma("Caatinga"),
        Bioma("Pampa"),
        Bioma("Pantanal")
    };

    // mapa nome->índice no vetor para facilitar inserção
    map<string,int> idx;
    for (size_t i = 0; i < biomas.size(); ++i) idx[biomas[i].getNome()] = (int)i;

    // 2) criar instâncias de animais (uma instância por espécie)
    // Usamos new para criar no heap e compartilhar ponteiros entre biomas
    map<string, Animal*> animaisObjs;
    animaisObjs["Capivara"] = new Animal("Capivara");
    animaisObjs["Gralha azul"] = new Animal("Gralha azul");
    animaisObjs["Tamandua-bandeira"] = new Animal("Tamandua-bandeira");
    animaisObjs["Onca pintada"] = new Animal("Onca pintada");
    animaisObjs["Tatu-bola"] = new Animal("Tatu-bola");

    // 3) criar instâncias de vegetais
    map<string, Vegetal*> vegetaisObjs;
    vegetaisObjs["Ipe amarelo"] = new Vegetal("Ipe amarelo");
    vegetaisObjs["Araucaria"] = new Vegetal("Araucaria");
    vegetaisObjs["Mandacaru"] = new Vegetal("Mandacaru");
    vegetaisObjs["Vitoria-regia"] = new Vegetal("Vitoria-regia");
    vegetaisObjs["Jatoba"] = new Vegetal("Jatoba");

    // 4) Tabelas de distribuição (conforme enunciado)
    map<string, vector<string>> distribuicaoAnimais = {
        {"Capivara", {"Amazonia","Mata Atlantica","Cerrado","Caatinga","Pampa","Pantanal"}},
        {"Gralha azul", {"Mata Atlantica","Pampa"}},
        {"Tamandua-bandeira", {"Amazonia","Mata Atlantica","Cerrado","Pampa"}},
        {"Onca pintada", {"Amazonia","Mata Atlantica","Caatinga","Pantanal"}},
        {"Tatu-bola", {"Caatinga"}}
    };

    map<string, vector<string>> distribuicaoVegetais = {
        {"Ipe amarelo", {"Amazonia","Mata Atlantica","Cerrado","Caatinga","Pampa","Pantanal"}},
        {"Araucaria", {"Mata Atlantica","Pampa"}},
        {"Mandacaru", {"Cerrado","Caatinga"}},
        {"Vitoria-regia", {"Amazonia","Pantanal"}},
        {"Jatoba", {"Amazonia","Mata Atlantica","Cerrado","Pantanal"}}
    };

    // 5) adicionar animais aos biomas conforme a tabela
    for (const auto& kv : distribuicaoAnimais) {
        const string& nomeAnimal = kv.first;
        const vector<string>& locais = kv.second;
        Animal* a = animaisObjs[nomeAnimal];
        if (!a) continue;
        for (const string& local : locais) {
            auto it = idx.find(local);
            if (it != idx.end()) {
                biomas[it->second].adicionarAnimal(a);
            }
        }
    }

    // 6) adicionar vegetais aos biomas
    for (const auto& kv : distribuicaoVegetais) {
        const string& nomeV = kv.first;
        const vector<string>& locais = kv.second;
        Vegetal* v = vegetaisObjs[nomeV];
        if (!v) continue;
        for (const string& local : locais) {
            auto it = idx.find(local);
            if (it != idx.end()) {
                biomas[it->second].adicionarVegetal(v);
            }
        }
    }

    // 7) exibir fauna e flora de cada bioma
    for (const Bioma& b : biomas) {
        b.exibirFauna();
        b.exibirFlora();
    }

    // 8) liberar memória (opcional, programa termina logo em seguida)
    for (auto& kv : animaisObjs) delete kv.second;
    for (auto& kv : vegetaisObjs) delete kv.second;

    return 0;
}
