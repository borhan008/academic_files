#include<stdio.h>

#define ll int

int main(){
	ll n, lowest, t;
	scanf("%d", &n);
	
	ll a[n];
	for(ll i=0; i<n; i++) scanf("%d", &a[i]);
	
	for(ll i=0; i<n; i++){
		lowest=i;
		
		for(ll j=i+1; j<n; j++){
			if(a[lowest] > a[j]) lowest=j;
		}
		
		t=a[lowest];
		a[lowest]=a[i];
		a[i]=t;
	}
	
	for(ll i=0; i<n; i++) printf("%d ", a[i]);
}