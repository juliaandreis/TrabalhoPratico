// Arrumamos o PID do PrintingProcess após a apresentação, agora funciona com o executar o processo específico.
// Classe system.cpp, método loadProcesses(). Comentamos nas linhas 156 e 161

#include "System.h"
#include "Process.h"
#include "Pool.h"

int main(){
    Pool<Process> pool;
    System system(&pool);

    char selecao = '0';

    // Variaveis de controle //

    while(selecao != '6'){

        // MENU //
        cout << endl << "Escolha uma opcao:" << endl;
        cout << "1 - Criar processo" << endl;
        cout << "2 - Executar proximo" << endl;
        cout << "3 - Executar processo especifico" << endl;
        cout << "4 - Salvar a fila de processos" << endl;
        cout << "5 - Carregar do arquivo a fila de processos" << endl;
        cout << "6 - Sair" << endl;
        cout << endl << " >> ";
        cin >> selecao;

        if (selecao < '1' || selecao > '6'){
            cout << "Opcao invalida." << endl;
        }

        // FUNCIONALIDADES //

        switch(selecao){
            case '1':
                system.newProcess();
                break;

            case '2':
                system.executeNext();
                break;

            case '3':
                system.executeSpecific();
                break;
        
            case '4':
                system.saveProcesses();
                break;

            case '5':
                system.loadProcesses();
                break;

            case '6':
                cout << "Fim do programa." << endl;
                break;
        }
    }

    return 0;
}