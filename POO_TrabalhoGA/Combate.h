#ifndef COMBATE_H
#define COMBATE_H

#include <string>
#include "Personagem.h"

using namespace std;

class Combate{
    private:
        Personagem* personagem;
        Personagem* monstro;
        
    public:
        Combate();
        ~Combate();
        Combate(Personagem* personagem, Personagem* monstro);
        void setPersonagem(Personagem* personagem);
        Personagem* getPersonagem();
        void setMonstro(Personagem* monstro);
        Personagem* getMonstro();
        void acaoCombate();
};

#endif // COMBATE_H