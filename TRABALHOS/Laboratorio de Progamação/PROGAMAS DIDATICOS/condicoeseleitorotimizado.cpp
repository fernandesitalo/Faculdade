#include <iostream>

using namespace std;

int main()
{
	int idade;
	string mensagem;
	
	if(idade > 17) // eleitor obrigatorio -- entre 18 e 69 anos ...
		{
		if(idade < 70) 
		mensagem = "Eleitor obrigatorio";
		}
		
	else if(idade < 16)
		mensagem = "Voce não pode ser um eleitor !"; 
		
	if(idade > 15) // eleitor opcional -- 16 e 17 anos
		{
		if(idade < 18)			
			mensagem = "Voce e um eleior opcional !";
		}
		
	if(idade > 69)  // eleitor opcional acima de 69 anos ....
		mensagem = "Voce e um eleior opcional !";
			
			
	cout << mensagem <<endl; // exibicao dos resultados de saida
		
}		
