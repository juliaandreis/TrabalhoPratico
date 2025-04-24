#include <iostream>
#include <string>
#include "Personagem.h"
#include "Magia.h"
#include "Ladino.h"

using namespace std;

Ladino::Ladino(string nome, int habilidade, int energia, int sorte, Magia** magias):Personagem(nome, habilidade, energia, sorte){}