#include "Processo.h"

class ComputingProcess : public Processo{
  public:
    ComputingProcess();
    ~ComputingProcess();
    ComputingProcess(Prioridade pid);
    void executar(int operando1, int operando2, char operacao);
};

ComputingProcess::ComputingProcess(){}

ComputingProcess::~ComputingProcess(){}
  
ComputingProcess::ComputingProcess(Prioridade pid):Processo(pid){}

void ComputingProcess::executar(int operando1, int operando2, char operacao){
  int resultado;
  switch (operacao)
    {
      case '+':
        resultado = operando1 + operando2;
        break;
      case '-':
        resultado = operando1 - operando2;
        break;
      case '*':
        resultado = operando1 * operando2;
        break;
      case '/':
        resultado = operando1 / operando2;
        break;
    }
  cout << resultado << endl;
}