#include <iostream>

using namespace std;

int main()
{
	int A[3][3] = {2,1,0,1,3,2,-1,2,1}
	,B[3][2] = {1,2,2,0,-1,1}
	,C[3][2] = {0,0,0,0,0,0};
	
	int ia,ja,ib,jb;
	int k,w,y;
	
	ia = 3;  // linhas mtariz A
	ja = 3; //colunos Matriz A
	
	ib = 3;    // linhas mtariz B
	jb = 2;   //colunos Matriz B

    cout << "MATRIZ A \n\n";
	for(k = 0 ; k < ia ; k++) // exibicao da matriz A
	{
		for(w = 0 ; w < ja ; w++)
		{
			cout <<"\t"<<A[k][w];
		}
		cout <<"\n\n";
	}
	cout <<"==================================="<<endl;
	
	cout << "MATRIZ B \n\n";
	for(k = 0 ; k < ib ; k++) // exibicao da matriz B
	{
		for(w = 0 ; w < jb ; w++)
		{
			cout <<"\t"<<B[k][w];
		}
		cout <<"\n\n";
	}

	
//multiplicacao das duas matrizes 
		for( k = 0 ; k < ia ; k++)  // linhas da matriz C
		{
			for(w = 0 ; w < jb ; w++)  // Colunas da matriz C
			{
				for(y = 0 ; y < ja ; y++)  
				{
					C[k][w] += A[k][y]  *  B[y][w];  
				}
			}
		}
		
	cout << "==================================="<<endl;
	cout << "MATRIZ A * MATRIZ B \n\n";
		for(k = 0 ; k < ia ; k++) // exibicao da matriz C
		{
			for(w = 0 ; w < jb ; w++)
			{
				cout <<"\t"<<C[k][w];
			}
			cout <<"\n\n";
		}
}
