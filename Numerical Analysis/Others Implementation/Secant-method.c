#include <stdio.h>
#include <math.h>
#define f(x) (x * x * x - 2 * x - 5)

int main()
{
	double a = 0, b = 0;
	double x1 = 0, x2 = 0;

	// Step 1 : finding the value of x1 and x2
	while (1)
	{
		/*
			ekhane dui bhabe check kortechi,
			dhoren,
			1) (0 1), (1,2) , ...
			2) (0,-1), (-1,-2), ....
			ig, yk why.
		*/
		if (f(a) * f((a - (double)1.0000)) < 0)
		{
			printf("%lf %lf", f(a), f((a - (double)1.0000)));
			x1 = a;
			x2 = a - 1;

			break;
		}
		if (f(b) * f((b + (double)1.0000)) < 0)
		{
			x1 = b;
			x2 = b + 1;
			break;
		}
		a--;
		b++;
	}
	// Step 2 & 3 : finding the root

	// we'll just jot down the steps which are written on the blog
	double ans = 1e9; // Just assume a number which can never be the answer
	while (1)
	{
		double prevAns = ans;
		double x = ((x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)));
		ans = x;
		x1 = x2;
		x2 = x;
		// Calculating the the  literation of last two answer
		if (fabs((prevAns) - (ans)) <= 0.001)
		{
			break;
		}
	}

	// Printing the answer
	printf("%lf", ans);
	return 0;
}
