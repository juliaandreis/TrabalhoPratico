#include <iostream>
#include <string>
#include "Personagem.h"
#include "Magia.h"
#include "Ladino.h"

using namespace std;

Ladino::Ladino(){}

Ladino::~Ladino(){}

Ladino::Ladino(string nome):Personagem(nome){
    setHabilidade(9);
    setEnergia(12);
    setSorte(6);
}