
#include "Mago.h"
#include "Magia.h"
#include "Personagem.h"
#include <iostream>
#include <string>

using namespace std;

Mago::Mago() {}

Mago::~Mago() {}

Mago::Mago(string nome, Magia *magia1, Magia *magia2, Magia *magia3) : Personagem(nome) {
  setHabilidade(6);
  setVida(12);
  setSorte(6);
  setDano(1);
  setMagia(magia1);
  setMagia(magia2);
  setMagia(magia3);
}