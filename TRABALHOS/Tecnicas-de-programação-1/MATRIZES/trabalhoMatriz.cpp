#include <stdio.h>
#include <stdlib.h>

void menu();

int main()
{
	int A[50][50],B[50][50],SOMA[50][50];
	int i,j;  
	int l1,l2;
	int c1,c2; 
	char opcao;

	printf("~BEM VINDO USUARIO!\n\n");	
	
	printf("Informe o numero de linhas e colunas da MATRIZ A: "); // obtencao dos dados de entrada 
	scanf(" %d%d",&l1,&c1); // leitura dos dados de entrada 

	printf("\nDigite os valores das matrizes linha por linha: \n");	
	for(i = 0 ; i < l1 ; i++)  // fixa o numero de linhas
	{
		for(j = 0 ; j < c1 ; j++) // fixa o numero de colunas
		{
			scanf("%d",&A[i][j]);// leitura da matriz A linha por linha por foi fixado o numero de linhas  !!!!
		}
	}
	
	printf("Informe o numero de linhas e colunas da MATRIZ B: "); // obtencao dos dados de entrada 
	scanf("%d",&l2); 
	scanf("%d",&c2); 

	printf("\nDigite os valores das matrizes linha por linha: \n");	
	for(i = 0 ; i < l2 ; i++)  // fixa o numero de linhas
	{
		for(j = 0 ; j < c2 ; j++) // fixa o numero de colunas
		{
			scanf("%d",&B[i][j]);// leitura da matriz A linha por linha por foi fixado o numero de linhas  !!!!
		}
	}
	do
	{
		system("pause");
		system("cls");
		
		menu();
		printf("\n>>OPCAO: ");
		scanf("%s",&opcao);		
		
		switch(opcao)
		{
			case 'a':// AQUI E FEITA A SOMA DAS MATRIZES 
			
			printf("l1: %d\n",l1);
			printf("l2: %d\n",l2);
			printf("c1: %d\n",c1);
			printf("c2: %d\n",c2);
			
				if( l1 == l2 && c1 == c2)
				{											
					for(i = 0 ; i < l1 ; i++) 
					{
						for(j = 0 ; j < c1 ; j++) 
						{
							SOMA[i][j] = A[i][j] + B[i][j];	// A soma de matrizes consiste na soma dos termos correspondentes , sendo as matrizes de Mesmos tamanhos
						}
					}
					
					printf("\n\nMatriz C = Matriz A + Matriz B\n\n"); // exibicao da matriz resultante entre a soma de matrizes 
					for(i = 0 ; i < l1 ; i++)
					{
						for(j = 0 ; j < c1 ; j++)
						{
							printf("\t%d",SOMA[i][j]); 
						}
						printf("\n");
					}
				}
				else
				{
					printf("\nNao eh possivel somar estas Matrizes. Elas possuem dimensoes diferentes!\n\n");
				}
				break;			
				
				
			case 'b':
				break;
				
			case 'c':
				break;
				
			case 'd':
				break;
				
			case 'e':
				break;
				
			case 'f':
				break;
				
			case 'g':
				break;
				
			case 'h':
				break;
				
			case 'i':
				break;
				
			case 'j':
				break;
				
			case 'k':
				break;
				
			case 'l':
				break;
				
			case 'm': // DIGITAR NOVAS MATRIZES
				printf("Informe o numero de linhas e colunas da MATRIZ A: "); // obtencao dos dados de entrada 
				scanf("%d%d",&l1,&c1); // leitura dos dados de entrada 
			
				printf("\nDigite os valores das matrizes linha por linha: \n");	
				for(i = 0 ; i < l1 ; i++)  // fixa o numero de linhas
				{
					for(j = 0 ; j < c1 ; j++) // fixa o numero de colunas
					{
						scanf("%d",&A[i][j]);// leitura da matriz A linha por linha por foi fixado o numero de linhas  !!!!
					}
				}
				
				printf("Informe o numero de linhas e colunas da MATRIZ B: "); // obtencao dos dados de entrada 
				scanf("%d%d",&l2,&c2); // leitura dos dados de entrada 
			
				printf("\nDigite os valores das matrizes linha por linha: \n");	
				for(i = 0 ; i < l2 ; i++)  // fixa o numero de linhas
				{
					for(j = 0 ; j < c2 ; j++) // fixa o numero de colunas
					{
						scanf("%d",&B[i][j]);// leitura da matriz A linha por linha por foi fixado o numero de linhas  !!!!
					}
				}			
				break;
				
			case 'n':
				printf("\n~Ate logo Querido Usuario!\n");
				break;
				
			default:
				printf("OPCAO INVALIDA. DIGITE NOVAMENTE . . .\n");		
		}
		
	}while(opcao != 'n');
	
	return 0;	
}

void menu()
{
	printf("\ta- SOMA\n");
	printf("\tb- SUBTRACAO\n");
	printf("\tc- MULTIPLICACAO\n");
	printf("\td- VERIFIQUE SE AS MATRIZES SAO TRIANGULARES SUPERIORES\n");
	printf("\te- VERIFIQUE SE AS MATRIZES SAO TRIANGULARES INFERIORES\n");
	printf("\tf- VERIFIQUE SE AS MATRIZES SAO SIMETRICAS\n");
	printf("\tg- VERIFIQUE SE AS MATRIZES SAO ANTI-SIMETRICAS\n");
	printf("\th- VERIFIQUE SE SAO MATRIZES IDENTIDADES\n");
	printf("\ti- MATRIZ TRANSPOSTA\n");
	printf("\tj- MULTIPLICAR A MATRIZ POR 'K'\n");
	printf("\tk- VERIFIQUE SE AS MATRIZES SAO IGUAIS\n");
	printf("\tl- VERIFIQUE SE AS MATRIZES SAO DIFERENTES\n");
	printf("\tm- DIGITE NOVAS MATRIZES\n");
	printf("\tn- SAIR\n");
}
