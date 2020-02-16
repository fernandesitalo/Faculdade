#include <iostream>

using namespace std;

int main()
{
	int A[20][30],  B[20][30],  C[20][30]; // Declaracao das matrizes 
	int i,j,m,n; //contadores das linhas e colunas 
	
	
	
	cout << "Digite as Dimensoes que as matrizes 'A' e 'B' terao: "<<endl;
	cout << "LINHAS(max 20): ";
	cin >> m; // guarda a quantidade de linhas da matriz 
	cout << "COLUNAS(max 30): ";
	cin >> n; // guarda a quantidade de coluna da matriz

// Leitura dos dados da matriz A	
	cout << "Digite os dados da matriz 'A' Meu querido Usuario: "<<endl;
	for(i = 0 ; i < m ; i++) 
	{
		for(j = 0 ; j < n ; j++)
		{
			cin >> A[i][j];
		}
		cout <<"\n";
	}
	
// Leitura dos dados da matriz B	
	cout << "Agora , Meu querido Usuario, Digite os dados da Matriz 'B':"<<endl;	
	for(i = 0 ; i < m ; i++) 
	{
		for(j = 0 ; j < n ; j++)
		{
			cin >> B[i][j];
		}
		cout <<"\n\n";
	}
	
// exibicao da matriz C
	cout << "MATRIZ 'C' -= MATRIZ 'C' = MATRIZ 'A' + MATRIZ 'B' =- \n\n";
	for(i = 0 ; i < m ; i++) 
	{
		for(j = 0 ; j < n ; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
			cout <<"\t"<<C[i][j];
		}
		cout <<"\n\n";
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
