#include <stdio.h>

int main(void)
{
	int A[20][20],P[20][20]; // matrizes
	int i,j;  // contadores
	int l,c; // linha e coluna
	int k; // auiliadora

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
	
	printf("Digite a Consta K , sendo K * Matriz A: ");
	scanf("%d",&k);
	
	for( i = 0 ; i < l ; i++ )
	{
		for( j = 0 ; j < c ; j++)
		{
			P[i][j] = A[i][j] * k;
		}
	}
	
	printf("\nProduto Matriz A * K\n");
	for( i = 0 ; i < l ; i++ )
	{
		for( j = 0 ; j < c ; j++)
		{
			printf("\t%d",P[i][j]);
		}
		printf("\n\n");
	}	
}
