#ifndef MAGIA_H
#define MAGIA_H

#include <string>

using namespace std;

class Magia{
    private:
        string nome;
        int dano;
        bool item_magico; // para definir se é item mágico

    public:
        Magia();
        ~Magia();
        Magia(string nome, int dano, bool item);
        void setNome(string nome);
        string getNome();
        void setDano(int dano);
        int getDano();
        void setItem_magico(bool item);
        bool getItem_magico();
};

#endif // MAGIA_CPP
