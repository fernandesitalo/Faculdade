#include <iostream>

using namespace std;

int main()
{
	string nome;  // declaracao variavel literal
	float pcompra,pvenda,w,y,totalcompra,totalvenda,lucro,preju,preju_tot; //declaracao variaveis reais 
	int	x1,x2,x3; //declaracao variaveis inteiras 

	//atribuindo valores para o inicio do progama
	x1 = 0;
	x2 = 0;
	x3 = 0;	 
	totalcompra = 0;
	totalvenda = 0;
	preju = 0;
	
	cout << "ATENCAO! Para parar o progama digite 'fim' em nome da mercadoria :"; // aviso pro usuario

	
	//obtencao dos dados de entrada 
	cout << "\n\n\nNome da mercadoria : ";
	cin.ignore();
	getline(cin,nome);
	
	while (nome != "fim" && nome != "Fim" )
	{		
		cout << "Preco de compra: R$ ";
		cin >> pcompra;	
		cout << "Preco de venda: R$ ";
		cin >>pvenda; 
		cout << "----------------------------"<<endl;
		
		
		w = pcompra + pcompra * 0.10;		
		y = pcompra + pcompra * 0.30;
		
		
			if (pvenda > pcompra) // se o preço de compra for menor que o preco de venda , gerando lucro , ...
			{		
				if(pvenda < w ) // ate 10% de lucro
				{
					x1 =  x1 + 1;
				}
				else
				{
					if(pvenda >= w && pvenda <= y) // ate 30% de lucro
					{
						x2 = x2 + 1;
					}
		
					else // acima de 30 % de lucro 
					{
						x3 = x3 + 1;
					}
				}
			}
			else // qndo o prco de compra e maior que o de venda gerando prejuizo
			{
				preju = pcompra - pvenda;
				preju_tot = preju_tot + preju;
			}
			
		totalcompra = totalcompra + pcompra;  
		totalvenda = totalvenda + pvenda;
	
		//obtencao dos dados de entrada 	
		cout << "Nome da mercadoria: ";
		cin >> nome ;		
	}		
	
	lucro = totalvenda - totalcompra - preju; // lucro da compra 
	
	//exibcao dos resultados de saida 	
	cout << "\n\n===Lucro ate de 10 %: "<<x1<<" mercadorias"<<endl;	
	cout << "===Lucro entre 10 % e 30 %: "<<x2<<" mercadorias"<<endl;	
	cout << "===Lucro acima de 30%: "<<x3<<" mercadorias"<<endl;
	
	cout << "\n\n==Valor total de compra: R$ "<<totalcompra<<endl;
	cout << "==Valor total de venda : R$ "<<totalvenda<<endl;
	
	
	if(lucro < 0) // lucro negativo que significa prejuizo
	{
		cout << "\n\n=Prejuizo total: R$ "<<preju_tot;	
	}	
	
	else // lucro positivo  
	{
		cout << "\n\n=Lucro total: R$ "<<lucro;  
	}
}




















