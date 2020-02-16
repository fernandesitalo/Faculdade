#include <stdio.h>

int main(void)
{
	int A[20][20],At[20][20];
	int i,j,l,c;
	
	printf("Informe o numero de linhas e colunas da MATRIZ A: "); // obtencao dos dados de entrada 
	scanf("%d%d",&l,&c); // leitura dos dados de entrada 
		
	for(i = 0 ; i < l ; i++) 
	{
		for(j = 0 ; j < c ; j++)
		{
			scanf("%d",&A[i][j]);// leitura da matriz A
		}
	}

	
	/*CALCULO MATRIZ TRANSPOSTA*/
	for(i = 0 ; i < c ; i++) // fixa-se o numero de colunas
	{
		for(j = 0 ; j < l ; j++) // varia o numero de linha
		{
			At[i][j] = A[j][i];
		}
	}
	
	printf("znMatriz Transposta\n");
	for(i = 0 ; i < c ; i++) // numero de linhas passa a ser o numero de colunas - principio matriz transposta
	{
		for(j = 0 ; j < l ; j++) //numero de colunas passa a ser o numero de linhas - principio  da matrtiz transposta
		{
			printf("\t%d",At[i][j]);
		}
		printf("\n\n");
	}
}
	
