#include <iostream>

using namespace std;

int main()
{
	//decalracao das variaveis necessarias 
	float masc,fem,pf,concorrencia,maior,maiorcc,codmaiorcc;
	int codcurso,x,tot,vagas;	
	// variaveis de inicializacao 
	maior = -1;	
	tot = 0;	
	codmaiorcc=0;
	maiorcc=0;	
	
	cout << "Para indicar o fim dos cursos , Digite '0' em cod do curso"<<endl;//informando o flag para o usuario	
	cout <<"Digite o CODIGO do curso: "; // dados iniciais 
	cin >> codcurso;
	
	while(codcurso != 0)
	{
		//obtencao do restante dos dados 
		cout << "Digite o numero de Vagas: ";
		cin >>vagas;
		cout << "Canditados do sexo masculino: ";
		cin >>masc;
		cout << "Canditados do sexo Feminino: ";
		cin >>fem;
		
		concorrencia = (masc+fem)/vagas; // candidatos por vaga
		pf = (fem*100)/(fem+masc);   // porcentagem de canditados do sexo feminino 
	
		cout << "\n\n                    _________________________________________________________"<<endl;
		cout << "                       ==> Codigo do Curso: "<<codcurso<<endl;
		cout << "                       ==> Candidatos por vaga: "<<concorrencia<<endl;
		cout << "                       ==> Porcentagem de canditados do sexo feminino: "<<pf<<"%"<<endl;
		cout << "                    _________________________________________________________\n\n"<<endl;
	
		if(concorrencia > maior)  // designar qual a maior concorrencia 
		{
			maiorcc = concorrencia;
			codmaiorcc= codcurso;
		}
	
		x = masc + fem; // variavel para somar o total de variaveis do curso em questao 	
		tot = tot + x;	//total de vestibulandos 
	
		cout <<"Digite o CODIGO do curso: ";
		cin >> codcurso;
	}	
	cout << "\n\nO curso "<<codmaiorcc<<" e o curso de maior concorrencia contendo "<<maiorcc<<" Canditados/Vaga"<<endl;	
	cout << "Total de Candidatos: "<<tot<<endl;	
}
