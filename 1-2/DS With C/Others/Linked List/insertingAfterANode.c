#include<stdio.h>

int main(){
	//adding after a specific VALUE not NODE
	
	int START=6;
	int INFO[1000] = {55,23,64,78,10,25,10,32,64,20};
	int LINK[1000]={5,3,-1,4,2,1,9,0,7,8,20,19,18,17,16,15,14,13,12,11,10};
	
	int AVAIL = 10;
	
	int addAfter = 64;
	int VALUE=36;
	int point=START;
	
	while(INFO[point] != addAfter)
		point = LINK[point];
	
	
	point=LINK[point];
	
	int NEW = LINK[AVAIL];
	
	INFO[AVAIL]=INFO[point];
	LINK[AVAIL]=LINK[point];
	
	
	INFO[point]	= VALUE;
	LINK[point]	= AVAIL;
	
	AVAIL=NEW;
	
		
	point = START;
	while(point != -1){
		printf("%d\n",INFO[point]);
		point = LINK[point];
	}	
	
	
	
	return 0;
}