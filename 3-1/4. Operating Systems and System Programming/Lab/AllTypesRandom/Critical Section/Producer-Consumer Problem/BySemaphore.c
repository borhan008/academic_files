#include <stdio.h>

int mutex = 1, full = 0, empty = 3;

void wait(int *S) {
	(*S)--;
}

void signal(int *S) {
	(*S)++;
}

void produce() {
	wait(&empty);
	wait(&mutex);
	printf("Producer produces the item %d\n", full + 1);
	signal(&mutex);
	signal(&full);
}

void consume() {
	wait(&full);
	wait(&mutex);
	printf("Consumer consumes the item %d\n", full + 1);
	signal(&mutex);
	signal(&empty);
}

int main ()
{	
	printf("1.Producer\n2.Cosumer\n3.Exit\n");
	int choice;
	
	while(1) {
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				if(mutex == 1 && empty != 0) produce();
				else printf("Buffer is full\n");
				break;
			
			case 2:
				if(mutex == 1 && full != 0) consume();
				else printf("Buffer is empty\n");
				break;
			
			case 3:
				return 0;
		}
	}
	
	return 0;
}

