#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    } while (opcao < '1' || opcao > '4');  // aqui não é && ???? (copiei o menu da sora)

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
    char unidades[7][3];
} Pocao;

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
    printf("\nIngredientes Disponíveis:\n");
    for (int i = 0; i < 7; i++) 
    {
        printf("%d. %s: %d %s\n", i+1, estoque[i].nome, estoque[i].quantidade, estoque[i].unidade);
    }
}

//opção 2 - Preparar poção
char selecionarReceita(Pocao receita[])
{
    char numPocao;
    do
    {    
        printf("\nReceitas Disponíveis:\n");
        for (int i = 0; i < 5; i++) 
        {
            printf("%d. %s\n", i+1, receita[i].nome);
        }

        printf("Escolha a poção que deseja preparar (1-5): ");
        scanf(" %c", &numPocao);

        if (numPocao < '1' || numPocao > '5') 
        {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (numPocao < '1' && numPocao > '5'); 

    return numPocao;
}

void fazerReceita(char numPocao, Ingrediente estoque[], Pocao receitas[])
{
    if (numPocao == '1') 
    {
        bool comparacao = true;
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
    else if (numPocao == '2') 
    {
        bool comparacao = true;
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
    else if (numPocao == '3')
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
    else if (numPocao == '4')
    {
        bool comparacao = true;
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

void ingedientesReceita(int x)
{

}

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
    int quantidades0[4] = {30, 20, 20, 10};
    char unidades0[4][3] = {"g","ml","g", "ml"};
    receitas[0] = inicializarPocao("Poção de Cura", ingredientes0, quantidades0, unidades0, 4);

    int ingredientes1[3] = {3, 2, 4}; 
    int quantidades1[3] = {20, 30, 30};
    char unidades1[3][3] = {"ml", "g", "g"};
    receitas[1] = inicializarPocao("Poção Força da Floresta", ingredientes1, quantidades1, unidades1, 3);

    int ingredientes2[2] = {2, 1}; 
    int quantidades2[2] = {30, 50};
    char unidades2[2][3] = {"g", "ml"};
    receitas[2] = inicializarPocao("Poção Sabedoria da Riqueza", ingredientes2, quantidades2, unidades2, 2);

    int ingredientes3[3] = {3, 4, 6}; 
    int quantidades3[3] = {10, 50, 5};
    char unidades3[3][3] = {"ml", "g", "ml"};
    receitas[3] = inicializarPocao("Poção Sorte no Amor", ingredientes3, quantidades3, unidades3, 3);

    int ingredientes4[2] = {5, 2}; 
    int quantidades4[2] = {10, 15};
    char unidades4[2][3] = {"ml", "g"};
    receitas[4] = inicializarPocao("Poção Malvada", ingredientes4, quantidades4, unidades4, 2);

    char escolha;

    do {        
        escolha = menuPrincipal();

        switch (escolha) {
            case '1':
                mostrarIngredientes(estoque);
                break;
            case '2':
                char numReceita = selecionarReceita(receitas);
                fazerReceita(numReceita, estoque, receitas);
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