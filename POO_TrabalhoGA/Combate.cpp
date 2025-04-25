#include <iostream>
#include <string>
#include "Combate.h"
#include "Personagem.h"
#include "Magia.h"
#include "Item.h"
#include "Mago.h"
#include "Monstro.h"
#include "Guerreiro.h"
#include "Ladino.h"
#include <cstdlib> // rand() e srand()
#include <ctime>   // time()

using namespace std;

Combate::Combate(){}

Combate::~Combate(){}

Combate::Combate(Personagem* personagem, Personagem* monstro){
    this->personagem = personagem;
    this->monstro = monstro;
}

void Combate::setPersonagem(Personagem* personagem){this->personagem = personagem;}

Personagem* Combate::getPersonagem(){return personagem;}

void Combate::setMonstro(Personagem* monstro){this->monstro = monstro;}

Personagem* Combate::getMonstro(){return monstro;}

void Combate::acaoCombate() {
    srand(time(0));
    int fa_personagem = (rand() % 10 + 1) + personagem->getHabilidade();
    int fa_monstro = (rand() % 10 + 1) + monstro->getHabilidade();

    cout << personagem->getNome() << " FA: " << fa_personagem << endl;
    cout << monstro->getNome() << " FA: " << fa_monstro << endl;

    if (fa_personagem > fa_monstro) {
        cout << personagem->getNome() << " venceu" << endl;
        monstro->setEnergia(monstro->getEnergia() - 2);
    } else if (fa_monstro > fa_personagem) {
        cout << monstro->getNome() << " venceu" << endl;
        personagem->setEnergia(personagem->getEnergia() - 2);
    } else {
        cout << "Empate" << endl;;
    }
}
