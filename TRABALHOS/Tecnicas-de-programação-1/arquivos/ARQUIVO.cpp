#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int main()
{
	
	string nome;
	float nota;
	
	ofstream ARQ;	
	ARQ.open("arqTeste.txt");
	
	
	getline(cin,nome);
	while(nome != "fim")
	{
		cin >> nota;		
		ARQ << nome << "\n" << nota << "\n";
		
		cin.ignore();
		getline(cin,nome);
				
	}
	
	ARQ.close();
	
	
	
	
	
	
}
