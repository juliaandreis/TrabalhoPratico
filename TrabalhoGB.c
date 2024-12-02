// INCLUDE C TOOLS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// DEFINE

#define QUANT_ESTOQUE 7
#define QUANT_RECEITAS 5

// STRUCTS

typedef struct
{
    char nome[30];
    int quantidade;
    char unidade[3];
} Ingrediente;

typedef struct
{
    char nome[30];
    int ingredientes[QUANT_ESTOQUE];
    int quantidades[QUANT_ESTOQUE];
    char unidades[QUANT_ESTOQUE][3];
} Pocao;


// FUNCOES

char menuPrincipal(void);

Ingrediente inicializarIngredientes(char nome[], int quantidade, char unidade[]);

Pocao inicializarPocao(char nome[], int ingredientes[], int quantidades[], char unidades[][3], int tamanho);

void mostrarIngredientes(Ingrediente estoque[]);

int selecionarReceita(Pocao receita[]);

void fazerReceita(int numPocao, Ingrediente estoque[], Pocao receitas[]);

void reabastecerIngredientes(Ingrediente estoque[]);


// MAIN

int main()
{
    Ingrediente estoque[QUANT_ESTOQUE];
    Pocao receitas[QUANT_RECEITAS];

    estoque[0] = inicializarIngredientes("Po de Fenix", 100, "g");
    estoque[1] = inicializarIngredientes("Essencia Celestial", 50, "ml");
    estoque[2] = inicializarIngredientes("Raiz de Dragao", 45, "g");
    estoque[3] = inicializarIngredientes("Orvalho Lunar", 30, "ml");
    estoque[4] = inicializarIngredientes("Flores secas", 200, "g");
    estoque[5] = inicializarIngredientes("Elixir amargo", 20, "ml");
    estoque[6] = inicializarIngredientes("Lagrimas de unicornio", 15, "ml");

    int ingredientes0[] = {0, 1, 4, 6}; 
    int quantidades0[] = {30, 20, 20, 10};
    char unidades0[][3] = {"g","ml","g","ml"};
    receitas[0] = inicializarPocao("Pocao de Cura", ingredientes0, quantidades0, unidades0, 4);

    int ingredientes1[] = {3, 2, 4}; 
    int quantidades1[] = {20, 30, 30};
    char unidades1[][3] = {"ml", "g", "g"};
    receitas[1] = inicializarPocao("Pocao Força da Floresta", ingredientes1, quantidades1, unidades1, 3);

    int ingredientes2[] = {2, 1}; 
    int quantidades2[] = {30, 50};
    char unidades2[][3] = {"g", "ml"};
    receitas[2] = inicializarPocao("Pocao Sabedoria da Riqueza", ingredientes2, quantidades2, unidades2, 2);

    int ingredientes3[] = {3, 4, 6}; 
    int quantidades3[] = {10, 50, 5};
    char unidades3[][3] = {"ml", "g", "ml"};
    receitas[3] = inicializarPocao("Pocao Sorte no Amor", ingredientes3, quantidades3, unidades3, 3);

    int ingredientes4[] = {5, 2}; 
    int quantidades4[] = {10, 15};
    char unidades4[][3] = {"ml", "g"};
    receitas[4] = inicializarPocao("Pocao Malvada", ingredientes4, quantidades4, unidades4, 2);

    char escolha;

    do {        
        escolha = menuPrincipal();

        switch (escolha) {
            case '1':
                mostrarIngredientes(estoque);
                break;
            case '2':
                int numReceita = selecionarReceita(receitas);
                fazerReceita(numReceita, estoque, receitas);
                break;
            case '3':
                reabastecerIngredientes(estoque); 
                break;
            case '4':
                printf(" Saindo do programa.\n"); 
                break;
            default:
                printf("\n Valor invalido.");
        }

    } while (escolha != '4'); 

    return 0; 
}


char menuPrincipal(void)
{
    char opcao;

    do 
    {
        printf("\n Menu Principal:\n");
        printf(" Opcao 1 - Consultar Ingredientes Disponiveis\n");
        printf(" Opcao 2 - Preparar Pocao\n");
        printf(" Opcao 3 - Reabastecer Ingrediente\n");
        printf(" Opcao 4 - Sair do Programa\n");
        printf("\n Escolha uma opcao (1-4): ");
        
        scanf(" %c", &opcao);

        if (opcao < '1' || opcao > '4')
        {
            printf(" Opcao invalida. Tente novamente.\n");
        }
    } while (opcao < '1' || opcao > '4');

    return opcao;
}


Ingrediente inicializarIngredientes(char nome[], int quantidade, char unidade[])
{
    Ingrediente x;
    strcpy(x.nome, nome);
    x.quantidade = quantidade;
    strcpy(x.unidade, unidade);
    return x;
}


Pocao inicializarPocao(char nome[], int ingredientes[], int quantidades[], char unidades[][3], int tamanho)
{
    Pocao x;
    strcpy(x.nome, nome);
    for (int i = 0; i < tamanho; i++) {
        x.ingredientes[i] = ingredientes[i];
        x.quantidades[i] = quantidades[i];
        strcpy(x.unidades[i], unidades[i]);
    }
    return x;
}


// opção 1 - Consultar ingredientes
void mostrarIngredientes(Ingrediente estoque[])
{
    printf("\n Ingredientes Disponiveis:\n");
    for (int i = 0; i < QUANT_ESTOQUE; i++) 
    {
        printf("%d. %s: %d %s\n", i+1, estoque[i].nome, estoque[i].quantidade, estoque[i].unidade);
    }
}


//opção 2 - Preparar poção
int selecionarReceita(Pocao receita[])
{
    int numPocao;
    do
    {    
        printf("\n Receitas Disponiveis: \n");
        for (int i = 0; i < QUANT_RECEITAS; i++) 
        {
            printf("%d. %s\n", i+1, receita[i].nome);
        }

        printf(" Escolha a pocao que deseja preparar (1-%d): ", QUANT_RECEITAS);
        scanf(" %d", &numPocao);

        if (numPocao < 1 || numPocao > QUANT_RECEITAS) 
        {
            printf("\n Opcao invalida. Tente novamente.\n");
        }
    } while (numPocao < 1 || numPocao > QUANT_RECEITAS); 

    return numPocao;
}


void fazerReceita(int numPocao, Ingrediente estoque[], Pocao receitas[])
{
    bool comparacao = true;
    if (numPocao == 1) 
    {
        for(int i = 0; i < 4; i++)
        {
            if(receitas[0].quantidades[i] > estoque[receitas[0].ingredientes[i]].quantidade)
            {
                comparacao = false;
            }
        }    

        if (comparacao)
        {
            printf("\nPoção criada com sucesso!\n");
            printf("Estoque atualizado:\n");
            for(int i = 0; i < 4; i++)
            {
                estoque[receitas[0].ingredientes[i]].quantidade = estoque[receitas[0].ingredientes[i]].quantidade - receitas[0].quantidades[i];
                printf("%d. %s: %d %s\n", i+1, estoque[receitas[0].ingredientes[i]].nome, estoque[receitas[0].ingredientes[i]].quantidade, receitas[0].unidades[i]);
            }
        }
        else
        {
            printf("Não foi possível preparar a poção. Ingredientes em falta:\n");
            int n = 1;
            for(int i = 0; i < 4; i++)
            {
                if(receitas[0].quantidades[i] > estoque[receitas[0].ingredientes[i]].quantidade)
                {
                    printf("%d. %s: necessário %d %s, disponível %d %s.\n", n,  estoque[receitas[0].ingredientes[i]].nome, receitas[0].quantidades[i], receitas[0].unidades[i], estoque[receitas[0].ingredientes[i]].quantidade, receitas[0].unidades[i]);
                    n++;
                }
            }  
        }
    }        
    else if (numPocao == 2) 
    {
        for(int i = 0; i < 3; i++)
        {
            if(receitas[0].quantidades[i] > estoque[receitas[0].ingredientes[i]].quantidade)
            {
                comparacao = false;
            }
        }    

        if (comparacao)
        {
            printf("\nPoção criada com sucesso!\n");
            printf("Estoque atualizado:\n");
            for(int i = 0; i < 3; i++)
            {
                estoque[receitas[0].ingredientes[i]].quantidade = estoque[receitas[0].ingredientes[i]].quantidade - receitas[0].quantidades[i];
                printf("%d. %s: %d %s\n", i+1, estoque[receitas[0].ingredientes[i]].nome, estoque[receitas[0].ingredientes[i]].quantidade, receitas[0].unidades[i]);
            }
        }
        else
        {
            printf("Não foi possível preparar a poção. Ingredientes em falta:\n");
            int n = 1;
            for(int i = 0; i < 3; i++)
            {
                if(receitas[0].quantidades[i] > estoque[receitas[0].ingredientes[i]].quantidade)
                {
                    printf("%d. %s: necessário %d %s, disponível %d %s.\n", n,  estoque[receitas[0].ingredientes[i]].nome, receitas[0].quantidades[i], receitas[0].unidades[i], estoque[receitas[0].ingredientes[i]].quantidade, receitas[0].unidades[i]);
                    n++;
                }
            }  
        }
    }
    else if (numPocao == 3)
    {
        for(int i = 0; i < 2; i++)
        {
            if(receitas[0].quantidades[i] > estoque[receitas[0].ingredientes[i]].quantidade)
            {
                comparacao = false;
            }
        }    

        if (comparacao)
        {
            printf("\nPoção criada com sucesso!\n");
            printf("Estoque atualizado:\n");
            for(int i = 0; i < 2; i++)
            {
                estoque[receitas[0].ingredientes[i]].quantidade = estoque[receitas[0].ingredientes[i]].quantidade - receitas[0].quantidades[i];
                printf("%d. %s: %d %s\n", i+1, estoque[receitas[0].ingredientes[i]].nome, estoque[receitas[0].ingredientes[i]].quantidade, receitas[0].unidades[i]);
            }
        }
        else
        {
            printf("Não foi possível preparar a poção. Ingredientes em falta:\n");
            int n = 1;
            for(int i = 0; i < 2; i++)
            {
                if(receitas[0].quantidades[i] > estoque[receitas[0].ingredientes[i]].quantidade)
                {
                    printf("%d. %s: necessário %d %s, disponível %d %s.\n", n,  estoque[receitas[0].ingredientes[i]].nome, receitas[0].quantidades[i], receitas[0].unidades[i], estoque[receitas[0].ingredientes[i]].quantidade, receitas[0].unidades[i]);
                    n++;
                }
            }  
        }
    }
    else if (numPocao == 4)
    {
        for(int i = 0; i < 3; i++)
        {
            if(receitas[0].quantidades[i] > estoque[receitas[0].ingredientes[i]].quantidade)
            {
                comparacao = false;
            }
        }    

        if (comparacao)
        {
            printf("\nPoção criada com sucesso!\n");
            printf("Estoque atualizado:\n");
            for(int i = 0; i < 3; i++)
            {
                estoque[receitas[0].ingredientes[i]].quantidade = estoque[receitas[0].ingredientes[i]].quantidade - receitas[0].quantidades[i];
                printf("%d. %s: %d %s\n", i+1, estoque[receitas[0].ingredientes[i]].nome, estoque[receitas[0].ingredientes[i]].quantidade, receitas[0].unidades[i]);
            }
        }
        else
        {
            printf("Não foi possível preparar a poção. Ingredientes em falta:\n");
            int n = 1;
            for(int i = 0; i < 3; i++)
            {
                if(receitas[0].quantidades[i] > estoque[receitas[0].ingredientes[i]].quantidade)
                {
                    printf("%d. %s: necessário %d %s, disponível %d %s.\n", n,  estoque[receitas[0].ingredientes[i]].nome, receitas[0].quantidades[i], receitas[0].unidades[i], estoque[receitas[0].ingredientes[i]].quantidade, receitas[0].unidades[i]);
                    n++;
                }
            }  
        }
    }
    else
    {
        bool comparacao = true;
        for(int i = 0; i < 2; i++)
        {
            if(receitas[0].quantidades[i] > estoque[receitas[0].ingredientes[i]].quantidade)
            {
                comparacao = false;
            }
        }    

        if (comparacao)
        {
            printf("\nPoção criada com sucesso!\n");
            printf("Estoque atualizado:\n");
            for(int i = 0; i < 2; i++)
            {
                estoque[receitas[0].ingredientes[i]].quantidade = estoque[receitas[0].ingredientes[i]].quantidade - receitas[0].quantidades[i];
                printf("%d. %s: %d %s\n", i+1, estoque[receitas[0].ingredientes[i]].nome, estoque[receitas[0].ingredientes[i]].quantidade, receitas[0].unidades[i]);
            }
        }
        else
        {
            printf("Não foi possível preparar a poção. Ingredientes em falta:\n");
            int n = 1;
            for(int i = 0; i < 2; i++)
            {
                if(receitas[0].quantidades[i] > estoque[receitas[0].ingredientes[i]].quantidade)
                {
                    printf("%d. %s: necessário %d %s, disponível %d %s.\n", n,  estoque[receitas[0].ingredientes[i]].nome, receitas[0].quantidades[i], receitas[0].unidades[i], estoque[receitas[0].ingredientes[i]].quantidade, receitas[0].unidades[i]);
                    n++;
                }
            }  
        }
    }   
}


//opção 3 - Reabastecer ingredientes
void reabastecerIngredientes(Ingrediente estoque[])
{
    int ingrediente, quantReabastecida;
    mostrarIngredientes(estoque);
    printf("\n Selecione o ingrediente que deseja reabastecer: ");
    scanf("%d", &ingrediente);
    ingrediente--;
    if(ingrediente < 0 || ingrediente > QUANT_ESTOQUE-1)
    {
        printf("\n Item nao identificado. Voltando ao menu...\n");
    }
    else
    {
        printf("\n Digite o valor a ser adicionado ao estoque: ");
        scanf("%d",&quantReabastecida);
        printf("\n Novo valor em estoque: ");
        printf("%d. %s: %d %s -->> %d %s\n", ingrediente, estoque[ingrediente].nome, estoque[ingrediente].quantidade, estoque[ingrediente].unidade, estoque[ingrediente].quantidade+quantReabastecida, estoque[ingrediente].unidade);
        estoque[ingrediente].quantidade += quantReabastecida;
    }
}
