#ifndef COMBATE_H
#define COMBATE_H

#include <string>
#include "Personagem.h"

using namespace std;

class Combate{
    private:
        Personagem* personagem;

    public:
        Combate();
        ~Combate();

};

#endif // COMBATE_H