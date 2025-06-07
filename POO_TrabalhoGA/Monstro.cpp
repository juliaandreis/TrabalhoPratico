#include "Monstro.h"
#include "Personagem.h"
#include <iostream>
#include <string>

using namespace std;

Monstro::Monstro() { 
  setNome("");
  setTesouro(100);
  setProvisoes(5);
  setNum_magias(0);
  setProtecao(0);
  setDano(2);
  setInventario(new Inventario);
}

Monstro::~Monstro() {}

Monstro::Monstro(string nome) : Personagem(nome) {
  setHabilidade(6);
  setVida(12);
  setSorte(6);
}

Monstro::Monstro(string nome, int hab, int sorte, int vida, int tesouro, int provisao, int paginaVitoria, int paginaDerrota) : Personagem(nome) {
  setHabilidade(hab);
  setVida(vida);
  setSorte(sorte);
  setTesouro(tesouro);
  setProvisoes(provisao);
  //cout << " Monstro criado com sucesso" << endl;
}

// Settesr
void Monstro::setPaginaVitoria(int paginaVitoria){ this->paginaVitoria = paginaVitoria; }
void Monstro::setPaginaDerrota(int paginaDerrota){ this->paginaDerrota = paginaDerrota; }
void Monstro::setProveItem(bool proveItem){ this->proveItem = proveItem; }

// Getters
int Monstro::getPaginaVitoria(){ return paginaVitoria; }
int Monstro::getPaginaDerrota(){ return paginaDerrota; }
bool Monstro::getProveItem(){ return proveItem; }