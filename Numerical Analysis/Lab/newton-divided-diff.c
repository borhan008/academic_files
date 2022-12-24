#include <stdio.h>
#include<stdlib.h>
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

	double table[n][n];
	for (int j = 0; j < n; j++)
		table[j][0] = y[j];
	

	for (int i = 1; i < n; i++)
		for (int k = 0; k < n - i; k++)
		table[k][i] = (table[k + 1][i - 1] - table[k][i - 1]) / (x[i + k] - x[k]);
	
	double ans = y[0];
	for (int i = 1; i < n-1; i++)
	{
		double ansa = 1.00;
		for (int k = 0; k <= i-1; k++)
			ansa *= (X - x[k]);
		ans += (ansa)*table[0][i];
	}


	//printing ans
	printf("Ans: %lf ", ans);
	return 0;
}