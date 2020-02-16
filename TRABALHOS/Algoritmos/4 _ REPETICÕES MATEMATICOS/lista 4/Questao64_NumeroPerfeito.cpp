#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	int num,n,soma;
	
	cout << "Digite um numero para Verificar se este numero e perfeito: ";
	cin >> num;
	
	while(num != 0)
	{
		soma = 1;
/*qndo achamos um dividor , na verdade achamos 2 divisores o divisor e o dividendo(por isso comecamos soma com 1 , para nao incluir o proprio numero)!!!!
 e se fizermos os calculos somente ate a raiz (sem inclui-la) vamos achar qse todos os seus divisores inteiros deixando de fora ele mesmo*/
		
		for(n = 2 ; n < sqrt(num) ; n++) // laco for execulta n++ antes de ir para a comparacao , portanto execulta n++ antes de sair do laco
		{
			if(num % n == 0)
			{
				soma += n + (num/n);
			}
		}		
			if((n*n) == sqrt(num)) 
			{
				soma += n; 
			}		
				if(soma == num) // requisito para ser um numero perfeito 
				{
					cout << "ESTE NUMERO E PERFEITO"<<endl;      //exibicao dos dados de entrada 
				}
				else
				{
					cout << "ESTE NUMERO NAO E PERFEITO"<<endl;			//exibicao dos dados de entrada 
				}
		cout << "Digite um numero para Verificar se este numero e perfeito: ";
		cin >> num;		
	} 
}


