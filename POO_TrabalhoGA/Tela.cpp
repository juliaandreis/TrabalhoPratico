#include "Tela.h"
#include "Item.h"
#include <cctype> // toupper
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Tela::Tela() { numOpcoes = combate = magiaAdquirida = itemAdquirido = 0; }
Tela::~Tela() {}

// Getters
int Tela::getNumOpcoes() { return numOpcoes; }
int Tela::getOpcoes(int i) { return opcoes[i]; }
Magia *Tela::getMagia() { return magia; }
Item *Tela::getItem() { return item; }
Monstro *Tela::getMonstro() { return monstro; }
int Tela::getCombate() { return combate; }
int Tela::getItemAdquirido() { return itemAdquirido; }
int Tela::getMagiaAdquirida() { return magiaAdquirida; }

// Setters
void Tela::setNumOpcoes(int numOpcoes) { this->numOpcoes = numOpcoes; }
void Tela::setOpcoes(int prox, int i) { opcoes[i] = prox; }
void Tela::setMagia(Magia *magia) { this->magia = magia; }
void Tela::setItem(Item *item) { this->item = item; }
void Tela::setMonstro(Monstro *monstro) { this->monstro = monstro; }
void Tela::setCombate(int combate) { this->combate = combate; }

void Tela::leituraArquivo(string &arquivo) {
  ifstream file(arquivo);
  if (!file.is_open()) {
    cerr << "Erro ao carregar:" << arquivo << endl;
    return;
  }

  string linha;
  int contaLinha = 0;
  int salvaLinha = 0;
  bool identificarItem = 0;
  bool identificarMonstro = 0;
  bool identificarMagia = 0;

  while (getline(file, linha)) {
    contaLinha++;

    if (linha[0] == '@') { // Opcoes int (decisao na historia)
      size_t pontoEVirgula = linha.find(';'); // separa escolha e proxima tela
      if (pontoEVirgula != string::npos) {
        //int escolha = stoi(linha.substr(1, pontoEVirgula - 1));
        opcoes[numOpcoes] = stoi(linha.substr(pontoEVirgula + 1));
        //cout << " Opcao " << escolha << " : " << opcoes[numOpcoes] << endl;
        numOpcoes++;
      }
    } else if (linha[0] == '#') { // Proxima tela
      opcoes[numOpcoes] = stoi(linha.substr(1));
      //cout << " Proxima tela: " << opcoes[numOpcoes] << endl;
    } else if (linha[0] == '%') { // Identifica evento
      switch (toupper(linha[1])) {

      case 'I': // Item
        identificarItem = 1;
        salvaLinha = contaLinha;
        item = new Item();
        break;

      case 'M': // Monstro
        identificarMonstro = 1;
        salvaLinha = contaLinha;
        monstro = new Monstro();
        monstro->setInventario(new Inventario());
        monstro->getInventario()->adicionarItem(new Item());
        break;

      case 'W': // Magia
        identificarMagia = 1;
        salvaLinha = contaLinha;
        magia = new Magia();
        break;
      }
    } else if (identificarItem) // Leitura do item
      leituraItem(&identificarItem, linha, (contaLinha - salvaLinha));

    else if (identificarMagia) // Leitura da magia
      leituraMagia(&identificarMagia, linha, (contaLinha - salvaLinha));

    else if (identificarMonstro) // Leitura do monstro
      leituraMonstro(&identificarMonstro, linha, (contaLinha - salvaLinha));

    else // Acumula o texto lido
      conteudo += linha + "\n";
  }
  file.close();
}

void Tela::leituraItem(bool *lerItem, string linha, u_int8_t contagem) {
  switch (contagem) {
  case 1:
    item->setNome(linha);
    break;
  case 2:
    item->setTipo(toupper(linha[0]));
    break;
  case 3:
    item->setCombate(stoi(linha));
    break;
  case 4:
    item->setFA(stoi(linha));
    break;
  case 5:
    item->setDano(stoi(linha));
    *lerItem = 0;
    itemAdquirido = 1;
    break;
  }
}

void Tela::leituraMagia(bool *lerMagia, string linha, u_int8_t contagem) {
  switch (contagem) {
  case 1:
    magia->setNome(linha);
    break;
  case 2:
    magia->setCura(stoi(linha));
    break;
  case 3:
    magia->setDano(stoi(linha));
    break;
  case 4:
    magia->setUsoDisponivel(stoi(linha));
    *lerMagia = 0;
    magiaAdquirida = 1;
    break;
  }
}

// Realiza a leitura das informacoes do monstro no arquivo .txt
void Tela::leituraMonstro(bool *lerMonstro, string linha, u_int8_t contagem) {
  switch (contagem) {
  case 1:
    monstro->setNome(linha);
    break;
  case 2:
    monstro->setProveItem(stoi(linha));
    break;
  case 3:
    monstro->setHabilidade(stoi(linha));
    break;
  case 4:
    monstro->setSorte(stoi(linha));
    break;
  case 5:
    monstro->setVida(stoi(linha));
    break;
  case 6:
    monstro->setTesouro(stoi(linha));
    break;
  case 7:
    monstro->setProvisoes(stoi(linha));
    break;
  case 8:
    monstro->setPaginaVitoria(stoi(linha));
    break;
  case 9:
    monstro->setPaginaDerrota(stoi(linha));
    if (!monstro->getProveItem()) // Verifica se o monstro possui item
      *lerMonstro = 0;
    
    combate = 1;
    break;
  case 10:
    monstro->getInventario()->getItem(0)->setNome(linha);
    break;
  case 11:
    monstro->getInventario()->getItem(0)->setTipo(toupper(linha[0]));
    break;
  case 12:
    monstro->getInventario()->getItem(0)->setCombate(stoi(linha));
    break;
  case 13:
    monstro->getInventario()->getItem(0)->setFA(stoi(linha));
    break;
  case 14:
    monstro->getInventario()->getItem(0)->setDano(stoi(linha));
    // Item completamente definido no monstro
    *lerMonstro = 0;
    break;
  }
}

void Tela::mostrar() {
  cout << "=====================================================" << endl;
  cout << conteudo << endl;
  cout << "=====================================================" << endl
       << endl;
}