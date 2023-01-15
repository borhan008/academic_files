#include<stdio.h>
#define MAX (int)1e5

char stack[MAX];
int top=-1;

void push(char x){
	if(top == 1e5) return;
	top++;
	stack[top]=x;
}
char pop(){
	if(top == -1) return 'a';
	top--;
	return stack[top+1];
}

bool validChecker(char x[], int n){
	
	for(int i=0; i<n; i++){
		if(x[i] == '(' || x[i] == '{' || x[i] == '['){
			push(x[i]);
		}else{
			if((x[i] == ')' && pop() != '(')
			||
			(x[i] == '}' && pop() != '{')
			||
			(x[i] == ']' && pop() != '['))
			return false;
		}
	}	
	if(top == -1)
		return true;
	else return false;	
}

int main(){
	int n=10;
	char x[n]="[{([()])}]";
	
	printf("%s", validChecker(x, n) ? "Valid" : "Invalid");

	return 0;
	
}