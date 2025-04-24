#include <iostream>
#include <string>
#include "Personagem.h"
#include "Magia.h"
#include "Mago.h"

using namespace std;

Mago::Mago(){}

Mago::~Mago(){}

Mago::Mago(string nome, int habilidade, int energia, int sorte, Magia** magias):Personagem(nome, habilidade, energia, sorte){
    magias = new Magia *[5];
    for (int i = 0; i < 5; i++) {
        magias[i] = nullptr;
    }
    num_magias = 0;
}

//Getters e Setters
void Mago::setMagia(Magia* magia){
    if (num_magias < 5) {
        magias[num_magias] = magia;
        num_magias++;
    }
}

Magia** Mago::getMagias(){return magias;}

int Mago::getNum_magias(){return num_magias;}

void Mago::setNum_magias(int num_magias){this->num_magias = num_magias;}

//Métodos
void Mago::imprime_magias(){
    cout << "MAGIAS:" << endl;
    for (int i = 0; i < 5; i++){
        if (magias[i] != nullptr){
            cout << "Nome do magia: " << magias[i]->getNome() << endl;
            cout << "Dano: " << magias[i]->getDano() << endl << endl;
            if (magias[i]->getItem_magico()){
                cout << "Item mágico" << endl << endl;
            }
        }
    }
}
void Mago::imprime_info(){
    imprime();
    imprime_magias();
}