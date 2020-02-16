#include<iostream>
using namespace std;

int main()
{ 
	int IX,IANO,IMESES,IDIAS; //declaracao das variaveis necessarias
	
	std::cout<<"Favor, digite sua idade em dias e tecle 'Enter' : ";
	std::cin>>IX; //obtencao dos resultados de entrada
	
	IANO=IX/365; // calculo anos
	
	IMESES=(IX%365)/30; // calculo meses
	
	IDIAS=(IX%365)%30; // calculos dias 	
	
	std::cout<<"\n\nVoce tem "<<IANO<<" anos "<<IMESES<<" meses e "<<IDIAS<<" dias de vida !\n\n";
	// exibicao dos resultados de saida
	
	return 0;


}
