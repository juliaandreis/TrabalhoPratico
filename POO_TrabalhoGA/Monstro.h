#ifndef MONSTRO_H
#define MONSTRO_H

#include <string>
#include "Personagem.h"

using namespace std;

class Monstro: public Personagem{
    public:
        Monstro();
        ~Monstro();
        Monstro(string nome);
        Monstro(string nome, int hab, int sorte, int vida, int tesouro, int provisao, int paginaVitoria, int paginaDerrota);

        void setPaginaVitoria(int paginaVitoria);
        void setPaginaDerrota(int paginaDerrota);
        void setProveItem(bool proveItem);
        
        int getPaginaVitoria();
        int getPaginaDerrota();
        bool getProveItem();

    private:
        int paginaVitoria;
        int paginaDerrota;
        bool proveItem;
};

#endif // MONSTRO_H