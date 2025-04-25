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
};

#endif // MONSTRO_H