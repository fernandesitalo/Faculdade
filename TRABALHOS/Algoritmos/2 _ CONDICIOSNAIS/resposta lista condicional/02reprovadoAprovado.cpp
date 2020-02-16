#include <iostream>
#include <string>

using namespace std;

int main()
{
	float n1,n2,n3,media; // declaração das variaveis 
	string cod; 
	
	// obtencao dos dados 
	cout << "Digite o codigo do aluno: ";
	cin >> cod;	
	cout <<"Nota 1: ";
	cin >> n1;	
	cout << "Nota 2: ";
	cin >> n2;	
	cout << "Nota 3: ";
	cin >> n3;		
	
	//calculos 
	
		if(n1 > n2) 
		{
			if(n1 > n3)    // n1 e a maior nota
			{
				media=(n1*4 + n2*3 + n3*3) / 10;
			}
				else
				{
					media = (n3*4 + n2*3 + n1*3) / 10;
				} 
		}			
			else // n1 nao e a maior , entao a maior e n2 ou n3
			{	
		  		media = (n2*4 + n1*3 + n3*3) / 10;					
			}			
							
	//exibição dos resultados de saida 		
	cout << "\n\nCodigo do aluno: "<<cod<<endl;
	cout << "Notas: "<<n1<<","<<n2<<","<<n3;
	cout << "\nMedia Ponderada: "<<media<<endl;
	


	// condicao de aprovacao 
		if(media > 4)   
		{
		cout << "Aprovado!"<<endl;
		}
			else
			{
			cout <<"Reprovado!"<<endl;			
			}
	return 0;
}
