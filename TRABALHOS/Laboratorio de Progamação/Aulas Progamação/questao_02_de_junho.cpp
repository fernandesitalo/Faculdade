/* obtenha 100 letras do alfabeto. A seguir pedir a digitaçao de uma
determinada letra que devera ser retirada das 100 letras que foram 
obtidas e exibir as letras resultantes apos a retirada .Utilzar como 
comando de repeticao somente o camando de repeticao 'for' */

#include <iostream>

using namespace std;

int main()
{
	int i;
	char car[10],letra;
	
	cout << "Digite letras aleatorias e para cada tecle 'Enter':"<<endl;
	for(i = 0 ; i < 10 ; i++) //leitura da sequencia aleatoria de
		cin >> car[i];
	}
	
	cout << "Digite uma letra para retira-la da sequencia:"<<endl;
	cin >>letra;
	
	cout << "\n\nNova sequencia: ";
	
	for(i = 0 ; i < 10 ; i++) // varre o vetor
	{
		if(letra != car[i]) // compara com a letra a ser excluida da sequncia 
		{
			cout << car[i];
		}
	}
	cout <<endl;
	
	
	 
	

}
