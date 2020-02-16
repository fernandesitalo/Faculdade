#include <iostream>
using namespace std;

int main()
{
// inicio do progama

	int M,N,L1,L2,H;
	//declaração das variaveis
	
	
	std::cout<<"         ATENCAO! \n Use somente numeros inteiros e positivos !!!\n\n\n\n";
	//aviso ao usuario
	
	std::cout<<"Favor, digite o primeiro valor, que seja o menor, e tecle 'enter' :\n\n ";
	std::cin>>M;
	std::cout<<"Favor, digite o segundo valor, sendo maior que o anterior por sua vez, e tecle 'enter' :\n\n ";
	std::cin>>N;
	//Obtencao dos dados de entrada 
	
	
	H=(M*M)+(N*N);
	L1=(M*M)-(N*N);
	L2=2*M*N;
	//calculos dos Lados e da Hipotenusa
	
	//Comandos de saida de dados	
	std::cout<<"O valor da Hipotenusa do triangulo vale : "<<H;
	std::cout<<"\n\nValor dos catetos do triangulos valem, respectvamente : "<<L1<<" e "<<L2<< "\n\n\n\n";
	

}
//final do Progama
