#include <stdio.h>

int main(void)
{
	int A[20][20]; // matrizes
	int i,j;  // contadores
	int l,c; // linha e coluna
	bool aux; // auiliadora

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
	
	
	
	if(l != c)
	{
		printf("\nSO EXISTEM MATRIZES QUADRADAS DESTE TIPO. PORTANTO NAO E POSSIVEL FAZER ESTA ANALISE!\n");
	}
	else
	{
		/*Analise se a matriz e ou nao ANTIsimietrica*/
		aux = true;
		for(i = 1 ; i < l && A[i][i] == 0 ; i++) // a condicao deste for verifica se a diagonal principal e nula 
		{										// se algum termo nao for igual a  zero, o laço e parado e 'i' sera menor q 'l'	, .: entra no if fora dos 2 'for'	
			for( j = 0 ; j < i && A[i][j] == -1* A[j][i]; j++);
			
			if(i != j)
			{
				i = l;
				aux = false;
			}		
		}
		if(i < l) // if fora dos 2'for' 
		{
			aux = false;
		}
		
		printf(aux == true ? "\n=> A matriz eh Simetrica!\n":"\n=> A matriz NAO eh Simetrica!\n");
		
	}
	
}
