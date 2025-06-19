#include "Pool.h"

template<class T>
class System {
private:
    Fila<T>* fila;

public:
    System();
    ~System();

    void newProcess(Process* processo);
    void executeNext();
    void executeSpecific();
    bool saveQueue();
};