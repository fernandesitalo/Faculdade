#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	int n,c,divisores;	//n e c sao os contadores 
	
	for(n = 300 ; n <= 400 ; n++)
	{
		divisores = 0;
		for(c = 1; c < sqrt(n) ; c++) // c++ e feito antes da verificacao da condicao
		{
			if(n % c == 0) // condicao dos divisores 
			{
				divisores += 2;
			}
		}		
			if((c*c) == n) // como c foi icrementado antes de encerrar o laco (pois c++ e feito antes da verificacao da condicao) e facil entender essa comparacao
			{
				divisores++;	
			}
			
		cout << "\nO numero "<<n<<" possui "<<divisores<<" divisores"<<endl; //exibicao dos dados de saida 
	}
}
