#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Inventario.h"
#include "Item.h"
#include "Magia.h"
#include <string>

class Personagem {
private:
  string nome;
  int habilidade; // Representa a destreza em combate
  int vida;       // Representa pontos de vida
  int sorte;
  Magia **magias;         // Magias que o personagem possui.
  Inventario *inventario; // Equipamentos que o personagem possui.
  int num_magias;
  int tesouro;
  int provisoes;
  int protecao; // Quanto de dano é subtraido quando o personagem é atacado
  int dano; // dano que o personagem causa (para não ficar usando for toda vez)

public:
  Personagem();
  ~Personagem();
  Personagem(string nome);

  // Setters
  void setNome(string nome);
  void setHabilidade(int habilidade);
  void setVida(int vida);
  void setSorte(int sorte);
  void setMagia(Magia *magia);
  void setNum_magias(int num_magias);
  void setTesouro(int tesouro);
  void setProvisoes(int provisoes);
  void setInventario(Inventario *inventario);
  void setProtecao(int protecao);
  void setDano(int dano);

  // Getters
  string getNome();
  int getHabilidade();
  int getVida();
  int getSorte();
  Magia *getMagias(int i);
  int getNum_magias();
  int getTesouro();
  int getProvisoes();
  Inventario *getInventario();
  int getProtecao();
  int getDano();

  // Métodos
  void escolheValorAtributos(int hab, int ene, int sor);
  void aleatorioValorAtributos();
  void equiparItem(Item *item); // equipar item
  void desequiparItem(Item *item); // desequipar item
  void adicionarItem(Item *item); // adiciona ao inventario
  void removerItem(Item *item); // remove do inventario
  int ataque();                    
  void defesa(int n);              
  void cura(int n);
  void usarMagia(Magia *magia);
  void usarProvisao();
  bool testarSorte();
  void imprime_magias();
  void imprime_inventario();
  void imprime_info();
};

#endif // PERSONAGEM_H