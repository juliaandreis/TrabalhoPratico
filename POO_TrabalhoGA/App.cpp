#include "App.h"
#include "Combate.h"
#include "Guerreiro.h"
#include "Inventario.h"
#include "Item.h"
#include "Ladino.h"
#include "Magia.h"
#include "Mago.h"
#include "Monstro.h"
#include "Personagem.h"
#include "Tela.h"
#include <cctype> // toupper
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

App::App() {
  telas = new Tela *[TOTAL_CENAS];
  for (int i = 0; i < TOTAL_CENAS; i++)
    telas[i] = new Tela();
  telaAtual = 0;

  player = new Personagem();
  string nomeArquivo;
  string opcao;
  for (int i = 0; i < TOTAL_CENAS; i++) {
    nomeArquivo = to_string(i) + ".txt";
    telas[i]->leituraArquivo(nomeArquivo);
  }
  while (telaAtual != 24) {
    telas[telaAtual]->mostrar();

    if(telas[telaAtual]->getItemAdquirido()){ // se tiver item na tela
      player->adicionarItem(telas[telaAtual]->getItem());
      cout << endl << " Item " << telas[telaAtual]->getItem()->getNome() << " encontrado!" << endl << endl;
    }

    if(telas[telaAtual]->getMagiaAdquirida()){ // se tiver magia na tela
      player->setMagia(telas[telaAtual]->getMagia());
      cout << endl << " Magia " << telas[telaAtual]->getMagia()->getNome() << " aprendida." << endl << endl;
      }

    if (telaAtual != 0 && telaAtual != 23 && telas[telaAtual]->getCombate() == 0) { // se nao for menus, creditos e combate
      cout << " S: Salvar e Sair" << endl;
      cout << " I: Abrir Inventario" << endl;
    }
    cout << endl << " -> ";
    cin >> opcao;

    if (telas[telaAtual]->getCombate()) {
      setMonstro(telas[telaAtual]->getMonstro());

      cout << endl << " Monstro " << this->monstro->getNome() << " encontrado!" << endl;
      cout << " Combate ativado0!" << endl << endl;

      if(this->monstro->getProveItem())
        cout << " Item \"" << monstro->getInventario()->getItem(0)->getNome() << "\" pode ser obtido com a Vitoria!" << endl << endl;

      while (telas[telaAtual]->getCombate() != 0) combate();
    }

    if (telaAtual == 0 && stoi(opcao) == 2) {
      carregar("save1.txt");
    } else if (telaAtual == 0 && stoi(opcao) == 3) {
      carregar("save2.txt");
    } else if (telaAtual == 23) {
      criarPersonagem(stoi(opcao));
      telaAtual = 1;
    } else if (toupper(opcao[0]) != 'S' && toupper(opcao[0]) != 'I') {
      int prox = stoi(opcao);
      telaAtual = telas[telaAtual]->getOpcoes(prox - 1);
    } else if (toupper(opcao[0]) == 'S') {
      cout << " Onde voce deseja salvar?" << endl;
      cout << " 1) Save 1      2) Save 2" << endl;
      cout << endl << " -> ";
      cin >> opcao;
      if (stoi(opcao) == 1) {
        salvar("save1.txt");
      } else if (stoi(opcao) == 2) {
        salvar("save2.txt");
      }
    } else if (toupper(opcao[0]) == 'I') {
      abrirInventario();
    }
    opcao = "";
  }
  telas[telaAtual]->mostrar();
}

void App::setPlayer(Personagem *player) { this->player = player; }

void App::setMonstro(Monstro *monstro) { this->monstro = monstro; }

// mostra o menu inicial
void App::menu() { telas[0]->mostrar(); }

// inicia com o personagem escolhido
void App::criarPersonagem(int opcao) {
  // Nome;Tipo;Combate;FA;Dano
  Item *espada = new Item("Espada", 'w', 1, 2, 2);
  Item *escudo = new Item("Escudo", 'r', 1, 0, -1);
  Item *adaga = new Item("Adaga", 'w', 1, 3, 3);
  Item *armadura = new Item("Armadura", 'r', 1, 0, -1);

  if (opcao == 1) {
    player = new Guerreiro("Guerreiro");
    player->adicionarItem(espada);
    player->adicionarItem(escudo);
    player->adicionarItem(armadura);
  } else if (opcao == 2) {
    Magia *bolaDeFogo = new Magia("Bola De Fogo", 0, 3, 4);
    Magia *cura = new Magia("Cura", 5, 0, 2);
    Magia *choqueDoTrovão = new Magia("Choque Do Trovão", 0, 4, 1);
    player = new Mago("Mago", bolaDeFogo, cura, choqueDoTrovão);
  } else if (opcao == 3) {
    player = new Ladino("Ladino");
    player->adicionarItem(adaga);
    player->adicionarItem(armadura);
  }
  player->imprime_info();
  cout << endl;
  cout << " Você tem 12 ponntos para distribuir entre Habilidade, Vida e Sorte."
       << endl << endl;
  cout << " Habilidade: mínimo igual a 6 e máximo igual a 12" << endl;
  cout << " Vida: mínimo igual a 12 e máximo igual a 24;" << endl;
  cout << " Sorte: mínimo igual a 6 e máximo igual a 12" << endl << endl;
  cout << endl;
  cout << " 1) Escolher como distribuir" << endl;
  cout << " 2) Distribuir aleatoriamente" << endl << endl;
  cout << " -> ";
  int distribuir;
  cin >> distribuir;
  
  if (distribuir == 1){
    int habEscolhida, vidaEscolhida, sorEscolhida;
    int habilidade, vida, sorte;
    do{
      cout << " Adicionar a Habilidade: ";
      cin >> habEscolhida;
      cout << " Adicionar a Vida: ";
      cin >> vidaEscolhida;
      cout << " Adicionar a Sorte: ";
      cin >> sorEscolhida;
      
      habilidade = (player->getHabilidade() + habEscolhida);
      vida = (player->getVida() + vidaEscolhida);
      sorte = (player->getSorte() + sorEscolhida);
      
      if ((((habilidade <= 12)*habEscolhida + (vida <= 24)*vidaEscolhida + (sorte <= 12)*sorEscolhida) == 12) && (habEscolhida + vidaEscolhida + sorEscolhida) == 12) {
        player->escolheValorAtributos(habEscolhida, vidaEscolhida, sorEscolhida);
      } else {
        cout << endl << " A soma dos valores deve ser 12, e os valores máximos não devem ser ultrapassados" << endl << endl;
      }
    } while (!((((habilidade <= 12)*habEscolhida + (vida <= 24)*vidaEscolhida + (sorte <= 12)*sorEscolhida) == 12) && (habEscolhida + vidaEscolhida + sorEscolhida) == 12));
    
  }
  else if (distribuir == 2){
    player->aleatorioValorAtributos();
  }
  cout << endl << "Novos valores: " << endl;
  player->imprime_info();
}

// Salvar Jogo Atual
void App::salvar(string arquivo) {
  ofstream save(arquivo);
  if (!save.is_open()) {
    cerr << "Erro ao abrir o arquivo para escrita!\n";
    return;
  }
  save << telaAtual << endl;
  save << player->getNome() << endl;
  save << player->getHabilidade() << endl;
  save << player->getVida() << endl;
  save << player->getSorte() << endl;
  save << player->getTesouro() << endl;
  save << player->getProvisoes() << endl;
  Inventario *inv = player->getInventario();

  for (int i = 0; i < 6; i++) {
    Item *item = inv->getItem(i);
    if (item != nullptr) {
      save << "I" << endl;
      save << item->getNome() << ";" << item->getTipo() << ";" << item->getFA()
           << ";" << item->getDano() << ";" << item->getEquipado() << endl;
    }
  }
  for (int i = 0; i < player->getNum_magias(); i++) {
    if (player->getMagias(i) != nullptr) {
      save << "M" << endl;
      save << player->getMagias(i)->getNome() << ";"
           << player->getMagias(i)->getCura() << ";"
           << player->getMagias(i)->getDano() << ";"
           << player->getMagias(i)->getUsoDisponivel() << endl;
    }
  }

  save.close();

  cout << "Jogo salvo com sucesso!" << endl;
  telaAtual = 24;
}

// Carregar Jogo Salvo
void App::carregar(string arquivo) {
  ifstream save(arquivo);
  if (!save.is_open()) {
    cerr << "Erro ao abrir o arquivo para leitura!\n";
    return;
  }

  string classe, tipo, linha;
  string nomeItem, nomeMagia;
  char tipoItem;
  int hab, vid, sor, tes, prov;
  int fa, dano, cura, usoDisponivel;
  bool equipado;

  Magia *magia1 = nullptr, *magia2 = nullptr, *magia3 = nullptr;
  Item *itens[6] = {nullptr}; // suporta até 6 itens
  int itemCount = 0;
  int magiaCount = 0;

  save >> telaAtual;
  save.ignore(); // Ignora \n após número

  getline(save, classe);
  save >> hab;
  save >> vid;
  save >> sor;
  save >> tes;
  save >> prov;
  // save.ignore(); // Ignora \n após provisoes

  // Lê os dados de itens e magias antes de instanciar o player
  while (getline(save, tipo)) {
    if (tipo == "I") {
      getline(save, linha); // Nome;Tipo;FA;Dano;Equipado

      size_t pos1 = linha.find(';');
      nomeItem = linha.substr(0, pos1);

      size_t pos2 = linha.find(';', pos1 + 1);
      tipoItem = linha[pos1 + 1];

      size_t pos3 = linha.find(';', pos2 + 1);
      fa = stoi(linha.substr(pos2 + 1, pos3 - pos2 - 1));

      size_t pos4 = linha.find(';', pos3 + 1);
      dano = stoi(linha.substr(pos3 + 1, pos4 - pos3 - 1));

      equipado = stoi(linha.substr(pos4 + 1));

      if (itemCount < 6) {
        itens[itemCount++] = new Item(nomeItem, tipoItem, fa, dano, equipado);
      }
    } else if (tipo == "M") {
      getline(save, linha); // Nome;Cura;Dano;UsoDisponivel

      size_t pos1 = linha.find(';');
      nomeMagia = linha.substr(0, pos1);

      size_t pos2 = linha.find(';', pos1 + 1);
      cura = stoi(linha.substr(pos1 + 1, pos2 - pos1 - 1));

      size_t pos3 = linha.find(';', pos2 + 1);
      dano = stoi(linha.substr(pos2 + 1, pos3 - pos2 - 1));

      usoDisponivel = stoi(linha.substr(pos3 + 1));

      Magia *novaMagia = new Magia(nomeMagia, cura, dano, usoDisponivel);
      if (magiaCount == 0)
        magia1 = novaMagia;
      else if (magiaCount == 1)
        magia2 = novaMagia;
      else if (magiaCount == 2)
        magia3 = novaMagia;
      magiaCount++;
    }
  }

  // Criação do player após leitura de tudo
  if (classe == "Guerreiro") {
    player = new Guerreiro(classe);
  } else if (classe == "Ladino") {
    player = new Ladino(classe);
  } else if (classe == "Mago") {
    player = new Mago(classe, magia1, magia2, magia3);
  }

  // Define atributos
  player->setHabilidade(hab);
  player->setVida(vid);
  player->setSorte(sor);
  player->setTesouro(tes);
  player->setProvisoes(prov);

  // Adiciona os itens
  for (int i = 0; i < itemCount; i++) {
    player->adicionarItem(itens[i]);
  }
  save.close();
}

void App::abrirInventario() {
  int escolhaMenu = 0;
  int escolha = 0;
  while (escolhaMenu != 3){
    cout << endl << " 1) Ver Itens     2) Ver Magias     3) Fechar" << endl;
    cout << " -> ";
    cin >> escolhaMenu;
    cout << endl;
    if (escolhaMenu == 1) {
      player->imprime_inventario();
      cin >> escolha;
      if (escolha == 1) {
        cout << endl << " Qual item deseja equipar?" << endl;
        cout << " -> ";
        cin >> escolha;
        player->equiparItem(player->getInventario()->getItem(escolha - 1));
      } else if (escolha == 2) {
        cout << endl <<  " Qual item deseja desequipar?" << endl;
        cout << " -> ";
        cin >> escolha;
        player->desequiparItem(player->getInventario()->getItem(escolha - 1));
      } else if (escolha == 3) {
        cout << endl <<  " Qual item deseja excluir?" << endl;
        cout << " -> ";
        cin >> escolha;
        player->removerItem(player->getInventario()->getItem(escolha - 1));
      }
      else if (escolha == 4) {
        player->usarProvisao();
      }
        else if (escolha == 5) {
        cout << " Voltando..." << endl;
      }
    }
    else if (escolhaMenu == 2){
      player->imprime_magias();
      cout << " -> ";
      cin >> escolha;
      if (escolha == 1){
        cout <<  endl << "Qual magia deseja usar?" << endl;
        cout << " -> ";
        cin >> escolha;
        player->usarMagia(player->getMagias(escolha - 1));
      }
      else if (escolha == 2){
        cout << "Voltando..." << endl;
      }
    }
  }
}

void App::combate() {
  Combate *comb = new Combate(player, monstro);
  cout << "1) Iniciar Combate     2) Tentar fugir" << endl << endl;
  cout << " -> ";
  int escolha;
  cin >> escolha;
  cout << endl;
  if (escolha == 1 && player->getDano() <= 1){
    cout << endl << " Voce nao vai equipar um item ou magia para batalhar?" << endl << endl;
    cout << " 1) Equipar    2) Ir assim mesmo" << endl << endl;
    int boolEquipar;
    cout << " -> ";
    cin >> boolEquipar;
    if(boolEquipar == 1)
      abrirInventario();
    else
      comb->acaoCombate();
  }
  if (escolha == 1 && player->getDano() > 1)
    comb->acaoCombate();
  
  else if (escolha == 2){
    if (comb->fugir()){
      cout << "Você conseguiu fugir!" << endl;
      telaAtual = 15;
    }
    else {
      cout << "Você não conseguiu fugir, hora do combate!" << endl;
      comb->acaoCombate();
    }
  }
      
  if (comb->getMonstro()->getVida() <= 0){
    telas[telaAtual]->setCombate(0);
    
    player->setTesouro(player->getTesouro() + comb->getMonstro()->getTesouro());
    player->setProvisoes(player->getProvisoes() + comb->getMonstro()->getProvisoes());
    
    if (comb->getMonstro()->getProveItem()){
      player->adicionarItem(comb->getMonstro()->getInventario()->getItem(0));
      cout << " Item Obtido: " << comb->getMonstro()->getInventario()->getItem(0)->getNome() << endl;
    }
    cout << " Tesouro atual: " << player->getTesouro() << endl;
    cout << " Provisoes atuais: " << player->getProvisoes() << endl;
    
    telaAtual = comb->getMonstro()->getPaginaVitoria();
    //cout << " teste Tela Vitoria: " << telaAtual << endl;
  }
  else if (comb->getPersonagem()->getVida() <= 0){
    telas[telaAtual]->setCombate(0);
    
    telaAtual = comb->getMonstro()->getPaginaDerrota();
    //cout << " teste Tela Derrota: " << telaAtual << endl;
    telas[telaAtual]->mostrar();
  }
}