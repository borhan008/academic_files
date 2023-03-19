#include<stdio.h>
#include<math.h>

#define ll int

ll partition(ll a[],  ll low, ll high){
	ll pivot,i,j,t;
	
	pivot = a[high];
	for(i=low-1, j=low; j<high; j++){
		if(a[j] < pivot){
			i++;
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}
	
	t=a[high];
	a[high]=a[i+1];
	a[i+1]=t;
	
	return (i+1);
}

void quickSort(ll a[], ll low, ll high){
	if(low >= high) return;
	
	ll p = partition(a, low, high);

	quickSort(a, low, p-1);
	quickSort(a, p+1, high);
}

int main(){
	ll n; scanf("%d", &n);
	ll a[n];
	for(ll i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	quickSort(a, 0, (n-1));
	
	for(ll i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}	