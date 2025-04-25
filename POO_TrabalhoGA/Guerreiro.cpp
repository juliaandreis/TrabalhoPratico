#include <iostream>
#include <string>
#include "Personagem.h"
#include "Magia.h"
#include "Guerreiro.h"

using namespace std;

Guerreiro::Guerreiro(){}

Guerreiro::~Guerreiro(){}

Guerreiro::Guerreiro(string nome):Personagem(nome){
    setHabilidade(6);
    setEnergia(18);
    setSorte(6);
}