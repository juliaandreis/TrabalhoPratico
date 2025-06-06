#pragma once
#include <iostream>
#include <string>

using namespace std;

//nos exercicios usei enum pq fica mais visual, mas podemos mudar
enum Prioridade {
    BAIXA = 0,
    MEDIA = 1,
    ALTA = 2
};

template<class T>
class Nodo {
private:
  T elemento;
  Nodo *ant;
  Nodo *prox;

public:
  Nodo();
  ~Nodo();
  Nodo(T elemento, Prioridade prioridade);

  void setElemento(T elemento);
  void setPrioridade(Prioridade prioridade);
  void setProx(Nodo *prox);
  void setAnt(Nodo *ant);

  T getElemento();
  Prioridade getPrioridade();
  Nodo *getProx();
  Nodo *getAnt();

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
void Nodo<T>::setProx(Nodo *prox){this->prox = prox;}

template<class T>
void Nodo<T>::setAnt(Nodo *ant){this->ant = ant;}

template<class T>
T Nodo<T>::getElemento(){return elemento;}

template<class T>
Prioridade Nodo<T>::getPrioridade(){return elemento->getPrioridade();}

template<class T>
Nodo<T>* Nodo<T>::getProx(){return prox;}

template<class T>
Nodo<T>* Nodo<T>::getAnt(){return ant;}

template<class T>
void Nodo<T>::imprime(){
  cout << elemento << endl;
}