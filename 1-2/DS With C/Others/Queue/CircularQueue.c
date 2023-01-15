#include<stdio.h>
#define max 5

int Queue[max];
int front=-1;
int rear=-1;

void enqueue(int x){
	if((rear+1)%max == front){
		printf("Overflow\n");
		return;
	}
	if(rear == -1) front=0;
	Queue[(rear+1)%max]=x;
	rear = (rear+1)%max;
}
int dequeue(){
	if(front==-1){
		printf("Underflow\n");
		return -1;
	}
	int x = Queue[front];
	front =  (front+1)%max;
	
	return x;
}

void traverse(){
	if(front == -1 || rear == -1){
		printf("Empty");
		return;
	}
	int i=front;
	while(i!=rear){
		printf("%d ", Queue[i]);
		i = (i+1)%max;
	}
	printf("%d", Queue[rear]);
	printf("\n");
}

int main(){
	enqueue(1); 
	enqueue(2); 
	enqueue(3); 
	enqueue(4); 
	enqueue(5);
	enqueue(6);
	traverse();
	printf("Dequeue : %d \n", dequeue());
	printf("Dequeue : %d \n", dequeue());
	traverse();
	enqueue(100);
	enqueue(200);
	traverse();
	return 0;
}