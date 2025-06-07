#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.h"

class Inventario {
public:
  Inventario();
  ~Inventario();

  void adicionarItem(Item *item);
  void removerItem(Item *item);
  bool equiparItem(Item *item);
  void desequiparItem(Item *item);
  void usarItem(Item *item); //falta implementar
  bool comparaTipoEquipados(Item *item);
  void imprimeInventario();
  void imprimeItens();
  Item *getItem(int i);
  void setItem(int i, Item *item);
  
private:
  Item **itens;
};

#endif // INVENTARIO_H