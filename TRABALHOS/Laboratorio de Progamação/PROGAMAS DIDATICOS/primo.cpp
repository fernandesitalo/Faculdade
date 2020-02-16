#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	int i,num;
	
	for(;num != 0;)	
	{
		cout << "Digite para descobrir se ele e primo: ";
		cin >> num;	
		
		for (i = 2 ; i <= sqrt(num) && num % i != 0 ; i++ )
		{}
		
		if(i > sqrt(num)) // i so sera maior que a raiz do numero qndo o for rodar todas as vezes possiveis , isto e ate a raiz"!!
		{
			cout << "E PRIMO CARAI"<<endl;
		}
		else
		{
			cout << "NAO E PRIMO PARCA!!!"<<endl;
		}	
	}			
}
