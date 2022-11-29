#include<stdio.h>
#define MAXSTACKS 100

int stack_arr[MAXSTACKS];
int top=-1;

void push(int data){
	if(top == MAXSTACKS){
		printf("Stack is full \n");
		return;
	}
	top++;
	stack_arr[top] = data;
}

int pop(){
	if(top == -1){
		printf("Stack is empty \n");
		return -1;
	}
	top--;
	return stack_arr[top+1];
}



bool isEmpty(){
	if(top == -1){
		return true;
	}
	return false;
}

bool isFull(){
	if(top == MAXSTACKS){
		return true;
	}
	return false;
}

void traverse(){
	if(top == -1){
		printf("Stack is empty");
		return;
	}
	for(int i=0; i<=top; i++){
		printf("%d ", stack_arr[i]);
	}
}

int main(){
	push(5);
	push(5);
	push(5);
	traverse();
	int pop1 = pop();
	printf("\npop : %d \n", pop1);
	traverse();
	printf("\n%d\n", isEmpty());
	printf("%d\n", isFull());
}