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

int main() 
{
    // Inicializa a semente para a função rand()
    srand(time(0));

    // Criação dos personagens
    Mago mago("Mago", nullptr);
    
    Magia bolaFogo("Bola de Fogo", 0, 5, 0);
    Magia cura("Cura", 2, 0, 0);
    mago.setMagia(&bolaFogo);
    mago.setMagia(&cura);
    
    Monstro monstro("Monstro");
    Item espada;
    espada.nome = "Espada";
    espada.tipo = 'w';
    espada.combate = 1;
    espada.FA = 2;
    espada.dano = 3;
    monstro.setInventario(&espada);
    monstro.setTesouro(10);
    monstro.setProvisoes(3);
    
    Guerreiro guerreiro("Guerreiro");
    Ladino ladino("Ladino");

    mago.imprime_info();
    cout << endl;
    guerreiro.imprime_info();
    cout << endl;
    ladino.imprime_info();
    cout << endl;
    monstro.imprime_info();
    cout << endl;

    // Combate entre o mago e o monstro
    Combate combate(&mago, &monstro);
    combate.acaoCombate();
    
    return 0;
}