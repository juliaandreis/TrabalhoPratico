#include <iostream>
#include <string>
#include <cstdlib> // rand() e srand()
#include <ctime>   // time()
#include <cctype> // tolower()
#include "Personagem.h"
#include "Magia.h"
#include "Item.h"

using namespace std;

Personagem::Personagem(){}

Personagem::~Personagem(){}

Personagem::Personagem(string nome){
    this->nome = nome;
    tesouro = 20;
    provisoes = 5;
    inventario = new Item *[5];
    for (int i = 0; i < 5; i++) {
        inventario[i] = nullptr;
    }
    num_inventario = 0;
    magias = new Magia *[2];
    for (int i = 0; i < 2; i++) {
        magias[i] = nullptr;
    }
    num_magias = 0;
}

//Getters e Setters
void Personagem::setNome(string nome){this->nome = nome;}

string Personagem::getNome(){return nome;}

void Personagem::setHabilidade(int habilidade){this->habilidade = habilidade;}

int Personagem::getHabilidade(){return habilidade;}

void Personagem::setEnergia(int energia){this->energia = energia;}

int Personagem::getEnergia(){return energia;}

void Personagem::setSorte(int sorte){this->sorte = sorte;}

int Personagem::getSorte(){return sorte;}

void Personagem::setInventario(Item* item){
    if (num_inventario < 10) {
        inventario[num_inventario] = item;
        num_inventario++;
    }
    num_inventario++;
}

Item** Personagem::getInventario(){return inventario;}

void Personagem::setMagia(Magia* magia1, Magia* magia2){
    magias[0] = magia1;
    magias[1] = magia2;
    num_magias = 2;
}

Magia** Personagem::getMagias(){return magias;}

void Personagem::setNum_magias(int num_magias){this->num_magias = num_magias;}

int Personagem::getNum_magias(){return num_magias;}

void Personagem::setTesouro(int tesouro){this->tesouro = tesouro;}

int Personagem::getTesouro(){return tesouro;}

void Personagem::setProvisoes(int provisoes){this->provisoes = provisoes;}

int Personagem::getProvisoes(){return provisoes;}

void Personagem::setNum_inventario(int num_inventario){this->num_inventario = num_inventario;}

int Personagem::getNum_inventario(){return num_inventario;}

//Métodos
int Personagem::ataque(){
    int ataqueTotal = 2;
    for (int i = 0; i < num_inventario; i++){
        if (inventario[i]->combate == 1 && tolower(inventario[i]->tipo) == 'w'){ // verifica se o item pode ser usado em combate e se é arma
            if (inventario[i]->dano != 0){ // verifica se o item tem bonus de dano
                ataqueTotal += inventario[i]->dano;
            }
        }
    }
    return ataqueTotal;
}

void Personagem::cura(int n){
    if (energia + n < 24){
        energia += n;
    }
}

void Personagem::defesa(int n){
    for (int i = 0; i < num_inventario; i++){
        if (inventario[i]->combate == 1 && tolower(inventario[i]->tipo) == 'r'){// verifica se o item pode ser usado em combate e se é armadura
            energia = energia - n + inventario[i]->dano;
        }
        else {
            energia -= n;
        }
    }
}

int usarMagia(Magia* magia){
    if (magia->getCura() != 0){
        magia->setUsoDisponivel(-1);
        return magia->getCura();
    }
    else if (magia->getDano() != 0){
        magia->setUsoDisponivel(-1);
        return magia->getDano();
    }
    else {
        return 0;
    }
}

void Personagem::escolheValorAtributos(int hab, int ene, int sor){
    if (hab + ene + sor == 12){
        if (habilidade + hab < 12){
            habilidade += hab;
        }
        if (energia + ene < 24){
            energia += ene;
        }
        if (sorte + sor < 12){
            sorte += sor;
        }
    }
}
// sucesso se total <= sorte
bool Personagem::testarSorte(){
    if (sorte <= 0) {
        cout << "SORTE = 0" << endl;
        return false;
    }
    // Simula dois dados de 6 lados
    int dado1 = std::rand() % 6 + 1;
    int dado2 = std::rand() % 6 + 1;
    int total = dado1 + dado2;

    cout << "Teste de sorte: " << total << endl;
    cout << "SORTE: " << sorte << endl;

    bool sucesso = total <= sorte;
    sorte--;

    if (sucesso) {
        cout << "Você conseguiu!" << endl;
    } else {
        cout << "Você falhou no teste de sorte." << endl;
    }

    return sucesso;
}

// nome;cura;dano
void Personagem::imprime_magias(){
    if (magias != nullptr && num_magias > 0){
        cout << "M: ";
        for (int i = 0; i < num_magias; i++){
            if (magias[i] != nullptr){
                cout << magias[i]->getNome() <<  ", " << magias[i]->getCura()  <<  ", " << magias[i]->getDano() << ". ";
            }
        }
    } 
    cout << endl;
}

//nome;tipo;combate;FA;dano
void Personagem::imprime_inventario(){
    for (int i = 0; i < num_inventario; i++)
        if (inventario[i] != nullptr){
            cout << "I: " << inventario[i]->nome << ", " << inventario[i]->tipo << ", " << inventario[i]->combate << ", " << inventario[i]->FA << ", " << inventario[i]->dano << endl;
        }
}

void Personagem::imprime_info(){
    cout << "N: " << nome << endl;
    if (num_magias != 0){
        imprime_magias();
    }
    cout << "H: " << habilidade << endl;
    cout << "S: " << sorte << endl;
    cout << "E: " << energia << endl;
    if (tesouro != 0){
        cout << "T: " << tesouro << endl;
    }
    if (provisoes != 0){
        cout << "P: " << provisoes << endl;
    }
    if (num_inventario != 0){
        imprime_inventario();
    }
}
