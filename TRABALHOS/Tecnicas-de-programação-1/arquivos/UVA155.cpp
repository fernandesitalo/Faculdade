#include <cstdio>
#include <iostream>
using namespace std;

int qtd = 0;

int xp,yp;


void cq(int x,int y,int k)
{
	if(k == 0)
		return;
	
	if(xp <= x+k && xp >= x-k && yp <= y+k && yp >= y-k)
	{
		qtd++;
	} 
	
	cq(x-k,y-k,k/2);
	
	cq(x+k,y-k,k/2);
	cq(x-k,y+k,k/2);
	cq(x+k,y+k,k/2);
	
}


int main()
{
	int k;
	
	
	while(cin >> k>>xp>>yp,k || xp || yp){
	
	cq(1025,1025,k);
	cout<< qtd<<endl;
	
}
	
	
}

