#include <iostream>

using namespace std;

int main()
{
	// decalracao das variaveis necessarias 
	string matricula,codigo;
	float n1,n2,n3,ntfinal,maior,menor,media,somant;
	int freq,x,i,reprovado;
	//variaveis de inicializacao
	menor = 100000000;
	maior = -1;
	x = 0;
	reprovado = 0;

	for(i = 0; i < 100 ; i++) // para(variavel de inicializacao ; condicao ; incremento)
	{
		//obtencao dos dados de entrada 
		cout << "Numero de Matricula: ";
		cin.ignore();
		getline (cin,matricula);
		
		cout << "Nota 1 : ";
		cin >> n1;
		cout << "Nota 2 : ";
		cin >> n2;
		cout << "Nota 3 : ";
		cin >> n3;		
		cout << "Numero de aulas frequentadas: ";
		cin >>freq; 
		
		ntfinal = (n1+n2+n3)/3; // media aritmetica das 3 notas 
		
		if(ntfinal > maior) // designar a maior nota 
		{
			maior = ntfinal;
		}	
			if(ntfinal < menor) // designar a menor nota 
			{
				menor = ntfinal;
			}		
		if(ntfinal >= 6 && freq >= 40) // condicao de aprovados 
		{
			codigo = "APROVADO!";
		}
		else  // se nao for aprovado sera reprovado 
		{
		reprovado++;
		codigo = "REPROVADO!";		
			if(freq < 40)
			{
				x++;
			}
		}			
		// exibicao dos resultados parciais 
		somant = somant + ntfinal;
		cout << "\n              _______________________________________"<<endl;
		cout << "              ==>Matricula do Aluno: "<<matricula<<endl;
		cout << "              ==>Frequencia do Aluno : "<<freq<<endl;
		cout << "              ==>Nota Final do Aluno : "<<ntfinal<<endl;
		cout << "              ==>O aluno esta "<<codigo<<endl;		
		cout << "              _______________________________________\n"<<endl;
	}
	//exibicao dos resultados finais
	media = somant/100;	
	cout << "Menor Nota da Turma: "<<menor<<endl;
	cout << "Maior Nota da Turma: "<<maior<<endl;
	cout << "Media de Notas da Turma: "<<media<<endl;
	cout << "Total de Reprovados: "<<reprovado<<endl;
	cout << "Total de Reprovados por falta: "<<x<<endl;
}
