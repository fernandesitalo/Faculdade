#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n10,aux,n2,pot;
	
	cout << "digite o numnero de base 10 a ser convertido:";
	
	cin >> n10;
	
	aux = n10;
	pot =1;
	n2 = 0;
	
		while(aux!=0)
		{	
			n2 = n2 + (aux%2) * pot;
			pot = pot * 10;
			aux = aux / 2;
		}
	cout<<"O numero "<<n10<<" em binario equivale a "<<n2<<endl;
}

