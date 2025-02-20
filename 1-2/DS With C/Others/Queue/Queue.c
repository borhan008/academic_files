#include<stdio.h>
#define max 5


int Queue[500];
int front=-1, rear=-1;

void enqueue(int x){
	if(rear == max-1){
		printf("Overflow\n");
		return;
	}
	if(rear == -1) front = 0;
	rear++;
	Queue[rear]=x;
}

int dequeue(){
	if(front == -1){
		printf("Underflow\n");
		return -1;
	}
	int x = Queue[front];
	return x;
}


void traverse(){
	if(front == -1 || rear == -1){
		printf("Empty\n");
		return;
	}
	for(int i=front; i<=rear; i++){
		printf("%d ", Queue[i]);
	}
	printf("\n");
}


int main(){
	
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	traverse();
	printf("Dequeue : %d \n" ,dequeue());
	traverse();
	enqueue(30);
	traverse();
	enqueue(40);	
	return 0;
	
}