#include <stdio.h>   // biblioteca do 'c' - printf e scanf
#include <stdlib.h> // biblioteca detentora de comandos do sistema

int main(void)
{
	int p,i,k,m,aux,inicio,fim,maior,menor,cont1,cont2;
	int vetA[100],vetB[100],aux_a[100],aux_b[100],uniao[200],intercessao[100],diferenca[100],novo[200];
	char opcao;
	
	printf("Numero de Termos do conjunto A : ");
	scanf("%d",&m);
	printf("CONNJUNTO A: ");
	for(i = 0; i < m ; i++)
	{
		scanf("%d",&vetA[i]);		
		aux_a[i] = vetA[i];
	}

	printf("\nNumero de Termos do conjunto B: ");
	scanf("%d",&p);	
	
	printf("CONJUNTO B: ");
	for(i = 0; i < p ; i++)
	{
		scanf("%d",&vetB[i]);		
		aux_b[i] = vetB[i];
	}

	do{
	printf("\n");
	system("PAUSE"); // aguarda o usuario pressionar uma tecla para continuar e limpar a tela
	system("cls"); // comando do sistema q limpa a tela
	
	printf("\n\t=========================ESCOLHA UMA OPCAO==============================\n");	
	printf("\ta - Descubra se A e/ou B saoo conjuntos vazios\n");
	printf("\tb - Uniao: A e B\n");
	printf("\tc - Intercessao: A e B\n");
	printf("\td - Diferenca: A - B\n");
	printf("\te - Diferenca: B - A\n");
	printf("\tf - Descubra se A e subconjunto de B\n");
	printf("\tg - Descubra se B e subconjunto de A\n");
	printf("\th - Descubra se A e B sao conjuntos identicos\n");
	printf("\ti - Descubra se A e B sao conjuntos disjuntos\n");
	printf("\tj -Amplitude dos Conjuntos A e B\n");
	printf("\tk -Produto escalar entre A e B \n");
	printf("\tl -Conjunto G - Maior subcadeia ordenada de forma Crescente de A\n");
	printf("\tm -Conjunto H - Maior subcadeia ordenada de Forma Decrescente de B\n");
	printf("\tn -Conjunto I, Vetores A  e B Intercalados e Ordenados\n");
	printf("\to -Exibir os 2 conjuntos novamente\n");
	printf("\ts -Sair do Progama\n");
	printf("\t========================================================================\n");
		
	printf("\nDIGITE A OPCAO: ");
	scanf("%s",&opcao);
	
	switch (opcao)
	{		
	case 'a':
			printf(m == 0 ? "\n=>O conjunto 'A' e um conjunto Vazio\n" : "\n=>O conjunto 'A' nao e um conjunto vazio\n");
			printf(p == 0 ? "=>O conjunto 'B' e um conjunto Vazio\n" : "=>O Conjunto 'B' nao e um conjunto Vazio\n");	
			break;		

	case 'b': // UNIAO DE VETORES
			for(i=0 ; i < m ; i++)
			{
				uniao[i] = vetA[i];
			}
			aux = i;		
			for(i=0; i < p ;i++)
			{ 
				for(k = 0; k < m && vetA[k] != vetB[i] ; k++);
				
				if(k == m)
				{
					uniao[aux] = vetB[i];
					aux++;
				}
			}
			printf("\nUniao dos Conjuntos A e B: { ");
			for(i = 0; i < aux ;i++)
			{
				printf("%d ",uniao[i]);
			}	
			printf("}\n");			
			break;			
			
	case 'c': // intercessao dos vetores
			aux = 0;
			for(i = 0 ; i < m ; i++)
			{
				for(k=0; k < p-1 && vetA[i] != vetB[k]; k++);			
				if(vetA[i] == vetB[k])
				{
					intercessao[aux] = vetA[i];
					aux++;
				}
			}
			printf("\n=> Conjunto Intercessao: { ");
			for(i = 0; i < aux ; i++)
			{
				printf("%d ",intercessao[i]);
			}
			printf("}\n");
			break;			
			
	case 'd': // diferenca dos conjuntos A - B
			aux = 0;	
			for(i = 0 ; i < m ; i++)
			{
				for(k = 0 ; k < p && vetA[i] != vetB[k] ; k++);			
				if(k == p)
				{
					diferenca[aux] = vetA[i];
					aux++;
				}
			}	
			printf("\n=> Diferenca A - B: { ");
			for(i = 0; i < aux ;i++)
			{
				printf("%d ",diferenca[i]);
			}
			printf("}\n");
			break;		

	case 'e': // diferenca B - A
			aux = 0;		
			for(i = 0 ; i < p ; i++)
			{
				for(k = 0 ; k < m && vetB[i] != vetA[k] ; k++);
				
				if(k == m)
				{
					diferenca[aux] = vetB[i];
					aux++;
				}
			}	
			printf("\n=> Diferenca B - A: { ");
			for(i = 0; i < aux ;i++)
			{
				printf("%d ",diferenca[i]);
			}
			printf("}\n");
			break;			
				
	case 'f': // se A e subconjunto de B
			if(m > p)
			{
				printf("\n=> O Conjunto A nao e um subconjunto de B!\n");
			}
			else
			{		
				for(aux = 0,i = 0 ; i < m ; i++)
				{		
					for(k = 0 ; k < p-1 && vetA[i] != vetB[k] ; k++);		
					
					if(vetA[i] == vetB[k])
					{
						aux++;
					}
					else
					{
						i = m;
					}
				}	
				printf(aux == m ? "\n=> O conjunto A e um subconjunto de B!\n":" \n=>O Conjunto A nao e um subconjunto de B !\n");
			}
			break;		
					
	case 'g':// VERIFICA SE B E UM SUB CONJUNTO DE A 
			if(p > m)
			{
				printf("\n\n=> O Conjunto B nao e um subconjunto de A !\n");
			}
			else
			{			
				for(aux = 0,k = 0 ; k < p ; k++)
				{		
					for(i = 0 ; i < m-1 && vetB[k] != vetA[i] ; i++);		
					
					if(vetA[i] == vetB[k])
					{
						aux++;
					}
					else
					{
						i = m;
					}
				}	
				printf(aux == p ? "\n=> O conjunto B e um subconjunto de A!\n":" \n=> Conjunto B nao e um subconjunto de A!\n");
			}
			break;				
			
	case 'h':// VERIFICA SE OS CONJUNTOS SAO IDENTICOS
			if(m != p)
			{
			printf("\n=> Os conjuntos nao sao identicos !\n");
			}
			else
			{
				for(aux=0 ,i=0 ; i < m ; i++)
				{ 				
					for(k=0 ; k < p && vetA[i] != vetB[k] ; k++); 
										
					if(p == k)
					{ // se entrar nesse 'if' e pq um elemento de A nao esta em B e portanto nao os conjuntos nao sao identicos 
						i = m; // como nao sao identicos , o progama deve parar 
					}
					else
					{ // se entrar nesse 'else' e pq o elemento de 'A' e igual ao elemento de 'B'
						aux++; 
					}
				}
			printf(aux == p ? "\n=> Os conjuntos A e B sao conjuntos IDENTICOS\n":"\n=> Os conjuntos A e B NAO sao conjuntos IDENTICOS\n");		
			}	
			break;		
		
	case 'i'://verifica se os conjuntos sao disjuntos ,isto e, se nao possuem elementos Iguais	
			for(aux = 0 , i = 0 ; i < m ; i++)
			{
				for(k=0 ; k < p && vetA[i] != vetB[k] ; k++);
				
				if(k == p)
				{ // se entrar nesse 'if' e pq o elemento de 'A' nao e igual a 'B' e foram analisadas todas possibilidades
					aux++;
				}
				else
				{ // o elemento do conjunto 'A' e igual ao elemento do Conjunto 'B' , ja sei q os conjuntos nao sao disjunto , paro de procurar
					i=m;
				}
			}				
				printf(aux == m?"\n=> Os conjuntos sao Disjuntos\n":"\n=> Os conjuntos nao sao Disjuntos\n");
			break;		
		
	case 'j': // CALCULO DA AMPLITUDE de cada conjunto , isto e,  maior valor - menor valor = amplitudde
			maior = vetA[0];
			menor = maior;			
			for(i = 1 ; i < m ; i++)
			{		
				if(vetA[i] < menor)
				{
					menor = vetA[i];
				}
				else
				{
					if(vetA[i] > maior)
					{
						maior = vetA[i];
					}	
				}
			}			
			printf("\n=> Amplitude do Conjunto A: %d\n",maior - menor);		
			maior = vetB[0];
			menor = maior;			
				for(i = 1 ; i < p ; i++)
				{			
					if(vetB[i] < menor)
					{
						menor = vetB[i];
					}
					else
					{
						if(vetB[i] > maior)
						{
							maior = vetB[i];
						}
					}						
				}			
			printf("\nAmplitude do Conjunto B: %d\n",maior - menor);
			break;		
		
	case 'k': // PRODUTO ESCALAR ENTRE OS 2 CONJUNTOS
			if(m != p)
			{
				printf("=> Nao eh possivel calcular o produto escalar. O tamanho dos vetores sao diferentes!\n");
			}
			else
			{
				aux = 0;
				for(i = 0 ; i < m ; i++)
				{
					aux += vetA[i] * vetB[i];
				}			
				printf("\n=> Produto Escalar entre os Vetores: %d\n",aux);
			}
			break;		
		
	case 'l':// MAIOR SUB CADEIA CRESCENTE DE A	
			inicio = 0; // inicio da sub cadeia 
			fim = 0; // fim da sub cadeia			
			for(i = 0 ; i < m ; i++) // sera verificada a existencia de m subcadeias, uma a uma
			{	
			// i marca o inicio da sub cadeia ordenada				
				for(k = i; k < m-1 && vetA[k] < vetA[k+1]; k++);// este for e executado enquanto A[K] for menor que A[K+1] , isto e , enquanto formar uma sequencia crescente
				// no final desde laco de repeticao , K marca o final da subcadeia ordenada				
				if(k - i > fim - inicio)
				{
					inicio = i; // guarda o inicio da maior subcadeia
					fim = k; // guarda o final da sub cadeia
				}					
				i = k; // ate k foi verificado a existencia desta sub cadeia
			}				
			printf("=> Conjunto G: { ");
			if(fim - inicio != 0)
			{
				for(i = inicio ; i <= fim ; i++)
				{
					printf("%d  ",vetA[i]);
				}	
			}			
			printf("}\n");
			break;		
		
	case 'm': // MAIOR Sub Cadeia DESCRECENTE DE B				
			inicio = 0; // inicio da sub cadeia 
			fim = 0; // fim da sub cadeia			
			for(i = 0 ; i < p ; i++) // sera verificada a existencia de n subcadeias, uma a uma
			{	
				// i marca o inicio da sub cadeia ordenada				
				for(k = i; k < p-1 && vetB[k] > vetB[k+1]; k++);// este for e executado enquanto A[K] for menor que A[K+1],isto e,enquanto formar uma sequencia Decrescente
				// no final desde laco de repeticao , K marca o final da subcadeia ordenada				
				if(k - i > fim - inicio)
				{
					inicio = i; // guarda o inicio da maio subcadeia
					fim = k; // guarda o final da sub cadeia
				}				
				i = k; // ate k foi verificado a existencia desta sub cadeia
			}			
			printf("=> Conjunto H: { ");
			if(fim - inicio != 0)
			{
				for(i = inicio ; i <= fim ; i++)
				{
					printf("%d  ",vetB[i]);
				}
			}			
			printf("}\n");				
			break;		
		
	case 'n': // intercalados e ordendos	
			for(i = 1 ; i < m ; i++)
			{  // o laco comeca com i = 1 pois nao tem como ordenar um so termo 
				aux = aux_a[i]; // termo q sera guardado para coloca-lo na posicao correta				
				for(k=i-1 ; k >= 0 && aux < aux_a[k] ; k--)
				{ // ando uma posição para frente com cada termo menor que o termo auxiliar
					aux_a[k+1] = aux_a[k];
				}	
				aux_a[k+1] = aux; // quando e encontrada a posicao correta inserimos o termo auxiliar
								// antes de sair do laco 'for' e decrementada uma unidade do k , pois isso K+1
			}					
			for(i = 1 ; i < p ; i++)
			{  // o laco comeca com i = 1 pois nao tem como ordenar um so termo 
				aux = aux_b[i]; // termo q sera guardado para coloca-lo na posicao correta
				for(k=i-1 ; k >= 0 && aux < aux_b[k] ; k--)
				{ // ando uma posição para frente com cada termo menor que o termo auxiliar
					aux_b[k+1] = aux_b[k];
				}	
				aux_b[k+1] = aux; // quando e encontrada a posicao correta inserimos o termo auxiliar
								// antes de sair do laco 'for' e decrementada uma unidade do k , pois isso K+1
			}			
			cont1=0;
			cont2=0;			
			// INTERCALANDO E ORDENADO  ATE UM VETOR ACABAR	
			for(i=0 ; cont1 < m && cont2 < p ; i++)
			{ 				
				if(aux_a[cont1] < aux_b[cont2])
				{
					novo[i] = aux_a[cont1];
					cont1++;
				}
				else
				{
					novo[i] = aux_b[cont2];
					cont2++;
				}	
			}		
			// TERMINA DE COLOCAR OS ELEMNTOS DO OUTRO VETOR Q NAO ACABOU	
			for(;cont1 < m ; cont1++,i++)
			{ 
				novo[i] = aux_a[cont1];
			}
			// TERMINA DE COLOCAR OS ELEMNTOS DO OUTRO VETOR Q NAO ACABOU		
			for(; cont2 < p; cont2++,i++)
			{ 
				novo[i] = aux_b[cont2];
			}						
			printf("\n=> VETOR 'A' E VETOR 'B' ORDENADOS E INTERCALADOS : \n");
			for(cont1 = 0; cont1 < m+p ; cont1++)
			{ // EXIBE O VETOR ORDENADO E INTERCALADO
				printf("%d ",novo[cont1]);
			}	
			printf("\n");	
			break;
			
	case 'o': // exibicao dos vetores 'A' e 'B' 
			printf("\nCONJUNTO A: { ");
			for(i = 0; i < m ; i++)
			{
				printf("%d ",vetA[i]);			
			}
			printf("}\n");	
		
			printf("\nCONJUNTO B: { ");		
			for(i = 0; i < p ; i++)
			{
				printf("%d ",vetB[i]);		
			}		
			printf("}\n");	
			break;
				
	case 's': // se o usuario estiver de saida
			printf("\n     -=Ate Mais e Bons estudos caro estudante!=-\n");
			break;		

	default: // se nao for nenhum dos casos acima
			printf("\nESTA OPCAO NAO EXISTE.DIGITE NOVAMENTE\n");
			break;
	}	
	}while(opcao != 's');	
	
	return 0;
}
