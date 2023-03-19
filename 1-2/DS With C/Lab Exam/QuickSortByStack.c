#include<stdio.h>
#include<math.h>

#define ll int
#define MAX 100000

ll HIGH[MAX];
ll topHigh=-1;

ll LOW[MAX];
ll topLow=-1;

void highPush(ll data){
	if(topHigh == MAX-1){
		printf("Stack is full\n");
		return;
	}
	HIGH[++topHigh]=data;
}

int highPop(){
	if(topHigh == -1){
		printf("Stack is empty");
		return -1;
	}
	return HIGH[topHigh--];
}

void lowPush(ll data){
	if(topLow == MAX-1){
		printf("Stack is full");
		return;
	}
	LOW[++topLow]=data;
}

int lowPop(){
	if(topLow == -1){
		printf("Stack is empty");
		return -1;
	}
	return LOW[--topLow];
}


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


int main(){
	ll n; scanf("%d", &n);
	ll a[n];
	
	for(ll i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	
	lowPush(0); highPush(n-1);
	while(topHigh != -1 && topLow != -1){
		ll low=lowPop();
		ll high=highPop();
		
		ll p = partition(a, low, high);
		
		if(low < p-1){
			lowPush(low);
			highPush(p-1);
		}
		if(p+1 < high){
			lowPush(p+1);
			highPush(high);
		}

	}
	
	for(ll i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}	