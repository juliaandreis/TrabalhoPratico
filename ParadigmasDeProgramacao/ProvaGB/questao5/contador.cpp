#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

int contador = 0;
mutex mtx;

void incrementar_sem_protecao() {
    for (int i = 0; i < 300000; ++i) {
        contador++;
    }
}

void incrementar_com_protecao() {
    for (int i = 0; i < 300000; ++i) {
        lock_guard<mutex> lock(mtx);
        contador++;
    }
}

int main() {
    contador = 0;
    thread t1(incrementar_sem_protecao);
    thread t2(incrementar_sem_protecao);
    t1.join(); t2.join();
    cout << "Resultado sem protecao: " << contador << endl;

    contador = 0;
    thread t3(incrementar_com_protecao);
    thread t4(incrementar_com_protecao);
    t3.join(); t4.join();
    cout << "Resultado com protecao: " << contador << endl;

    return 0;
}