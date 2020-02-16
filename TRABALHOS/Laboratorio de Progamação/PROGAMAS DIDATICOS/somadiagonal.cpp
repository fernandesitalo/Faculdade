#include<iostream>
using namespace std;
int main()
{
	int m[3][3], i, j, dp, ds;
	for( i=0; i<3; i++ )
	{
		for( j=0; j<3; j++ )
		{
			cout<<"m["<< i + 1<< "," << j + 1<< "] =";
			cin>>m[i][j];
		 }
	}
	for( i=0; i<3; i++ )
	{
		for( j=0; j<3; j++ )
		{
			cout<<m[i][j]<<"\t";
		}
		cout<<endl;
	}
	for( i=0; i<3; i++ )
	{
		for( j=0; j<3; j++ )
		{	
			dp = dp + m[i][i];
		}
	}
	j = 3 - 1;
	for( i=0; i<3; i++ )
	{
		for( j=0; j<3; j++ )
		{ 
			ds = ds + m[i][j];
		}
	}
	if ( dp == ds )
	{
		cout<<"Sao iguais"<<endl;
	}
	else
	{
		cout<<"Nao sao iguais"<<endl;
	}
}
