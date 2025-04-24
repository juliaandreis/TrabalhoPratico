#include <iostream>
#include <string>
#include <cstdlib> // rand() e srand()
#include <ctime>   // time()
#include "Personagem.h"
#include "Magia.h"
#include "Item.h"

using namespace std;

Personagem::Personagem(){}

Personagem::~Personagem(){}

Personagem::Personagem(string nome, int habilidade, int energia, int sorte){
    this->nome = nome;
    this->habilidade = habilidade;
    this->energia = energia;
    this->sorte = sorte;
    tesouro = 20;
    provisoes = 5;
    inventario = new Item *[10];
    for (int i = 0; i < 10; i++) {
        inventario[i] = nullptr;
    }
    num_inventario = 0;
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

//Métodos

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

void Personagem::imprime_inventario(){
    cout << "INVENTARIO:" << endl;
    for (int i = 0; i < 10; i++){
        if (inventario[i] != nullptr){
            cout << "Nome do item: " << inventario[i]->nome << endl;
            cout << "Tipo: " << inventario[i]->tipo << endl;
            cout << "Combate (1 - sim, 2 - não): " << inventario[i]->combate << endl;
            cout << "Bônus de Força de Ataque: " << inventario[i]->FA << endl;
            cout << "Bônus de Dano: " << inventario[i]->dano << endl << endl;
        }
    }
}

void Personagem::imprime(){
    cout << "Nome: " << nome << endl;
    cout << "Habilidade: " << habilidade << endl;
    cout << "Energia: " << energia << endl;
    cout << "Sorte: " << sorte << endl;
    if (tesouro != 0){
        cout << "Tesouro: " << tesouro << endl;
    }
    if (provisoes != 0){
        cout << "Provisões: " << provisoes << endl;
    }
    imprime_inventario();
}