
#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

typedef struct {
    string nome; // Nome do item
    char tipo; // C - Item comum | R - Armadura | W - Arma
    bool combate; // 1 para combate, 0 para não-combate
    int FA; // Bônus de Força de Ataque
    int dano; // Bônus de Dano
} Item;

#endif // ITEM_H