#include <iostream>

using namespace std;

int main()
{
	int i,k,j,menor,meses[300],aux,num[300],x,y; // declaracao das variaveis necessarias 
	
	cout << "FLAG --> numero do funcionario e meses na empresa iguais a ZERO"<<endl;
	cout << "Numero do funcionario: ";
	cin >> x;
	cout << "Meses na empresa: ";
	cin >> y;
	i = 0;
	while(( x != 0 || y != 0) && i < 300 ) // leitura dos dados de entrada 
	{
		num[i] = x;
		meses[i] = y;
		
		cout << "Numero do funcionario: ";
		cin >> x;
		cout << "Meses na empresa: ";
		cin >> y;
		i++;
	}	
	
	for(k = 0 ; k < 3 ; k++) // ordenar os tres primeiros termos da sequencia 
	{
		menor = k;
	
		for(j = (k+1) ; j < i ; j++)
		{
			if( meses[j] < meses[menor])
			{
				menor = j;
			}
		}

		cout << "Empregado :"<<num[menor]<<endl;
		cout << "Tempo de Empresa :"<<meses[menor]<<endl;
		cout << "======================"<<endl;
		
			aux = meses[k];
			meses[k] = meses[menor];
			meses[menor] = aux;
			
			aux = num[k];
			num[k] = num[menor];
			num[menor] = aux;	
}
}
