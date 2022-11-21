#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	printf("The number of x and f(x)");
	scanf("%d", &n);
	double x[n], y[n], xi;
	printf("Write the number of x:");
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &x[i]);
	}
	printf("Write the number of f(x):");
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &y[i]);
	}

	printf("X = ");
	scanf("%lf", &xi);

	double da[n][n];
	for (int j = 0; j < n; j++)
	{
		da[j][0] = y[j];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{

			// printf(" %lf  %lf ", da[j + 1][i - 1], da[j][i - 1]);
			da[j][i] = (da[j + 1][i - 1] - da[j][i - 1]) / (x[i + j] - x[j]);
		}
	}

	// double p = (xi - x[0]) / (x[1] - x[0]);
	double ans = y[0];
	for (int i = 1; i < n; i++)
	{
		double localP = 1.00;

		for (int j = 1; j <= i; j++)
		{
			localP *= (x[i] - x[i - 1]);
		}
		ans += (localP)*da[0][i];
	}

	printf(" %lf ", ans);

	return 0;
}