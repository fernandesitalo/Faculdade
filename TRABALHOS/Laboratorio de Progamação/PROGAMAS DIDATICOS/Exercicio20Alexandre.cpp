#include <iostream>
using namespace std;

int main ()
{
	float x,y;//declarar as variaveis
	//obter dados de entrada
	cout<<"Informe a coordenadas X\n";
	cin>>x;
	cout<<"Informe a coordenadas Y\n";
	cin>>y;
	
	if (x>=1 && y>=1)//verificar se esta no 1Âº quadrante
	{
		cout<<"Esta no 1º Quadrante\n";
	}
		{
		if (x<=-1 && y>=1)//verificar se esta no 2Âº quadrante
		{
			cout<<"Esta no 2º Quadrante\n";
		}
			{
			if (x<=-1 && y<=-1)//verificar se esta no 3Âº quadrante
			{
				cout<<"Esta no 3º Quadrante\n";
			}
				{
				if (x>=1 && y<=-1)//verificar se esta no 4Âº quadrante
				{
					cout<<"Esta no 4º Quadrante\n";
				}
					{
					if (x==0 && y==0)//verificar se esta no ponto central
					{
						cout<<"Esta no ponto central\n";
					}
						{
						if (x==0 || y==0)//verificar se esta sobre um dos eixos
						{
							cout<<"O ponto esta sobre um dos eixos\n";
						}
							{	
							if (y==0 && x>=1)//verificar se esta sobre o eixo X positivo
							{
							cout<<"O ponto esta no semi-eixo ṕositivo das abcisas\n";
							}
								{
								if (x==0 && y>=1)//verificar se esta sobre o eixo Y positivo
								{
								cout<<"O ponto esta no semi-eixo positivo das abcisas\n";
								}
									{
									if (x==0 && y<=-1)//verificar se esta sobre o eixo X negativo
									{
									cout<<"O ponto esta no semi-eixo negativo das abcisas\n";
									}
										{
										if (y==0 && x<=-1)//verificar se esta sobre o eixo Y negativo
										{
										cout<<"O ponto esta no semi-eixo negativo das abcisas\n";
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
