#include <iostream>
#include <string>
#include "Personagem.h"
#include "Monstro.h"

using namespace std;

Monstro::Monstro(){}

Monstro::~Monstro(){}

Monstro::Monstro(string nome):Personagem(nome){
    setHabilidade(6);
    setEnergia(12);
    setSorte(6); 
}