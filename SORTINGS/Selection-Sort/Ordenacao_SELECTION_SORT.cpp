/*ELABORAR UM PROGAMA PARA OBTER OS 30 ELEMENTOS DE UM VETOR DE
CARACTERES E EXIBIR O VETOR COM OS ELEMENTOS CLASSIFICADOS EM ORDEM 
CRESCENTE (ASCENDENTE)   selecao insercao -- metodos de ordenacao*/


#include <iostream>

using namespace std;

int main()
{
	char vetor[30], // vetor
		 aux; 
	
	int ind, // index --> reflete a posicao do vetor 
		indaux,
		menor;
		
//obtencao dos dados de entrada 
	for(ind = 0 ; ind < 5 ; ind++)
	{
		cout << "Informe o elemento "<<ind+1<<" do vetor: ";
		cin >> vetor[ind];
	}
//Ordenacao do vetor 
	for(ind = 0 ; ind < 5 ; ind++)
	{
//a primeira posicao sera a menor de inicio
		menor = ind;
		
		for(indaux = (ind+1) ; indaux < 5 ; indaux++)
		{
			if( vetor[indaux] < vetor[menor])
			{
				menor = indaux; // guarda a posicao do menor valor 
			}
		}
//troca a posicao ind(a primeira posicao) com a posicao menor 		
		aux = vetor[ind]; 
		vetor[ind] = vetor[menor];
		vetor[menor] = aux;
	}
	
//exibicao dos dados de saida 
	for(ind = 0 ; ind < 5 ; ind++)
	{
		cout <<vetor[ind]<<" | ";
	}
}
