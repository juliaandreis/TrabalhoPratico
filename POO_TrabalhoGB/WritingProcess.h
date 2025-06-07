#include "Process.h"

class WritingProcess : public Process {

};

 /*
 void App::salvar(string arquivo) {
  ofstream save(arquivo);
  if (!save.is_open()) {
    cerr << "Erro ao abrir o arquivo para escrita!\n";
    return;
  }
  save << telaAtual << endl;
  save << player->getNome() << endl;
  save << player->getHabilidade() << endl;
  save << player->getVida() << endl;
  save << player->getSorte() << endl;
  save << player->getTesouro() << endl;
  save << player->getProvisoes() << endl;
  Inventario *inv = player->getInventario();

  for (int i = 0; i < 6; i++) {
    Item *item = inv->getItem(i);
    if (item != nullptr) {
      save << "I" << endl;
      save << item->getNome() << ";" << item->getTipo() << ";" << item->getFA()
           << ";" << item->getDano() << ";" << item->getEquipado() << endl;
    }
  }
  for (int i = 0; i < player->getNum_magias(); i++) {
    if (player->getMagias(i) != nullptr) {
      save << "M" << endl;
      save << player->getMagias(i)->getNome() << ";"
           << player->getMagias(i)->getCura() << ";"
           << player->getMagias(i)->getDano() << ";"
           << player->getMagias(i)->getUsoDisponivel() << endl;
    }
  }

  save.close();

  cout << "Jogo salvo com sucesso!" << endl;
  telaAtual = 24;
}
 */