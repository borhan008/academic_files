#include<stdio.h>

int main(){
	int n,t;
	scanf("%d", &n);
	
	int a[n];
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++){
			if(a[j] > a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}	
	}
	
	for(int i=0; i<n; i++) printf("%d ", a[i]);
}