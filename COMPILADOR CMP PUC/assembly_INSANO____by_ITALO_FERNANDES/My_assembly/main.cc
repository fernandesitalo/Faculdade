// compilado com:: g++ -Wall -Wextra -fsanitize=address -std=c++11 -o "%e" "%f"
// by: Italo Fernandes Goncalves

#include <bits/stdc++.h> // INCLUI TODAS BIBLIOTECAS.. MANDIGA MESMO
#include "MV.h" // DOCUMENTACAO BASICA SE ENCONTRA NESSE ARQUIVO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
using namespace std;

// function for read archive
string read_archive(string nome_do_arquivo);

int main(){

  string text = read_archive("input"); /// NOME DO ARQUIVO COM O PROGRAMA AQUI!!!!!!! COLOCAR NA MESMA PASTA COM ESSE ARQUIVO '.cc' ...

  MV assembly( text );
  assembly.process();

  return 0;
}

/*

SAMPLE OF INPUT:

mov r2 5
mov r3 5
sub r1 r2 r3
print r1
add r1 r2 r3
print r1
mov r3 1
mov r2 r1
jne r3 r1 r2
div r1 r2 r3
print r1
mod r1 r2 r3
print r1
mul r1 r2 r3
print r1
pot r1 r2 r3
print r1
mov r1 6
print r1
mov r1 100
push r1
pop r3
add r1 r1 r3
print r1

OUTPUT FOR THIS INPUT:
0
10
10
0
10
10
6
200

*/


string read_archive(string nome_do_arquivo){
  freopen(nome_do_arquivo.data(),"r",stdin);
  string prog,line;
  while(cin >> line){
    prog += line;
    prog += " ";
  }
  return prog;
}
