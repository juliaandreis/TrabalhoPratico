#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
#include "Process.h"
#include "ComputingProcess.h"

using namespace std;

template<class T>
class Nodo {
private:
  T *elemento;
  Nodo *anterior;
  Nodo *proximo;

public:
  Nodo();
  ~Nodo();
  Nodo(T *elemento);

  void setElemento(T *elemento);
  void setProximo(Nodo *proximo);
  void setAnterior(Nodo *anterior);

  T* getElemento();
  int getPid();
  Nodo *getProximo();
  Nodo *getAnterior();

  void imprime();
};

template<class T>
Nodo<T>::Nodo(){}

template<class T>
Nodo<T>::~Nodo(){}

template<class T>
Nodo<T>::Nodo(T* elemento) {
  this->elemento = elemento;
  this->proximo = nullptr;
  this->anterior = nullptr;
}

template<class T>
void Nodo<T>::setElemento(T* elemento){this->elemento = elemento;}

template<class T>
void Nodo<T>::setProximo(Nodo *proximo){this->proximo = proximo;}

template<class T>
void Nodo<T>::setAnterior(Nodo *anterior){this->anterior = anterior;}

template<class T>
T* Nodo<T>::getElemento(){return elemento;}

template<class T>
int Nodo<T>::getPid(){return elemento->getPid();}

template<class T>
Nodo<T>* Nodo<T>::getProximo(){return proximo;}

template<class T>
Nodo<T>* Nodo<T>::getAnterior(){return anterior;}

template<class T>
void Nodo<T>::imprime(){
  elemento->imprime();
}

#endif // NODO_H