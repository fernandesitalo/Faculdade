#include <stdio.h>

int main(void){
	
	int i,k,m,n,A[20],B[20],aux;
	
	int aux_a[20],aux_b[20],cont1,cont2;
	
	int novo[40];
	

	
	printf("A : ");
	scanf("%d",&m);	
	for(i=0 ; i < m ; i++)
	{
		scanf("%d",&A[i]);
		aux_a[i] = A[i];
	}
	
	printf("\n\nB : ");
	scanf("%d",&n);	
	for(i=0 ; i < n ; i++)
	{
		scanf("%d",&B[i]);
		aux_b[i] = B[i];
	}
	
	
	for(i=1 ; i<m ; i++)
	{  // o laco comeca com i = 1 pois nao tem como ordenar um so termo 
		aux = aux_a[i]; // termo q sera guardado para coloca-lo na posicao correta
		
		for(k=i-1 ; k >= 0 && aux < aux_a[k] ; k--)
		{ // ando uma posição para frente com cada termo menor que o termo auxiliar
			aux_a[k+1] = aux_a[k];
		}	
		aux_a[k+1] = aux; // quando e encontrada a posicao correta inserimos o termo auxiliar
						// antes de sair do laco 'for' e decrementada uma unidade do k , pois isso K+1
	}
	
	
	for(i=1 ; i<n ; i++)
	{  // o laco comeca com i = 1 pois nao tem como ordenar um so termo 
		aux = aux_b[i]; // termo q sera guardado para coloca-lo na posicao correta
		
		for(k=i-1 ; k >= 0 && aux < aux_b[k] ; k--)
		{ // ando uma posição para frente com cada termo menor que o termo auxiliar
			aux_b[k+1] = aux_b[k];
		}	
		aux_b[k+1] = aux; // quando e encontrada a posicao correta inserimos o termo auxiliar
						// antes de sair do laco 'for' e decrementada uma unidade do k , pois isso K+1
	}	
	
	
	
	
	
	

	cont1=0;
	cont2=0;
	
// INTERCALANDO E ORDENADO  ATE UM VETOR ACABAR	
	for(i=0 ; cont1 < m && cont2 < n ; i++){ 	
	
	
		if(aux_a[cont1] < aux_b[cont2])
		{
			novo[i] = aux_a[cont1];
			cont1++;
		}
		else
		{
			novo[i] = aux_b[cont2];
			cont2++;
		}	
	}

// TERMINA DE COLOCAR OS ELEMNTOS DO OUTRO VETOR Q NAO ACABOU	
		for(;cont1<m; cont1++,i++)
		{ 
			novo[i] = aux_a[cont1];
		}
// TERMINA DE COLOCAR OS ELEMNTOS DO OUTRO VETOR Q NAO ACABOU		
		for(;cont2<n; cont2++,i++)
		{ 
			novo[i] = aux_b[cont2];
		}
		
		cont2 = m+n;
	
	printf("\nVETOR 'A' E VETOR 'B' ORDENADOS E INTERCALADOS : \n");
	for(cont1 = 0; cont1 < cont2 ; cont1++)
	{ // EXIBE O VETOR ORDENADO E INTERCALADO
		printf("%d ",novo[cont1]);
	}	
	printf("\n");	
	
	
	return 0;
}
	
