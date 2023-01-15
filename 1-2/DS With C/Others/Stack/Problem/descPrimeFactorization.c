#include<stdio.h>
#define MAX 5000
//Write a program to print all prime factors of a number in descending order using a stack

int stack[MAX];
int top=-1;

void push(int n){
	if(top == MAX) return;
	top++;
	stack[top] = n; 
}


int pop(){
	top--;
	return stack[top+1];

}

void primeFactosWithDescending(int n){
	int i=2;
	while(n >= i){
		while(n%i == 0){
			push(i);
			n=n/i;
		}
		i++;
	}
	if(n > 2)  push(n);
	while(top != -1){
		printf("%d ", pop());
	}
}




int main(){
	int n;
	scanf("%d", &n);
	primeFactosWithDescending(n);
	
}