#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>

class Personagem{  
    private:
        string nome;
        int habilidade; // Representa a destreza em combate, mínimo igual a 6 e máximo igual a 12
        int energia; // Representa pontos de vida, mínimo igual a 12 e máximo igual a 24
        int sorte; // Pode ser testada e também pode mudar valores do dano, mínimo igual a 6 e máximo igual a 12
        bool mago; // Representa se o personagem é mago ou não.
        Magia** magias; // Magias que o personagem possui.
        Item** inventario; // Equipamentos que o personagem possui.
        Item** tesouro; // Tesouros que o personagem possui.
        Provisao** provisoes; // Só podem ser usadas fora de combate. Uma provisão recupera 4 pontos de vida.

    public:
        Personagem();
        ~Personagem();
        Personagem(string nome, int vida, int ataque, int defesa, int habilidade, int energia, int sorte, bool mago);
        void setNome(string nome);
        string getNome();
        void setVida(int vida);
        int getVida();
        void setAtaque(int ataque);
        int getAtaque();
        void setDefesa(int defesa);
        int getDefesa();
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
        void setTesouro(Item** tesouro);
        Item** getTesouro();
        void setProvisoes(Provisao** provisoes);
        Provisao** getProvisoes();
};

#endif // PERSONAGEM_CPP