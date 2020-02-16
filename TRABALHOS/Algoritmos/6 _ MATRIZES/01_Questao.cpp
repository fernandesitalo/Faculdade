#include <iostream>

using namespace std;

int main()
{
	float soma;
	int i,j;
//inicializacao da matriz assim como manda a questao	
	float A[5][6]= {175  ,225  ,10   ,9000 ,3.7  ,4.75 ,
			9.8  , 100 , 363 , 432 , 156 , 18  ,
			40.0 , 301 , 30.2, 6381, 1   , 0   ,
			402.0, 4211, 7213, 992 , 442 , 7321,
			21.0 , 3   , 2   , 1   , 9000, 2000};

// exibicao da matriz para o Sr. usuario 		
	cout << "SEJA A MATRIZ 'A' DADA NA QUESTAO 01 :\n\n"; 		
	for(i=0 ; i<5 ; i++)
	{
		for(j=0 ; j<6 ; j++)
		{
			cout <<"\t"<<A[i][j];
		}
		cout<<"\n\n";
	}
	
//	respostas 	
	cout << "A) Fazem parte dessa matriz exatamente 30 elementos, pois sao 5 linhas e 6 colunas ...Portanto 6*5 = 30 !\n\n\n";
	
	cout << "B) O elemento A[4]][5] = "<< A[3][4]<<"\n\n\n";
	
	cout << "C) Apos o Comando X = A[3][2] + A[5][1] , X equivale a "<<A[2][1] + A[4][0]<<"\n\n\n";
	
	cout << "D) Caso fosse referenciado o elemento A[6][2] seria usado o 'lixo' contido nessa variavel \n\n\n";
	
	
	j = 3; // quarta coluna	
	for(i = 0,soma = 0 ; i < 5 ; i++)
	{
		soma += A[i][j];	
	}	

	cout << "E) Soma dos elementos da quarta coluna: "<<soma<<"\n\n\n";
	
	
	i = 2; // terceira lnha	
	for(j = 0,soma = 0 ; j < 5 ; j++)
	{
		soma += A[i][j];	
	}	

	cout << "F) Soma dos elementos da terceira Linha: "<<soma<<"\n\n\n";		
}


