#include <bits/stdc++.h>
using namespace std;

void OrdenacaoTopologica(vector<int> *graph,vector<int> *OT,bool * visitado, int u){
	
	visitado[u] = true; // true pois foi visitado..
	
	for(int i = 0 ; i < (int) graph[u].size() ; ++i) // visita todos visinhos adjacentes ao vetice u
	{
		int v = graph[u][i]; // vertice v adjacente a u
		 
		if(visitado[v] == false) // se nao foi visitado ainda... vamos para lah
		{
			OrdenacaoTopologica(graph,OT,visitado,v);
		}
	}
	
	OT->push_back(u); // ordenacao topologica
}



int main(){
	
	
	freopen("Entrada_Matriz_Curricular.txt","r",stdin);
	
	string u,v;
	int num_vertice,i,n,m;
	
	
	// inicializacao
	map<string,int> indiceA; // nome do vertice - numero do vertice
	map<int,string> indiceB; // numero do vertice - nome do vertice
	num_vertice = 0;
	
	cout << "DIGITE O NUMERO DE ARESTAS DO GRAFO: ";
	cin >> n;
	
	vector<int> graph[n+10]; // declaracao do grafo
	
	for(i = 0 ; i < n ; ++i){
		
		cin>> u >> v; // leitura de uma aresta
		
		if(indiceA.find(u) == indiceA.end())
		{ 
			indiceA[u] = num_vertice;
			indiceB[num_vertice] = u;
			num_vertice++;
		}
		
		if(indiceA.find(v) == indiceA.end())
		{
			indiceA[v] = num_vertice;
			indiceB[num_vertice] = v;
			num_vertice++;	
		}

		graph[ indiceA[u] ].push_back( indiceA[u] ); // INSERÇÃO DA ARESTA NO GRAFO

	}	
	
	cout << "DIGITE O NUMERO DE VERTICES QUE PERTENCEM AO GRAFO, MAS QUE NAO ESTAM CONECTADOS AOS DEMAIS VERTICES (VERTICES DE GRAU 0): ";
	cin>>m;
	
	for(i = 0 ; i < m ;++i){
		cin>>u; // leitura de um vertice que possui grau 0
		
		if(indiceA.find(u) == indiceA.end()){
			indiceA[u] = num_vertice;
			indiceB[num_vertice] = u;
			num_vertice++;
		}
	}
	
	
	bool visitado[num_vertice+10];// vetor de visitados
	for(i = 0 ; i < num_vertice ; ++i)
	{
		visitado[i] = 0; // 0 que nao foi visitado
	}
	
	
	cout << "ORDENACAO TOPOLOGICA: " <<endl;
	
	vector<int> OT;
	
	for(i = 0 ; i < num_vertice ; ++i)
	{
		if(visitado[i] == false)
		{
			OrdenacaoTopologica(graph,&OT,visitado,i);
		}
	}
	
	
	for(i = OT.size()-1 ; i > -1 ; --i)
	{
		cout << indiceB[ OT[i] ] << " -> "; 
	}
	cout << endl;
	
	return 0;
}
