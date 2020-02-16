// by: Italo Fernandes
// Analizador lexico INSANO
// ATENÇÂO!?#%
// compilado com: g++ -Wall -Wextra -fsanitize=address -std=c++11 -o "%e" "%f"


#include<bits/stdc++.h> // biblioteca do mal - inclui tudo hahaa
using namespace std;

#define db(x_) cerr << #x_ << " == " << x_ << '\n'

#define ID         0
#define NUM        1
#define OPR_AR     2
#define OPR_REL    3
#define OPR_LOG    4
#define DELIM      5
#define ATRIB      9
#define ERRO       10

int const maxt = 20;

string const delim = "(),;";
string const opr_ar = "+-/%*^";

string types[maxt]; // "hash" simples dos tipos, posicao da string eh seu hash - "mapa" e o contra hash
unordered_map<string,int> mapa, palavrasReservadas;
// unordered_map das palavras reservadas, se encontrar um ID, vou verificar se este ID esta neste map...
// caso esteja, eh uma palavra revervada e seu type é o conteudo desta string no map


struct token{ // token insano
  int type;
  string value;
  token():type(11),value(""){/*TOKEN VAZIO*/}
  token(int type,string value):type(type),value(value){}
};


void inicializa_analisador(){ // insanamente
  string aux;
  //                0   1      2       3       4     5  6    7     8     9   10    11
  stringstream ss("ID NUM OPR_AR OPR_REL OPR_LOG DELIM IF ELSE WHILE ATRIB ERRO VAZIO"); // !!!
  int idx = 0;
  while(ss>>aux){
    mapa[aux] = idx;  // mapa e contra mapa
    types[idx++] = aux;
  }

  // MAPEANDO Palavras reservadas
  palavrasReservadas["while"] = 8;
  palavrasReservadas["else"] = 7;
  palavrasReservadas["if"] = 6;
  palavrasReservadas["and"] = 4;
  palavrasReservadas["or"] = 4;
  palavrasReservadas["not"] = 4;
}



vector<token> analisa(string in){

  vector<token> LIST;

  // funcao lambda  -  eh ou n um DELIM
  auto isdelim = [&](const char & a)->bool{
    for(auto i : delim)
      if(a == i) return true;
    return false;
  };

  // funcao lambda  - eh ou n um OPR_AR?
  auto isopr_ar = [&](const char & a)->bool{
    for(auto i : opr_ar)
      if(a == i) return true;
    return false;
  };

  // funcao lambda - trata caso ID
  auto trata_caso_id = [&](string token_atual)->void{
    if(palavrasReservadas.count(token_atual))
      LIST.push_back({palavrasReservadas[token_atual],token_atual});
    else 
			LIST.push_back({ ID , token_atual });
  };


  // analisador comeca aqui!
  // tratei caso a caso - fluxograma ta cmg..
  // fiz com o automato tbm, porem o codigo n ficou legivel como este.

  int sz = in.size(), idx = 0;
  string token_atual;
  string nd = "";
  while(sz > idx){
		
    if(in[idx] == ' ' || in[idx] == '\n'){ // ignora espaço
      idx++;
      continue;
    }

    token_atual = "";

    if(isalpha(in[idx])){                                                           // TRATA ID
      while(sz > idx && (isalpha(in[idx]) || isdigit(in[idx])) ) token_atual += in[idx++];
      trata_caso_id(token_atual);
    }
    else if(in[idx] == '-' || isdigit(in[idx])){                                    // TRATA DIGITO
      if(in[idx] == '-') token_atual = '-',idx++;

      if(sz > idx && isdigit(in[idx])){	
        while(sz > idx && isdigit(in[idx])) // enquanto for digito 
					token_atual+=in[idx++];

        if(sz > idx && in[idx] == '.'){			// o numero eh decimal

          if(sz > idx+1 && isdigit(in[idx+1])){ 
            token_atual += in[idx++];
            while(sz > idx && isdigit(in[idx])) // pega parte decimal
							token_atual+=in[idx++]; 
							
            LIST.push_back({ NUM ,token_atual});
          }
          else { // caso em que encontra "NUM." , o ponto era zueira
            LIST.push_back({ NUM , token_atual}),
            LIST.push_back({ ERRO , "." }),
            idx++;
          }
        }
        else LIST.push_back({ NUM ,token_atual});                                   // OPR_AR que veio apos um digito!

        if(sz > idx && isopr_ar(in[idx])) 																					// OPR_AR apos NUM (pode ser um '-')
					LIST.push_back({ OPR_AR ,nd+in[idx++]}); 
      }
      else LIST.push_back({ OPR_AR ,token_atual});                                  // '-' não faz parte de um numero .: considera opr_ar
    }
    else if(isdelim(in[idx]))    LIST.push_back({ DELIM ,nd+in[idx++]});						// trata DELIM
    else if(isopr_ar(in[idx]))   LIST.push_back({ OPR_AR ,nd+in[idx++]});						// trata OPR_AR
    else{
      // tratar casos de OPERADORES RELACIONAIS na "UNHA"

      if(sz > idx+1 && in[idx] == '!' && in[idx+1] == '=')   LIST.push_back({ OPR_REL ,"!="}),idx+=2; 	// !=
      else if(in[idx] == '='){																		
        if(sz > idx+1 && in[idx+1] == '=')                   LIST.push_back({ OPR_REL ,"=="}),idx+=2;		// ==
        else                                                 LIST.push_back({ ATRIB ,"="}),idx++;				// =
      }
      else if(in[idx] == '<'){
        if(sz > idx+1 && in[idx+1] == '=')                   LIST.push_back({ OPR_REL ,"<="}),idx+=2;		// <=
        else                                                 LIST.push_back({ OPR_REL ,"<"}),idx++;			// <
      }
      else if(in[idx] == '>'){
        if(sz > idx+1 && in[idx+1] == '=')                   LIST.push_back({ OPR_REL ,">="}),idx+=2;   // >=
        else                                                 LIST.push_back({ OPR_REL ,">"}),idx++;			// >
      }
      else                                                   LIST.push_back({ ERRO , nd+in[idx++]}); // erro lexico
    }
  }
  return LIST;
}



int main(){
	
	freopen("in","r",stdin); // progama
  
  inicializa_analisador(); // uhuu
	string prog(""),aux("");

	while( getline(cin,aux) ){
		// inserir espaco para que na analise, se 2 variaveis estiverem separadas por uma quebra de linha, sejam consideradas separadas
		prog += aux + " "; 
	}
	
  /// testes alfa
  // auto tokens = analisa("x=10+7+2+1+x;");
  // auto tokens = analisa("int main(){}");
  // auto tokens = analisa("while(1) x = x + 1;");
	// auto tokens = analisa("vc 5 + 10 * 18 % 2 + 1 if else -5090 88 -8.90 8.1.......... and or not =");
	
	auto tokens = analisa(prog);
	
  cout << "TOKEN\tTYPE\n\n";
  for(auto t : tokens){
    cout << types[ t.type ] << "\t" << t.value << "   \n";
  }
  
  cout <<"\n";
}
