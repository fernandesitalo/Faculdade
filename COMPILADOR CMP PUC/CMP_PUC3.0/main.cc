// compilado com:: g++ -Wall -Wextra -fsanitize=address -std=c++11 -o "%e" "%f"
// by: Italo Fernandes Goncalves

#include <bits/stdc++.h> // INCLUI TODAS BIBLIOTECAS.. MANDIGA MESMO
#include "MV.h" // DOCUMENTACAO BASICA SE ENCONTRA NESSE ARQUIVO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
using namespace std;


bool nooperation(string line){
	for(auto i : line) {
		if(i != ' ') return false;
	}
	return true;
}




int main(){
  freopen("entrada.cmp","r",stdin);
  vector<string> prog;
  string line;
  bool flag = true; // inicio
  
  while(getline(cin,line)){
	if(flag){
		if(!nooperation(line)){
			prog.push_back(line);
			flag = false;
		}
	}
	else{
		prog.push_back(line);
	}
  }
  

  MV assembly( prog );
  assembly.process();
  
  return 0;
}
