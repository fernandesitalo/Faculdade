#include<iostream>

using namespace std;

int main()
{
	int dia,mes,ano; // declaracao das variaveis 
	
	// obtencao dos dados de entrada	
	cout << "Informe o Dia :";
	cin >> dia;	
	cout << "Informe o Mes :";
	cin >> mes;	
	cout << "Informe o Ano :";
	cin >> ano;
	
	
	if(dia < 01 || dia > 31 || mes > 12 || mes < 01 || ano < 0) // se o usuario digitar alguma coisa errada o progama ja para aqui
	{
		cout << "Data invalida"; 
	}
	
	else // se aparentemente ta tudo ok , vamos continuar
	{
			if(mes == 02) // mes de fevereiro			
			{	
				if((ano % 4 == 0) && (ano % 100 != 0 || ano % 400 == 0))
					{
						if(dia > 29)  //para ano bissexto
						{
							cout << "Data Invalida";
						}
						else
						{
							cout << "Data valida";
						}
					}
					
					else // se não deu resto zero e pq o ano em questao , e um ano nao bissexto , neste caso , fev so vai ate dia 28
					{
						if(dia > 28)
						{
							cout << "Data Invalida";
						}
						else 
						{
							cout << "Data Valida";
						}
					}
			}
					
			else // se não e mes 02 , entao ....
			{
				if(mes == 4 || mes == 6 || mes == 9 || mes == 11)	// meses com 30 dias 
				{						
					if(dia <= 30 )
					{
						cout << "Data Valida";
					}
					else 
					{
						cout << "Data Invalida";
					}
								
				}
				else // se nao e mes 02 e não e nenhum mes que tem 30 dias e pq e um mes de 31 dias, e se tem 31 dias , ta valendo
				{
					cout << "Data Valida";
				}					
			}
	}	
		
}
