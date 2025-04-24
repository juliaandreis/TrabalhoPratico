#ifndef MAGIA_H
#define MAGIA_H

#include <string>

using namespace std;

class Magia{
    private:
        string nome;
        int dano;

    public:
        Magia();
        ~Magia();
        Magia(string nome, int dano);
        void setNome(string nome);
        string getNome();
        void setDano(int dano);
        int getDano();
};

#endif // MAGIA_H
