#include <iostream>

using namespace std;

int main()
{
	// Declaracao das variaveis necessarias 
	char id,presenca;
	int matriculados,t,a,ausentes,x;
	float pa; // porcentagem de ausentes
	string matricula;
	
	ausentes = 0; //variavel de inicializacao
	x = 0;	//variavel de inicializacao
	
	for(t = 0; t < 2; t++ )
	{
		cout << "Identificacao da turma: "; // recebendo dados de entrada
		cin >> id;
		
		while(id < 65 || id > 122)   //validando dados de entrada 
		{
			cin.ignore(0);
			cout << "DIGITE UMA IDENTIFICACAO VALIDA: ";			
			cin >> id;			
		}
		
		cout << "Numero de alunos matriculados Nesta Turma: ";// recebendo dados de entrada
		cin >> matriculados;
		
		for(a = 0; a < matriculados; a++)
		{
			cout <<"____________________________________________________"<<endl;
			cout << "------Numero de Matricula do aluno: ";
			cin.ignore();
			getline (cin,matricula);			
		
			
		
			 if (presenca == 'a'|| presenca == 'A')
			 {
			 	ausentes++; //contador de ausentes 
			 }
		
		    cout << "------Presenca: ";
		    cin >>presenca;
		
			while(presenca != 'a' && presenca != 'A' && presenca != 'p' && presenca != 'P') //validando dados de entrada 
			{
			 	cout << "DIGITE UMA PRESENCA VALIDA: (A / P): ";
			 	cin.ignore();
		 		cin >>presenca;
		 	}			
		}
		
		pa = (ausentes * 100)/matriculados;
		//Exibindo resultados parciais 
		cout << "\n              ======================================"<<endl;
		cout << "              ==> Turma: "<<id<<" \n              ==> Porcentagem de ausentes: "<<pa<<"%"<<endl;
		cout << "              ======================================\n\n"<<endl;
		
		if(pa > 5.0)
		{
			x++;
		}
		 ausentes = 0;
	}
	//exibindo resultado final 
	cout << "\n\n==> Numero de turmas com ausencia superior a 5%: "<<x<<endl;
	
}
