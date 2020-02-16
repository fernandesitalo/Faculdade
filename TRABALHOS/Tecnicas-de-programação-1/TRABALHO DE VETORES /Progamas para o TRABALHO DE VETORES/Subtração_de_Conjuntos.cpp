/*DIFERENÇA DE CONJUNTOS OU SIMPLISMENTE VETOR A MENOS VETO*/
#include <stdio.h>

int main(void){
	int m,n,k,i,aux=0;
	int vetA[100],vetB[100],novo[100];
	
	printf("Numero de Termos do Vetor A: ");
	scanf("%d",&m);

	printf("Vetor A: ");
	for(i=0; i<m ; i++){
		scanf("%d",&vetA[i]);
	}

	printf("\nNumero de Termos do Vetor B: ");
	scanf("%d",&n);
	printf("Vetor B: ");
	for(i=0; i<n ; i++){
		scanf("%d",&vetB[i]);
	}
	
	for(i=0 ; i<m ; i++){
		
		for(k=0 ; k<n && vetA[i] != vetB[k];k++);
		
		if(k == n){
			novo[aux] = vetA[i];
			aux++;
		}
	}	
	
	printf("\n\nVetor A - Vetor B: ");
	for(i=0; i<aux ;i++){
		printf("%d  ",novo[i]);
	}
	printf("\n\n");
	return 0;

}
