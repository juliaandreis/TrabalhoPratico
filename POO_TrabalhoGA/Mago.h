#ifndef MAGO_H
#define MAGO_H

#include <string>
#include "Personagem.h"
#include "Magia.h"
#include "Item.h"

class Mago: public Personagem{  
    public:
        Mago();
        ~Mago();
        Mago(string nome, Magia** magias);
};

#endif // MAGO_H