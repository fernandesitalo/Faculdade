#include<iostream>
using namespace std;

int main ()
{
	
	float A,B,C,D,DET; // declaracao das variaveis necessarias 
	
	std::cout<<"Seja a matriz:    | A   B|\n";
	std::cout<<"                  | C   D|"; 
	//interface com o usuario , matriz generica
	
	std::cout<<"\n\nFavor, digite o valor do termo A e tecle 'Enter': ";
	std::cin>>A; // obtecao do termo A
	
	std::cout<<"\n\nFavor, digite o valor do termo B e tecle 'Emter : ";
	std::cin>>B; // obtecao do termo B
	
	std::cout<<"\n\nFavor, digite o valor do termo C e tecle 'Enter': ";
	std::cin>>C; // obtecao do termo C
	
	std::cout<<"\n\nFavor, digite o valor do termo D e tecle 'Emter : ";
	std::cin>>D; // obtecao do termo D
	
	
	DET=(A*D)-(C*B); //calculo do determinante
	
	
	std::cout<<"\n\n\n\nO valor do determinante da matriz e : " <<DET<< " !\n";
	//Exibicao dos resultados de saida 
		
}
