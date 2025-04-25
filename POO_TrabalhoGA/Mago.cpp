#include <iostream>
#include <string>
#include "Personagem.h"
#include "Magia.h"
#include "Mago.h"

using namespace std;

Mago::Mago(){}

Mago::~Mago(){}

Mago::Mago(string nome, Magia** magias):Personagem(nome){
    magias = new Magia *[5];
    for (int i = 0; i < 5; i++) {
        magias[i] = nullptr;
    }
    setHabilidade(6);
    setEnergia(12);
    setSorte(6);
    setNum_magias(0);
}