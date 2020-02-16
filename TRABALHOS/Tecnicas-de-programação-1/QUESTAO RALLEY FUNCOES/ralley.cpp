#include <stdio.h>
#include <math.h>

float PontosEtapa(float tp , float temp);

int main()
{
	float tp1,tp2,tp3;	
	int insc;
	float temp1,temp2,temp3;
	float etapa1,etapa2,etapa3,total;
	float campea,maior = 0;

	printf("\t-=RALLYE AUTOMOBILISTICO=-\n");	
	printf("\t  -=Apuracao dos dados=-\n");
	
	
	/*OBTENCAO DOS TEMPOS PADROES*/
	printf("TEMPO PADRAO - Etapa 1: ");
	scanf("%f",&tp1); //tp1 - tempo padrao 1
	
	printf("TEMPO PADRAO - Etapa 2: ");
	scanf("%f",&tp2);//tp2 - tempo padrao 2
	
	printf("TEMPO PADRAO - Etapa 3: ");
	scanf("%f",&tp3);//tp3 - tempo padrao 3	
		
	
	printf("Digite o Numero de Inscricao da Equipe: ");
	scanf("%d",&insc);	
	
	while(insc != 9999 )
	{
	/*OBTENCAO DOS TEMPOS DA EQUIPE*/	
		printf("\n\nTempo Etapa 1: ");
		scanf("%f",&temp1);		
		
		printf("Tempo Etapa 2: ");
		scanf("%f",&temp2);		
		
		printf("Tempo Etapa 3: ");
		scanf("%f",&temp3);
		
		
		/*calculo e exibicao dos resultados*/
		etapa1 = PontosEtapa(tp1,temp1);
		printf("\nPontos Etapa 1: %f\n",etapa1);		
		
		etapa2 = PontosEtapa(tp2,temp2);
		printf("Pontos Etapa 2: %f\n",etapa2);		
		
		etapa3 = PontosEtapa(tp3,temp3);
		printf("Pontos Etapa 3: %f\n",etapa3);		
	
		total = etapa1 + etapa2 + etapa3;		
		printf("Total de Pontos: %f\n\n",total);
		
		if(total > maior)
		{
			maior = total;
			campea = insc;
		}		
		
		printf("Numero de Inscricao da Equipe: ");
		scanf("%d",&insc);		
	}	
	
	printf("\n\nEQUIPE CAMPEA %d COM %f PONTOS !",campea,maior);
	
	return 0;
}

/*FUNCAO DE PASSAGEM DE PARAMETROS POR VALORES*/
float PontosEtapa(float tp , float temp)
{
	int delta = fabs(tp - temp);
	
	if(delta < 3)
	{
		return 100;
	}
	if(delta <= 5)
	{
		return 80;
	}	
	return 80 - ((delta - 5)/5.0);
}
