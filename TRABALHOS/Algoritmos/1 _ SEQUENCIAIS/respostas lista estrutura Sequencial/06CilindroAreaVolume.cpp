#include<iostream>
using namespace std;
#include<cmath>

int  main()
{ 
	float R,H,VOLUME,AREA; // declaracao das variaveis necessarias
		
	std::cout<<"ATENCAO!\nO progama calcula o volume e a area do clilinro a partir do raio e da altura deste mesmo... ";
	//alerta ao usuario 
	
	std::cout<<"\n\nFavor,digite o valor do raio : ";
	std::cin>>R; // obtencao do raio
	
	std::cout<<"\n\nFavor,digite o valor da altura : ";
	std::cin>>H; //obtencao da altura 
	
	
	AREA=2*M_PI*R*(H+R); // calculo da area 	
	
	VOLUME=M_PI*R*R*H;  // calculo volume
	
	
	std::cout<<"\n\n\n\nA area do cilindro equivale a : " <<AREA ; 
	std::cout<<"\n\nO volume do cilindro equivale a : " <<VOLUME<<"\n\n" ; 	
	// exibição dos resultados de saida		
}
