#include<stdio.h>

int fib(int n){
	if(n==0) return 0;
	if(n==1 || n==2) return 1;
	return fib(n-2)+fib(n-1);
}

int main(){
	

	
	printf("%d", fib(6));
	
	
	return 0;
}