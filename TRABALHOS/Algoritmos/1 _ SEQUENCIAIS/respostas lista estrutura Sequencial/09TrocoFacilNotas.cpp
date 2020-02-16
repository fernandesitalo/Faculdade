#include<iostream>
using namespace std;

int main()
{
	int X,N100,N50,N20,N10,N5,N2,N1;
	// Declaracao das varaveis necesarias
	
	std::cout<<"Digite um valor em reais para saber o menor numero de notas para se obte-lo,na sequencia tecle 'Enter' :\n\nR$" ;
	std::cin>>X; // Instrucoes ao usiario 
	
	N100=X/100;  
	cout<<"\n\n\nNumero de notas de 100 reais : "<<N100;
	// exibicao da quantidade de notas de 100


			X=X%100; // resto da divisao , valor menor que 100	
	
	N50=X/50;
	std::cout<<"\n\nNumero de notas de 50 reais  : "<<N50;
	//exibicao da quantidade de notas de 50 
	
		
			X=X%50; // resto da divisão , valor menor que 50	

	N20=X/20;
	std::cout<<"\n\nNumero de notas de 20 reais  : "<<N20;
	//exibicao da quantidade de notas de 20 
	
	
			X=X%20;// resto da divisao, valor menor que 20
	
	N10=X/10;
	std::cout<<"\n\nNumero de notas de 10 reais  : "<<N10;
	//exibicao da quantidade de notas de 10
	
	
			X=X%10;// resto da divisao, valor menor que 10
	
	N5=X/5;
	std::cout<<"\n\nNumero de notas de 5 reais   : "<<N5;
	//exibicao da quantidade de notas de 5
	
			X=X%5;//resto da divisao, valor menor q 5
		
	N2=X/2;
	std::cout<<"\n\nNumero de notas de 2 reais   : "<<N2;
	//qexibicao da uantidade de notas de 2
	
			
			X=X%2;//resto da divisao,valor menor que 2
	
	N1=X;
	std::cout<<"\n\nNumero de moedas de um real  : "<<N1<<"\n";
	//Se vai ter que completar ou nao o valor com uma moeda de 1 real
	}
	
	
	
	
	
	
	
	
	


