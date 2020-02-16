#include <bits/stdc++.h>
using namespace std;



template <class T>
int partition(T *arr,int l, int r){
	T pivot = arr[r];
	
	for(int i = l; i < r ; ++i){
		if(arr[i] < pivot){ // se o elemento é menor que o pivot, coloca ele la na frente...
			swap(arr[i],arr[l++]);
		}		
	}
	swap(arr[r],arr[l]); // coloca o pivot no lugar certo
	return l;
}


template <class T>
void QuickSort(T *arr, int l, int r){
	
	if(l >= r) return;
	
	int middle = partition(arr,l,r); // retorna o lugar onde o pivot ficou
	
	QuickSort(arr,      l      ,  middle-1);
	QuickSort(arr,   middle+1  ,   r      );
}



int main(){
	freopen("Aleatorio.txt","r",stdin);
	int n;
	scanf("%d",&n);
	long double *arr = new long double[n+1];
	for(int i = 0 ; i < n ; ++i) scanf(" %Lf",&arr[i]);
	QuickSort(arr,0,n-1);
}
	
