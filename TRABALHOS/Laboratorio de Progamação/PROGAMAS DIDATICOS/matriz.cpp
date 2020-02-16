#include<iostream>
using namespace std;
int main()
{
	int linha = 3, coluna = 4, i, j;
	int a[linha][coluna], t[coluna][linha];
	//ler a matriz
	for( i = 0; i < linha; i++ )
	{
		for( j = 0; j < coluna; j++ )
		{
			cout<<"a["<< i + 1 << "," << j + 1 << "]";
			cin>> a[i][j];
		}
	}
	for( i = 0; i < linha; i++ )
	{
		for( j = 0; j < coluna; j++ )
		{
			cout<< a[i][j] <<"\t";
		}
		cout<<endl;
	}
	cout<<"Matriz transporta: "<<endl;
	for( i = 0; i < coluna; i++ )
	{
		for( j = 0; j < linha; j++ )
		{
			t[i][j] = a[j][i];
		}
	}
	for( i = 0; i < coluna; i++ )
	{
		for( j = 0; j < linha; j++ )
		{
			cout<<t[i][j]<<"\t";
		}
		cout<<endl;
	}
	
}
