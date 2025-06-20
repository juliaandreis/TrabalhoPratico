#ifndef COMPUTINGPROCESS_H
#define COMPUTINGPROCESS_H

#include "Process.h"
#include <iomanip>
#include <cstdlib>

class ComputingProcess : public Process{
  private:
    int operando1;
    int operando2;
    char operacao;
    string expressao;

  public:
    ComputingProcess();
    ~ComputingProcess();
    void setProcesso(int pid, string expressao);
    string getExpressao();
    void execute();
    void imprime();
};

ComputingProcess::ComputingProcess(){
  operando1 = 0;
  operando2 = 0;
  operacao = '\0';
  setType(COMPUTING);
}

ComputingProcess::~ComputingProcess(){}

void ComputingProcess::setProcesso(int pid, string expressao){
  setPid(pid);
  size_t pos;

  for (pos = 0; pos < expressao.length(); ++pos) {
    if (!isdigit(expressao[pos])) break;
  }
  this->expressao = expressao;
  operando1 = stoi(expressao.substr(0, pos));
  operacao = expressao[pos];
  operando2 = stoi(expressao.substr(pos + 1));
}

string ComputingProcess::getExpressao(){return expressao;}

void ComputingProcess::execute(){
  float resultado;
  switch (operacao)
    {
      case '+':
        resultado = (float)operando1 + operando2;
        break;
      case '-':
        resultado = (float)operando1 - operando2;
        break;
      case '*':
        resultado = (float)operando1 * operando2;
        break;
      case '/':
        resultado = (float)operando1 / operando2;
        break;
    }

  cout << expressao << " = ";
  cout.precision(2);
  cout << setiosflags(ios::fixed) << resultado << endl;
}

void ComputingProcess::imprime(){
  cout << "PID: " << getPid() << ", Computing Process, ";
  cout << operando1 << operacao << operando2 << endl;
}

#endif // COMPUTINGPROCESS_H