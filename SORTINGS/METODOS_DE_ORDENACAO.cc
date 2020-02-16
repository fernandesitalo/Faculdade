#include <bits/stdc++.h>
using namespace std;

void radixSort (int digitos, int* arr ,  int tam){

	queue<int> vet[10];
	int aux = 1,aux2;
	
	while(digitos--){
		aux *= 10;
		aux2 = aux/10;
		
		for(int i = 0 ; i < tam ; ++i){
			vet[(arr[i]%aux)/aux2].push(arr[i]);
		}
		
		int idx = 0;
		
		for(int i = 0 ; i < 10 ; ++i){
			
			int temp;
			
			while(!vet[i].empty()){
				temp = vet[i].front();
				arr[idx++] = temp;
				vet[i].pop();
			}
		}			
	}
}


void insertSort(int* arr,int tam){
	
	int menor;	
	for(int i = 0 ; i < tam-1 ; ++i){
		menor = i;
		for(int j = i+1 ; j < tam ; ++j){
			if(arr[menor] > arr[j]){
				swap(menor,j);
			}
		}		
		swap(arr[menor],arr[i]);
	}
	
}


void BubbleSort(int * arr, int tam){
	
	bool p = 1;
	
	while (p){
		p = false;
		
		for(int j = 1; j < tam ; ++j){
			if(arr[j-1] > arr[j]){
				swap(arr[j-1],arr[j]);
				p = true;
			}
		}
	}
	
}

void mergeSort (int* arr, int n)
{
	if (n == 1)
		return;
	
	int mid = n / 2;
	
	mergeSort(arr, mid);
	mergeSort(arr + mid, n - mid);
	
	int i = 0;
	int j = mid;
	int k = 0;
	
	int vet[n];
	
	while (i < mid && j < n)
		if (arr[i] < arr[j])
			vet[k++] = arr[i++];
		else
			vet[k++] = arr[j++];
			
	while (i < mid)
		vet[k++] = arr[i++];
	while (j < n)
		vet[k++] = arr[j++];
	
	for (i = 0; i < k; ++i)
		arr[i] = vet[i];
}

void quickSort (int* arr, int left, int right) {
      int l = left, r = right;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (l <= r) {
            while (arr[l] < pivot)
                  l++;
            while (arr[r] > pivot)
                  r--;
            if (l <= r)
				swap(arr[l++], arr[r--]);
      }
 
      /* recursion */
      if (left < r) quickSort(arr, left, r);
      if (l < right) quickSort(arr, l, right);
}

int main(){

	int vet[] = {92,546,78,123,6,7,9,124,65,78,10,2,2,4};
	
	int tam = sizeof(vet)/sizeof(vet[0]);
	
	//mergeSort(vet, tam);
	//BubbleSort(vet,tam);
	
	for(int i = 0 ; i < tam ; ++i) printf("%d ",vet[i]);
	
	
	return 0;
}
