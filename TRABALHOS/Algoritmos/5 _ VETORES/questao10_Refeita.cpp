#include <iostream>

using namespace std;

int main()
{

	int A[100],B[100],C[200]; // declaracao dos vetores A ,B , C
	int i,k,j, // contadores
	num_a,num_b; //numero de elemento dos vetores 

	cout << "    	-=INTERCALACAO DE VETORES=-  \n\n"<<endl;
	cout << "DIGITE A QUANTIDADE DE TERMOS DO VETOR A: ";
	cin >> num_a;
	
	cout << "DIGITE O(s) "<<num_a<<" ELEMENTO(s) DO VETOR 'A' ja ORDENADOS : "<<endl; // obtencao dos dados de entrada
	for(i = 0 ; i < num_a ; i++)
	{
		cin >> A[i];
	}

	cout << "\n\nDIGITE A QUANTIDADE DE TERMOS DO VETOR B : ";
	cin >> num_b;
	cout << "DIGITE O(s) "<<num_b<<" ELEMENTO(s) DO VETOR 'B' ja ORDENADOS : "<<endl;// obtencao dos dados de entrada
	for(i = 0 ; i < num_b ; i++)
	{
		cin >> B[i];
	}

	j = 0; // contador do vetor A
	k = 0; // contador do vetor B
	
	for(i = 0; (j < num_a ) && (k < num_b) ; i++) // intercalacao dos vetores ordenados somente ate a posicao do menor deles 
	{		
		if(A[j] <= B[k]) 
		{
			C[i] = A[j];
			j++; // contador do vetor A
		}
		else
		{
				C[i] = B[k];
				k++; // contador do vetor B
		}
	}
// adciona ao vetor C os elementos do maior vetor que sobraram do ultimo for 
	for(; j < num_a ; i++) // neste caso nao e necessario variaveis de inicializacao 
	{
		C[i] = A[j];
		j++;
	}
	
	for(; k < num_b ; i++)// neste caso nao e necessario variaveis de inicializacao
	{
		C[i] = B[k];
		k++;
	}
	
	cout << "INTERCALACAO DOS VETORES"<<endl; // exibicao dos dados de saida 
	for(k = 0 ; k < i ; k++)
	{
		cout <<"=>"<<C[k]<<endl;
	}	
}
