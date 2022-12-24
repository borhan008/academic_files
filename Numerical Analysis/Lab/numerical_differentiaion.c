#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;
int main()
{
	//taking the total number of x
	printf("Enter number of x and y or f(x)\n");
	scanf("%d", &n);
	double x[n], y[n], X;
	
	
	// taking the value of X
	printf("jot down the value of x\n");
	for (int i = 0; i < n; i++)
		scanf("%lf", &x[i]);
	
	// taking the value of y/f(x)
	printf("write down the number of y or f(x):\n");
	for (int i = 0; i < n; i++)
		scanf("%lf", &y[i]);

	//taking the value of question
	printf("The X you want to get = ");
	scanf("%lf", &X);
	
	int Xindex;
	
	for(int i=0; i<n; i++){
		if(X == x[i]) Xindex=i;
	}

	double table[n][n];
	for (int j = 0; j < n; j++)
	{
		table[j][0] = y[j];
	}

	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			table[j][i] = (table[j + 1][i - 1] - table[j][i - 1]);

	double ans = 0.000000;
			

	for (int i = 0; i < n; i++)
	{
		if(i%2 == 1) 
			ans-=(1/(i+1))*(table[Xindex-i][i]);
		
		else  
			ans+=(1/(i+1))*(table[Xindex-i][i]);
	}

	printf("Ans for the 3rd derivative  :  %lf ", ans);

	return 0;
}