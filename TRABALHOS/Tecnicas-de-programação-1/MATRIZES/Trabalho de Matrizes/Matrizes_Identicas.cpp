#include <stdio.h>

int main(void)
{
	int A[20][20],B[20][20],C[20][20]; // matrizes
	int i,j;  // contadores
	int l,c; // linha e coluna
	
	int l2,c2;
	
	bool aux; 
	
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
	
	printf("Informe o numero de linhas e colunas da MATRIZ B: "); // obtencao dos dados de entrada 
	scanf("%d%d",&l2,&c2); // leitura dos dados de entrada 
		
	printf("\nDigite os valores da Matriz B linha por Linha:\n");	
	for(i = 0 ; i < l2 ; i++)
	{
		for(j = 0 ; j < c2 ; j++)
		{
			scanf("%d",&B[i][j]); //leitura da matriz B
		}
	}
	
	
	
	if(l != l2 || c != c2)
	{
		printf("\nAS MATRIZES DEVEM TER MESMAS DIMENSOES PARA SEREM IDENTICAS. PORTANTO ESTAS MATRIZES NAO SAO IDENTICAS!\n");
	}
 	else
 	{
 		aux = true;
 		
 		for(i = 0 ; i < l ; i++) 
		{
			for(j = 0 ; j < c && A[i][j] == B [i][j] ; j++);
			
			if(j < c)
			{
				i = l;
				aux = false;
			}
		}
		
		printf(aux == true?"\n=> As matrizes sao Identicas!\n":"\n=> As matrizes NAO sao Identicas!\n");

 		
	}
	
}
