#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include "Magia.h"
#include "Item.h"

class Personagem{  
    private:
        string nome;
        int habilidade; // Representa a destreza em combate, mínimo igual a 6 e máximo igual a 12
        int energia; // Representa pontos de vida, mínimo igual a 12 e máximo igual a 24
        int sorte; // Pode ser testada e também pode mudar valores do dano, mínimo igual a 6 e máximo igual a 12
        Magia** magias; // Magias que o personagem possui.
        Item** inventario; // Equipamentos que o personagem possui.
        int num_magias;
        int num_inventario;
        int tesouro;
        int provisoes;
    
    public:
        Personagem();
        ~Personagem();
        Personagem(string nome);

        //Getters e Setters
        void setNome(string nome);
        string getNome();
        void setHabilidade(int habilidade);
        int getHabilidade();
        void setEnergia(int energia);
        int getEnergia();
        void setSorte(int sorte);
        int getSorte();
        void setMagia(Magia* magia);
        Magia** getMagias();
        void setNum_magias(int num_magias);
        int getNum_magias();
        void setTesouro(int tesouro);
        int getTesouro();
        void setProvisoes(int provisoes);
        int getProvisoes();
        void setNum_inventario(int num_inventario);
        int getNum_inventario();
        void setInventario(Item* item);
        Item** getInventario();

        //Métodos
        int ataque();
        void cura(int n);
        void defesa(int n);
        int usarMagia(Magia* magia);
        void escolheValorAtributos(int hab, int ene, int sor);
        bool testarSorte();
        void imprime_magias();
        void imprime_inventario();
        void imprime_info();
};

#endif // PERSONAGEM_H
