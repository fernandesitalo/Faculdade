#include <iostream>

using namespace std;

int main()
{
	int n,y,k,x; //declaracao das variaveis inteiras 
 
	cout << "Os numeros ";
	for( n = 1000 ; n <= 9999 ; n ++) 
	{
		x = n / 100; // 2 primeiros algarismo do numero
		y = n % 100; // 2 ultimos algarismos do numero
		
		k = (x+y) * (x+y); // 2 ultimos mais 2 primeiros algarismos elevados ao quadadro
		
		if(k == n) // condicao da caracteristica 
		{
			cout <<n<<" ; "; 
		}
	}
	
	cout << "apresentam tal caracteristica"<<endl; //exibicao dos dados de saida 
}
