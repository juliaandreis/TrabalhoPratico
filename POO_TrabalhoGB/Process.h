#include <iostream>
#include <string>

using namespace std;

//nos exercicios usei enum pq fica mais visual, mas podemos mudar
enum Prioridade {
    BAIXA = 0,
    MEDIA = 1,
    ALTA = 2
};

class Process{
  private:
    Prioridade pid;

  public:
    Process();
    ~Process();
    Process(Prioridade pid);

    void setPid(Prioridade pid);
    Prioridade getPid();

    virtual void executar();
};

Process::Process(){}

Process::~Process(){}

Process::Process(Prioridade pid){this->pid = pid;}

void Process::setPid(Prioridade pid){this->pid = pid;}

Prioridade Process::getPid(){return pid;}