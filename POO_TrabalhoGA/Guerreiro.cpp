#include <iostream>
#include <string>
#include "Personagem.h"
#include "Magia.h"
#include "Guerreiro.h"
#include <iostream>

using namespace std;

Guerreiro::Guerreiro(){}

Guerreiro::~Guerreiro(){}

Guerreiro::Guerreiro(string nome):Personagem(nome){
    setHabilidade(6);
    setVida(18);
    setSorte(6);
    setDano(1);
}