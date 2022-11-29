#include<stdio.h>
#define max 10000

int low[max];
int high[max];
int topLow = -1;
int topHigh = -1;
void pushLow(int x){
	if(topLow == max) return;
	topLow++;
	low[topLow]=x;
}
void pushHigh(int x){
	if(topHigh == max) ;
	topHigh++;
	high[topHigh]=x;
}
int popLow(){
	if(topLow == -1) return -1;
	topLow--;
	return low[topLow+1];
}

int popHigh(){
	if(topHigh == -1) return -1;
	topHigh--;
	return high[topHigh+1];
}

int arr[max];


int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	pushLow(0);
	pushHigh(n-1);
	while(topLow != -1 && topHigh!=-1){
		int i = popLow();
		int j = popHigh();
		int x=i, y=j;
		int pivot = arr[i];
	
		while(i<j){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;	
			}else{
				if(arr[i] == pivot) j--;
				else i++;
			}
		} 
		
	
		if(j-1-x >= 2){
			pushLow(x);
			pushHigh(j-1);
				
		}
		if(y-j-1 >= 2){
			pushLow(j+1);
			pushHigh(y);
				
		}
	
	}
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
}