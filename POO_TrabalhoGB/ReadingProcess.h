#include "Process.h"

class ReadingProcess : public Process{


};
/*
void App::carregar(string arquivo) {
  ifstream save(arquivo);
  if (!save.is_open()) {
    cerr << "Erro ao abrir o arquivo para leitura!\n";
    return;
  }

  string classe, tipo, linha;
  string nomeItem, nomeMagia;
  char tipoItem;
  int hab, vid, sor, tes, prov;
  int fa, dano, cura, usoDisponivel;
  bool equipado;

  Magia *magia1 = nullptr, *magia2 = nullptr, *magia3 = nullptr;
  Item *itens[6] = {nullptr}; // suporta até 6 itens
  int itemCount = 0;
  int magiaCount = 0;

  save >> telaAtual;
  save.ignore(); // Ignora \n após número

  getline(save, classe);
  save >> hab;
  save >> vid;
  save >> sor;
  save >> tes;
  save >> prov;
  // save.ignore(); // Ignora \n após provisoes

  // Lê os dados de itens e magias antes de instanciar o player
  while (getline(save, tipo)) {
    if (tipo == "I") {
      getline(save, linha); // Nome;Tipo;FA;Dano;Equipado

      size_t pos1 = linha.find(';');
      nomeItem = linha.substr(0, pos1);

      size_t pos2 = linha.find(';', pos1 + 1);
      tipoItem = linha[pos1 + 1];

      size_t pos3 = linha.find(';', pos2 + 1);
      fa = stoi(linha.substr(pos2 + 1, pos3 - pos2 - 1));

      size_t pos4 = linha.find(';', pos3 + 1);
      dano = stoi(linha.substr(pos3 + 1, pos4 - pos3 - 1));

      equipado = stoi(linha.substr(pos4 + 1));

      if (itemCount < 6) {
        itens[itemCount++] = new Item(nomeItem, tipoItem, fa, dano, equipado);
      }
    } else if (tipo == "M") {
      getline(save, linha); // Nome;Cura;Dano;UsoDisponivel

      size_t pos1 = linha.find(';');
      nomeMagia = linha.substr(0, pos1);

      size_t pos2 = linha.find(';', pos1 + 1);
      cura = stoi(linha.substr(pos1 + 1, pos2 - pos1 - 1));

      size_t pos3 = linha.find(';', pos2 + 1);
      dano = stoi(linha.substr(pos2 + 1, pos3 - pos2 - 1));

      usoDisponivel = stoi(linha.substr(pos3 + 1));

      Magia *novaMagia = new Magia(nomeMagia, cura, dano, usoDisponivel);
      if (magiaCount == 0)
        magia1 = novaMagia;
      else if (magiaCount == 1)
        magia2 = novaMagia;
      else if (magiaCount == 2)
        magia3 = novaMagia;
      magiaCount++;
    }
  }

  // Criação do player após leitura de tudo
  if (classe == "Guerreiro") {
    player = new Guerreiro(classe);
  } else if (classe == "Ladino") {
    player = new Ladino(classe);
  } else if (classe == "Mago") {
    player = new Mago(classe, magia1, magia2, magia3);
  }

  // Define atributos
  player->setHabilidade(hab);
  player->setVida(vid);
  player->setSorte(sor);
  player->setTesouro(tes);
  player->setProvisoes(prov);

  // Adiciona os itens
  for (int i = 0; i < itemCount; i++) {
    player->adicionarItem(itens[i]);
  }
  save.close();
}

*/