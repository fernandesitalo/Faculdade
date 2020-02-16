#include <iostream>

using namespace std;

int main()
{
	int tabela[10][4],aux,lucro = 0,preju = 0,i,j = 0,voo;
	float preco[10];
	long long int id;	
	
	cout << "                                  -:: COMPANHIA AEREA DO ZE TIAO ::-"<<endl;
	cout << "                         SEJA BEM VINDO AO SISTEMA OTIMIZADO DE GESTAO DE VOO's \n"<<endl;
/* tavela[10][4] e uma matriz ... a primeira coluna tabela[i][0] armazena o numero do voo ,  a segunda coluna tabela[i][1]armazena o tipo do aviao ,
a terceira coluna tabela[i][2] armazena a lotacao maxima . a quarta coluno tabela[i][3] armazena a quantidade de reservas naquele aviao*/	
	
// leitura dos doados dos 10 voos 	
	for( i = 0 ; i < 2 ; i++)
	{
		for(j = 0 ; j < 3 ; j++)
		{				
					
			if(j == 0) // primeiro dado a ser obtido e o j = 0
			{			
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";				
				cout << " >> Numero do voo : ";
				cin >>tabela[i][j];				
			}
			else
			{
				if( j == 1) // segundo dado a ser obtido e o j = 1
				{
					cout << " >> Tipo de AVIAO (707,727,737): ";
					cin >> aux;    // fazer validacao
					
						while((aux != 707) && (aux != 727) && (aux != 737))
						{
							cout << "Nao temos este aviao na compania aerea. Digite Novamente : ";
							cin >> aux;
						}
											
					tabela[i][j] = aux;							

					if(tabela[i][j] == 707)// completa dos dados da quarta coluna da tabela com a capacidade de cada aviao 
					{
						tabela[i][2] = 5; // lotacao maxima 
						tabela[i][3] = 0;  // quantidade de reservas  
					}
					else
					{
						if(tabela[i][j] == 727)
						{
							tabela[i][2] = 170;   // lotacao maxima 
							tabela[i][3] = 0;     // quantidade de reservas
						}
						else
						{
							tabela[i][2] = 120;   // lotacao maxima 
							tabela[i][3] = 0;     // quantidade de reservas
						}
					} 										
				}
				else // terceiro dado a ser obtido
				{
					cout << " >> Preco da passagem: R$";
					cin >> preco[i];					
					cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";	
				}				
			}		
		}
	}	
// leitura dos pedidos de reserva

	cout << "============================\n"<<endl;
	cout << ":: Digite o o numero da IDENTIDADE do passageiro: ";
	cin >> id;
	while( id != 0)
	{
		cout << "      >> Numero do voo desejado: ";
		cin >> voo;
		
		for(i = 0 ; tabela[i][0] != voo ; i++); // vare a matriz na coluna 0 que guarda o numero dos voo  -- FOR DO CACHORRO 	
	
		if(tabela[i][3] < tabela [i][2]) // CONFIRMACAO DO PEDIDO DE RESERVA 
		{
			cout << "\n        => Identidade: "<<id<<endl;
			cout << "        => Voo desejado: "<<voo<<endl;
			cout << "        => Situacao : RESERVA CONFIRMADA!"<<endl;
			tabela[i][3]++;
		}
		else // CONFIRMACAO DO PEDIDO DE RESERVA 
		{
			cout << "\n      X Identidade: "<<id<<endl;
			cout << "      X Voo desejado: "<<voo<<endl;
			cout << "      X Situacao: VOO LOTADO! LAMENTAMOS rsrs"<<endl;
		}
			cout << "===========================\n"<<endl;
		cout << ":: Digite o o numero da IDENTIDADE do passageiro: ";
		cin >> id;
	}
	
	for(i = 0 ; i < 2 ; i++)
	{			
		cout << "\n\n\n            -= ESTATISTICA do VOO "<<tabela[i][0]<<" =-"<<endl;					

// aux calcula a porcentagem das reservas de cada voo
		aux =  (tabela[i][3] * 100.0) / tabela[i][2] ; // 	tabela[i][3] => qunatidade de reservas 
						
			if(aux > 60.0)
			{  				
				cout << " => Lucro -- "<<aux<<" % das reservas Vendidas\n\n\n\n";//exibicao dos dados de saida 
				lucro++;
			}
			else
			{
				if(aux < 60.0)
				{
					cout << "          => Prejuizo -- "<<aux<<" %  das reservas Vendidas\n\n\n\n"; //exibicao dos dados de saida 
					preju++;
				}
				else
				{
					cout << "          => NEM PREJUIZO , NEM LUCRO ....."<<endl;		//exibicao dos dados de saida 			
				}	
			}
		}		
		
		if((lucro - preju) > 0) 
		{
			cout << "A COMPANHIA AEREA LUCROU "<<endl;//exibicao dos dados de saida 
		}
		else
		{
			if((lucro - preju) < 0)
			{
				cout << "A COMPANHIA AEREA OBTEVE PREJUIZOS" <<endl; //exibicao dos dados de saida 
			}
			else
			{
				cout << "NAO FORAM OBTIDOS LUCROS NEM PREJUIZOS"<<endl;//exibicao dos dados de saida 
			}
		}		
	}
	


