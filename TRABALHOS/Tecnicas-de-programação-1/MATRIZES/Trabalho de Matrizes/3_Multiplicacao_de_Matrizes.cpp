#include <stdio.h>

int main(void)
{
	int A[20][20],B[20][20],C[20][20];
	int i,j,k,l1,c1,l2,c2;
	
	printf("Informe o numero de linhas e colunas da MATRIZ A: "); // obtencao dos dados de entrada 
	scanf("%d%d",&l1,&c1); // leitura dos dados de entrada 
	l2 = c1;  
	
	for(i = 0 ; i < l1 ; i++) 
	{
		for(j = 0 ; j < c1 ; j++)
		{
			scanf("%d",&A[i][j]);// leitura da matriz A
		}
	}
	printf("\n\nPara que seja possivel multiplicas as matrizes o numero de Colunas da matriz A deve ser igual ao numero de Linhas da Matriz B!\n\n");	
	printf("Muito bem. Agora informe o numero de colunas da MATRIZ B: ");
	scanf("%d",&c2);
	
	for(i = 0 ; i < l2 ; i++)
	{
		for(j = 0 ; j < c2 ; j++)
		{
			scanf("%d",&B[i][j]); //leitura da matriz B
		}
	}
// AQUI E FEITA A MULTIOPLICACAO DAS MATRIZES 	
	for(i = 0 ; i < l1 ; i++)//fixa a quantidade de linha que a nova matriz tera (qntd de linhas da matriz 'A')
	{
		for(j = 0 ; j < c2 ; j++) //fixa a quantidade de colunas q a nova matriz tera (qntd de colunas da matriz 'B')
		{
			C[i][j] = 0; 
			
			for(k = 0 ; k < l1 ; k++) // e feita a multiplicacao dos termos correspondentes , somadas e atribuido o valor ao elemento da Matriz'C' Correspondente
			{
				C[i][j] += A[i][k] * B[k][j]; 
			}
		}
	}
	
	printf("\n\nMatriz C = Matriz A * Matriz B\n\n"); // exibicao da matriz resultante entre a multiplicacao de matrizes 
	for(i = 0 ; i < l2 ; i++)
	{
		for(j = 0 ; j < c2 ; j++)
		{
			printf("\t%d",C[i][j]); 
		}
		printf("\n");
	}
	
		
}
