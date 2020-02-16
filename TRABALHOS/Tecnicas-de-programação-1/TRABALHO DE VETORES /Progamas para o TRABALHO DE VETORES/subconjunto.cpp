	/*DIFERENÇA DE CONJUNTOS OU SIMPLISMENTE VETOR A MENOS VETO*/
#include <stdio.h>

int main(void){
	int m,n,k,i,aux=0;
	int vetA[100],vetB[100];
	
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
	
	if(m > n){
		printf("\n\n=> Conjunto A nao e um subconjunto de B!!!!\n\n");
	}
	else{
	
	for(aux = 0,i=0 ; i<m ; i++){		
		for(k=0 ; k<n && vetA[i] != vetB[k];k++);		
		
		if(k< n && vetA[i] == vetB[k]){
			aux++;
		}
		else{
			i = m;
		}
	}	
	printf(aux == m ? "\n\nO conjunto A e um subconjunto de B":" \n\nConjunto A nao e um subconjunto de B , se fodeo!!!\n\n");
	}
	return 0;

}
