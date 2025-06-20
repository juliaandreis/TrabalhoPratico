/**
 * @file ReadingProcess.h
 * @brief Classe processo de escrita
 * @author Julia, Tobias
 * @date 2025-06-19
 */

#ifndef WRITINGPROCESS_H
#define WRITINGPROCESS_H

#include "Process.h"
#include <fstream>
#include <streambuf>
#include <iostream>

class WritingProcess : public Process {
private:
  string arquivo;
  string expressao;

public:
  WritingProcess();
  ~WritingProcess();
  WritingProcess(int pid, string expressao);
  void setProcesso(int pid, string expressao);
  string getExpressao();
  void execute();
  void imprime();
};

WritingProcess::WritingProcess() { 
  arquivo = "computation.txt"; 
  setType(WRITING);
}

WritingProcess::~WritingProcess() {}

WritingProcess::WritingProcess(int pid, string expressao) : Process(pid) {
  this->expressao = expressao;
}

void WritingProcess::setProcesso(int pid, string expressao){
  this->setPid(pid);
  this->expressao = expressao;
}

string WritingProcess::getExpressao() {
  return expressao;
}

void WritingProcess::execute() {
  string line = "";
  
  ofstream writing(arquivo, ios::app);
  if (!writing.is_open()) {
    cerr << "Erro ao abrir o arquivo para leitura!\n";
  } else {
    writing << expressao << endl;
    writing.close();
    cout << "Expressao escrita com sucesso!" << endl;
  }
}

/*
void App::salvar(string arquivo) {
 ofstream save(arquivo);
 if (!save.is_open()) {
   cerr << "Erro ao abrir o arquivo para escrita!\n";
   return;
 }
 save << telaAtual << endl;
 save << player->getNome() << endl;

   save << item->getNome() << ";" << item->getTipo() << ";" << item->getFA()
        << ";" << item->getDano() << ";" << item->getEquipado() << endl;

   if (player->getMagias(i) != nullptr) {
     save << "M" << endl;
     save << player->getMagias(i)->getNome() << ";"
          << player->getMagias(i)->getCura() << ";"
          << player->getMagias(i)->getDano() << ";"
          << player->getMagias(i)->getUsoDisponivel() << endl;
   }

 save.close();

 cout << "Jogo salvo com sucesso!" << endl;
}
*/

void WritingProcess::imprime() {
  cout << "PID: " << getPid() << ", Writing Process, ";
  cout << expressao << endl;
}

#endif // WRITINGPROCESS_H