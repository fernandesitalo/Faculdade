#include <stdio.h>

int main(void){
	
	int i,k,m,n,A[20],B[20],aux;
	
	printf("A : ");
	scanf("%d",&m);	
	for(i=0 ; i < m ; i++){
		scanf("%d",&A[i]);
	}
	
	printf("B :");
	scanf("%d",&n);	
	for(i=0 ; i < n ; i++){
		scanf("%d",&B[i]);
	}

	
	for(aux =0 , i=0 ; i<m ; i++){
		
		for(k=0 ; k< n && A[i] != B[k] ; k++);
		
		if(k == n){ // se entrar nesse 'if' e pq o elemento de 'A' nao e igual a 'B' e foram analisadas todas possibilidades
			aux++;
		}
		else{ // o elemento do conjunto 'A' e igual ao elemento do Conjunto 'B' , ja sei q os conjuntos nao sao disjunto , paro de procurar
			i=m;
		}
	}
	
	printf(aux == m?"\n\nSao Conjuntos Distintos,portanto nao possuem elementos Iguais\n\n":"\n\nNao sao conjuntos distintos \n\n");
	
	
	
	system("PAUSE");
	return 0;
	
}
