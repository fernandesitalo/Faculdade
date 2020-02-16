/* elaborar um progama para verificar se uma determinada pessoa pode:
	A- ser eleitora obrigatoria
	B- ser eleitora opcional
	C- nao ser eleitora
	
	( menor que 16 anos não pode ser eleitor , acima de 16 e abaixo de 18 opcional,
	  acima de 18 e abaixo de 70 obrigatoria , acima de 70 opcional)*/
	  
// progama sem colectivos logicos , somente com o comando if , didatico....	  
	 
#include <iostream>

using namespace std;

int main ()
{
	int idade; //declaracao variavel numerica
	string mensagem; // declaracao variavel literal
	
	cout << "Digite sua idade: ";
	cin >> idade;
	
	//condicoes - calculos
	
	if(idade > 17)   // eleitor obrigatorio entre 18 e 69 anos ....
		if(idade < 70)  
		mensagem = "Voce e um eleitor obrigatorio !";  
		
		
	if(idade < 16)  // ate 15 anos vc não pode votar
	mensagem = "voce nao pode ser eleitor !";
		
		
	if(idade > 15) // eleitor opcional -- 16 e 17 anos
		if(idade < 18)			
			mensagem = "Voce e um eleior opcional !";
		
		
	if(idade > 69)  // eleitor opcional acima de 69 anos ....
		mensagem = "Voce e um eleior opcional !";
			
			
	cout << mensagem<<endl; // exibicao dos resultados de saida
}
		
	
			
			
	  	
