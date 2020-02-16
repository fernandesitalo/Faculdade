#include <iostream>

using namespace std;

int main ()
{
	float x,y;    
	string mensagem;  // declaração das variaveis
	
	cout << "Digite a abcissa do ponto e tecle 'Enter': "; 
	cin >> x; 
	
	cout << "Digite a ordenada do ponto e tecle 'Enter': ";
	cin >> y;
	
	// condicoes 
	if(x==0 && y==0)
	{
	mensagem = "O ponto e a origem do plano cartesiano\n";
	}	 
		else 
		{			
	 		if(x>0 && y>0)
	 		{
	 		mensagem = "O ponto esta no primeiro quadrante!\n";
			}
				else
				{
				 	if(x<0 && y>0)
	 				{
	 				mensagem = "O ponto esta no segundo quadrante!\n";
					}
						else 
						{			
							if (x<0 && y<0)
							{
							mensagem = "O ponto esta no terceiro quadrante!\n";
							}
					
								else
								{
									if(x>0 && y<0)											
									{
									mensagem = "O ponto esta no quarto quadrante!\n";
									}
						
	 									else
										{
											if(x==0)
	 										{
	 										mensagem = "O ponto passa pelo eixo das ordenadas!\n";
											}
							
												else
												{
													if(y==0)
													{
													mensagem = "O ponto passa pelo eixo das coordenadas!\n";
													}
												}
										}
								}
						}
				}
	   	}
		cout << mensagem;
}
