#ifndef MAGIA_H
#define MAGIA_H

#include <string>

using namespace std;

class Magia{
    private:
        string nome;
        int cura;
        int dano;
        int usoDisponivel;

    public:
        Magia();
        ~Magia();
        Magia(string nome, int cura, int dano, bool item_magico);
        void setNome(string nome);
        string getNome();
        void setCura(int cura);
        int getCura();
        void setDano(int dano);
        int getDano();
        void setItem_magico(bool item);
        bool getItem_magico();
};

#endif // MAGIA_H
