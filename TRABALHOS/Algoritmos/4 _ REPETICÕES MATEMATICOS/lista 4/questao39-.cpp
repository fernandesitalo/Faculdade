#include <iostream>

using namespace std;

int main()
{
	int n,x; // declaracao das vaariaveis interias 
	double termo = 1,soma; // declaracao das variaveis reais 	
	
	cout << "Digite um numero X: ";  // obtencao dso dados de entrada 
	cin >>x;

	soma = x; // inicialização da variavel soma 	
	for(n = 1 ; n < 20; n++)    
	{			
		termo = termo * (x * x) / ( 2 * n * (2 * n + 1) ) * -1;	// termos 
		soma += termo; // somatorio 	
	}	
	cout << "Valor calculado pela serie: "<<soma<<endl;	//exibicao dos dados de entrada 
}
