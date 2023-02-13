#include<stdio.h>

int main(){
	int START=6;
	int INFO[1000] = {55,23,64,78,10,25,10,32,64,20};
	int LINK[1000]={5,3,-1,4,2,1,9,0,7,8};
	
	int search = 55;
	int point=START;
	while(point != -1){
		if(INFO[point] == search){
			printf("Found at %d\n", point);
			return 0;
		}
		point=LINK[point];
	}
	printf("Not Found.");
	return 0;
	
	
}