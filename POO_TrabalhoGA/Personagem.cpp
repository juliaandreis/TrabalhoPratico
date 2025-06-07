#include "Personagem.h"
#include "Magia.h"
#include "Inventario.h"
#include "Item.h"
#include <cctype>  // tolower()
#include <cstdlib> // rand() e srand()
#include <ctime>   // time()
#include <iostream>
#include <fstream>

using namespace std;

Personagem::Personagem() {}

Personagem::~Personagem() {}

Personagem::Personagem(string nome) {
  this->nome = nome;
  tesouro = 100;
  provisoes = 5;
  num_magias = 0;
  protecao = 0;
  dano = 0;
  inventario = new Inventario();
  magias = new Magia *[3];
  for (int i = 0; i < 3; i++) {
    magias[i] = nullptr;
  }
}

// Getters e Setters

void Personagem::setNome(string nome) { this->nome = nome; }

string Personagem::getNome() { return nome; }

void Personagem::setHabilidade(int habilidade) {
  this->habilidade = habilidade;
}

int Personagem::getHabilidade() { return habilidade; }

void Personagem::setVida(int vida) { this->vida = vida; }

int Personagem::getVida() { return vida; }

void Personagem::setSorte(int sorte) { this->sorte = sorte; }

int Personagem::getSorte() { return sorte; }

void Personagem::setInventario(Inventario *inventario) {
  this->inventario = inventario;
}

Inventario *Personagem::getInventario() { return inventario; }

void Personagem::setMagia(Magia *magia) {
  magias[num_magias] = magia;
  num_magias++;
}

Magia *Personagem::getMagias(int i) { return magias[i]; }

void Personagem::setNum_magias(int num_magias) {
  this->num_magias = num_magias;
}

int Personagem::getNum_magias() { return num_magias; }

void Personagem::setTesouro(int tesouro) { this->tesouro = tesouro; }

int Personagem::getTesouro() { return tesouro; }

void Personagem::setProvisoes(int provisoes) { this->provisoes = provisoes; }

int Personagem::getProvisoes() { return provisoes; }

void Personagem::setProtecao(int protecao) { this->protecao = protecao; }

int Personagem::getProtecao() { return protecao; }

void Personagem::setDano(int dano) { this->dano = dano; }

int Personagem::getDano() { return dano; }

// Métodos

void Personagem::escolheValorAtributos(int hab, int vida, int sor) {
  if (hab + vida + sor == 12) {
    if (habilidade + hab < 12) {
      habilidade += hab;
    }
    else {
      habilidade = 12;
    }
    if (this->vida + vida < 24) {
      this->vida += vida;
    }
    else {
      vida = 24;
    }
    if (sorte + sor < 12) {
      sorte += sor;
    }
    else {
      sorte = 12;
    }
  }
}

void Personagem::aleatorioValorAtributos() {
  int hab, vid, sor;
  do{
    hab = rand() % (12 - habilidade + 1);
    vid = rand() % (24 - vida - hab + 1);
    sor = 12 - hab - vid;
 
    if ((hab + vid + sor) == 12) {
      cout << hab << " " << vid << " " << sor << endl;
      escolheValorAtributos(hab, vid, sor);
    }
  } while (!((hab + vid + sor) == 12));
}

// Equipa item

void Personagem::equiparItem(Item *item) {
  if (inventario->equiparItem(item)){
    if (item->getTipo() == 'w'){
      habilidade += item->getFA();
      dano += item->getDano();
    }
    else if (item->getTipo() == 'r'){
      protecao += item->getFA();
      dano += item->getDano();
    }
  }
}

// Desequipa item

void Personagem::desequiparItem(Item *item) {
  if (item->getEquipado()){// aqui nao sei se faz sentido do jeito que ta, pq eu usei item e inventario. 
    inventario->desequiparItem(item); // tipo se to usando item, aqui podia ser so item->setEquipado(false);
    if (item->getTipo() == 'w'){
      habilidade -= item->getFA();
    }
    else if (item->getTipo() == 'r'){
      protecao -= item->getFA();
    }
  }
}

// Adiciona item no inventário

void Personagem::adicionarItem(Item *item) {
  inventario->adicionarItem(item);
}

// Remove item do inventário

void Personagem::removerItem(Item *item) {
  inventario->removerItem(item);
}

void Personagem::cura(int n) {
  if (vida + n < 24) {
    vida += n;
  } else {
    vida = 24;
  }
}

// terminar de implementar para ser void, acho que faz mais sentido
void Personagem::usarMagia(Magia *magia) {
  if (magia->getUsoDisponivel() > 0){
    if (magia->getCura() != 0) {
      magia->setUsoDisponivel(-1);
      cura(magia->getCura());
    } 
    else if (magia->getDano() != 0) {
      magia->setUsoDisponivel(-1);
      setDano(magia->getDano());
    }
  }
}

void Personagem::usarProvisao() {
  if (provisoes > 0) {
    cura(4);
    provisoes--;
  }
}

// sucesso se teste > 6
bool Personagem::testarSorte() {
  if (sorte <= 0) {
    cout << "SORTE = 0" << endl;
    return false;
  }

  int teste = rand() % 10 + 1;

  cout << "Teste de sorte: " << teste << endl;

  bool sucesso = teste > 6;
  sorte--;

  if (sucesso) {
    cout << "Você conseguiu!" << endl;
  } else {
    cout << "Você falhou no teste de sorte." << endl;
  }

  return sucesso;
}

// Nome;Cura;Dano;UsoDisponivel
void Personagem::imprime_magias() {
  for (int i = 0; i < 30; ++i)
  cout << "\n";
  cout << "========================================" << endl;
  cout << "              Magias" << endl << endl;
  for (int i = 0; i < num_magias; i++) {
    if (magias[i] != nullptr) {
      cout << i + 1 << " ";
      magias[i]->imprimeMagia();
      cout << endl;
    }
  }
  cout << endl << "========================================" << endl;
  cout << " 1) Usar Magia          2) Voltar" << endl;
}

// nome;tipo;combate;FA;dano
void Personagem::imprime_inventario() {
  inventario->imprimeInventario();
  cout << "Provisões " << provisoes << endl;
  cout << endl << "========================================" << endl;
  cout << " 1) Equipar item      2) Desequipar item" << endl;
  cout << " 3) Excluir Item      4) Usar Provisão" << endl;
  cout << " 5) Voltar" << endl;
}

void Personagem::imprime_info() {
  cout << "N: " << nome << endl;
  cout << "H: " << habilidade << endl;
  cout << "V: " << vida << endl;
  cout << "S: " << sorte << endl;

  if (tesouro != 0) {
    cout << "T: " << tesouro << endl;
  }
  if (provisoes != 0) {
    cout << "P: " << provisoes << endl;
  }
}