#include <iostream>
#include <string>
#include <cstdlib> // rand() e srand()
#include <ctime>   // time()
#include "Personagem.h"

using namespace std;

Personagem::Personagem(){}

Personagem::~Personagem(){}

Personagem::Personagem(string nome, int vida, int ataque, int defesa, int habilidade, int energia, int sorte, bool mago){
    this->nome = nome;
    this->vida = vida;
    this->ataque = ataque;
    this->defesa = defesa;
    this->habilidade = habilidade;
    this->energia = energia;
    this->sorte = sorte;
    this->mago = mago;
}

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
    cout << "SORTE: " << sorte << "\n";

    bool sucesso = total <= sorte;
    sorte--;

    if (sucesso) {
        cout << "Teste de sorte bem-sucedido!\n";
    } else {
        cout << "Teste de sorte falhou.\n";
    }

    return sucesso;
}

void Personagem::imprime_info(){}
void Personagem::imprime_inventario(){}

//Getters e Setters
void Personagem::setNome(string nome){this->nome = nome;}
string Personagem::getNome(){return nome;}
void Personagem::setHabilidade(int habilidade){this->habilidade = habilidade;}
int Personagem::getHabilidade(){return habilidade;}
void Personagem::setEnergia(int energia){this->energia = energia;}
int Personagem::getEnergia(){return energia;}
void Personagem::setSorte(int sorte){this->sorte = sorte}
int Personagem::getSorte(){return sorte;}
void Personagem::setMago(bool mago){this->mago = mago;}
bool Personagem::getMago(){return mago}
void Personagem::setMagias(Magia** magias){}
Magia** Personagem::getMagias(){}
void Personagem::setInventario(Item** inventario){}
Item** Personagem::getInventario(){}
void Personagem::setTesouro(Item** tesouro){}
Item** Personagem::getTesouro(){}
void Personagem::setProvisoes(Provisao** provisoes){}
Provisao** Personagem::getProvisoes(){}
