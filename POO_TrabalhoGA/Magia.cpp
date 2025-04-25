#include <iostream>
#include <string>
#include "Magia.h"

using namespace std;

Magia::Magia(){}

Magia::~Magia(){}

Magia::Magia(string nome, int cura, int dano, int usoDisponivel){
    this->nome = nome;
    this->cura = cura;
    this->dano = dano;
    this->usoDisponivel = usoDisponivel;
}

void Magia::setNome(string nome){this->nome = nome;}

string Magia::getNome(){return nome;}

void Magia::setCura(int cura){this->cura = cura;}

int Magia::getCura(){return cura;}

void Magia::setDano(int dano){this->dano = dano;}

int Magia::getDano(){return dano;}

void Magia::setItem_magico(bool item_magico){this->item_magico = item_magico;}

bool Magia::getItem_magico(){return item_magico;}
