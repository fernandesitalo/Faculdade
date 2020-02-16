//       02 DE MAIO DE 2016 

/*Elaborar um progama para obter os N(N<=20) elementos inteiros de um vetor 'A' e obter e exibir
um vetor 'B' a partir do vetor'A' estruturado de ordem inversa do mesmo */
#include <iostream>

using namespace std;

int main()
{
	int vetor[20],novo[20],i,num,a; // declaracao das variaveis necessarias 
	
	cout << "Digite o numero elementos do vetor em questao que seja ate 20: ";
	cin >> num; // obtencao do numero de elementos do vetor 
	
	cout << "Digite os "<<num<<" elementos do vetor: "<<endl;

	for(i = 0 ; i < num ; i++)
	{
// obtencao do vetor inicial de 'num' elementos 
		cin >> vetor[i];
	}
	
// (num - 1) pois a contagem comeca do zero !
	for(i = (num-1) , a = 0 ; i >= 0 ; i--,a++) 
	{
// pegamos o ultimo elemento do vetor e atribuimos ao primeiro elemento de um novo vetor 
		 novo[a] = vetor[i] ;
	}
	
	cout << "Nova Vetor com sequencia invertida : "<<endl;
//exibicao do novo vetor 
		for(a = 0 ; a < num ; a++)  
		{
			cout <<novo[a]<<endl;
		}
}
