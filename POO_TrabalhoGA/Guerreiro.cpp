#include <iostream>
#include <string>
#include "Personagem.h"
#include "Magia.h"
#include "Guerreiro.h"

using namespace std;

Guerreiro::Guerreiro(string nome, int habilidade, int energia, int sorte, Magia** magias):Personagem(nome, habilidade, energia, sorte){}