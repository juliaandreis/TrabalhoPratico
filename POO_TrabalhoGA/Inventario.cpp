#include "Inventario.h"
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

#define ITENS_INVENTARIO 6

//inicializa o inventario com espaco para 6 itens
Inventario::Inventario() {
  itens = new Item *[ITENS_INVENTARIO];
  for (int i = 0; i < ITENS_INVENTARIO; i++){
    itens[i] = nullptr;
  }
}

Inventario::~Inventario() {}

Item *Inventario::getItem(int i){
  return itens[i];
}

void Inventario::setItem(int i, Item *item){
  itens[i] = item;
}

void Inventario::adicionarItem(Item *item) {
  for (int i = 0; i < ITENS_INVENTARIO; i++) {
    if (itens[i] == nullptr){
      itens[i] = item;
      break;
    }
  }
}

void Inventario::removerItem(Item *item) {
  for (int i = 0; i < ITENS_INVENTARIO; i++) {
    if (itens[i] == item) {
      itens[i] = nullptr;
      break;
    }
  }
}

// retorna 1 se ja tem um item do mesmo tipo equipado, 0 se nao tem
bool Inventario::comparaTipoEquipados(Item *item) {
  for (int i = 0; i < ITENS_INVENTARIO; i++){
    if (itens[i] != nullptr && itens[i]->getTipo() == item->getTipo() && itens[i]->getEquipado()){
      return true;
    }
  }
  return false;
}

bool Inventario::equiparItem(Item *item) {
  if (!comparaTipoEquipados(item)){
    for (int i = 0; i < ITENS_INVENTARIO; i++){
      if (itens[i] == item){
        item->setEquipado(true);
        return true;
      }
    }
  }
  return false;
}

void Inventario::desequiparItem(Item *item) {item->setEquipado(false);}

void Inventario::usarItem(Item *item) {}

void Inventario::imprimeItens(){
  for (int i = 0; i < ITENS_INVENTARIO; i++)
    if (itens[i] != nullptr)
      itens[i]->imprimeItem();
}

void Inventario::imprimeInventario() {
  for (int i = 0; i < 30; ++i)
  cout << "\n";
  cout << "========================================" << endl;
  cout << "              Inventario" << endl << endl;
  for (int i = 0; i < ITENS_INVENTARIO; i++) {
    if (itens[i] != nullptr) {
      cout << i + 1 << " ";
      itens[i]->imprimeItem();
      cout << endl;
    }
  }
}