// SOMATORIO DOS 15 PRIMEIROS TERMOS DA SEQUENCIA DE FIBONACCI 

#include <iostream>

using namespace std;

int main()
{
	int n,termo,termoA = 1,termoB = 1,soma = 2; // declaracao e atribuicao de valores as variaveis de inicialização

	for(n = 3 ; n <= 15 ; n++) // n = 3 pois o termo 1 e o termo 2 ja sao inicializados e somados , e o laco comeca pelo termo 3
	{
		termo = termoA + termoB;  // logica sequencial 
		soma += termo; //somatorio		
		termoB = termoA; // lei de formaçcao generica
		termoA = termo;	// lei de formacao generica 
	}	
	cout << "A soma dos 15 primeiros termos da sequencia de fibonacci e igual a "<<soma<<" !!!"<<endl; //exibicao dos dados de saida 
}
