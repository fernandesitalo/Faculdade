#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Aluno{
	public:
	char nome[40];
	int mat,fr;
	float n1;
};




int main()
{
	Aluno A;
	ofstream ARQ3("ARQ3.dat");	
		
    for(int i = 0 ; i < 2 ; i++)
	{
		cin.getline(A.nome,40);
		
		cin>>A.mat>>A.fr>>A.n1;
		ARQ3.write((char*)&A,sizeof(Aluno));
		cin.ignore();
	}
	
	ARQ3.close();

}
