#include <iostream>

using namespace std;

int main()
{
	int i,j,opc[10],resp[10][5],aux;
	string name;
	
	
// inicializacao da matriz em zero
	for(i = 0 ; i < 10 ; i++)
	{
		for(j=0 ; j < 5 ; j++)
		{
			resp[i][j] = 0;
		}
	}
	
	cout << "Digite seu nome: ";
	getline (cin,name);
	
	
	while(name != "vazio")
	{
		for(i = 0 ; i < 10 ; i++)
		{
			cout << "Resposta da pergunta "<<i+1<<" :";
			cin >>opc[i];
			
			aux = opc[i] - 1;
			
			resp[i][aux]++;
		}
		
		cout << "\n\nGabarito Marcado Pelo(a) "<<name<<":\n\n";
		
		for(i = 0 ; i < 10 ; i++)
		{
			cout << " => Questao "<<i+1<<" ( "<<opc[i]<<" )"<<endl;
		}
		
		cout << "\nDigite seu nome: ";		
		cin.ignore();
		getline(cin,name); 
	}
	
	cout << "\n\nQuantidade de Vezes em que cada alternativa foi escolhida ...\n\n"<<endl;
	
		for(i = 0 ; i < 10 ; i++)
		{
			for(j = 0 ; j < 5 ; j++)
			{
				cout << "** Questao "<<i+1<<" Alternativa "<<j+1<<" : " <<resp[i][j]<<" vezes\n"<<endl;
			}
		}
}
