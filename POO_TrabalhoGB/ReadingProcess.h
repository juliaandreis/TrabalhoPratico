#ifndef READINGPROCESS_H
#define READINGPROCESS_H

#include "Process.h"
#include "Pool.h"

class ReadingProcess : public Process{
private:
    Pool<Process> *pool;

public:
    ReadingProcess();
    ReadingProcess(Pool<Process> *pool);
    ~ReadingProcess();
    void setProcesso(int pid);
    void executar();
    void imprime();

};

ReadingProcess::ReadingProcess(){}

ReadingProcess::ReadingProcess(Pool<Process> *pool){
  this->pool = pool;
  setType(READING);
}

ReadingProcess::~ReadingProcess(){}

void ReadingProcess::setProcesso(int pid){
  setPid(pid);
}

void ReadingProcess::executar() {
  ifstream leitor("computation.txt");
  if (!leitor.is_open()) {
    cerr << "Erro ao abrir o arquivo para leitura!\n";
  } else {
    string expressao = "";
    int pid = 0;
    
    while (getline(leitor, expressao)) {
      ComputingProcess *computing = new ComputingProcess();
      pid = pool->getTamanho() + 1;
      computing->setProcesso(pid, expressao);
      pool->push(computing);
      
    }
    ofstream arquivoEscrita("computation.txt", ios::trunc);
    leitor.close();
  }
}

void ReadingProcess::imprime(){
  cout << "PID: " << getPid() << ", Reading Process" << endl;
}

#endif // READINGPROCESS_H