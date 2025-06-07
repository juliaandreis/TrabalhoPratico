#ifndef APP_H
#define APP_H

#define TOTAL_CENAS 25

#include "Personagem.h"
#include "Monstro.h"
#include "Tela.h"

class App {
private:
  int telaAtual;
  Tela **telas;
  Personagem *player;
  Monstro *monstro;

public:
  App();
  ~App(){};

  void setPlayer(Personagem *player);
  void setMonstro(Monstro *monstro);

  void menu();
  void criarPersonagem(int opcao);
  void salvar(string arquivo);
  void carregar(string arquivo);
  void abrirInventario();
  void combate();
};

#endif // APP_H