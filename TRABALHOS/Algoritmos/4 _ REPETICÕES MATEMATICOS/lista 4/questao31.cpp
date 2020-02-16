#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n,sinal = 1; // declaracao das variaveis interias 
	float soma = 0,termo = 1; // termo comeca com 1 para entrar no laco de repeticao
	
	for(n = 1; fabs(termo) >= 0.0001; n++,sinal *= -1) // precisao de 0,0001 refere-se aos termos com valor absoluto maior ou igual a 0,0001
	{
		termo = 4.0 / (n*2 - 1) * sinal; 
		soma += termo; 	
	}	
	cout << "Soma: "<<soma<<endl; // exibição dos dados de saida 
}
