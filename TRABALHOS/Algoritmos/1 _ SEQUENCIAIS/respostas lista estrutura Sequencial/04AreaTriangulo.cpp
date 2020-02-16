#include<iostream>
using namespace std;
#include<math.h> // Biblioteca com as funções matemáticas 

int main()
//inicio do progama

{
	int A,B,C,T,AREA;
	//Declarar variaveis
	
	std::cout<<"\nDigite o valor de cada lado do triangulo e tecle 'Enter' em seguida ...\n\n" ;
	std::cin>>A;
	std::cin>>B;
	std::cin>>C;
	//Obtencao dos dados de entrada
	
	
	T=(A+B+C)/2;
	//calculo de uma 'variavel oculta' para obter o valor da area
	
	AREA=sqrt(T*(T-A)*(T-B)*(T-C));
	//Calculo da area do triangulo
	
	std::cout<<"\n\nA area do triangulo e igual a : " <<AREA<< "\n\n\n\n\n\n";
	
}
// final do progama
