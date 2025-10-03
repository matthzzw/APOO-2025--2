#include <iostream>
#include "Bioma.h"
using namespace std;

int main() {
    // Criar biomas
    Bioma amazon("Amazonia");
    Bioma mata("Mata Atlantica");
    Bioma cerrado("Cerrado");
    Bioma caatinga("Caatinga");
    Bioma pampa("Pampa");
    Bioma pantanal("Pantanal");

    // Criar animais
    Animal capivara("Capivara");
    Animal gralha("Gralha azul");
    Animal tamandua("Tamandua-bandeira");
    Animal onca("Onca pintada");
    Animal tatu("Tatu-bola");

    // Criar vegetais
    Vegetal ipe("Ipe amarelo");
    Vegetal araucaria("Araucaria");
    Vegetal mandacaru("Mandacaru");
    Vegetal vitoria("Vitoria-regia");
    Vegetal jatoba("Jatoba");

    // Distribuição dos animais
    amazon.adicionarAnimal(&capivara);
    mata.adicionarAnimal(&capivara);
    cerrado.adicionarAnimal(&capivara);
    caatinga.adicionarAnimal(&capivara);
    pampa.adicionarAnimal(&capivara);
    pantanal.adicionarAnimal(&capivara);

    mata.adicionarAnimal(&gralha);
    pampa.adicionarAnimal(&gralha);

    amazon.adicionarAnimal(&tamandua);
    mata.adicionarAnimal(&tamandua);
    cerrado.adicionarAnimal(&tamandua);
    pampa.adicionarAnimal(&tamandua);

    amazon.adicionarAnimal(&onca);
    mata.adicionarAnimal(&onca);
    caatinga.adicionarAnimal(&onca);
    pantanal.adicionarAnimal(&onca);

    caatinga.adicionarAnimal(&tatu);

    // Distribuição dos vegetais
    amazon.adicionarVegetal(&ipe);
    mata.adicionarVegetal(&ipe);
    cerrado.adicionarVegetal(&ipe);
    caatinga.adicionarVegetal(&ipe);
    pampa.adicionarVegetal(&ipe);
    pantanal.adicionarVegetal(&ipe);

    mata.adicionarVegetal(&araucaria);
    pampa.adicionarVegetal(&araucaria);

    cerrado.adicionarVegetal(&mandacaru);
    caatinga.adicionarVegetal(&mandacaru);

    amazon.adicionarVegetal(&vitoria);
    pantanal.adicionarVegetal(&vitoria);

    amazon.adicionarVegetal(&jatoba);
    mata.adicionarVegetal(&jatoba);
    cerrado.adicionarVegetal(&jatoba);
    pantanal.adicionarVegetal(&jatoba);

    // Exibir resultados
    amazon.exibirFauna(); amazon.exibirFlora();
    mata.exibirFauna(); mata.exibirFlora();
    cerrado.exibirFauna(); cerrado.exibirFlora();
    caatinga.exibirFauna(); caatinga.exibirFlora();
    pampa.exibirFauna(); pampa.exibirFlora();
    pantanal.exibirFauna(); pantanal.exibirFlora();

    return 0;
}
