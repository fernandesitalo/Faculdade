/*  progama pega as 2 maiores notas de 3 ,soma-as e
	divide por 2 ... condicoes para indentificar as 
    2 maiores.....*/

#include<iostream>

using namespace std;

int main ()
{
	float n1,n2,n3,M; //declaracao das variaveis 
	
	cout << "digite a Nota 1 e tecle 'Enter': ";
	cin >> n1;
	
	cout << "digite a Nota 2 e tecle 'Enter': ";
	cin >> n2;
	
	cout << "digite a Nota 3 e tecle 'Enter': ";
	cin >> n3;
	
	
	//condicoes
	
	if(n1<n2 && n1<n3)
	{ //n1 e a menor
	M = (n2+n3)/2;
	}
	
		else 
		{ // n1 nao e a maior 
			
			if(n2<n3)
			{ // n2 e a menor 
			M = (n1+n3)/2;
			}
			
				else
				{ // n3 e a menor
				M = (n1+n2)/2;
				}
		}	
	cout << "\nmedia eh: "<<M<<endl;
	
	return (0); //fim prognotas
}	
	
	
	
	
	
	
	
