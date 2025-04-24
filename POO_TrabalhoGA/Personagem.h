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
        bool mago; // Representa se o personagem é mago ou não.
        Magia** magias; // Magias que o personagem possui.
        Item** inventario; // Equipamentos que o personagem possui.
        int num_magias;
        int num_inventario;
        int tesouro;
        int provisoes;
    
    public:
        Personagem();
        ~Personagem();
        Personagem(string nome, int habilidade, int energia, int sorte, bool mago);

    //Métodos
        bool testarSorte();
        void imprime_info();
        void imprime_inventario();

    //Getters e Setters
        void setNome(string nome);
        string getNome();
        void setHabilidade(int habilidade);
        int getHabilidade();
        void setEnergia(int energia);
        int getEnergia();
        void setSorte(int sorte);
        int getSorte();
        void setMago(bool mago);
        bool getMago();
        void setMagias(Magia** magias);
        Magia** getMagias();
        void setInventario(Item** inventario);
        Item** getInventario();
};

#endif // PERSONAGEM_CPP
