#include <stdio.h>   // biblioteca do 'c' - printf e scanf
#include <stdlib.h> // biblioteca detentora de comandos do sistema

void menu();
void imprime(int *vetor,int tam);
int tam_uniao(int *vetorA,int tam_a,int *vetorB,int tam_b,int *vetorC);
int tam_intercessao(int *vetorA,int tam_a,int *vetorB,int tam_b,int *vetorC);
int tam_diferenca(int *vetorA,int tam_a,int *vetorB,int tam_b,int *vetorC);
bool subconjunto(int *vetorA,int tam_a,int *vetorB,int tam_b);
bool identicos(int *vetorA,int tam_a,int *vetorB,int tam_b);
bool disjuntos(int *vetorA,int tam_a,int *vetorB,int tam_b);
int amplitude(int *vetor,int tam);
bool produtoEscalar(int *vetorA,int tam_a,int *vetorB,int tam_b,int *pe);
int tam_crescente(int *vetorA,int tam_a,int *vetorC);




int main(void)
{
	int p,i,k,m,aux,inicio,fim,cont1,cont2;
	
	int temp;
	
	int vetA[100],vetB[100],aux_a[100],aux_b[100],uniao[200],intercessao[100],diferenca[100],novo[200],crescente[100];
	char opcao;
	
	printf("Numero de Termos do conjunto A : ");
	scanf(" %d",&m);
	printf("CONNJUNTO A: ");
	for(i = 0; i < m ; i++)
	{
		scanf(" %d",&vetA[i]);		
		aux_a[i] = vetA[i];
	}

	printf("\nNumero de Termos do conjunto B: ");
	scanf(" %d",&p);	
	
	printf("CONJUNTO B: ");
	for(i = 0; i < p ; i++)
	{
		scanf(" %d",&vetB[i]);		
		aux_b[i] = vetB[i];
	}

	do
	{	
	system("PAUSE"); // aguarda o usuario pressionar uma tecla para continuar e limpar a tela
	system("cls"); // comando do sistema q limpa a tela	
		
	menu();//exibe o menu na tela		
	
	printf("\nDIGITE A OPCAO: ");
	scanf(" %s",&opcao);
	
		switch(opcao)
		{		
		case 'a':  // CONJUNTOS VAZIOS
			printf(m == 0 ? "\n~O conjunto 'A' e um conjunto Vazio\n" : "\n~O conjunto 'A' nao e um conjunto vazio\n");
			printf(p == 0 ? "~O conjunto 'B' e um conjunto Vazio\n" : "~O Conjunto 'B' nao e um conjunto Vazio\n");	
			break;
					
	
		case 'b': // UNIAO DE VETORES
			temp = tam_uniao(vetA,m,vetB,p,uniao); //e passado somente o nome do vetor nos parametros atuais
			printf("~Uniao dos Conjuntos A e B: ");//que correondem ao endereço de memoria da array		
			imprime(uniao,temp);			
			break;			
				
				
		case 'c': // intercessao dos vetores
			temp = tam_intercessao(vetA,m,vetB,p,intercessao);
			printf("\n~Conjunto Intercessao: ");
			imprime(intercessao,temp);
			break;				
						
				
		case 'd': // diferenca dos conjuntos A - B
			temp = tam_diferenca(vetA,m,vetB,p,diferenca);
			printf("\n~Diferenca A - B: ");
			imprime(diferenca,temp);
			break;			
				
	
		case 'e': // diferenca B - A
			temp = tam_diferenca(vetB,p,vetA,m,diferenca);
			printf("\n~Diferenca B - A: ");
			imprime(diferenca,temp);
			break;
						
					
		case 'f': // se A e subconjunto de B	
			if(!subconjunto(vetA,m,vetB,p)) // funcao subconjunto retorna um bool, se e ou nao subconjunto
			{
				printf("\n~ O conjunto A e um subconjunto de B!\n");
			}
			else
			{
				printf("\n~ Conjunto A nao e um subconjunto de B!\n");
			}
			break;				
				
						
		case 'g':// VERIFICA SE B E UM SUB CONJUNTO DE A 
			if(!subconjunto(vetB ,p ,vetA ,m))// funcao subconjunto retorna um bool, se e ou nao subconjunto
			{
				printf("\n~ O conjunto B e um subconjunto de A!\n");
			}
			else
			{
				printf("\n~ Conjunto B nao e um subconjunto de A!\n");
			}
			break;					
							
				
		case 'h':// VERIFICA SE OS CONJUNTOS SAO IDENTICOS
			if(!identicos(vetA ,m ,vetB ,p))// funcao subconjunto retorna um bool, se e ou nao identicos
			{
				printf("\n~ Os conjuntos A e B sao conjuntos IDENTICOS!\n");
			}
			else
			{
				printf("\n~ Os conjuntos A e B NAO sao conjuntos IDENTICOS!\n");
			}
			break;			
					
			
		case 'i'://verifica se os conjuntos sao disjuntos ,isto e, se nao possuem elementos Iguais	
			if(!disjuntos(vetA,m,vetB,p))
			{
				printf("\n~ Os conjuntos sao Disjuntos\n");
			}
			else
			{
				printf("\n~ Os conjuntos nao sao Disjuntos\n");
			}
			break;			
				
			
		case 'j': // CALCULO DA AMPLITUDE de cada conjunto , isto e,  maior valor - menor valor = amplitudde
			temp = amplitude(vetA,m);	
			printf("\n~ Amplitude do Conjunto A: %d\n",temp);		
			temp = amplitude(vetB,p);
			printf("\n~ Amplitude do Conjunto B: %d\n",temp);
			break;			
					
			
		case 'k': // PRODUTO ESCALAR ENTRE OS 2 CONJUNTOS
			if(!produtoEscalar(vetA,m,vetB,p,&temp))
			{
				printf("\n~ O produto escalar e igual a %d\n",temp);
			}
			else
			{
				printf("\n~ Nao foi possivel calcular o produto escalar\n");
			}
			break;					
					
			
		case 'l':// MAIOR SUB CADEIA CRESCENTE DE A	
			temp = tam_crescente(vetA,m,crescente);
			imprime(crescente,temp);
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
			
			
			
		case 'n': 
		// intercalados e ordendos	
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
			imprime(vetA,m);
			imprime(vetB,p)
			break;				
					
		case 's': // se o usuario estiver de saida
			printf("\n     -=Ate Mais e Bons estudos caro estudante!=-\n");
			break;					
	
		default: // se nao for nenhum dos casos acima
				printf("\nESTA OPCAO NAO EXISTE.DIGITE NOVAMENTE\n");
			
		}	
	}while(opcao != 's');	
	
	return 0;
}

void menu(){
	printf("\n\t=========================ESCOLHA UMA OPCAO==============================\n");	
	printf("\ta - Descubra se A e/ou B sao conjuntos vazios\n");
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
}

int tam_uniao(int *vetorA,int tam_a,int *vetorB,int tam_b,int *vetorC){         
	int aux,k,i;
	
	for(i = 0 ; i < tam_a ; i++)
	{
		vetorC[i] = vetorA[i];
	}	
	aux = i;		
		for(i = 0; i < tam_b ; i++) // fixa o elemento do vetor B
		{ 
			for(k = 0; k < tam_a && vetorA[k] != vetorB[i] ; k++); // verifica a existencia de um elemento A igual ao elemento de B fixado
																	// se houver algum igual , nao colocamo-os no conjunto uniao
			if(k == tam_a)
			{
				vetorC[aux] = vetorB[i];
				aux++;
			}
		}		
	return aux; // retorna o tamanho do vetor Uniao		
}

void imprime(int *vetor,int tam){
	int i;
	printf("{");
	for(i = 0 ; i < tam ; i++)
	{
		printf("%d ",vetor[i]);
	}
	printf("}\n");
}

int tam_intercessao(int *vetorA,int tam_a,int *vetorB,int tam_b,int *vetorC){
	int aux = 0,i,k;
	for(i = 0 ; i < tam_a ; i++)
	{
		for(k = 0; k < tam_b-1 && vetorA[i] != vetorB[k]; k++);			
		if(vetorA[i] == vetorB[k])
		{
			vetorC[aux] = vetorA[i];
			aux++;
		}
	}
	return aux;// tamanho do vetor Intercessao
}

int tam_diferenca(int *vetorA,int tam_a,int *vetorB,int tam_b,int *vetorC){
	int aux = 0,k,i;
	for(i = 0 ; i < tam_a ; i++)
	{
		for(k = 0 ; k < tam_b && vetorA[i] != vetorB[k] ; k++);			
		if(k == tam_b)
		{
			vetorC[aux] = vetorA[i];
			aux++;
		}
	}	
	return aux; // tamanho do vetor Diferenca
}

bool subconjunto(int *vetorA,int tam_a,int *vetorB,int tam_b){
	int i,k;// retorna se e ou nao um subconjunto de a em b ou vice versa
	
	if(tam_a > tam_b)
	{
		return false;
	}		
		for(i = 0 ; i < tam_a ; i++)
		{		
			for(k = 0 ; k < tam_b-1 && vetorA[i] != vetorB[k] ; k++);		
					
			if(vetorA[i] != vetorB[k])
			{
				return false; // encontra um elemento de A que nao esta em B
			}
		}			
	return true; // todos elementos de A estao em B		
	    		// foram verificadas todas possibilidades	    
}

bool identicos(int *vetorA,int tam_a,int *vetorB,int tam_b){
	int i,k;	
	if(tam_a != tam_b)
	{
		return false;
	}
	for(i = 0 ; i < tam_a ; i++) // fixa um elemento de A
	{ 				
		for(k = 0 ; k < tam_b && vetorA[i] != vetorB[k] ; k++); // compara o elemento fixado com todos de B
		if(tam_a == tam_b)
		{ // se entrar nesse 'if' e pq um elemento de A nao esta em B e portanto nao os conjuntos nao sao identicos 
			return false; // como nao sao identicos...
		}
	}
	return true;
}	

bool disjuntos(int *vetorA,int tam_a,int *vetorB,int tam_b){
	int i,k;
	for(i = 0 ; i < tam_a ; i++)
	{
		for(k = 0 ; k < tam_b && vetorA[i] != vetorB[k] ; k++);
		if(k != tam_b)
		{  // existe um elemento do conjunto 'A' que e igual ao elemento do Conjunto 'B' .: ja sei q os conjuntos nao sao disjunto , paro de procurar
			return false;
		}
	}	
	return true;			
}

int amplitude(int *vetor,int tam){
	int maior,menor,i,k;
	
	maior = vetor[0];
	menor = maior;
				
	for(i = 1 ; i < tam ; i++)
	{		
		if(vetor[i] < menor)
		{
			menor = vetor[i];
		}
		else
		{
			if(vetor[i] > maior)
			{
				maior = vetor[i];
			}	
		}
	}
	return maior - menor;				
}

bool produtoEscalar(int *vetorA,int tam_a,int *vetorB,int tam_b,int *pe){
int i;

	if(tam_a != tam_b)
	{
		return false; // assim nao da pra calcular 
	}
	else
	{
		*pe = 0; //produto escalar
		for(i = 0 ; i < tam_a ; i++)
		{
			*pe += vetorA[i] * vetorB[i];
		}					
		return true;
	}
}

int tam_crescente(int *vetorA,int tam_a,int *vetorC){	
// MAIOR SUB CADEIA CRESCENTE DE A	
	int i,k;
	int inicio = 0; // inicio da sub cadeia 
	int fim = 0; // fim da sub cadeia			

	for(i = 0 ; i < tam_a ; i++) // sera verificada a existencia de m subcadeias, uma a uma
	{	
	// i marca o inicio da sub cadeia ordenada				
		for(k = i; k < tam_a-1 && vetorA[k] < vetorA[k+1] ; k++);// este for e executado enquanto A[K] for menor que A[K+1] , isto e , enquanto formar uma sequencia crescente
		// no final desde laco de repeticao , K marca o final da subcadeia ordenada				
		if(k - i > fim - inicio)
		{
			inicio = i; // guarda o inicio da maior subcadeia
			fim = k; // guarda o final da sub cadeia
		}					
		i = k; // ate k foi verificado a existencia desta sub cadeia
	}				

	if(fim - inicio != 0)
	{
		for(k = 0,i = inicio ; i <= fim ; i++ , k++)
		{
			vetorC[k] = vetorA[i];
		}
		return k - 1 ;				
	}
	return 0;
}

