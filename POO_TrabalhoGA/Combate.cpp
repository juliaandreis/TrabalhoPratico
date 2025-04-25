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

void Combate::acaoCombate(){
    int fa_personagem;
    int fa_monstro;
    
    fa_personagem = (rand() % 10 + 1) + personagem->getHabilidade();
    fa_monstro = (rand() % 10 + 1) + monstro->getHabilidade();

    Item** items = personagem->getInventario();
    for (int i = 0; i < personagem->getNum_inventario(); i++){
        if (items[i] != nullptr && items[i]->combate == 1 && tolower(items[i]->tipo) == 'w'){ // verifica se o item pode ser usado em combate e se é arma
            if (items[i]->FA != 0){ // verifica se o item tem bonus de forca de ataque
                fa_personagem += items[i]->FA;
            }
        }
    }
        
    cout << personagem->getNome() << " FA: " << fa_personagem << endl;
    cout << monstro->getNome() << " FA: " << fa_monstro << endl;

    if (fa_personagem > fa_monstro) {
        cout << personagem->getNome() << " venceu turno" << endl;
        int dano = personagem->ataque();
        monstro->defesa(dano);
        cout << "Dano causado: " << dano << endl;
    } 
    else if (fa_monstro > fa_personagem) {
        cout << monstro->getNome() << " venceu turno" << endl;
        int dano = monstro->ataque();
        personagem->defesa(dano);
        cout << "Dano causado: " << dano << endl;
    } else {
        cout << "Empate" << endl;
    }
}

void Combate::turno(){
    //int t = 1;
    cout << personagem->getNome() << " Energia: " << personagem->getEnergia() << endl;
    cout << monstro->getNome() << " Energia: " << monstro->getEnergia() << endl;
    do {
        acaoCombate();
        //t++;
    } while(personagem->getEnergia() > 0 && monstro->getEnergia() > 0);

    cout << "Fim do Combate" << endl;
    cout << personagem->getNome() << " Energia final: " << personagem->getEnergia() << endl;
    cout << monstro->getNome() << " Energia final: " << monstro->getEnergia() << endl;
}
