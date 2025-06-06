#include <iostream>
#include <string>

//nos exercicios usei enum pq fica mais visual, mas podemos mudar
enum Prioridade {
    BAIXA = 0,
    MEDIA = 1,
    ALTA = 2
};

class Processo{
  private:
    Prioridade pid;

  public:
    Processo();
    ~Processo();
    Processo(Prioridade pid);

    void setPid(Prioridade pid);
    Prioridade getPid();

    virtual void executar();
};

Processo::Processo(){}

Processo::~Processo(){}

Processo::Processo(Prioridade pid){this->pid = pid;}

void Processo::setPid(Prioridade pid){this->pid = pid;}

Prioridade Processo::getPid(){return pid;}