#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// O construtor carrega tudo dos arquivos e inicia o menu principal.
Sistema::Sistema() {
    totalUsuarios = 0;
    totalTrocas = 0;
    totalPokemons = 0;
    usuarioLogado = nullptr;
    srand(time(NULL));
    carregarDados();
    menuPrincipal();
}

// Chama todas as funções de carregamento em ordem.
void Sistema::carregarDados() {
    carregarNomesPokemons();
    carregarUsuarios();
    carregarFigurinhas();
    carregarTrocas();
}

// Chama todas as funções de salvamento.
void Sistema::salvarDados() {
    salvarUsuarios();
    salvarFigurinhas();
    salvarTrocas();
    cout << "\nDados salvos com sucesso!" << endl;
}

// Lê o arquivo pokemons.csv e coloca no array nomesPokemons.
void Sistema::carregarNomesPokemons() {
    ifstream arquivo("pokemons.csv");
    string linha;
    if (arquivo.is_open()) {
        while (getline(arquivo, linha) && totalPokemons < MAX_POKEMONS) {
            if (linha.empty()) continue;
            stringstream ss(linha);
            string temp, nome, tipo;
            int numero;
            getline(ss, temp, ','); numero = stoi(temp);
            getline(ss, nome, ',');
            getline(ss, tipo);
            nomesPokemons[totalPokemons] = {numero, nome, tipo};
            totalPokemons++;
        }
        arquivo.close();
    }
}

// Lê o arquivo usuarios.csv e coloca no array usuarios.
void Sistema::carregarUsuarios() {
    ifstream arquivo("usuarios.csv");
    string linha;
    if (arquivo.is_open()) {
        while (getline(arquivo, linha) && totalUsuarios < MAX_USUARIOS) {
            if (linha.empty()) continue;
            stringstream ss(linha);
            string nome, senha;
            getline(ss, nome, ',');
            getline(ss, senha);
            if (!nome.empty()) {
                usuarios[totalUsuarios] = Usuario(nome, senha);
                totalUsuarios++;
            }
        }
        arquivo.close();
    }
}

// Lê o arquivo figurinhas.csv, busca o nome correto e adiciona ao álbum do usuário certo.
void Sistema::carregarFigurinhas() {
    ifstream arquivo("figurinhas.csv");
    string linha;
    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            if (linha.empty()) continue;
            stringstream ss(linha);
            string dono, tipo, temp;
            int numero, status;
            getline(ss, dono, ',');
            getline(ss, temp, ','); numero = stoi(temp);
            getline(ss, tipo, ',');
            getline(ss, temp, ','); status = stoi(temp);
            
            Usuario* user = findUsuario(dono);
            if (user) {
                user->getAlbum().adicionarFigurinha(Figurinha(numero, getNomePokemon(numero), tipo, status));
            }
        }
        arquivo.close();
    }
}

// Lê o arquivo trocas.csv e coloca no array trocas.
void Sistema::carregarTrocas() {
    ifstream arquivo("trocas.csv");
    string linha;
    if (arquivo.is_open()) {
        while (getline(arquivo, linha) && totalTrocas < MAX_TROCAS) {
            if (linha.empty()) continue;
            stringstream ss(linha);
            string temp, sol, parc;
            int id, fO, fD, stat;
            getline(ss, temp, ','); id = stoi(temp);
            getline(ss, sol, ',');
            getline(ss, parc, ',');
            getline(ss, temp, ','); fO = stoi(temp);
            getline(ss, temp, ','); fD = stoi(temp);
            getline(ss, temp, ','); stat = stoi(temp);
            trocas[totalTrocas] = Troca(id, sol, parc, fO, fD);
            trocas[totalTrocas].status = stat;
            totalTrocas++;
        }
        arquivo.close();
    }
}

// Salva os usuários no arquivo usuarios.csv.
void Sistema::salvarUsuarios() {
    ofstream arquivo("usuarios.csv");
    if(arquivo.is_open()){
        for(int i = 0; i < totalUsuarios; i++){
             arquivo << usuarios[i].getNomeUsuario() << ",senha_padrao\n";
        }
        arquivo.close();
    }
}

// Salva todas as figurinhas de todos os usuários no arquivo figurinhas.csv.
void Sistema::salvarFigurinhas() {
    ofstream arquivo("figurinhas.csv");
    if (arquivo.is_open()) {
        for (int i = 0; i < totalUsuarios; i++) {
            Album& albumDoUsuario = usuarios[i].getAlbum();
            const Figurinha* figs = albumDoUsuario.getFigurinhas();
            int totalFigs = albumDoUsuario.getTotalFigurinhas();
            for (int j = 0; j < totalFigs; j++) {
                arquivo << usuarios[i].getNomeUsuario() << ","
                        << figs[j].getNumero() << ","
                        << figs[j].getTipo() << ","
                        << figs[j].getStatus() << "\n";
            }
        }
        arquivo.close();
    }
}

// Salva todas as propostas de troca no arquivo trocas.csv.
void Sistema::salvarTrocas() {
    ofstream arquivo("trocas.csv");
    if(arquivo.is_open()){
        for(int i = 0; i < totalTrocas; i++){
            arquivo << trocas[i].id << ","
                    << trocas[i].solicitante << ","
                    << trocas[i].parceiro << ","
                    << trocas[i].figurinhaOferecida << ","
                    << trocas[i].figurinhaDesejada << ","
                    << trocas[i].status << "\n";
        }
        arquivo.close();
    }
}

// --- MENUS ---
// Controla o loop do menu inicial.
void Sistema::menuPrincipal() {
    int opcao = 0;
    while (opcao != 3) {
        cout << "\n===== TELA INICIAL =====" << endl;
        cout << "1 - Novo Album" << endl;
        cout << "2 - Acessar Album" << endl;
        cout << "3 - Sair do Aplicativo" << endl;
        cout << "Escolha: ";
        cin >> opcao;
        if (cin.fail()) {
            cout << "Entrada invalida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = 0;
            continue;
        }

        switch (opcao) {
            case 1: criarNovoUsuario(); break;
            case 2: acessarAlbum(); break;
            case 3: salvarDados(); break;
            default: cout << "Opcao invalida." << endl;
        }
    }
}

// Controla o loop do menu do usuário logado.
void Sistema::menuGerenciarAlbum() {
    if(!usuarioLogado) return;
    int opcao = 0;
    while (opcao != 4) {
        cout << "\n--- GERENCIAR ALBUM: " << usuarioLogado->getNomeUsuario() << " ---" << endl;
        cout << "1 - Ver Album" << endl;
        cout << "2 - Gerenciar a colecao" << endl;
        cout << "3 - Abrir pacote de Figurinhas" << endl;
        cout << "4 - Voltar ao menu Anterior" << endl;
        cout << "Escolha: ";
        cin >> opcao;
        if (cin.fail()) {
            cout << "Entrada invalida." << endl;
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = 0; continue;
        }

        switch (opcao) {
            case 1: verAlbum(); break;
            case 2: menuGerenciarColecao(); break;
            case 3: abrirPacote(); break;
            case 4: usuarioLogado = nullptr; cout << "Logout efetuado." << endl; break;
            default: cout << "Opcao invalida." << endl;
        }
    }
}

// Controla o loop do menu de gerenciamento da coleção.
void Sistema::menuGerenciarColecao() {
    if(!usuarioLogado) return;
    int opcao = 0;
    while (opcao != 5) {
        usuarioLogado->getAlbum().gerenciarColecao(*this);
        cout << "\n--- GERENCIAR COLECAO ---" << endl;
        cout << "1 - Colar Figurinha" << endl;
        cout << "2 - Disponibilizar para troca" << endl;
        cout << "3 - Propor troca de figurinhas" << endl;
        cout << "4 - Revisar solicitacoes de troca" << endl;
        cout << "5 - Voltar ao menu Anterior" << endl;
        cout << "Escolha: ";
        cin >> opcao;
        if (cin.fail()) {
             cout << "Entrada invalida." << endl;
             cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
             opcao = 0; continue;
        }

        switch (opcao) {
            case 1: colarFigurinha(); break;
            case 2: disponibilizarParaTroca(); break;
            case 3: proporTroca(); break;
            case 4: revisarTrocas(); break;
            case 5: break;
            default: cout << "Opcao invalida." << endl;
        }
    }
}

// --- AÇÕES ---
// Permite criar um novo usuário e senha.
void Sistema::criarNovoUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        cout << "Sistema cheio." << endl;
        return;
    }
    string nome, senha;
    cout << "Digite o nome do novo usuario: ";
    cin >> nome;
    if(findUsuario(nome)){
        cout << "Usuario ja existe." << endl;
        return;
    }
    cout << "Digite a senha: ";
    cin >> senha;
    usuarios[totalUsuarios] = Usuario(nome, senha);
    totalUsuarios++;
    cout << "Usuario criado com sucesso!" << endl;
}

// Permite que um usuário existente faça login.
void Sistema::acessarAlbum() {
    string nome, senha;
    cout << "Usuario: "; cin >> nome;
    cout << "Senha: "; cin >> senha;
    
    usuarioLogado = nullptr;
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].verificarLogin(nome, senha)) {
            usuarioLogado = &usuarios[i];
            break;
        }
    }
    if (usuarioLogado) {
        menuGerenciarAlbum();
    } else {
        cout << "Usuario ou senha invalidos." << endl;
    }
}

// Controla a navegação pelas páginas do álbum.
void Sistema::verAlbum() {
    if(!usuarioLogado) return;
    int pagina = 1;
    char acao;
    int figPorPagina = 10;
    int maxPaginas = (151 / figPorPagina) + (151 % figPorPagina > 0 ? 1 : 0);
    do {
        usuarioLogado->getAlbum().exibirPagina(pagina, figPorPagina, *this);
        cout << "Use 'a' para avancar, 'r' para recuar, ou 'v' para voltar: ";
        cin >> acao;
        if (acao == 'a' && pagina < maxPaginas) pagina++;
        else if (acao == 'r' && pagina > 1) pagina--;
    } while (acao != 'v');
}

// Chama o método para abrir um pacote no álbum do usuário logado.
void Sistema::abrirPacote() {
    if(usuarioLogado) usuarioLogado->getAlbum().abrirPacote(*this);
}

// Permite ao usuário colar uma figurinha que ele possui.
void Sistema::colarFigurinha() {
    if(!usuarioLogado) return;
    int num;
    cout << "Numero da figurinha para colar: ";
    cin >> num;
    if(cin.fail()){  cout << "Numero invalido." << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return; }

    Figurinha* fig = usuarioLogado->getAlbum().getFigurinha(num);
    if(fig){
        if(fig->getStatus() == 0 || fig->getStatus() == 2){
            fig->setStatus(1);
            cout << "Figurinha " << fig->getNome() << " colada!" << endl;
        } else {
            cout << "Esta figurinha ja esta colada." << endl;
        }
    } else {
        cout << "Voce nao possui esta figurinha." << endl;
    }
}

// Permite ao usuário marcar uma figurinha como disponível para troca.
void Sistema::disponibilizarParaTroca() {
    if(!usuarioLogado) return;
    int num;
    cout << "Numero da figurinha a disponibilizar para troca: ";
    cin >> num;
    if(cin.fail()){  cout << "Numero invalido." << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return; }

    Figurinha* fig = usuarioLogado->getAlbum().getFigurinha(num);
    if(fig && fig->getStatus() == 0){
        fig->setStatus(2);
        cout << "Figurinha " << fig->getNome() << " agora esta disponivel para troca." << endl;
    } else if (fig) {
        cout << "Esta figurinha nao pode ser disponibilizada (ja colada ou ja para troca)." << endl;
    } else {
        cout << "Voce nao possui esta figurinha." << endl;
    }
}

// Permite ao usuário propor uma troca com outro jogador.
void Sistema::proporTroca() {
    if (totalTrocas >= MAX_TROCAS) { cout << "Sistema de trocas esta cheio." << endl; return; }
    
    cout << "\n--- Propor Troca ---" << endl;
    cout << "Usuarios e suas figurinhas disponiveis para troca:" << endl;
    bool haTrocasDisponiveis = false;
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].getNomeUsuario() != usuarioLogado->getNomeUsuario()) {
            cout << "-> Usuario: " << usuarios[i].getNomeUsuario() << endl;
            const Figurinha* figs = usuarios[i].getAlbum().getFigurinhas();
            int totalFigs = usuarios[i].getAlbum().getTotalFigurinhas();
            int figsParaTroca = 0;
            for(int j=0; j<totalFigs; ++j){
                if(figs[j].getStatus() == 2){
                    cout << "   "; figs[j].exibir();
                    haTrocasDisponiveis = true;
                    figsParaTroca++;
                }
            }
            if(figsParaTroca == 0) cout << "   (Nenhuma figurinha para troca)" << endl;
        }
    }
    if(!haTrocasDisponiveis){ cout << "Ninguem tem figurinhas para troca no momento." << endl; return; }
    
    string nomeParceiro;
    int figDesejada, figOferecida;
    cout << "\nDigite o nome do usuario com quem quer trocar: "; cin >> nomeParceiro;
    Usuario* parceiro = findUsuario(nomeParceiro);
    if(!parceiro || parceiro->getNomeUsuario() == usuarioLogado->getNomeUsuario()){ cout << "Usuario invalido." << endl; return; }

    cout << "Digite o numero da figurinha que voce DESEJA (dele): "; cin >> figDesejada;
    cout << "Digite o numero da figurinha que voce OFERECE (sua): "; cin >> figOferecida;

    Figurinha* minhaFig = usuarioLogado->getAlbum().getFigurinha(figOferecida);
    Figurinha* figParceiro = parceiro->getAlbum().getFigurinha(figDesejada);

    if (minhaFig && minhaFig->getStatus() == 2 && figParceiro && figParceiro->getStatus() == 2) {
        int novoId = (totalTrocas > 0) ? trocas[totalTrocas - 1].id + 1 : 1;
        trocas[totalTrocas] = Troca(novoId, usuarioLogado->getNomeUsuario(), nomeParceiro, figOferecida, figDesejada);
        totalTrocas++;
        cout << "Proposta de troca enviada para " << nomeParceiro << "!" << endl;
    } else {
        cout << "Erro: Uma das figurinhas nao existe ou nao esta disponivel para troca." << endl;
    }
}

// Permite ao usuário aceitar ou recusar troca.
void Sistema::revisarTrocas() {
    cout << "\n--- Solicitacoes de Troca para Voce ---" << endl;
    bool encontrou = false;
    for (int i = 0; i < totalTrocas; i++) {
        if (trocas[i].parceiro == usuarioLogado->getNomeUsuario() && trocas[i].status == 0) {
            trocas[i].exibir(*this);
            encontrou = true;
        }
    }
    if (!encontrou) { cout << "Nenhuma nova solicitacao de troca." << endl; return; }

    int idTroca;
    cout << "\nDigite o ID da troca para revisar (ou 0 para cancelar): "; cin >> idTroca;
    if (idTroca == 0) return;

    Troca* troca = findTroca(idTroca);
    if (troca == nullptr || troca->parceiro != usuarioLogado->getNomeUsuario() || troca->status != 0) {
        cout << "ID de troca invalido." << endl;
        return;
    }

    int decisao;
    cout << "Digite 1 para ACEITAR ou 2 para RECUSAR: "; cin >> decisao;
    if (decisao == 2) {
        troca->status = 2; // Recusada
        cout << "Troca recusada." << endl;
    } else if (decisao == 1) {
        Usuario* solicitante = findUsuario(troca->solicitante);
        Usuario* parceiro = usuarioLogado;
        Figurinha* figOferecida = solicitante->getAlbum().getFigurinha(troca->figurinhaOferecida);
        Figurinha* figDesejada = parceiro->getAlbum().getFigurinha(troca->figurinhaDesejada);

        if (solicitante && parceiro && figOferecida && figDesejada && figOferecida->getStatus() == 2 && figDesejada->getStatus() == 2) {
            Figurinha copiaFigOferecida = *figOferecida;
            Figurinha copiaFigDesejada = *figDesejada;

            solicitante->getAlbum().removerFigurinha(copiaFigOferecida.getNumero());
            parceiro->getAlbum().removerFigurinha(copiaFigDesejada.getNumero());
            
            copiaFigOferecida.setStatus(0);
            copiaFigDesejada.setStatus(0);
            
            solicitante->getAlbum().adicionarFigurinha(copiaFigDesejada);
            parceiro->getAlbum().adicionarFigurinha(copiaFigOferecida);
            
            troca->status = 1; // Aceita
            cout << "Troca realizada com sucesso!" << endl;
        } else {
            cout << "Erro: A troca nao pode ser completada. Uma das figurinhas nao esta mais disponivel." << endl;
            troca->status = 2;
        }
    } else {
        cout << "Decisao invalida." << endl;
    }
}

// ---  AUXILIARES ---
// Busca os dados de um Pokémon pelo número.
const PokemonData* Sistema::getPokemonData(int numero) const {
    for (int i = 0; i < totalPokemons; i++) {
        if (nomesPokemons[i].numero == numero) {
            return &nomesPokemons[i];
        }
    }
    return nullptr;
}

// Busca apenas o nome de um Pokémon pelo número.
string Sistema::getNomePokemon(int numero) const {
    const PokemonData* data = getPokemonData(numero);
    if (data) return data->nome;
    return "Pokemon #" + to_string(numero);
}

// Busca um usuário no array pelo nome.
Usuario* Sistema::findUsuario(const string& nome) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].getNomeUsuario() == nome) {
            return &usuarios[i];
        }
    }
    return nullptr;
}

// Busca uma troca no array pelo ID.
Troca* Sistema::findTroca(int id) {
    for (int i = 0; i < totalTrocas; i++) {
        if (trocas[i].id == id) {
            return &trocas[i];
        }
    }
    return nullptr;
}