#include<iostream>
using namespace std;

int main()
{
	float M,A,T,V,DS,TRABM;
	//declaracao das variaveis necessarias 
	
	
	std::cout<<"Favor, digite a massa en toneladas do aviao e tecle 'Enter' : ";
	std::cin>>M; //
	
	std::cout<<"\nFavor,digite a aceleracao em m/s^2 do aviao : ";
	std::cin>>A;
	
	std::cout<<"\nFavor,Digite o tempo em segundos desde o momento de repouso do aviao ate sua decolagem : ";
	std::cin>>T;
    //obtencao dos dados de entrada	
		
	
	M=M*1000; // passando de toneladas para kilo
	V=A*T; // velociade em m/s
	DS=V*T; // pista em metros
	TRABM=(M*V*V)/2; //formula da energia mecanica

	
	V=A*T*3.6; // velocidade em km/h
	
	std::cout<<"\n\n\nVelocidade atingida : "<<V<<" km/h";
	std::cout<<"\nComprimento da pista : "<<DS<<" Metros";
	std::cout<<"\nTrabalho mecanico realizado : "<<TRABM<<" JOULES";
	//exibicao dos resultados de saida 
		
}

