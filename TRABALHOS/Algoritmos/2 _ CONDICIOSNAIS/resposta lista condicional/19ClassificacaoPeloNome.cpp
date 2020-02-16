#include <iostream>

using namespace std;

int main()
{
	string nome,mensagem; //Declaracao variavel literal string
	
	cout << "Nome do Aluno: ";
	cin >> nome[0];

	if(nome[0] >= 97) // se a letra estiver minuscula devemos passar para maiuscula usando a tabela ASCII
	{
		nome[0] = nome[0] - 32;
	}
		if(nome[0] <= 75) // 75 = K
		{
			mensagem = "Sala 101";
		}
			else
			{
				if(nome[0] <=78) // 78 = N
				{
					mensagem = "Sala 102";
				}
					else 
					{
						if(nome[0] <=90) //90 = Z
						{
							mensagem = "Sala 103";
						}
					}
			}
	cout << mensagem; 
}
