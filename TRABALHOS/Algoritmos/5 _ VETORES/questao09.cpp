#include <iostream>

using namespace std;

int main()
{
	int k=0,i,A[30],B[30],x; // declaracao das variaveis necessarias 
	
	cout << "Informe o valor dos 30 elementos do vetor A: "<<endl;
	for(i = 0 ; i < 30 ; i++)
	{	
		cout <<"A["<<i<<"] :"; // leitura do vetor A
		cin >> A[i];
	}
	
	cout << "Informe o valor dos 30 elementos do vetor A: "<<endl;
	for(i = 0 ; i < 30 ; i++)
	{
		cout <<"B["<<i<<"] :"; // leitura do vetor B
		cin >> B[i];
	}
	
	cout << "Digite um valor X para verificar sua existencia no vetor A :";
	cin >>x;
	
	for(i = 0 ; i < 30 ; i++)
	{
		if( x == A[i])  // verificar se x e igual a algum elemento de A
		{
			cout << "B["<<i<<"] = "<<B[i]<<endl; // exibicao dos dados de saida 
			k++;
		}
	}
	
	if ( k == 0)
	{
		cout << "O valor "<<x<<" nao foi encontrado no vetor A... LAMENTAMOS :("<<endl; // exibicao dos dados de saida 
	}

}
