
#ifndef TELA_H
#define TELA_H

#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

class Tela
{
    public:
        Tela();
        ~Tela();
        void menu();
        void menu2();
        void menu3();
        void menu4();
        void menu5();
        void menu6();
        void menu7();
        void menu8();
        void menu9();
        void menu10();
    
    private:
        string nomeCena;
        char tipo;
        string nomeConteudo;
        int habilidade;
        int sorte;
        int energia;
        int tesouro;
        int provisao;
        Item item;
        int proximaCenaSucesso;
        int proximaCenaDerrota;
};

#endif // TELA_H
