/*O programa faz uma simulação de crescimento bacteriano, levando em consideracao possiveis intemperies.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int menu,taxa,ciclo,populacaoFinal,populacaoInicial;
	int cont = 1;
	int sorteio = 0;

	printf("Bem vindo ao programa de simulacao de crescimento bacteriano!\n");
	printf("\n");

	do
	{
		printf("1 - Nova simulacao\n");
		printf("2 - Sair do programa\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &menu);
		printf("\n");

		if (menu != 1 && menu != 2)
		{
			printf("Opcao invalida. Tente novamente.\n");
		}
		else if (menu == 1)
		{
			printf("Digite a populacao inicial: ");
			scanf("%d", &populacaoInicial);
			printf("Digite a taxa de crescimento: ");
			scanf("%d", &taxa);
			printf("Digite a quantidade de ciclos: ");
			scanf("%d", &ciclo);
			
			printf("\n");
			cont = 1;

			while (cont <= ciclo)
			{
				populacaoFinal = populacaoInicial + (populacaoInicial * taxa / 100);
				sorteio = 1 + rand () % 100;
				
				if (sorteio <= 20)
				{
					populacaoFinal = (float)populacaoFinal * 0.7;
					printf("Ciclo %d = %d (condição adversa: alta temperatura)\n",cont,populacaoFinal);
				}
				else if (sorteio <= 35)
				{
					populacaoFinal = (float)populacaoFinal * 0.75;
					printf("Ciclo %d = %d (condição adversa: falta de nutrientes)\n",cont,populacaoFinal);
				}
				else if (sorteio <= 45)
				{
					populacaoFinal = (float)populacaoFinal * 0.8;
					printf("Ciclo %d = %d (condição adversa: excesso de umidade)\n",cont,populacaoFinal);

				}
				else if (sorteio <= 50)
				{
					populacaoFinal = (float)populacaoFinal * 0.5;
					printf("Ciclo %d = %d (condição adversa: radiacao ultravioleta)\n",cont,populacaoFinal);
				}
				else if (sorteio <= 60)
				{
					populacaoFinal = (float)populacaoFinal * 1.2;
					printf("Ciclo %d = %d (condicao favoravel)\n",cont,populacaoFinal);
				}
				else
				{
					printf("Ciclo %d = %d\n",cont,populacaoFinal);
				}

				sorteio = 0;
				populacaoInicial = populacaoFinal;
				cont++;
			}
			printf("\n");
			printf("Simulacao concluida. Populacao final: %d\n", populacaoFinal);
		}
		printf("\n");

	} while (menu != 2);
	
	printf("Programa encerrado.");

	return 0;
}
