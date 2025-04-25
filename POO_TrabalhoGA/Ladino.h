#ifndef LADINO_H
#define LADINO_H

#include <string>
#include "Personagem.h"

using namespace std;

class Ladino: public Personagem{  
    public:
        Ladino();
        ~Ladino();
        Ladino(string nome);
};

#endif // LADINO_H