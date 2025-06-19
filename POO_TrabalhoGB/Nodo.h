#pragma once
#include <iostream>
#include <string>
#include "Process.h"

using namespace std;

template<class T>
class Nodo {
private:
  T elemento;
  Nodo *anterior;
  Nodo *proximo;

public:
  Nodo();
  ~Nodo();
  Nodo(T elemento, Prioridade prioridade);

  void setElemento(T elemento);
  void setPrioridade(Prioridade prioridade);
  void setProximo(Nodo *proximo);
  void setAnterior(Nodo *anterior);

  T getElemento();
  Prioridade getPrioridade();
  Nodo *getProximo();
  Nodo *getAnterior();

  void imprime();
};

template<class T>
Nodo<T>::Nodo(){}

template<class T>
Nodo<T>::~Nodo(){}

template<class T>
Nodo<T>::Nodo(T elemento, Prioridade prioridade) {
  this->elemento = elemento;
  this->prioridade = prioridade;
  this->prox = nullptr;
  this->ant = nullptr;
}

template<class T>
void Nodo<T>::setElemento(T elemento){this->elemento = elemento;}

template<class T>
void Nodo<T>::setPrioridade(Prioridade prioridade){elemento->setPrioridade(prioridade);}

template<class T>
void Nodo<T>::setProximo(Nodo *proximo){this->proximo = proximo;}

template<class T>
void Nodo<T>::setAnterior(Nodo *anterior){this->anterior = anterior;}

template<class T>
T Nodo<T>::getElemento(){return elemento;}

template<class T>
Prioridade Nodo<T>::getPrioridade(){return elemento->getPrioridade();}

template<class T>
Nodo<T>* Nodo<T>::getProximo(){return proximo;}

template<class T>
Nodo<T>* Nodo<T>::getAnterior(){return anterior;}

template<class T>
void Nodo<T>::imprime(){
  cout << elemento << endl;
}