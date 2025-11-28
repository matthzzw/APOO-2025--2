#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <fstream>
#include "Pokemon.h"

// Função para salvar um array de Pokémons em arquivo CSV
void salvarPokemonCSV(Pokemon** pokemons, int tamanho, const std::string& nomeArquivo);

#endif
