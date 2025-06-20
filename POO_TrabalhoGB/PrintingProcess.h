#ifndef PRINTINGPROCESS_H
#define PRINTINGPROCESS_H

#include "Process.h"
#include "Pool.h"

class PrintingProcess : public Process{
private:
    Pool<Process> *pool;

public:
    PrintingProcess();
    ~PrintingProcess();
    PrintingProcess(Pool<Process> *pool);
    void setProcesso(int pid);
    void executar();
    void imprime();
};

PrintingProcess::PrintingProcess(){}

PrintingProcess::PrintingProcess(Pool<Process> *pool){
  this->pool = pool;
  setType(PRINTING);
}

PrintingProcess::~PrintingProcess(){}

void PrintingProcess::setProcesso(int pid){
  this->setPid(pid);
}

void PrintingProcess::executar(){
  if (pool->getTamanho() == 0){
    cout << "Lista vazia" << endl;
  } else{
      pool->imprime();
  }
}

void PrintingProcess::imprime(){
  cout << "PID: " << getPid() << ", Printing Process" << endl;
}

#endif // PRINTINGPROCESS_H