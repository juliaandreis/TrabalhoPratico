#include <iostream>
#include <string>
#include "Magia.h"

using namespace std;

Magia::Magia(){
    nome = "";
    cura = dano = usoDisponivel = 0;
}

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

void Magia::setUsoDisponivel(int usoDisponivel){this->usoDisponivel = usoDisponivel;}

int Magia::getUsoDisponivel(){return usoDisponivel;}

void Magia::imprimeMagia(){
    cout << nome << "; " << cura << "; " << dano << "; " << usoDisponivel << endl;
}