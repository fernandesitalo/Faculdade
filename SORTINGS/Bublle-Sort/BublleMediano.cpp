#include <stdio.h>
#include <iostream>
#include <cstdlib>
int main()
{
	
	int tam = 100000;
	std::string car = "Carregando";
	long double vetor[tam];
	std::cout<<"BUBLLE-SORT-MELHORADO\n";
	std::cout<<"Medio Caso! - QD  = "<<tam<<"\n"; 
	//std::cout<<"Vetor = {";
	std::cout<<car<<"...\n";	
	for(int c=0; c<tam; c++){
		
		vetor[c]= rand();
		//std::cout<<a<<",";
	}
//	std::cout<<"}\n";
		
	for(int i=0; i < tam-1; i++){
		for(int j = tam-1; j >= i+1; j--){
			if(vetor[j] < vetor[j-1]){
				int aux = vetor[j-1];
				vetor[j-1] = vetor[j];
				vetor[j] = aux;
			}
		}		 
	}
	std::cout<<"\n\n\n";
	
	for (int a = 0; a<tam; a++){
          if(a==tam-1){
			  car = "Fim!";
			  std::cout<<car;
		  }
	  }
	  std::cout<<"\n\n\n";
  }
