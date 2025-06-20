#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

// TYPES //

typedef enum{
    COMPUTING,
    WRITING,
    READING,
    PRINTING
} ProcessType;

class Process {
private:
    int pid;
    ProcessType type;

public:
    Process();
    virtual ~Process();
    Process(int pid);

    void setPid(int pid);
    int getPid();
    ProcessType getType();
    void setType(ProcessType type);

    virtual void execute();
    virtual void imprime();
};

Process::Process() { pid = 0;}

Process::~Process() {}

Process::Process(int pid) { this->pid = pid; }

void Process::setPid(int pid) { this->pid = pid; }

int Process::getPid() { return pid; }

ProcessType Process::getType(){return type;}

void Process::setType(ProcessType type){this->type = type;}

void Process::execute(){}

void Process::imprime(){}

#endif // PROCESS_H //