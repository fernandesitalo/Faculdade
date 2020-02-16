// o numero de linhas da matriz moca e igual ao numero de coluina da matriz rapaz

#include <iostream>

using namespace std;

int main()
{
	int moca[100][60],rapaz[50][100],afinidade[50][60]; // declaracao das matrizes necessarias 
	
	int m,r,i,j,k; // declaracao de marcadores e contadores 
	
	cout << "Use : "<<endl;
	cout << "           1 - Para NAO"<<endl;
	cout << "           2 - para SIM "<<endl;
	cout << "           3 - para INDIFERENTE "<<endl;
	cout << "\n\nQuantidade de MOCAS: ";
	cin >> m;
	
	cout << "Informe: "<<endl;
	
	for(i = 0 ; i < m ; i++) 
	{
		cout << "\n***GABARITO da Moca "<<i+1<<"!***"<<endl;
		
		for(j = 0; j < 100 ; j++) 
		{
			cout << "Resposta da Pergunta "<<j+1<<" => ";
			cin>> moca[j][i];// leitura COLUNA por COLUNA ---- I e J estao invertidos !!
			
			
			while(moca[j][i] != 1 && moca[j][i] != 2 && moca[j][i] != 3) // se a resposta digitada for diferente de 1,2 e 3 , deve-se entrar no laco de repeticao ate digitar uma opcao correta 
			{
				cout << "Use somente as possiveis opcoes (1 , 2 e 3).Digite Novamente: ";
				cin >> moca[j][i];
			}
			
		}
	
	}
	
	cout << "\n\nUse : "<<endl;
	cout << "           1 - Para NAO"<<endl;
	cout << "           2 - para SIM "<<endl;
	cout << "           3 - para INDIFERENTE "<<endl;
	
	cout << "\n\nQuantidade de RAPAZES: ";
	cin >> r;
	
	cout << "Informe: "<<endl;

	for(i = 0; i < r ; i++)	
	{
		cout << "***\nGABARITO do Rapaz "<<i+1<<"!***"<<endl;
				
		for(j = 0 ; j < 100 ; j++) // leiura LINHA por LINHA 
		{
			cout << "Resposta da Pergunta "<<j+1<<" => ";
			cin>>rapaz[i][j];
			
			while(rapaz[i][j] != 1 && rapaz[i][j] != 2 && rapaz[i][j] != 3)
			{
				cout << "Use somente as possiveis opcoes (1 , 2 e 3).Digite Novamente: ";
				cin >>rapaz[i][j];				
			}
		}
	}
	
	

	for(i=0 ; i < r ; i++) // seleciona um rapaz 
	{
		for(j=0 ; j < m ; j++) //seleciona uma moca ,,,, cada vez que termina a comparacao com um rapaz, ja vem outra moca 
		{
			afinidade[i][j] = 0;
			
			for(k=0 ; k < 100 ; k++)  
			{
				if(rapaz[i][k] == moca[k][j] || rapaz[i][k] == 03 || moca[k][j] == 03) // compara as respostas do rapaz selecionado com todas as moças 
				{
					afinidade[i][j]++;
				}			
			}		
		}
	}
	
	
	cout << "\nTABELA DE AFINIDADE (RAPAZES X MOCAS)\n"<<endl;
	
	for(i = 0; i < r ; i++)	
	{
		for(j = 0 ; j < m ; j++) // leiura LINHA por LINHA 
		{
			cout <<"\t"<<afinidade[i][j];
		}
		
		cout <<"\n\n";
	}
	
	
	
	for(i = 0; i < r ; i++)	
	{
		for(j = 0 ; j < m ; j++) // leiura LINHA por LINHA 
		{
			cout <<"Rapaz "<<i+1<<" c/ moca "<<j+1<<" :: Afinidade "<<afinidade[i][j]<<endl;
		}

	}
	
	
	
}
