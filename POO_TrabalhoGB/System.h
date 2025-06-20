#ifndef SYSTEM_H
#define SYSTEM_H

// INCLUDES //

#include "ComputingProcess.h"
#include "Pool.h"
#include "ReadingProcess.h"
#include "WritingProcess.h"
#include "PrintingProcess.h"
#include <math.h>

// CLASS //

class System {
private:
  Pool<Process> *pool;

public:
  System();
  System(Pool<Process> *pool);
  ~System();

  void newProcess();
  void executeNext();
  void executeSpecific();
  bool saveProcesses();
  void loadProcesses();
};

System::System() {}

System::System(Pool<Process> *pool) { this->pool = pool; }

System::~System() {}

void System::newProcess() {
    cout << endl << "Digite o tipo de processo: " << endl;
    cout << "1 - Computing Process" << endl;
    cout << "2 - Writing Process" << endl;
    cout << "3 - Reading Process" << endl;
    cout << "4 - Printing Process" << endl;
    cout << " : ";

    int tipo = 0;
    cin >> tipo;

    int pid = 0;
    string equacao = "";

    // Inicialização de variáveis temporárias
    ComputingProcess *computing = new ComputingProcess();
    WritingProcess *writing = new WritingProcess();
    ReadingProcess *reading = new ReadingProcess(pool);
    PrintingProcess *printing = new PrintingProcess(pool);

    switch (tipo) {
    case 1:
        cout << endl << "Digite a equacao: " << endl;
        cin >> equacao;
        pid = pool->getPosicao() + 1;
        computing->setProcesso(pid, equacao);
        pool->push(computing);
        //pool->front()->imprime();
        break;

    case 2:
        cout << endl << "Digite a equacao: " << endl;
        cin >> equacao;
        pid = pool->getPosicao() + 1;
        writing->setProcesso(pid, equacao);
        pool->push(writing);
        //pool->front()->imprime();
        break;

    case 3:
        pid = pool->getPosicao() + 1;
        reading->setProcesso(pid);
        pool->push(reading);
        //pool->push(reading);
        break;
        
    case 4:
        pid = pool->getPosicao() + 1;
        printing->setProcesso(pid);
        pool->push(printing);
        //pool->push(printing);
        break;
        
    default:
        cout << "Tipo de processo invalido" << endl;
        break;
    }
}

void System::executeNext() {
    // pool->front()->imprime();
    pool->front()->executar();
    pool->pop();
}

void System::executeSpecific(){
    int pid;
    cout << "Digite o PID do processo a ser executado: " << endl;
    cout << "Processo: ";
    cin >> pid;
    if(pool->getSearch(pid) != NULL)
        pool->getSearch(pid)->getElemento()->executar();
    else
        cout << "Processo nao encontrado" << endl;
}

bool System::saveProcesses(){
    string line = "";

    // Processos de bufferizacao
    ComputingProcess *computingProcess;
    WritingProcess *writingProcess;

    ofstream writing("poolProcess.txt", ios::app);
    if (!writing.is_open()) {
        cerr << "Erro ao abrir o arquivo para leitura!\n";
        return false;
    } else {
        while (pool->getTamanho() > 0) {
            switch (pool->front()-> getType()){
            case COMPUTING:
                cout << "teste computing" << endl;
                computingProcess = (ComputingProcess *) pool->front();
                writing << computingProcess->getType() << ";"
                        << computingProcess->getPid() << ";"
                        << computingProcess->getExpressao() << endl;
                break;
            case WRITING:
                cout << "teste writing" << endl;
                writingProcess = (WritingProcess *) pool->front();
                writing << writingProcess->getType() << ";"
                        << writingProcess->getPid() << ";"
                        << writingProcess->getExpressao() << endl;
                break;
            case READING:
                cout << "teste reading" << endl;
                writing << pool->front()->getType() << ";"
                        << pool->front()->getPid() << endl;
                break;
            case PRINTING:
                cout << "teste printing" << endl;
                writing << pool->front()->getType() << ";"
                        << pool->front()->getPid() << endl;
                break;
            }
            pool->pop();
        }
    
        writing.close();
        cout << "Expressao escrita com sucesso!" << endl;
        return true;
    }
}


void System::loadProcesses(){
  ifstream carregamento("poolProcess.txt");
  if (!carregamento.is_open()) {
    cerr << "Erro ao abrir o arquivo para leitura!\n";
  } else {
    // Atributos
    ProcessType tipo;
    string expressao;
    int pid = 0;
    int id_size = 0;

    // Processos de bufferizacao
    ComputingProcess *computing;
    WritingProcess *writing;
    ReadingProcess *reading;
    PrintingProcess *printing;

    while (getline(carregamento, expressao)) {
      tipo = (ProcessType)(expressao[0] - '0');
      expressao = expressao.substr(2);
      id_size = (int) expressao.find(";");
      for(int i = 0; i < id_size; i++){
        pid += (int)(pow(10,(id_size-1-i))) * (expressao[i] - '0');
      }
      expressao = expressao.substr(id_size+1);

      switch (tipo){
        case COMPUTING:
          computing = new ComputingProcess();
          computing->setProcesso(pid, expressao);
          pool->push(computing);
          break;
        case WRITING:
          writing = new WritingProcess();
          writing->setProcesso(pid, expressao);
          pool->push(writing);
          break;
        case READING:
          reading = new ReadingProcess(pool);
          reading->setProcesso(pid);
          pool->push(reading);
          break;
        case PRINTING:
          printing = new PrintingProcess(pool);
          printing->setProcesso(pid);
          pool->push(printing);
          break;
      }
      pid = 0;
    }
    ofstream arquivoEscrita("poolProcess.txt", ios::trunc);
    carregamento.close();
  }
}

#endif // SYSTEM_H //