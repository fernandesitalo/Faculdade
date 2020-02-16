#include<iostream>
using namespace std;

int main()
{
	float DISTANCIA,LITROS,CM;
	//declaracao das variaveis necessarias 
	
	
	std::cout<<"Favor,digite a Distancia em quilometros pela qual o automovel percorreu e em seguida tecle 'Enter' : \n";
	std::cin>>DISTANCIA; // obtencao das variaveis
	
	std::cout<<"\n\nFavor,digite o volume em litros de combustivel gasto pelo automovel para percorrer essa mesma distancia e tecle 'Enter'\n";
	std::cin>>LITROS; // obtencao das variaveis
	
	CM=DISTANCIA/LITROS; // calculo do consumo medio(CM)
	
	std::cout<<"O consumo do automovel e de "<<CM<<" KM/L";
    //exibicao dos resultados de saida
}
