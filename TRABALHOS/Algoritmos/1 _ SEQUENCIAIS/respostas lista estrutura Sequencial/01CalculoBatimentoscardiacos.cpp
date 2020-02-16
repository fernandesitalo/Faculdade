#include<iostream>
using namespace std;
int main()
{
	int MIN,HR,DIA,X,BC;
	float ANO;
	// Declaracao das variaveis necessarias	
	
	std::cout<<"\n\nFavor, digite sua idade em seguida tecle'enter'  : " ;	
	//Obtencao dos Resultados de Entrada
	
	MIN=60; 
	HR=60;
	DIA=24;
	ANO=365.25;
	//variaveis ocultas na execução do progama
	std::cin>>X;
	// ler a variavel X - idade.
	
	BC= MIN*HR*DIA*ANO*X;
	//Calculo dos batimetos cardiacos do usuario-formula
	
	std::cout<<"\n\n\n\nSeu coracao ja pulsou "<<BC<<" batimentos cardiacos !\n\n\n\n\n\n\n\n\n\n\n\n" ;
	//comando de saida de dados
	
	return (0);
}
