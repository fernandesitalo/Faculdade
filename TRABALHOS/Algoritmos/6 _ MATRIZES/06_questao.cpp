#include <iostream>

using namespace std;

int main()
{
	int A[20][50],At[50][20]; // Declaracao do vetor
	int m,i,j,n; //contadores das linhas e colunas 
	
	
	
	cout << "Digite as Dimensoes que a matriz 'A' tera: "<<endl; //coleta de dados 
	cout << "LINHAS(max 20): ";
	cin >> m;
	cout << "COLUNAS(max 50): ";
	cin >> n;
	
	cout << "Digite os dados da matriz Sr.usuario "<<endl;
	for(i = 0 ; i < m ; i++) // Leitura dos dados da matriz A
	{
		for(j = 0 ; j < n ; j++)
		{
			cin >> A[i][j];
		}
		cout <<"\n";
	}
	
	
	for(i = 0 ; i < n ; i++) // o numero de linhas passa a ser o numero de colunas e o numero de colunas passa a ser o numero de linhas 
	{
		for(j = 0 ; j < m ; j++)
		{
			At[i][j] = A[j][i]; // fixa a coluna e varia as linhas 
		}
	}
	
	
	
	cout << "=> TRANSPOSTA DA MATRIZ 'A' \n\n";
	for(i = 0 ; i < n ; i++) // o numero de linhas passa a ser o numero de colunas e o numero de colunas passa a ser o numero de linhas 
	{
		for(j = 0 ; j < m ; j++)
		{
			cout <<"\t"<<At[i][j];
		}
		cout <<"\n\n";
	}

}
