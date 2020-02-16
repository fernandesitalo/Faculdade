#include <iostream>
#include <vector>
#include <queue>

#define INF 9999999
#define BRANCO -1
#define PRETO 1

void MOSTRACAMINHO(int * pai,int v, int s){ // vetor de pai | onde quero chegar | onde comecei
	
	if(v == s){
		std::cout << s << std::endl;
	}
	else{
		MOSTRACAMINHO(pai,pai[v],s);
		std::cout << v << std::endl;
	}
}


void bfs(int source, int qtdVertices, std::vector< std::vector<int> >  G){ 	// busca em profundidade
	
	int cor[qtdVertices],pai[qtdVertices],d[qtdVertices];	// declaracao  vetores necessarios
	
	for(int i = 0 ; i <= qtdVertices ; ++i){
		pai[i] = -1;				// inicializa
		d[i] = INF;					// a distancia inicial sera INFINITO
		cor[i] = BRANCO;			// marca todos como naov visitados
	}	
	
	d[source] = 0;			// source	distancia dele ate ele mesmo é ZERO
	cor[source] = PRETO;	// source	cor PRETA -> EXPLORADO

	std::queue<int> q;		// fila da Busca Em Profundidade	
		
	q.push(source);			// Coloca o vertice inicial na fila	
			
	while(!q.empty()){		// enquanto houver algo na fila
		
		int u = q.front();
		q.pop();
		
		for(int i = 0 ; i < (int)G[u].size() ; ++i){	// vai em todos vizinhos adjacentes
			int v = G[u][i];
			
			if(cor[v] == BRANCO){						// se nao tiver sido explorado, explora
				q.push(v);
				pai[v] = u;
				d[v] = d[u] + 1;
				cor[v] = PRETO;
			}
		}
	}

	MOSTRACAMINHO(pai,3,source);						// mostra o caminho do vertice SOURCE ate o vertice 3....
}






int main(){
		
	std::vector< std::vector<int> > G(5);
	
	// int id[100];
	// int id[55] = 5;
	
	
	G[0].push_back(1);
	G[1].push_back(4);
	G[2].push_back(3);
	G[4].push_back(2);
	
	bfs(0,5,G);
	
	return 0;
}
