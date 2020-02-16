#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m,vetA[20],i,k,menor,aux;
	int n,vetB[20];
	
	int a,b,novo[40];


	printf("A : ");
	scanf("%d",&m);	
	for(i=0 ; i < m ; i++){
		scanf("%d",&vetA[i]);
	}
	

	printf("B :");
	scanf("%d",&n);	
	for(i=0 ; i < n ; i++){
		scanf("%d",&vetB[i]);
	}
	
	
	a=0;
	b=0;
	
	for(i = 0 ; a < m-1 && b < n-1; i++)
	{
		menor = vetA[a];
	
		for(k = a+1 ; k < m ; k++)
		{
			if(vetA[k] < menor)
			{
				menor = vetA[k];
				aux = k;
			}
		}
		vetA[aux] = vetA[a];
		vetA[a] = menor;
		printf("Menor A: %d\n",menor);
		system("pause");
		
		
		menor = vetB[b];
		for(k = b+1 ; k < n ; k++)
		{
			if(vetB[k] < menor)
			{
				menor = vetB[k];
				aux = k;
			}
		}
		vetB[aux] = vetB[b];
		vetB[b] = menor;
		
		printf("Menor B: %d\n",menor);
		system("pause");
		
		if(vetA[a] < vetB[b])
		{
			novo[i] = vetA[a];
			a++;		
		}
		else
		{
			novo[i] = vetB[b];
			b++;
		}		
			
	}
	
	
	
	
	
	for(; a < m; a++,i++)
	{
		novo[i] = vetA[a];
	}
	
	for(; b < n; b++,i++)
	{
		novo[i] = vetB[b];
	}
	
	
	printf("\n\n :");

	for(k=0 ;  k < i  ; k++)
	{
		printf("%d   ",novo[k]);
	}
}
