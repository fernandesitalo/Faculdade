#include <iostream>
using namespace std;

int main ()
{
	int x;  //declaracao da variavel
	
	cout << "Favor, digite um numero: ";  // obtencao dos dados
	cin >> x;
	
		if(x%2==0)  // se o resto da divisão for 0 e pq o numero e par 
		{  
		cout << "O numero eh par !!"<<endl;
		}
		
	else  // caso contrario e impar
	{
	cout << "O numero eh impar !!"<<endl;  
	}
	return 0; 
}
