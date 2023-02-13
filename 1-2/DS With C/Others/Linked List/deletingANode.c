#include<stdio.h>

int main(){
	int START=6;
	int INFO[1000] = {55,23,64,78,10,25,10,32,64,20};
	int LINK[1000]={5,3,-1,4,2,1,9,0,7,8,20,19,18,15,17,16,14,13,12,11,10};
	
	int AVAIL = 10;
	
	int deleteNode  = 0;
	int point=START;
	
	while(LINK[point] != deleteNode){
		point = LINK[point];
	}
	
	LINK[point]=LINK[deleteNode];
	LINK[deleteNode]=AVAIL;
	AVAIL=deleteNode;
	
	point = START;
	while(point != -1){
		printf("%d\n",INFO[point]);
		point = LINK[point];
	}
	
	
	
	
	
	
	return 0;
}