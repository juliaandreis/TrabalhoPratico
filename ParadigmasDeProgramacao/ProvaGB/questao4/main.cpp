#include "ContaBancaria.h"

int main() {
    ContaBancaria conta("Julia", 1000.0);

    cout << "Saldo Inicial: ";
    conta.mostrar_saldo();

    cout << endl << "----- Deposito de 500 -----" << endl;
    conta.depositar(500.0);
    conta.mostrar_saldo();

    cout << endl << "----- Saque de 300 -----" << endl;
    conta.sacar(300.0);
    conta.mostrar_saldo();

    cout << endl << "----- Saque de 1500 -----" << endl;
    conta.sacar(1500.0);
    conta.mostrar_saldo();

    return 0;
}