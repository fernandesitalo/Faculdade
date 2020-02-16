#include <iostream>

using namespace std;

int main()

{
   int n;    //declaracao da variavel
   
   cout << "Digite sua nota: ";   
   cin >> n;   
   
		if(n>=9)
		{ // se a nota maior igual a 9 ...
		n = 10;
		}
	
			else
			{ // senao ....
			n = n+1;
			}
			
   cout << "Nota atualizada: "<<n; //exibicao dos resultados de saida 
  
   return 0; // fim do progama
}
