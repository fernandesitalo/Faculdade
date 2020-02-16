#include <stdio.h>

int main(void){
	
	int i,k,m,n,A[20],B[20],aux;
	
	int maior,menor;
	
	printf("A : ");
	scanf("%d",&m);	
	for(i=0 ; i < m ; i++)
	{
		scanf("%d",&A[i]);
	}
	
	printf("\n\nB : ");
	scanf("%d",&n);	
	for(i=0 ; i < n ; i++)
	{
		scanf("%d",&B[i]);
	}
	
	
	maior = A[0];
	menor = maior;
	
	for(i=1 ; i<m ; i++)
	{		
		if(A[i] < menor)
		{
			menor = A[i];
		}
		else
		{
			if(A[i] > maior)
			{
				maior = A[i];
			}	
		}
	}
	
	printf("\n\nAmplitude do Conjunto A: %d",maior - menor);
	

	maior = B[0];
	menor = maior;
	
		for(i=1 ; i< n ; i++)
		{			
			if(B[i] < menor)
			{
				menor = B[i];
			}
			else
			{
				if(B[i] > maior)
				{
					maior = B[i];
				}
			}						
		}
	
	printf("\n\nAmplitude do Conjunto B: %d",maior - menor);
	
	return 0;
}
	
