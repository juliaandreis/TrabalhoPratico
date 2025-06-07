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
        Mago(string nome, Magia *magia1, Magia *magia2, Magia *magia3);
};

#endif // MAGO_H
