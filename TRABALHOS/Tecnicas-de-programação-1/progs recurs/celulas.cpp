#include <stdio.h>

bool PintaCelula(char**,int,int,int,int);
int Ncelulas(char**,int,int);
void IMPRIME(char**,int,int);

int main()
{
	int n,i,j,coluna,linha;	
	
	printf("Digite a Quantidade de Testes: ");	
	scanf(" %d",&n); // quantidade de IMAGENS
	
	for(;n;n--) // cast bool, enquanto n != 0 (isto é, enquanto for verdade) o laço será execultado
	{
		printf("DIGITE AS DIMENSOES DA IMAGEM DA CEULULA (linha e coluna): ");
		scanf(" %d %d",&linha,&coluna);
		
		
		char **mat = new char*[linha];// PONTEIRO P/ PONTEIRO que aponta para um vetor de PONTEIROS			
		for( i = 0 ; i < linha ; i++) // CADA PONTEIRO DESTE VETOR APONTARA PARA UM VETOR DE 'CHAR'
		{
			mat[i] = new char[coluna];		
		}
		
		
		for(i = 0; i < linha ; i++) // leitura de toda a imagem da celula, pixel por pixel
		{
			for(j = 0; j < coluna ; j++)
			{
				scanf(" %1c",&mat[i][j]);					
			}
		}	
		
		printf("\n\nTEMOS %d CELULAS\n\n",Ncelulas(mat,linha,coluna));			
		IMPRIME(mat,linha,coluna);				
		
		/// DESALOCA A MATRIZ DINAMICAMENTE ///		
		for( i = 0 ; i < linha ; i++)
		{
			delete []mat[i];		
		}
		delete []mat;			
	}
	return 0;	
}


bool PintaCelula(char **mat,int i,int j,int linha,int coluna) // COMPLETA CELULA
{
	if(i == linha || j == coluna || i < 0 || j < 0 || mat[i][j] != '#')
		return true;		

	mat[i][j]= 'o' ;//pinta a celula parte da celula "ja encontrada"

	return PintaCelula(mat,i,j-1,linha,coluna),
		  PintaCelula(mat,i,j+1,linha,coluna),
		  PintaCelula(mat,i+1,j,linha,coluna),
		  PintaCelula(mat,i-1,j,linha,coluna);								
}


int Ncelulas(char** mat,int linha,int coluna)
{
	int i,j,cont = 0;
		for( i = 0; i < linha ; i++)
			for(j = 0; j < coluna ; j++)
				if(mat[i][j] == '#')
				{ 
					PintaCelula(mat,i,j,linha,coluna);
					cont++;
				}						
	return cont;	
}

void IMPRIME(char** mat,int l, int c)
{
	int i,j;
	for(i = 0; i < l ; i++) // 
	{
			for(j = 0; j < c ; j++)
			{
				printf("%c",mat[i][j]);
			}
			printf("\n");
	}
	printf("\n======================================\n");	
}
