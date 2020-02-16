#include <stdio.h>

int main(void){
	int i,aux,k,n,m;
	int vetA[100],vetB[100],novo[200];
	
	printf("Numero de Termos VetorA : ");
	scanf("%d",&m);
	for(i=0; i<m ;i++){
		scanf("%d",&vetA[i]);
		novo[i] = vetA[i];
	}
	aux = i;
	
	printf("Numero de Termos VetorB : ");
	scanf("%d",&n);
	for(i=0; i<n ;i++){
		scanf("%d",&vetB[i]);
	}
	
	for(i=0; i<n ;i++){ // 'i' varia o vetorB e 'k' varia o vetorA
		for(k=0; k<m && vetA[k] != vetB[i];k++);
		if(k == m ){
			novo[aux] = vetB[i];
			aux++;
		}
	}
	
	printf("Uniao dos Vetores : ");

	for(i=0; i<aux ;i++){
		printf("%d ",novo[i]);
	}
	
	return 0;
}
