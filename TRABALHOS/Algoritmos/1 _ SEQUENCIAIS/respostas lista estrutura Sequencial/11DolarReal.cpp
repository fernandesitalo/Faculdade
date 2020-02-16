#include<iostream>
using namespace std;

int main ()
{
	
	float CDOLAR,TAXADOLAR,ICMS,LUCROEMPRESA,COMPRA,COMPRAREAIS;
	//declaracao das variavies necessarias 
	
	
	std::cout<<"Favor, Digite o valor da compra em DOLARES : $";
	std::cin>>CDOLAR;	
	std::cout<<"\nFavor, Digite a taxa do dolar no dia da compra : ";
	std::cin>>TAXADOLAR;	
	std::cout<<"\nFavor, Digite o percentual de ICMS : ";
	std::cin>>ICMS;	
	std::cout<<"\nFavor, Digite o percentual de lucro da empresa : ";
	std::cin>>LUCROEMPRESA;
	//obtencao dos dados de entrada
	
	
	COMPRA=CDOLAR*TAXADOLAR; 
	COMPRAREAIS=((COMPRA*ICMS)/100)+(COMPRA+LUCROEMPRESA);	
	//calculo da compra em reais
	
	
	std::cout<<"\n\nO valor da sua compra em reais e : R$"<<COMPRAREAIS<<"\n\n";
	//exibicao dos reultados de saida
	
}
	
	
