#include "Ladino.h"
#include "Magia.h"
#include "Personagem.h"
#include <iostream>
#include <string>

using namespace std;

Ladino::Ladino() {}

Ladino::~Ladino() {}

Ladino::Ladino(string nome) : Personagem(nome) {
  setHabilidade(9);
  setVida(12);
  setSorte(6);
  setDano(1);
}