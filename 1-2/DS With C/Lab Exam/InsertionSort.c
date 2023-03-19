#include<stdio.h>

#define ll int

int main(){
	ll n,j,k,t; 
	scanf("%d", &n);
	
	ll a[n];
	for(ll i=0; i<n; i++) scanf("%d", &a[i]);
	
	for(ll i=1; i<n; i++){
		j= i-1;
		k=i;
		
		while((a[j] > a[k]) && j >= 0){
			t=a[k];
			a[k]=a[j];
			a[j]=t;
			
			j--;
			k--;
		}
			
	}
	
	for(ll i=0; i<n; i++) printf("%d ", a[i]);
}