#include<iostream>

using namespace std;

int main()

{
	float x,y,resultado; //declaracao de variavel ponto flutuante ... numero quebrado
	char simb;    //declaracao variavel liveral que le caracteres
		
	//tabela com operacoes oferecidas pelo progama	
	cout << "Adicao------------ use + \n";
	cout << "Subtracao--------- use -\n";
	cout << "Multiplicacao----- use *\n";
	cout << "Divisao----------- use /";
	
	//obtencao dos dados de entrada
	cout << "\n\nInforme o primeiro valor da operacao: ";
	cin >>x;	
	cout << "\nEscolha a operacao aritmetica conforme a 'tabela' acima: ";
	cin >> simb;	
	cout << "\nInforme o segundo valor da operacao: ";
	cin >>y;
	
	//realização da operacao escolhida
	if(simb == '+')
	{
		resultado = x+y;
	}
		else
		{
			if(simb == '-')
			{
				resultado = x-y;
			}
				else
				{
					if(simb == '*')
					{
						resultado = x*y;
					}
						else
						{
							resultado = x/y;
						}
				
				}
				
		}
	
	cout << "\n\nO resultado da operacao eh "<<resultado; //exibicao dos dados de saida
	
	return 0;
}
