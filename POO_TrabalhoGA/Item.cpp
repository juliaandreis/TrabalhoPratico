#include "Item.h"
#include <iostream>

using namespace std;

Item::Item() {
  nome = "";
  tipo = '\0';
  combate = FA = dano = equipado = 0;
}

Item::~Item() {}

Item::Item(string nome){
  this->nome = nome;
  tipo = '\0';
  combate = FA = dano = equipado = 0;
}

Item::Item(string nome, char tipo, bool combate, int FA, int dano) {
  this->nome = nome;
  this->tipo = tipo;
  this->combate = combate;
  this->FA = FA;
  this->dano = dano;
  equipado = false;
}

string Item::getNome() { return nome; }

char Item::getTipo() { return tipo; }

bool Item::getCombate() { return combate; }

int Item::getFA() { return FA; }

int Item::getDano() { return dano; }

bool Item::getEquipado() { return equipado; }

void Item::setNome(string nome) { this->nome = nome; }

void Item::setTipo(char tipo) { this->tipo = tipo; }

void Item::setCombate(bool combate) { this->combate = combate; }

void Item::setFA(int FA) { this->FA = FA; }

void Item::setDano(int dano) { this->dano = dano; }

void Item::setEquipado(bool equipado) { this->equipado = equipado; }

void Item::imprimeItem() {
  if (equipado == true) {
    cout << "*";
  }
  cout << nome << "; " << tipo << "; " << combate << "; " << FA << "; " << dano
       << endl;
}