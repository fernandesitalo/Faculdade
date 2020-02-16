#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{


	string nome;
	float nota;
	
	ifstream ARQ;	
	ARQ.open("arqTeste.txt");
		
    while(getline(ARQ,nome))
	{
		ARQ >> nota;		
		cout << nome << " - " << nota << "\n";
		ARQ.ignore();		
	}
	
	ARQ.close();
	



}
