#include <iostream>

using namespace std;

int main()
{
	char MATRIZ_BIBLIOTECA[48000][420000];
	

	cout << "\nSão 8 departamentos, cada um com 40 estantes e cada estante com 150 livros , portanto   8*40*150 = 48000 LIVROS"<<endl;
	
	cout << "\nCada livro tem 200 paginas , cada pagina com 35 linhas e 60 colunas, portanto 200*60*35 = 420000"<<endl; 
	
	cout << "\nCada linha da matriz contera os caracteres de um livro Padrao da Biblioteca !"<<endl;
	
	cout << "\nENTAO A MATRIZ SERA DECLARADA DA SEGUINTE FORMA: \n\n char MATRIZ_BIBLIOTECA[48000][420000]";
}
