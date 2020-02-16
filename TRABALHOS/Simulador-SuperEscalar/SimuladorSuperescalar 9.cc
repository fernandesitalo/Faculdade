/*
  FALTA OUT-OUT (DEIXA EU FAZER FATORIAL QUE VAI FICAR PIKA PRA CARALEO)
*/

#include <bits/stdc++.h>
using namespace std;

#define maxCiclos 100000
#define inf 0x3f3f3f3f

// first -> intrucao , second -> quantidade de ciclos executados
typedef pair<int,int> ii;

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

bool in_in, in_out, out_out, forwarding;
int maxIF, maxEX, maxW;
int maiorId;  // tamanho do maior id lido

map<int,Instrucao> buffer;
int numGravacoes[maxCiclos]; // quantidade de instrucoes que serao gravadas no ciclo i

map<string,int> idToPos;
map<int,string> posToId;

map<int,int> prioridade;

struct Ciclo{
  int numCiclo;              // numero do ciclo atual
  deque<int> dispatcher;  // vai tirando -- preferencia para o primeiro -- inserir na ordem sem problema de dependencia -- reduzir nop's --- como?
  map<int,int> IF, ID, W;
  map<int,ii> EX;

  Ciclo()
  : numCiclo(0)
  {}

  // verifica se acabaram os ciclos
  bool finished() const{
    return IF.empty() && ID.empty() && EX.empty();
  }

  // instrucoes -> IF
  void fetch(deque<int>& instrucoes){
    while((int)IF.size() < maxIF && !instrucoes.empty()){
      int i;
      // procura posicao para ler
      for(i = 0 ; i < maxIF && IF.count(i); ++i);

      // le
      IF[i] = instrucoes.front();
      instrucoes.pop_front();
    }
  }

  // IF -> ID
  void decode(){
    while((int)ID.size() < maxIF && !IF.empty()){
      // para nao ficar esperando, pega a que entrou primeiro
      int pos = -1;
      int instrucao = 0;
      for(auto p : IF){
        if(prioridade[p.second] < prioridade[instrucao]){
          pos = p.first;
          instrucao = p.second;
        }
      }
      assert(pos >= 0);

      // procura posicao livre em ID
      int i;
      for(i = 0; i < maxIF && ID.count(i); ++i);
      assert(i < maxIF);

      // insere a instrucao
      ID[i] = instrucao;
      IF.erase(pos);
    }
  }

  // checa se a instrucao na posicao i pode ser executada
  /************** in-in / in-out so interessa aqui **************/
  bool podeExecutar(int i){
    // verifica se os dependencias foram executados
    for(auto d : buffer[i].dependencias){
      if(buffer[d].terminouCiclo == -1 || (buffer[d].terminouCiclo == numCiclo && !forwarding)){
        return false;
      }
    }

    // verifica se tem que sair em ordem
    /// assume que vetor buffer comeca com 1
    if(in_in && i > 1){
      int anterior = i - 1;
      if(buffer[anterior].terminouCiclo == -1){ // anterior nao terminou
        // procura se ta executando
        bool flag = false;
        for(auto ex : EX){
          int instrucao = ex.second.first;
          if(anterior == instrucao){ // achou!
            flag = true;

            // conta quando vai terminar
            int nciclos = buffer[instrucao].nc - ex.second.second;

            // se esse terminar antes, nao pode executar (para sair em ordem)
            if(nciclos >= buffer[i].nc){
              return false;
            }

            break;
          }
        }

        // o anterior nao esta sendo executado, ou seja esse nao pode!
        if(!flag){
          return false;
        }
      }
    }

    // verifica se quando terminar vai sair (para nao encher W e nao ficar ocupando EX)
    return numGravacoes[numCiclo + buffer[i].nc] < maxW;
  }

  // ID -> EX
  void execute(){
    // if(out_out){
      // executeDispatcher();
      // return;
    // }

    set<int> used;  // elementos ja tentados

    while((int)EX.size() < maxEX && used.size() < ID.size()){
      // procura um elemento com prioridade (para nao ficar esperando)
      int pos = -1;
      int instrucao = 0;
      for(auto p : ID){
        if(prioridade[p.second] < prioridade[instrucao] && !used.count(p.second)){
          pos = p.first;
          instrucao = p.second;
        }
      }
      used.insert(instrucao);
      assert(pos >= 0);

      if(podeExecutar(instrucao)){
        // acha o lugar pra executar a instrucao
        int i;
        for(i = 0; i < maxEX && EX.count(i); ++i);
        assert(i < maxEX);

        // executa a instrucao
        EX[i] = ii(instrucao, 1);   // ii(posicao, ciclos executados)
        ID.erase(pos);
        used.clear();               // reinicia pois pode encontrar outro

        // havera +1 a ser gravado nesse ciclo
        ++numGravacoes[numCiclo + buffer[instrucao].nc];
      }
    }
  }

  // EX -> W
  void write()
  {
    W.clear();

    // quem ta pronto DEVE sair
    for(auto ex = EX.begin(); ex != EX.end();)
    {
      int i = ex->second.first;               // posicao da instrucao atual
      int& ciclos = ex->second.second;        // numero de ciclos ja executados
      assert(ciclos <= buffer[i].nc);         // nao pode ficar ocupando EX
      if(ciclos == buffer[i].nc){             // acabou!
        assert((int)W.size() < maxW);         // tem que sair!

        int pos = W.size();
        W[pos] = i;                           // indice da intrucao que acabou
        buffer[i].terminouCiclo = numCiclo;
        ex = EX.erase(ex);
      }
      else{
        ++ex;
        ++ciclos;
      }
    }
  }

  Ciclo proximoCiclo(deque<int>& instrucoes) const{
    Ciclo c = *this;
    ++c.numCiclo;
    c.write();
    c.execute();
    c.decode();
    c.fetch(instrucoes);
    return c;
  }
};

//####################################################
//####################################################

struct Escalonador{
  int EX[1000][10];// "supondo" no maximo isso aqui
  int cicloFim[1000];
  bool jafoi[1000];
  int menorqtdCiclos;
  deque<int> otimo;
  vector<int> V;
  
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


  void Escalona(int cicloAtual,int qtd){

    if(qtd == (int)V.size()){
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

      if(jafoi[V[i]] == false && achaNoCiclo(l,c)){
        Instrucao I = buffer[V[i]];
        if(pode(I,cicloAtual)){
	        jafoi[V[i]] = true;
	        coloca(l,c,I.id,I.nc);
	        cicloFim[I.id] = l+(!forwarding);
	        Escalona(cicloAtual,qtd+1);Escalona(cicloAtual+1,qtd+1); // posso ir para o proximo ciclo ou nao...
	        tira(l,c,I.nc); // tira a instrucao que coloquei antes da recursao
	        cicloFim[I.id] = 0;
	        jafoi[I.id] = false;
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

  Escalonador(){

    // LE VARIAS INTRUCOES E ESCALONA NA FORCA BRUTA MORTALITI

    for(auto x : buffer) V.push_back(x.first);
    
    escalonador();

    for(auto i : otimo){
      cout << i <<'\n';
    }
  }

  int main(){

    return 0;
  }
};

void print(Ciclo c){
  const char str_separadora[] = {"  ###  "};
  string chr_separadora;
  while((int)chr_separadora.size() < maiorId){
    chr_separadora.push_back(' ');
  }
  chr_separadora.push_back('|');

  // imprime IF
  cout << '|';
  for(int i = 0; i < maxIF; ++i){
    if(c.IF.count(i)) cout << setw(maiorId) << posToId[ c.IF[i] ] << '|';
    else cout << chr_separadora;
  }
  cout << str_separadora;

  // imprime ID
  cout << '|';
  for(int i = 0; i < maxIF; ++i){
    if(c.ID.count(i)) cout << setw(maiorId) << posToId[ c.ID[i] ] << '|';
    else cout << chr_separadora;
  }
  cout << str_separadora;

  // imprime EX
  cout << '|';
  for(int i = 0; i < maxEX; ++i){
    if(c.EX.count(i)) cout << setw(maiorId) << posToId[ c.EX[i].first ] << '|';
    else cout << chr_separadora;
  }
  cout << str_separadora;

  // imprime W
  // ordena vetor W, para sair em ordem (caso do in_in)
  vector<int> temp;
  for(auto w : c.W){
    temp.push_back(w.second);
  }

  sort(temp.begin(),temp.end());
  cout << '|';
  for(int i : temp){
    cout << setw(maiorId) << posToId[i] << '|';
  }
  for(int i = temp.size() ; i < maxW; i++){
    cout << chr_separadora;
  }
  cout << "\n";
}

void simula(deque<int> instrucoes)
{
  vector<Ciclo> ciclos(1, Ciclo());
  while(!instrucoes.empty() || !ciclos.back().finished()){
    ciclos.push_back(ciclos.back().proximoCiclo(instrucoes));
  }

  ciclos.erase(ciclos.begin());         // remove o ciclo nulo
  for(auto c : ciclos){                 // imprime todos os ciclos
    print(c);
  }
}

void init(){
  in_in = false;
  in_out = false;
  out_out = false;
  forwarding = false;

  maxIF = -1;
  maxEX = -1;
  maxW = -1;
  maiorId = -1;

  buffer.clear();
  memset(numGravacoes, 0, sizeof numGravacoes);
  idToPos.clear();
  posToId.clear();
}

void le(){
  // >>>>>> dependentes != dependencias <<<<<<

  int mode = -1;
  cin >> maxIF >> maxEX >> maxW >> mode >> forwarding;
  assert(maxIF > 0 && maxEX > 0 && maxW > 0 && (mode == 0 || mode == 1 || mode == 2));

  in_in = mode == 0;
  in_out = mode == 1;
  out_out = mode == 2;

  map<string,set<int>> dependencias;        // dependencias de cada um

  char ignore;
  string id, dep;
  int nc, cnt = 0;

  cin.ignore(10000, '\n');
  while(getline(cin, id, ':') && cin >> nc >> ignore && getline(cin, dep, '\n')){
    assert(ignore == ':');                  // nao pode ter espacos
    assert(nc > 0);                         // ciclo tem que ser positivo

    // da um numero para o id
    int idPos = idToPos[id] = ++cnt;
    posToId[idPos] = id;

    maiorId = max(maiorId, (int)id.size()); // pega maior id para imprimir viadinho ;)

    // cria a instrucao
    buffer[idPos] = Instrucao(idPos, nc, dependencias[id]);

    // seta os dependentes
    istringstream iss(dep);
    while(getline(iss, dep, ',')){
      dependencias[dep].insert(idPos);
    }
  }
}

int main()
{
  assert(freopen("in","r",stdin));
  // assert(freopen("out","w",stdout));

  init();
  le();
  deque<int> instrucao;
  if(out_out){
    Escalonador e;
    instrucao = e.otimo;
  }
  else{
    for(auto x : buffer){
      instrucao.push_back(x.first);
    }
  }
  prioridade[0] = inf;
  int p = 0;
  for(auto x : instrucao){
    prioridade[x] = ++p;
  }

  simula(instrucao);

  return 0;
}
