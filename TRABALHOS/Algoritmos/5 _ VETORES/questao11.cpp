#include <iostream>

using namespace std;

int main()
{
	int A[30],B[20],C[50]; // declaracao dos vetores 
	int m,n,k,e,i;

	cout << "           -=UNIAO DE VETORES=-\n\n";

	cout << "DIGITE A QUANTIDADE DE TERMOS DO VETOR A: ";
	cin >> m;
	cout << "DIGITE O(s)"<<m<<" ELEMENTO(s) DO VETOR A : "<<endl;
	for(i = 0 ; i < m ; i++)
	{
		cin >> A[i];
		
	 	C[i] = A[i];
	}

	cout << "\n\nDIGITE A QUANTIDADE DE TERMOS DO VETOR B: ";
	cin >> n;
	cout << "DIGITE O(s) "<<n<<" ELEMENTO(s) DO VETOR B : "<<endl;
	for(i = 0 ; i < n ; i++)
	{
		cin >> B[i];
	}
// no caso da uniao de conjuntos(vetores) a quetao ja nos da a certeza que nao havera elementos repetidos dentro de um memo vetor 
// entao o conjunto uniao ja se inicializa com o vetor A . e verifica se um termo de B se repete em A . se repete não e atribuido ao conjunto uniao
// se nao repete entao e atribuido ao vetor uniao
	k = m;
	for(i = 0 ; i < n ; i++)
	{
		for(e = 0 ; e < m && B[i] != A[e]; e++)
		{}
		
		if(e == m)
		{
			C[k] = B[i];
			k++;
		}
	}

	cout << "UNIAO:"<<endl; // exibico dos dados de saida 
	
	for(i = 0 ; i < k ; i++)
	{
		cout << C[i]<<endl;
	}

}
