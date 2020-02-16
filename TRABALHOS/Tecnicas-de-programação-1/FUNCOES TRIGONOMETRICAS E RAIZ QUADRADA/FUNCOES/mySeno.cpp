#include <stdio.h>
#include <math.h>

double myseno(double x);

int main()
{
	double angulo;
	
	printf("Angulo: ");	
	scanf("%lf",&angulo);
	
	angulo = (angulo * M_PI)/180.0; // conversao de graus para radianos
	
	printf("Seno: %lf",myseno(angulo));	

}

double myseno(double x)
{
	double termo = x,seno = 0,n;
			
	for(n = 1;fabs(termo) >= 0.000001 ; n++)
	{		
		seno += termo;	
		termo *= (x * x) / ((n*2)*(n*2+1)) * -1;	// recorrencia	- calcular os proximos termos a partir dos anteriores
	}		
	return seno;	
}
