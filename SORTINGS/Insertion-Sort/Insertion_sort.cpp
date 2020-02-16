#include <stdio.h>
//#DEFINE MAX 100

int main(){
	
	int num; // numero de termos do vetor
	int aux; // termo do vetor que sera guardado parcialmente
	int i,k; // contadores
	int vet[100]; // vetor maximo
	
	
	printf("Numero de Termos (<=100):");
	scanf("%d",&num);
	
	printf("\nDigite os termos: \n");
	for(i=0 ; i<num ; i++){ // leitura do vetor a ser ordenado
		scanf("%d",&vet[i]);
	}
	
	for(i=1 ; i<num ; i++){  // o laco comeca com i = 1 pois nao tem como ordenar um so termo 
		aux = vet[i]; // termo q sera guardado para coloca-lo na posicao correta
		
		for(k=i-1 ; k >= 0 && aux < vet[k] ; k--){ // ando uma posição para frente com cada termo menor que o termo auxiliar
			vet[k+1] = vet[k];
		}	
		vet[k+1] = aux; // quando e encontrada a posicao correta inserimos o termo auxiliar
						// antes de sair do laco 'for' e decrementada uma unidade do k , pois isso K+1
	}	
	printf("Vetor Ordenado da forma Insertion Sort:\n");
	for(i=0 ; i<num ; i++){ // exibicao do vetor ordenado da forma insertion sort
		printf("%d  ",vet[i]);
	}	
	printf("\n\n");
	
	return 0;
}
