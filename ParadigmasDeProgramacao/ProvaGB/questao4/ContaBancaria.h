#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <iostream>

using namespace std;

class ContaBancaria {
    private:
        string titular;
        float saldo;

    public:
        ContaBancaria(string t, float s) {
            titular = t;
            saldo = s;
        }

        void depositar(float valor) {
            saldo += valor;
        }

        void sacar(float valor) {
            if (valor <= saldo) {
                saldo -= valor;
            } else {
                cout << "Saldo insuficiente" << endl;
            }
        }

        void mostrar_saldo() {
            cout << "Saldo: " << saldo << endl;
        }
};

#endif //CONTABANCARIA_H