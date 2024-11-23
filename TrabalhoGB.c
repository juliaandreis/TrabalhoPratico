#include <stdio.h>
#include <string.h>

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
    char unidade[2]; // como saber se eh gramas ou mililitros sem uma variável???? a sora n colocou no doc,
} Ingrediente;       // mas acho que precisa ne??

typedef struct {
    char nome[30];
    int ingredientes[7];
    int quantidades[7];
    char unidade[2];
} Pocao;

Ingrediente inicializarIngredientes(char nome[], int quantidade, char unidade[])
{
    Ingrediente x;
    strcpy(x.nome, nome);
    x.quantidade = quantidade;
    strcpy(x.unidade, unidade);
    return x;
}

Pocao inicializarPocao(char nome[], int ingredientes[], int quantidades[], char unidade[], int tamanho)
{
    Pocao x;
    strcpy(x.nome, nome);
    for (int i = 0; i < tamanho; i++) {
        x.ingredientes[i] = ingredientes[i];
        x.quantidades[i] = quantidades[i];
    }
    return x;
}

// opção 1 - Consultar ingredientes
void mostrarIngredientes(Ingrediente estoque[])
{
    printf("\nIngredientes Disponíveis:\n");
    for (int i = 0; i < 7; i++) 
    {
        printf("%d. %s: %d %s\n", i+1, estoque[i].nome, estoque[i].quantidade, estoque[i].unidade);
    }
}

//opção 2

//opção 3
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


int main()
{
    Ingrediente estoque[7];
    Pocao receitas[5];

    estoque[0] = inicializarIngredientes("Pó de Fênix", 100, "g");
    estoque[1] = inicializarIngredientes("Essência Celestial", 50, "ml");
    estoque[2] = inicializarIngredientes("Raiz de Dragão", 45, "g");
    estoque[3] = inicializarIngredientes("Orvalho Lunar", 30, "ml");
    estoque[4] = inicializarIngredientes("Flores secas", 200, "g");
    estoque[5] = inicializarIngredientes("Elixir amargo", 20, "ml");
    estoque[6] = inicializarIngredientes("Lágrimas de unicórnio", 15, "ml");

    int ingredientes0[4] = {0, 1, 4, 6}; 
    int quantidades0[4] = {15, 20, 20, 10};
    char unidade0[4][2] = {estoque[0].unidade, estoque[1].unidade, estoque[2].unidade, estoque[4].unidade};
    receitas[0] = inicializarPocao("Lágrimas de unicórnio", ingredientes0, quantidades0, unidade0, 4);

    int ingredientes1[3] = {3, 2, 4}; 
    int quantidades1[3] = {20, 30, 30};
    char unidade1[3][2] = {estoque[3].unidade, estoque[2].unidade, estoque[4].unidade};
    receitas[1] = inicializarPocao("Poção Força da Floresta", ingredientes1, quantidades1, unidade1, 3);

    int ingredientes2[2] = {2, 1}; 
    int quantidades2[2] = {30, 50};
    char unidade2[2][2] = {estoque[2].unidade, estoque[1].unidade};
    receitas[2] = inicializarPocao("Poção Sabedoria da Riqueza", ingredientes2, quantidades2, unidade2, 2);

    int ingredientes3[3] = {3, 4, 6}; 
    int quantidades3[3] = {10, 50, 5};
    char unidade3[3][2] = {estoque[3].unidade, estoque[4].unidade, estoque[6].unidade};
    receitas[3] = inicializarPocao("Poção Sorte no Amor", ingredientes3, quantidades3, unidade3, 3);

    int ingredientes4[2] = {5, 2}; 
    int quantidades4[2] = {10, 15};
    char unidade4[2][2] = {estoque[5].unidade, estoque[2].unidade};
    receitas[4] = inicializarPocao("Poção Malvada", ingredientes4, quantidades4, unidade4, 2);

    char escolha;

    do {        
        escolha = menuPrincipal();

        switch (escolha) {
            case '1':
                mostrarIngredientes(estoque);
                break;
            case '2':
                opcao2();
                break;
            case '3':
                opcao3(); 
                break;
            case '4':
                sair(); 
                break;
        }

    } while (escolha != '4'); 

    return 0; 
}