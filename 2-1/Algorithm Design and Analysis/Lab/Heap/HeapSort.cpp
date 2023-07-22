#include<bits/stdc++.h>
using namespace std;

void heapify(int n, int arr[], int size){
	int left = n*2;
	int right = left+1;	
	int largest = n;
	
	if(left <= size && arr[left] > arr[largest]){
		largest = left;
	}
	if(right <= size && arr[right] > arr[largest]){
		largest  = right;
	}
	
	if(n != largest){
		swap(arr[n], arr[largest]);
		heapify(largest, arr, size);
	}
}

void heapsort(int n, int arr[]){
	int size = n;
	
	for(int i=n/2; i>0; i--){
		heapify(i, arr, n);
	}	
	
	while(size > 1){
		swap(arr[1], arr[size]);
		size--;
		heapify(1, arr, size);
	}
}

int main(){
	int n;	cin >> n;
	int arr[n+1];
	arr[0]=-1;
	
	for(int i=1; i<=n; i++) cin >> arr[i];
	
	heapsort(n, arr);
	
	for(int i=1; i<=n; i++)	cout << arr[i] << " ";
	
	return 0;
}