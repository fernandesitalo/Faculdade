#include <stdio.h>
#include <math.h>

double mycos(double x);

int main()
{
	double angulo;
	
	printf("Angulo: ");	
	scanf("%lf",&angulo);
	
	angulo = (angulo * M_PI)/180.0; // conversao de graus para radianos
	
	printf("coseno: %lf",mycos(angulo));	
}

double mycos(double x)
{
	double termo = 1;
	double coseno = 0,fat;
	
	for(fat = 1 ; fabs(termo) > 0.000001 ; fat ++)
	{		
		coseno += termo;// coseno sera meu somatorio		
		termo *= -1 *  (x * x) / ((fat * 2)*(fat * 2 - 1));		 
	}
	return coseno;
}


