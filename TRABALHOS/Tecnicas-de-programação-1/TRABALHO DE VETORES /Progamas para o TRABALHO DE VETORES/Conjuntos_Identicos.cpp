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


////////////////////


	
	if(m != n){
		printf("\n\nOs conjuntos nao sao identicos !!! (1) \n\n");
	}
	else{
		
		for(aux=0 ,i=0 ; i < m ; i++){ 
			
			for(k=0 ; k<n && A[i] != B[k] ; k++); 
			
			if(n == k){ // se entrar nesse 'if' e pq um elemento de A nao esta em B e portanto nao os conjuntos nao sao identicos 
				i = m; // como nao sao identicos , o progama deve parar 
			}
			else{ // se entrar nesse 'else' e pq o elemento de 'A' e igual ao elemento de 'B'
				aux++; 
			}
		}
	}
	printf(aux == n ? "Os conjuntos A e B sao conjuntos IDENTICOS  (2)\n\n":"Os conjuntos A e B sao conjuntos NAO IDENTICOS (3)\n\n");



///////////////


	return 0;
}

	
