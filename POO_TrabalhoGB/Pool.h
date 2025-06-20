#ifndef POOL_H
#define POOL_H

#include "Nodo.h"

template <class T> 
class Pool {
private:
    Nodo<T> *inicio;
    Nodo<T> *fim;
    int tamanho;
    int posicao;

public:
    Pool();
    ~Pool();

    void push(T *elemento);
    T* pop();
    T* pop_midle(int pid);

    T* front();
    bool find(int pid);
    Nodo<T>* getSearch(int pid);
    void saiu();

    int getTamanho();
    int getPosicao();
    void imprime();
};

template <class T> Pool<T>::Pool() {
    inicio = nullptr;
    fim = nullptr;
    tamanho = posicao = 0;
}

template <class T> Pool<T>::~Pool() {}

template<class T>
void Pool<T>::push(T *elemento){
    Nodo<T> *novo = new Nodo<T>(elemento);
    if (inicio == nullptr){
        inicio = novo;
        fim = novo;
    }
    else{
        novo->setAnterior(fim);
        fim->setProximo(novo);
        fim = novo;
    }
    tamanho++;
    posicao++;
}

template <class T> 
T *Pool<T>::pop() {
    if (inicio == nullptr) {
        return nullptr;
    }
    T* elemento = inicio->getElemento();
    Nodo<T> *temp = inicio;
    if (inicio == fim) {
        inicio = nullptr;
        fim = nullptr; 
    } else {
        inicio = inicio->getProximo();
        inicio->setAnterior(nullptr);
    }
    delete temp;
    tamanho--;
    return elemento;
}

template<class T>
T* Pool<T>::pop_midle(int pid){
    if (!find(pid)) {
        return nullptr;
    }

    Nodo<T> *atual = inicio;

    while (atual->getPid() != pid) {
        atual = atual->getProximo();
    }

    Nodo<T> *anterior = atual->getAnterior();
    Nodo<T> *proximo = atual->getProximo();

    anterior->setProximo(proximo);
    proximo->setAnterior(anterior);

    tamanho--;

    return atual->getElemento();
}

template <class T> 
T *Pool<T>::front() { return inicio->getElemento(); }

template <class T>
bool Pool<T>::find(int pid) {
    Nodo<T> *atual = inicio;
    while (atual != nullptr) {
        if (atual->getPid() == pid) {
            return true;
        }
        atual = atual->getProximo();
    }
    return false;
}

template <class T>
Nodo<T>* Pool<T>::getSearch(int pid) {
    Nodo<T> *atual = inicio;
    while (atual != nullptr) {
        if (atual->getPid() == pid) {
            return atual;
        }
        atual = atual->getProximo();
    }
    return NULL;
}

template <class T> 
int Pool<T>::getTamanho() { return tamanho; }

template <class T> 
int Pool<T>::getPosicao() { return posicao; }

template <class T> void Pool<T>::imprime(){
    Nodo<T> *atual = inicio;
    for (int i = 0; i < tamanho; i++){
        atual->imprime();
        atual = atual->getProximo();
    }
}

#endif // POOL_H