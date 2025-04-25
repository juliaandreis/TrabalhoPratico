#ifndef GUERREIRO_H
#define GUERREIRO_H

#include <string>
#include "Personagem.h"

using namespace std;

class Guerreiro: public Personagem{  
    public:
        Guerreiro();
        ~Guerreiro();
        Guerreiro(string nome);
};

#endif // GUERREIRO_H