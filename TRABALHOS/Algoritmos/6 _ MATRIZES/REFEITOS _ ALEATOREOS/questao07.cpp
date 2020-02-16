#include <iostream>

using namespace std;

int main()
{
	int mat[20][11]; // decalracao da matriz princiapl da questao 
	int i,j,m,n,ne;
	
	cout << "Digite o Numero de linhas(max 20): ";  // obtencao do numero de linhas 
	cin >> m;	
	cout << "Digite o numero de colunas(max 10): "; // obtencao do numero de colunas 
	cin >> n;
	
	cout << "DIGITE A MATRIZ "<<m<<" X "<<n<<" linha por linha"<<endl;  // obtencao da matriz 
	for(i = 0 ; i < m ; i++)
	{
		ne = 1 ; // novo elemento 
		
		cout << "LINHA "<<i+1<<endl;
		for(j=0 ; j < n ; j++)
		{
			cin >>mat[i][j];
			ne *= mat[i][j];
		}
		
		mat[i][j] = ne;  // novo elemento j = n+ 1 , por causa do ultimo incremento 
		cout << endl;
	}
	
	cout << "MATRIZ DIGITADA : \n\n";
	
	for(i = 0 ; i < m ; i++)  // exibicao da matriz digitada 
	{
		for(j=0 ; j < n ; j++)
		{
			cout << "  \t"<<mat[i][j];
		}
		cout <<"\n\n";
	}
	n = n + 1;
	
	cout << "NOVA MATRIZ "<<m<<" X "<<n<<" DE ACORDO COM A QUESTAO: \n\n";
	
	for(i = 0 ; i < m ; i++) // exibicao da nova matriz 
	{
		for(j=0 ; j < n ; j++)
		{
			cout << "\t"<<mat[i][j];
		}
		cout <<"\n\n";
	}
}
