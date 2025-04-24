#ifndef MAGO_H
#define MAGO_H

#include <string>
#include "Personagem.h"
#include "Magia.h"
#include "Item.h"

class Mago: public Personagem{  
    private:
        Magia** magias; // Magias que o personagem possui.
        int num_magias;

    public:
        Mago();
        ~Mago();
        Mago(string nome, int habilidade, int energia, int sorte, Magia** magias);
        void imprime_info();
        void imprime_magias();

    //Getters e Setters
        void setMagia(Magia* magia);
        Magia** getMagias();
        int getNum_magias();
        void setNum_magias(int num_magias);
};

#endif // MAGO_H