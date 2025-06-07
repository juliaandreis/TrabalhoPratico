#ifndef COMBATE_H
#define COMBATE_H

#include <string>
#include "Personagem.h"
#include "Monstro.h"

using namespace std;

class Combate{
    private:
        Personagem* personagem;
        Monstro* monstro;
        int turno; // 0 - turno do personagem, 1 - turno do monstro
        
    public:
        Combate();
        ~Combate();
        Combate(Personagem* personagem, Monstro* monstro);
        void setPersonagem(Personagem* personagem);
        Personagem* getPersonagem();
        void setMonstro(Monstro* monstro);
        Monstro* getMonstro();
        void setTurno(int turno);
        int getTurno();

        void trocaTurno();
        void turnos();
        void acaoCombate();
        bool fugir();
};

#endif // COMBATE_H
