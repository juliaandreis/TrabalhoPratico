#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item {
private:
  string nome;   // Nome do item
  char tipo;     // C - Item comum | A - Armadura | W - Arma
  bool combate;  // 1 para combate, 0 para não-combate
  int FA;        // Bônus de Força de Ataque
  int dano;      // Dano
  bool equipado; // 1 para equipado, 0 para não-equipado

public:
  Item();
  ~Item();
  Item(string nome);
  Item(string nome, char tipo, bool combate, int FA, int dano);
  string getNome();
  char getTipo();
  bool getCombate();
  int getFA();
  int getDano();
  bool getEquipado();
  void setNome(string nome);
  void setTipo(char tipo);
  void setCombate(bool combate);
  void setFA(int FA);
  void setDano(int dano);
  void setEquipado(bool equipado);

  void imprimeItem();
  void usarItem(); // para usar um item magico
};

#endif // ITEM_H