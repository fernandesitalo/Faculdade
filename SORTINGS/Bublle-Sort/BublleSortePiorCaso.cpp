#include <stdio.h>
#include <iostream>
int main()
{
	long double a=0.0;
	int tam = 10;
	std::string car = "Carregando";
	long double vetor[tam];
	std::cout<<"BUBLLE-SORT-MELHORADO\n";
	std::cout<<"Pior Caso! - QD  = "<<tam<<"\n"; 
	//std::cout<<"Vetor = {";
	std::cout<<car<<"\n";	
	a=tam;
	for(int c=0; c<tam; c++){
		a--;
		vetor[c]=a;
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
