#include <stdio.h>
#include <string.h>

void opcao1(Ingrediente estoque[])
{
    printf("Consultar Ingredientes Disponíveis:\n");
    
}

void opcao2()
{
    printf("Preparar Poção:\n");
}

void opcao3()
{
    printf("Reabastecer Ingrediente:\n");
}

void sair()
{
    printf("Saindo do programa.\n");
}

char menuPrincipal()
{
    char opcao;

    do {
        printf("\nMenu Principal:\n");
        printf("1 - Opção 1\n");
        printf("2 - Opção 2\n");
        printf("3 - Opção 3\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção (1-4): ");
        
        
        scanf(" %c", &opcao);


        if (opcao < '1' || opcao > '4') {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao < '1' || opcao > '4');  

    return opcao;
}

typedef struct {
    char nome[30];
    int quantidade;
} Ingrediente;

typedef struct {
    char nome[30];
    int ingredientes[7];
    int quantidades[7];
} Pocao;

Ingrediente inicializarIngredientes(char nome[], int quantidade)
{
    Ingrediente x;
    strcpy(x.nome, nome);
    x.quantidade = quantidade;
}

Pocao inicializarPocao(char nome[], int ingredientes[], int quantidades[])
{
    Pocao x;
    strcpy(x.nome, nome);
    for (int i = 0; i < 4) // FAZER DE UM JEITO QUE VÁ SÓ ATE A QUANTIDADE MAX DE INGREDIENTES!!!!!!!
    {
        x.ingredientes[0] = ingredientes; // MEU RACIOCINIO TAVA ERRADO EU TAVA PENSANDO QUE AQUI ERA PRA SER CHAR
    } // MAS A SORA PEDIU INT. COMO FAZER PRA DEPOIS APARECER O NOME DE CADA INGREDIENTE??????? COMO SERIA P FAZER
    x.ingredientes[0] = ingredientes; // UMA FUNÇAO QUE PREENCHE ARRAYS.. VAI NA ORDEM TIPO PRIMEIRO DIGITA TODOS
    x.quantidades[] = quantidades; // DO PRIMEIRO ARRAY E DPS TODOS DO SEGUNDO ARRAY??????????
}

int main()
{
    Ingrediente estoque[7];
    Pocao receitas[5];

    estoque[0] = inicializarIngredientes("Pó de Fênix", 100);
    estoque[1] = inicializarIngredientes("Essência Celestial", 50);
    estoque[2] = inicializarIngredientes("Raiz de Dragão", 45);
    estoque[3] = inicializarIngredientes("Orvalho Lunar", 30);
    estoque[4] = inicializarIngredientes("Flores secas", 200);
    estoque[5] = inicializarIngredientes("Elixir amargo", 20);
    estoque[6] = inicializarIngredientes("Lágrimas de unicórnio", 15);

    strcpy(receitas[0].nome, "Lágrimas de unicórnio");
    strcpy(receitas[0].ingredientes[0], "Pó de Fênix");
    receitas[0].quantidades[0] = 15;
    strcpy(receitas[0].ingredientes[0], "Essência Celestial");
    receitas[0].quantidades[0] = 20;
    strcpy(receitas[0].ingredientes[0], "Flores secas");
    receitas[0].quantidades[0] = 20;
    strcpy(receitas[0].ingredientes[0], "Lágrimas de unicórnio");
    receitas[0].quantidades[0] = 10;

    strcpy(receitas[0].nome, " Poção Força da Floresta");
    strcpy(receitas[0].ingredientes[0], "Orvalho Lunar");
    receitas[0].quantidades[0] = 20;
    strcpy(receitas[0].ingredientes[0], "Raiz de Dragão");
    receitas[0].quantidades[0] = 30;
    strcpy(receitas[0].ingredientes[0], "Flores secas");
    receitas[0].quantidades[0] = 30;

    strcpy(receitas[0].nome, "Poção Sabedoria da Riqueza");
    strcpy(receitas[0].ingredientes[0], "Essência Celestial ");
    receitas[0].quantidades[0] = 30;
    strcpy(receitas[0].ingredientes[0], " Pó de Fênix");

    strcpy(receitas[0].nome, "Poção Sorte no Amor");
    strcpy(receitas[0].ingredientes[0], "Orvalho Lunar");
    receitas[0].quantidades[0] = 10;
    strcpy(receitas[0].ingredientes[0], "Flores secas");
    receitas[0].quantidades[0] = 50;
    strcpy(receitas[0].ingredientes[0], "Lágrimas de unicórnio");
    receitas[0].quantidades[0] = 5;

    strcpy(receitas[0].nome, "Poção Malvada");
    strcpy(receitas[0].ingredientes[0], "Elixir amargo");
    receitas[0].quantidades[0] = 10;
    strcpy(receitas[0].ingredientes[0], "Raiz de Dragão");
    receitas[0].quantidades[0] = 15;

    char escolha;

    do {        
        escolha = menuPrincipal();

        switch (escolha) {
            case '1':
                opcao1();
                break;
            case '2':
                opcao2();
                break;
            case '3':
                opcao3(); 
                break;
            case '4':
                opcao4(); 
                break;
            case '5':
                sair(); 
                break;
        }

    } while (escolha != '4'); 

    return 0; 
}