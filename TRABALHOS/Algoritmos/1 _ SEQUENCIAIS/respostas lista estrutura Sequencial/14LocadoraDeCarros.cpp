#include<iostream>
using namespace std;

int main()


{
	float X,Y,D,Q,TOTAL,TOTALFINAL,DESCONTO;
	//declaracao das variaveis necessarias
	
	std::cout<<"ATENCAO!\nNao use a virgula(,) para separar casas decimais use o ponto(.)\nPor exemplo : 1.99 e nao 1,99 !!";
	//instrucao ao usuario 
	
		
	std::cout<<"\n\n\n\nDigite a taxa fixa por dia e tecle 'Enter' : R$";
	std::cin>>X;	
	std::cout<<"\nDigite a taxa de quilometro rodado e tecle 'Enter' : R$";
	std::cin>>Y;	
	std::cout<<"\nDigite o numero de dias que o carro foi alugado e tecle 'Enter' : R$";
	std::cin>>D;	
	std::cout<<"\nDigite o numero de quilometros rodados e tecle 'Enter' : R$";
	std::cin>>Q;
	//obtencao dos resultados de entrada
	
	
	TOTAL=(X*D)+(Y*Q); //calculo do valor sem desconto

	DESCONTO=0.10*(X*D); // calculo do desconto 
	
	TOTALFINAL=TOTAL-DESCONTO; // calculo valor com desconto
	
	std::cout<<"\n\nValor total : "<<TOTAL;	
	std::cout<<"\nValor do Desconto : R$"<<DESCONTO;	
	std::cout<<"\n\nO valor a ser pago pelo carro alugado por "<<D<<" dias e com "<<Q<<" quilometros\nrodados e de : R$"<<TOTALFINAL<<"\n\n";
	//exibicao dos resultados de saida 
	
	return 0;
}
