#include <iostream>

using namespace std;

int main()
{
	int i,j,municipio,estado,soma = 0,maior = -1; // variaveis inteiras necessarias 
	long long int pop[23][10]; // matriz que guarda as populacoes 
	float media;  //variavel real
	
// obtencao dos dados de entrada 	
	cout << "Digite as seguintes populacoes: "<<endl;  
	for(i=0 ; i<23 ; i++)
	{
		for(j=0 ; j<10 ; j++)
		{
			cout << "Estado "<<i+1<<" Municipio "<<j+1<<" :";
			cin >> pop[i][j];
		}
	}
		
//Detecta o Municipio MAIS populoso
	for(i=0 ; i<23 ; i++) 
	{
		for(j=0 ; j<10 ; j++)
		{
			if(pop[i][j] > maior)
			{
				maior = pop[i][j];
				estado = i;
				municipio = j;
			}
		}
	}
//exibicao dos dados de saida -- municicio mais populoso	
	cout << "\nO Municipio "<<municipio+1<<" do estado "<<estado+1<<" tem a maior populacao do pais!\n\n";

//Media da populacao das capitais dos 23 estados
	for(i=0 ; i<23 ; i++)
	{
		soma += pop[i][0];
	}
	
	media = soma/23.0;
//exibicao dos dados de saida 	-- media das capitais dos 23 estados
    cout << "Media das Capitais dos 23 estados: "<<media<<endl;   
}
    
    
    
    
    
