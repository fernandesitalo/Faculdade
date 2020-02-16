#include <stdio.h>
#include <math.h>

/*FUNCAO QUE DESCOBRE O COSSENO DO ANGULO EM RADIANOS*/
double mycos(double x)
{
	double termo = 1,coseno = 0,n;
	
	for(n = 1; fabs(termo) > 0.000001 ; n++) // n e usado para calcular o fatorial!
	{		
		coseno += termo;// coseno sera meu somatorio		
		termo *= -1 *  (x * x) / ((n * 2)*(n * 2 - 1));	// calculo pelo termo anterior	 
	}
	return coseno;
}

/*FUNCAO QUE DESCOBRE O SENO DO ANGULO EM RADIANOS*/
double myseno(double x)
{
	double termo = x,seno = 0,n;
				
	for(n = 1;fabs(termo) >= 0.000001 ; n++) // n e usado para calcular o fatorial
	{		
		seno += termo;	
		termo *= (x * x) / ((n*2)*(n*2+1)) * -1;// recorrencia	- calcular os proximos termos a partir dos anteriores
	}		
	return seno;	
}


/* FUNCAO TANGENTE */
bool mytan(double x, double *tan_aux)
{	
	int i;
	
	for(i = 1 ; i * (M_PI * 0.5) < x ; i+=2); // poderia verificar se cos x e igual a zero, pois nao existe 1/0 por exemplo , isto tende ao infinito
	if(i * (M_PI * 0.5) == x)                 // porem isso nao teria graca ...	
	{
		*tan_aux = 0; // retorno um valor pra depois nao dar merda no progama
		return false;
	}
							
	*tan_aux = myseno(x)/mycos(x);
	return true;
}


/* FUNCAO QUE CALCULA A RAIZ QUADRADA - METODO DAS APROXIMACOES*/
double raizQD(double y)
{
	double x1,x,dif;
		
	x = y/2.0; // primeira aproximacao
		
	do
	{
		x1 = ( (x*x)  + y) / (2* x); // aproximacoes sucessivas		
		dif = fabs(x - x1); // diferenca entre o termo anterior e o termo atual		
		x = x1;
	}
	while(dif > 0.000001); // faço o procedimento das aproimacoes sucessivas enquanto esta diferenca for maior que 0.000001
	
	return x;	// retornar a raiz quadrada
}
