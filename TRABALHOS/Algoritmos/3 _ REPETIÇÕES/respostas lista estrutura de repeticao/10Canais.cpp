#include <iostream>

using namespace std;

int main()
{
	// declaracao das variaveis necessarias 
	float tot,tot4,tot5,tot7,tot12;
	int canal,npessoas;	
	//variaveis de inicializacao
	tot = 0;
	tot4 = 0;	
	tot5 = 0;
	tot7 = 0;
	tot12 = 0;

	cout << "PARA FINALIZAR A PESQUISA DIGITE '0' EM CANAL !!!!\n\n"<<endl;// informando o flag do progama 	
	cout << "Digite o canal: ";
	cin >>canal;
	while( canal != 0 && canal != 4 && canal != 5 && canal != 7 && canal != 12) // validando o canal
	{
		cout << "Digite um canal VALIDO: ";
		cin >> canal;
	}

	while(canal != 0) // enquanto canal diferente de 0
	{
		cout << "Numero de pessoas assistindo o canal: ";
		cin >> npessoas;
		cout << "________________________________"<<endl;
		 
		 tot = tot + npessoas;
		
		if(canal == 4) // se for o canal 4
		{			
			tot4 = tot4 + npessoas;
		}
		else
		{
			if(canal == 5)// se for o canal 5
			{				
				tot5 = tot5 + npessoas;
			}
			else
			{
				if(canal == 7)// se for o canal 7
				{					
					tot7 = tot7 + npessoas;
				}
				else // se nao for nenhum canal a cima , sera o canal 12
				{						
					tot12 = tot12 + npessoas;			
				}
			}
		}
		
	cout << "Digite o canal: ";
	cin >>canal;
	
		while( canal != 0 && canal != 4 && canal != 5 && canal != 7 && canal != 12) // validando canal
		{
			cout << "Digite um canal VALIDO: ";
			cin >> canal;
		}		
	}
	// porcentagem de audiencia de cada canal
	tot4 = (tot4*100)/tot;
	tot5 = (tot5*100)/tot;
	tot7 = (tot7*100)/tot;
	tot12 = (tot12*100)/tot;
	
	//exibicao dos resultados 
	cout <<"\n\n==> Pocentagem de audiencia do Canal 4: "<<tot4<<"%"<<endl;
	cout <<"==> Pocentagem de audiencia do Canal 5: "<<tot5<<"%"<<endl;
	cout <<"==> Pocentagem de audiencia do Canal 7: "<<tot7<<"%"<<endl;
	cout <<"==> Pocentagem de audiencia do Canal 12: "<<tot12<<"%"<<endl;		
	
}

