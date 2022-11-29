#include<stdio.h>
#include<string.h>
#define max  1000

char infix[max];
char postfix[max];
char stack[max];
int top=-1;


char pop(){
	if(top == -1) return '0';
	top--;
	return stack[top+1];
	
}

void push(char x){
	if(top == max) return;
	stack[top+1] = x;
	top++;
}
bool isEmpty(){
	if(top==-1) return true;
	return false;
}
int precedence(char x){
	switch(x){
		case '^' :
			return 3;
		case '*' :
		case '/' :
			return 2;	
		case '+' :
		case '-' :
			return 1;
		default :
		return 0;						
	}
	return 0;
} 

void infixToPostfix(){
	int i=0, j=0;
	char symbol, next;
	while(infix[i] != '\0'){
		symbol = infix[i];
		switch(symbol){
			case '(' :
				push(symbol);
				break;
			case ')' :
				while((next=pop()) != '('){
					postfix[j++]=next;
				}	
				break;
			case '+':	
			case '-':	
			case '*':	
			case '/':	
			case '^':	
				while(!isEmpty() && precedence(stack[top]) >= precedence(symbol)){
					postfix[j++]=pop();
				}
				push(symbol);
				break;																		
			default:
				postfix[j++]=symbol;	
		}
		i++;
	}
	

	while(!isEmpty()){
			
		postfix[j++]=pop();
	}
	
	printf("%s", postfix);
	
}

int main(){
	gets(infix);	
	infixToPostfix();
}