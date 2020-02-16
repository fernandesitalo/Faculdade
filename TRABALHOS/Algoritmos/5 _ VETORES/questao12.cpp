#include <iostream>

using namespace std;

int main()
{
    int i,k,e,n; // declaracao das variaveis necessarias 
	float P,Y,x,coef[20];


	for(i = 0 ; i < 10 ; i++) // progama deve repetir 10 vezes 
	{
		cout << "Digite o valor de X: "; //obtencao dos dados de entradas 
		cin >> x;

		cout << "Digite o valor N (N <= 20): "; //obtencao dos dados de entradas 
		cin >> n;
		
		for(k = 0 ; k < n ; k ++)
		{
			cout << "Digite o valor do coeficiente do termo "<<k+1<<": "; // leitura dos oeficientes 
			cin >> coef[k];
		}
		
		P = coef[0]; // primeito termo sempre e igual ao primeiro coeficiente segundo a equacao 
		Y = 1; //Facilitar o progama a calcular X elevado a N
		
		for (e = 1 ; e < n  ; e++ )
		{
			Y *= x;
						
			P += (Y * coef[e]);	
		}
		
		cout << "  ==> Valor de X: "<<x<<endl;
		cout << "  ==> Valor de P: "<<P<<endl;
		cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
}
}
