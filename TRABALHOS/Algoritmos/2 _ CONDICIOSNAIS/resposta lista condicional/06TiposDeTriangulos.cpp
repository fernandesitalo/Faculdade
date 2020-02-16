#include<iostream>
using namespace std;

int main()
{
	float a,b,c; // declaracao das variaveis necessarias , numericas!
	string mensagem; // declaracao de variaveis literais 
	
	//obtencao dos dados 
	cout << "Digite 3 valores e para cada um tecle 'Enter': "<<endl;
	cin >>a;
	cin >>b;
	cin >>c;
	
	if(a > (b + c) || b > (a + c) || c > (a + b)) // para que 3 valores formem um triangulo , o comprimento de um lado e SEMPRE menor do que a soma dos outros dois...
	{
		mensagem="Os valores nao formam um triangulo :( ... Tente novamente com outros valores!";
	}
		else 
		{
			if(a == b && b == c)
			{
				mensagem= "Os valores formam um triangulo equilatero ! =)";
			}
				else 
				{
					if(a == b || b == c || a == c)
					{
						mensagem = "Os valores formam um triangulo isoceles !";
					}
						else
						{
							mensagem= "Os valores formam um trianglo escaleno !";
						}
				}
		}
		cout <<mensagem; // exibicao na tela do usuario dos resultados obtidos
}
