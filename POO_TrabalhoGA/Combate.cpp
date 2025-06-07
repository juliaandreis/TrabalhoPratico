#include "Combate.h"
#include "Guerreiro.h"
#include "Inventario.h"
#include "Item.h"
#include "Ladino.h"
#include "Magia.h"
#include "Mago.h"
#include "Monstro.h"
#include "Personagem.h"
#include <cstdlib> // rand() e srand()
#include <ctime>   // time()
#include <iostream>
#include <string>

using namespace std;

Combate::Combate() {}

Combate::~Combate() {}

Combate::Combate(Personagem *personagem, Monstro *monstro) {
  this->personagem = personagem;
  this->monstro = monstro;
  turno = 0;
}

// Getters e Setters
void Combate::setPersonagem(Personagem *personagem) {
  this->personagem = personagem;
}

Personagem *Combate::getPersonagem() { return personagem; }

void Combate::setMonstro(Monstro *monstro) { this->monstro = monstro; }

Monstro *Combate::getMonstro() { return monstro; }

void Combate::setTurno(int turno){this->turno = turno;}

int Combate::getTurno(){return turno;}

// Métodos
void Combate::turnos() {
  int fa_personagem;
  int fa_monstro;

  // Define a forca de ataque de cada um
  fa_personagem = (rand() % 10 + 1) + personagem->getHabilidade();
  fa_monstro = (rand() % 10 + 1) + monstro->getHabilidade();

  if (turno == 0 && fa_personagem >= fa_monstro) { // turno do personagem e ele pode atacar
    int dano = 2 - (monstro->getProtecao());
    if(personagem->getDano() > 0){dano += personagem->getDano();}
    monstro->setVida(monstro->getVida() - dano);
  } 
  else if (turno == 0 && fa_personagem < fa_monstro) { // turno do personagem e ele nao pode atacar
    cout << "Jogador errou o ataque" << endl;
  }  
  else if (turno == 1 && fa_personagem <= fa_monstro) { // turno do monstro e ele pode atacar
    int dano = 2 - (personagem->getProtecao());
    if(personagem->getDano() < 0){dano += personagem->getDano();}
    personagem->setVida(personagem->getVida() - dano);
  } 
  else if (turno == 1 && fa_personagem > fa_monstro) { // turno do monstro e ele nao pode atacar
    cout << "Monstro errou o ataque" << endl;
  }
}

void Combate::trocaTurno(){
  if (turno == 0)
    turno = 1;
  else
    turno = 0;
}

void Combate::acaoCombate() {
  turno = 0; // 0 - turno do personagem, 1 - turno do monstro

  //personagem->imprime_info();
  //cout << endl;
  /*cout << " Monstro:" << endl;
  cout << monstro->getNome() << endl;
  cout << monstro->getProveItem() << endl;
  cout << monstro->getDano() << endl;
  cout << monstro->getVida() << endl;
  cout << monstro->getHabilidade() << endl;
  cout << monstro->getSorte() << endl;
  cout << monstro->getTesouro() << endl;
  cout << monstro->getProvisoes() << endl;
  cout << monstro->getPaginaVitoria() << endl;
  cout << monstro->getPaginaDerrota() << endl;*/
  //monstro->imprime_info();
  //cout << endl;
  
  cout << " Vida jogador (J): " << personagem->getVida() << endl;
  for (int i = 0; i < personagem->getVida(); ++i) {
    cout << "⫾";
  }
  cout << endl;
  cout << " Vida monstro (M): " << monstro->getVida() << endl;
  for (int i = 0; i < monstro->getVida(); ++i) {
    cout << "⫾";
  }
  cout << endl;
  do {
    cout << endl;
    getchar();
    turnos();
    cout << " Jogador: ";
    for (int i = 0; i < personagem->getVida(); ++i) {
      cout << "⫾";
    }
    cout << endl;
    cout << " Monstro: ";
    for (int i = 0; i < monstro->getVida(); ++i) {
      cout << "⫾";
    }
    if (personagem->getVida() > 0 && monstro->getVida() > 0){
      cout << endl << " Enter para continuar" << endl;
    }
    
    trocaTurno();
  } while (personagem->getVida() > 0 && monstro->getVida() > 0);

  cout << endl << " Fim do Combate" << endl << endl;
}

bool Combate::fugir(){
  return personagem->testarSorte();
}