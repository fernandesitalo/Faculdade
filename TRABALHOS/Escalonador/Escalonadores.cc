#include <bits/stdc++.h>
using namespace std;


struct Instrucao{
  int id;                 // numero da instrucao
  int nc;                 // numero de ciclos
  int terminouCiclo;      // ciclo que esta instrucao terminou
  set<int> dependencias;  // lista dos id's de dependencias

  Instrucao()
  : id(-1),
    nc(-1),
    terminouCiclo(-1),
    dependencias()
  {}

  Instrucao(int id, int nc, set<int> dependencias)
  : id(id),
    nc(nc),
    terminouCiclo(-1),
    dependencias(dependencias)
  {}
};

int maxIF, maxEX, maxW;
int EX[1000][10];// "supondo" no maximo isso aqui
int cicloFim[1000];
bool jafoi[1000];
int menorqtdCiclos;
deque<int> otimo;

void coloca(int l, int c, int id, int tam){
  tam = l+tam;
  for( ; l < tam ; ++l){  EX[l][c] = id;  }
}
void tira(int l, int c , int tam){
  tam = l+tam;
  for( ; l < tam ; ++l){  EX[l][c] = 0;   }
}
bool achaNoCiclo(int l, int &c){
  for(c = 0 ; c < maxEX ; ++c){
    if(EX[l][c] == 0){ // achou!! coloca
      return true;
    }
  }
  return false;
}

bool pode(Instrucao &I,int cicloatual){
  for(auto i : I.dependencias){
    if( !(jafoi[i] && cicloatual > cicloFim[i])) return false;
  }
  return true;
}

void pega(int ciclofim){
  otimo.clear();
  bool peguei[1000];
  memset(peguei,0,sizeof peguei);
  peguei[0] = 1;

  for(int i = 0 ; i <= ciclofim; ++i){
    for(int j = 0 ; j < maxEX ; ++j){
      if(!peguei[ EX[i][j] ]){
        peguei[EX[i][j]] = 1;
        otimo.push_back(EX[i][j]);
      }
    }
  }
}
int ultimociclo(int l){
  int ret = l;
  for(int c = 0 ; c < maxEX ; ++c){
    int k = l;
    while(EX[k][c] != 0){
      k++;
    }
    ret = max(ret,k-1);
  }
  return ret;

}

int cont = 1;
vector<Instrucao> V;
void Escalona(int cicloAtual,int qtd){



  if(qtd == (int)V.size()){
  // cout << "----------------------------" << endl;
      // for(int i = 0 ; i < cicloAtual+7 ; ++i){
        // for(int j = 0 ; j < maxEX ; ++j){
          // cout << EX[i][j] << "  " ;
        // }cout << "\n";
      // }
  // cout << "====================================" << endl;
    int numeroCiclo = ultimociclo(cicloAtual);
    if(menorqtdCiclos > numeroCiclo){
      menorqtdCiclos = numeroCiclo;
      pega(cicloAtual);
    }
    return;
  }

  bool bolha = true;

  for(int i = 0 ; i < (int)V.size() ; ++i){
    int l = cicloAtual,c = 0;

    if(jafoi[V[i].id] == false && achaNoCiclo(l,c)){
      if(pode(V[i],cicloAtual)){
        jafoi[V[i].id] = true;
        coloca(l,c,V[i].id,V[i].nc);
        cicloFim[V[i].id] = l;
        Escalona(cicloAtual,qtd+1);Escalona(cicloAtual+1,qtd+1); // posso ir para o proximo ciclo ou nao...
        tira(l,c,V[i].nc); // tira a instrucao que coloquei antes da recursao
        cicloFim[V[i].id] = 0;
        jafoi[V[i].id] = false;
        bolha = false;
      }
    }
  }
  if(bolha){
    Escalona(cicloAtual+1,qtd);
  }
}

void escalonador(){
  memset(EX,0,sizeof EX);
  memset(cicloFim,0,sizeof cicloFim);
  memset(jafoi,false,sizeof jafoi);
  menorqtdCiclos = 1e9;
  otimo.clear();
  Escalona(0,0);
}



int main(){


  // LE VARIAS INTRUCOES E ESCALONA NA FORCA BRUTA MORTALITI

  maxEX = 3;
  freopen("in","r",stdin);

  int id,nc;
  while(cin>>id,id){
    cin>>nc;
    int t; cin>>t;
    set<int> s;
    for(;t--;){
      int z;cin>>z;
      s.insert(z);
    }
    V.push_back(Instrucao(id,nc,s));
  }
  escalonador();

  cout << "menor numero de ciclos possiveis sem IF e ID: "<< menorqtdCiclos+1 << '\n';
  cout << ":::::::::::::::::::::  " << otimo.size() << '\n';

  for(auto i : otimo){
    cout << i <<'\n';
  }

  return 0;
}
