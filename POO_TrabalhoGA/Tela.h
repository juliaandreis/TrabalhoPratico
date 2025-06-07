#ifndef TELA_H
#define TELA_H

#include <string>
#include "Item.h"
#include "Magia.h"
#include "Monstro.h"

using namespace std;

class Tela {
  public:
    Tela();
    ~Tela();

    // Printa tela
    void mostrar();

    // Getters
    int getNumOpcoes();
    int getOpcoes(int i);
    Magia *getMagia();
    Item *getItem();
    Monstro *getMonstro();
    int getCombate();
    int getItemAdquirido();
    int getMagiaAdquirida();

    // Setters
    void setNumOpcoes(int prox);
    void setOpcoes(int prox, int i);
    void setMagia(Magia *magia);
    void setItem(Item *item);
    void setMonstro(Monstro *monstro);
    void setCombate(int combate);

    // Leitura
    void leituraArquivo(string &arquivo);
    void leituraMonstro(bool *lerMonstro, string linha, u_int8_t contagem );
    void leituraItem(bool *lerItem, string linha, u_int8_t contagem );
    void leituraMagia(bool *lerMagia, string linha, u_int8_t contagem );

  private:
    string conteudo; // Texto
    int opcoes[5]; // Opções de escolha
    int numOpcoes; // Número de opções
    int combate; // Se a tela inicia combate
    int itemAdquirido;
    int magiaAdquirida;
    Item *item;
    Magia *magia;
    Monstro *monstro;
};

#endif // TELA_H