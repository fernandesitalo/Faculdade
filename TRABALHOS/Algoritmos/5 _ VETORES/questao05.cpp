#include <iostream>

using namespace std;

int main()
{
	int nota[11] = {0,0,0,0,0,0,0,0,0,0,0}; //inicialização dos vetores q serviram de contadores 
	int i,x; 
	
	
	cout << "Digite as 80 notas: "<<endl;
	for(i = 0 ; i < 80 ; i++) // obtencao dos dados de entrada
	{
		cout << "=>";
		cin >>x;
			while(x < 0 || x > 10) // validacao das notas 
			{
				cout << "As notas variam de 0 a 10 . Digite novamente: ";
				cin >> x;
			}
		
		nota[x] += 1; // incremento da nota de posicao x
	}
	
	cout << "    NOTA       FREQ.ABSOLUTA       FREQ.RELATIVA"<<endl;  // cabecalho da tabela
	cout << "   ----------------------------------------------"<<endl;
	for(i = 0 ; i < 11 ; i++)
	{
		cout <<"      "<<i<<"              "<<nota[i]<<"               "<<nota[i]/80.0<<endl;  // exibicao das linhas da tabela 
		cout << "   ----------------------------------------------"<<endl;
	}
	
	

}
