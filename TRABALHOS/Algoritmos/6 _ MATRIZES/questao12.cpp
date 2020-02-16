#include<iostream>

using namespace std;

int main()
{
	float tabela[15][11]; /* coluna zero  guarda o codigo da atividade 	
	 Da coluna 1 a coluna 7 sao armazenados as quantidades de cada recurso  
	 coluna oito armazena o preco unitario de custo - item D.1
	 coluna nove Armazena o preco unitario para se obter um lucro de 36% - item D.2
	 coluna dez  armazena a taxa de LEIS SOCIAIS - item D.3*/

	float fixos[4][7] = {50.0, 0.4, 0.6, 5.0, 3.0, 0.0, 3.0,   //Fundacao
						 20.0, 0.3, 0.0, 2.0, 1.0, 100, 1.0,   //Alvenaria
				  		 70.0, 0.3, 0.7, 6.0, 3.0, 0.0, 35.0,  //Estrutura
						 40.0, 0.2, 0.0, 9.0, 5.0, 0.0, 1.0};  //Acabamento
	
	float preco[7]; // vetor que guarda os precos do recurso
	
	float aux,perc,soma; //declaracao das variaveis reais Necessarias 
	int i,j,k;   //declaracao das variaveis inteiras Necessarias 
	
	
	
// ler o percentual de administracao do mes 	
	cout << "Informe o Percentual de Administracao do mes : %";
	cin >> perc;
	
// ler os custos unitarios dos setes recursos envolvidos 
	cout << "\n\nInforme: \n\n";	
	for(i = 0 ; i < 7; i++)
	{
		cout << "Preco do Recurso "<<i+1<<" R$ ";
		cin >> preco[i];
	}	

// ler um conjunto indeterminado de dados (max 15) contendo os quantitativos de recursos envolovidos em cada atividade 
	cout << "\n =>  Codigo da Atividade: ";
	cin >> aux ;
	
	k = 0;
	while( aux != 0 && k < 15)
	{
		soma = 0;
		
		tabela[k][0] = aux; // COLUNA 00
				
		for(j = 1 ; j <= 7 ; j++)// COLUNA 01 A COLUNA 07
		{
			cout << "Quantitativo do recurso "<<j<<" :";
			cin >> tabela[k][j];
			
			soma += (tabela[k][j] * preco[j-1]);
		}
		tabela[k][8] = soma + (soma *(perc/100.0));		
		
		cout << "\n =>  Codigo da Atividade: ";
		cin >> aux ;
		k++;		
	}
	
//calcular e imprimir o Preco unitario de custo(direto + adm) de cada Atividade
	cout << "\n(D.1):::: Preco unitario de custo(direto + adm) de cada Atividade :::: \n\n";	 
	for( i = 0 ; i < k ; i++)  
	{
		cout << "                       Atividade -="<<tabela[i][0]<<"=- R$ "<<tabela[i][8]<<endl;;		
	}
	
// 36% de lucro em cada atividade 
	cout << "\n\n(D.2)::::Para se obter lucro 36%, cada atividade passara a ter o seguinte preco::::\n\n"; // COLUNA 08
	for( i = 0 ; i < k ; i++ )  
	{
		tabela[i][9] = tabela[i][8] + ( tabela[i][8] * 0.36);
		
		cout << "                       Atividade -="<<tabela[i][0]<<"=- R$ "<<tabela[i][9]<<endl;		
	}
	
//16% de leis sociais 
	cout << "\n\n(D.3)::::Quantia a ser recolhida em cada atividade ,referente a LEIS SOCIAIS (16%):::: \n\n"; // COLUNA 09	
	for(i = 0 ; i < k ; i++)
	{
		tabela[i][10] = (tabela[i][3] * 1.6 )+ (tabela[i][4] * 1.6);
		
		cout << "                       Atividade -="<<tabela[i][0]<<"=- R$ "<<tabela[i][10]<<endl;		
	}
	
	
/*D.4*/
	cout << "\n\n(D.4)::::COTACAO DE UMA OBRA PRE DEFINIDA :::::\n\n";
	for(i = 0 ; i < 4 ; i++)
	{
		aux = 0;		
			switch(i)
			{
			case 0:
				cout <<"     FUNCACAO : "<<fixos[i][0]<<" METROS CUBICOS ---- R$ ";
				break;
			
			case 1:
				cout <<"    ALVENARIA : "<<fixos[i][0]<<" METROS QUADRADOS -- R$ ";
				break;
				
			case 2:
				cout <<"    ESTRUTURA : "<<fixos[i][0]<<" METROS CUBICOS ---- R$ ";
				break;
				
			case 3:
				cout <<"   ACABAMENTO : "<<fixos[i][0]<<" METROS QUADRADOS--- R$ ";
				break;
			}			
		for(j = 0 ; j < 7 ; j++)
		{ 
			aux += (preco[j] * fixos[i][j]);	
		}		
		cout <<aux<<endl<<endl;		
	}
/*D.5*/	
	cout << "(D.5):::: QUANTIDADE TOTAL DE RECURSOS PARA A OBRA COTADA ::::"<<endl;
	for(j = 0 ; j < 7 ; j++)
	{
		aux = 0;
		
		for(i = 0 ; i < 4 ; i++)
		{
			aux += fixos[i][j];			
		}		
		cout << "                  Recurso "<<j+1<<" : "<<aux<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
