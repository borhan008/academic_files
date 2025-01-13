#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 3

bool flag[2] = {false, false};
int buffer[BUFFER_SIZE];
int items = 0;
int in = 0;
int out = 0;
int turn = 0;

void* producer(void* arg) {
	while(1) {
		// Entry Section
		flag[0] = true;
		turn = 1;
		
		while(flag[1] && turn == 1); // Wait
		
		// Critical Section
		if(items < BUFFER_SIZE) {
			buffer[in] = in + 1;
			printf("Producer: Produced item %d\n", buffer[in]);
			in = (in + 1) % BUFFER_SIZE;
			items++;
		} else {
			printf("Producer: Buffer is full, waiting...\n");
		}
		
		// Remainder Section
		flag[0] = false;
		
		sleep(1); // Delay for slower output
	}
	
	return NULL;
}

void* consumer(void* arg) {
	while(1) {
		// Entry Section
		flag[1] = true;
		turn = 0;
		
		while(flag[0] && turn == 0); // Wait
		
		// Critical Section
		if(items > 0) {
			printf("Consumer: Consumed item %d\n", buffer[out]);
			out = (out + 1) % BUFFER_SIZE;
			items--;
		} else {
			printf("Consumer: buffer is empty, waiting...\n");
		}
		
		// Remainder Section
		flag[1] = false;
		
		sleep(1);
	}
	
	return NULL;
}

int main()
{
	pthread_t producer_thread, consumer_thread;
	
	pthread_create(&producer_thread, NULL, producer, NULL);
	pthread_create(&consumer_thread, NULL, consumer, NULL);
	
	pthread_join(producer_thread, NULL);
	pthread_join(consumer_thread, NULL);
		
	return 0;
}