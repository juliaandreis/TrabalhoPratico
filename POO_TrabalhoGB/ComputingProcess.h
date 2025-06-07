#include "Process.h"

class ComputingProcess : public Process{
  private:
    int operando1;
    int operando2;
    char operacao;

  public:
    ComputingProcess();
    ~ComputingProcess();
    ComputingProcess(string processo);
    void executar();
};

ComputingProcess::ComputingProcess(){}

ComputingProcess::~ComputingProcess(){}
  
ComputingProcess::ComputingProcess(string processo){
  operando1 = stoi(processo.substr(0,1));
  operando2 = processo.substr(1,2);
  operacao = stoi(processo.substr(0,1));
}

void ComputingProcess::executar(){
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