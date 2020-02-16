#include <iostream>

using namespace std;

int main()
{	
	int mat[20][20]; // declaracao da matriz necessaria 
	
	int i,j,m; // declaracao de contadores e marcadores 
	
	cout << "Informe o valor de M para a matriz M x M (max 20): "; //obtencao dos dados de entrada 
	cin >>m;
	
	cout << "Digite os valores da Madtriz "<<m<<" x "<<m<<" : "<<endl;
	
//obtencao dos dados de entrada 	
	for(i=0 ; i < m ; i++)
	{
		for(j=0 ; j < m ; j++)
		{
			cin >>mat[i][j];
		}
		cout <<endl;
	}
//exibicao dos dados de saida 
	for(i=0 ; i < m ; i++)
	{
		for(j=0 ; j < m ; j++)
		{
			cout << "\t"<<mat[i][j];
		}
		cout <<"\n\n";
	}	

// verificar se a matriz e ou nao simetrica da seguinte maneira 
	for(i=0 ; i < (m-1) ; i++)
	{
		for(j= (i+1) ; j < m ; j++)
		{			
			if(mat[i][j] != mat[j][i])
			{
				j = m;
				i = m;				
				cout << "A matriz nao e simetrica..."<<endl;
			}
		}
	}
// neste caso foram analizadas todas possibilidades no ultimo for , por isso a matriz e simetrica 	
	if(i == (m-1)) 
	{
		cout << "A matriz e simetrica !"<<endl;
	}
	
	
	
	
	
}
