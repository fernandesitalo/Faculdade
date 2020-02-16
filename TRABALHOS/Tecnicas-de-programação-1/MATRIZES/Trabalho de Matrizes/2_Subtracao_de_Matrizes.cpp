#include <stdio.h>
int main(void)
{
	int A[20][20],B[20][20],C[20][20]; // matrizes
	int i,j;  // contadores
	int l,c; // linha e coluna

	printf("Informe o numero de linhas e colunas da MATRIZ A: "); // obtencao dos dados de entrada 
	scanf("%d%d",&l,&c); // leitura dos dados de entrada 
	
	printf("\nDigite os valores das matrizes linha por linha: \n");	
	for(i = 0 ; i < l ; i++)  // fixa o numero de linhas
	{
		for(j = 0 ; j < c ; j++) // fixa o numero de colunas
		{
			scanf("%d",&A[i][j]);// leitura da matriz A linha por linha por foi fixado o numero de linhas  !!!!
		}
	}
	
	//AQUI  Tira a possibilidade do usuario errar , colocando uma matriz com o numero de linhas e colunas diferentes 
	printf("\nAs matrizes Devem ter Mesmas Dimensoes para que seja Possivel Subtrai-las!\n\n");	
	printf("Portanto, MATRIZ B tambem tera %d Linhas e %d Colunas\n\n",l,c);
	
	printf("\nDigite os valores da Matriz B, linha por Linha:\n");	
	for(i = 0 ; i < l ; i++)
	{
		for(j = 0 ; j < c ; j++)
		{
			scanf("%d",&B[i][j]); //leitura da matriz B
		}
	}
	
// AQUI E FEITA A SUBTRAÇÃO DAS MATRIZES 	
	for(i = 0 ; i < l ; i++) 
	{
		for(j = 0 ; j < c ; j++) 
		{
			C[i][j] = A[i][j] - B[i][j];	// A soma de matrizes consiste na soma dos termos correspondentes , sendo as matrizes de Mesmos tamanhos
		}
	}
	
	printf("\n\nMatriz C = Matriz A - Matriz B\n\n"); // exibicao da matriz resultante entre a soma de matrizes 
	for(i = 0 ; i < l ; i++)
	{
		for(j = 0 ; j < c ; j++)
		{
			printf("\t%d",C[i][j]); 
		}
		printf("\n");
	}
	
	return 0;	
}
