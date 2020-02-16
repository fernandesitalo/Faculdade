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
			scanf("%d",&A[i][j]);// leitura da matriz A linha por linha por foi fixado o numero de linhas  !
		}
	}
	
	if(l != c)
	{
		printf("\nSO EXISTEM MATRIZES QUADRADAS DESTE TIPO. PORTANTO NAO E POSSIVEL FAZER ESTA ANALISE!\n");
	}
	else
	{	
		aux = true;	
		/*Determina se e ou nao uma mattriz triangular inferior*/
		for(i = 0 ; i < l ; i++) // fixa o numero de linhas
		{
			for(j = i+1 ; j < c && A[i][j] == 0 ; j++); 
			
			if(j != c)
			{
				i = l;
				aux = false;
			}		
		}	
		printf(aux == true ? "\n=> Eh uma Matriz Triangular Inferior!\n":"\n=> Nao eh uma Matriz Triangular Inferior!\n");
	}
}
