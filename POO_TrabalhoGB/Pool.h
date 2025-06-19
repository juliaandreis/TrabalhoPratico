#pragma once
#include "Nodo.h"

template<class T>
class Pool {
private:
    Nodo<T> *inicio;
    Nodo<T> *fim;
    int tamanho;

public:
    Pool();
    ~Pool();

    void push_back(T elemento);
    void push_front(T elemento);
    T pop_back();
    T pop_front();

    T front();
    bool find(T elemento);
    void chegou(T elemento, Prioridade prioridade);
    void saiu();

    void inverte();
    void imprime();
};

template<class T>
Pool<T>::Pool(){
    inicio = nullptr;
    fim = nullptr;
    tamanho = 0;
}

template<class T>
Pool<T>::~Pool(){}

template<class T>
void Pool<T>::push_back(T elemento){
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
}

template<class T>
void Pool<T>::push_front(T elemento){
    Nodo<T> *novo = new Nodo<T>(elemento);
    if (inicio == nullptr){
        inicio = novo;
        fim = novo;
    }
    else{
        novo->setProximo(inicio);
        inicio->setAnterior(novo);
        inicio = novo;
    }
tamanho++;
}

template<class T>
T Pool<T>::pop_back(){
    if (fim == nullptr) {
        return -1;
    }
    T elemento = fim->getElemento();
    Nodo<T>* temp = fim;
    if (inicio == fim) {
        inicio = nullptr;
        fim = nullptr;
    } else {
        fim = fim->getAnterior();
        fim->setProximo(nullptr);
    }
    delete temp;
    tamanho--;
    return elemento;
}

template<class T>
T Pool<T>::pop_front(){
    if (inicio == nullptr) {
        return -1;
    }
    T elemento = inicio->getElemento();
    Nodo<T>* temp = inicio;
    if (inicio == inicio) {
        inicio = nullptr;
        inicio = nullptr;
    } else {
        inicio = inicio->getAnterior();
        inicio->setProximo(nullptr);
    }
    delete temp;
    tamanho--;
    return elemento;
}

template<class T>
T Pool<T>::front(){
    return inicio->getElemento();
}

template<class T>
bool Pool<T>::find(T letra){
    while (fim!=nullptr){
        if (fim->getElemento() == letra){
            return true;
        }
        pop_front();
    }
return false;
}

template<class T>
void Pool<T>::chegou(T elemento, Prioridade prioridade){
    Nodo<T> *novo = new Nodo<T>(elemento, prioridade);
    if (inicio == nullptr) {
        inicio = novo;
        fim = novo;
    } else {
        Nodo<T> *seguinte = fim;
        while (seguinte != nullptr && seguinte->getPrioridade() >= prioridade) {
            seguinte = seguinte->getProximo();
        }
        if (seguinte == nullptr) {
            inicio->setProximo(novo);
            novo->setAnterior(inicio);
            inicio = novo;
        } else if (seguinte == fim) {
            novo->setProximo(fim);
            fim->setAnterior(fim);
            fim = novo;
        } else {
            novo->setProximo(seguinte);
            novo->setAnterior(seguinte->getAnterior());
            seguinte->getAnterior()->setProximo(novo);
            seguinte->setAnterior(novo);
        }
    }
}