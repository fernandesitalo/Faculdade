#include <iostream>

using namespace std;

int main()
{
	int num,vetor[20],n_retirar,ind,aux2;
	float aux1;	
	
	cout << "Numero de elementos do Vetor(max 20): ";
	cin >>aux1;
	
	num = aux1;
	
	while(aux1 > 20 || aux1 < 0 || num != aux1)
	{
		cout << "Quantidade Invalida. Digite Novamente:";
		cin >>aux1;
		
		num = aux1;
	}
	

	
	cout << "Informe os elementos do vetor: "<<endl;
	for(ind = 0 ; ind < num ; ind++)
	{
		cin >> vetor[ind];
	}	
	
	do
	{
		cout << "Digite o numero para retira-lo da sequencia ja informada: ";
		cin >> n_retirar;
		
		for(ind = 0 , aux2 = 0; ind < num ; ind++)
		{
			if(n_retirar == vetor[ind])
			{
				cout << "\n=> FOI ENCONTRADO O NUMERO -="<<num<<"=- NA POSICAO { "<<ind<<" } DO VETOR\n\n"<<endl;
				aux2++;
			}			
		}
		
			if( aux2 == 0)
			{
				cout << "\nNao encontramos este numero na sequencia...\n\n"<<endl;
			}   
			
	}
	while( n_retirar != 0 );
}
