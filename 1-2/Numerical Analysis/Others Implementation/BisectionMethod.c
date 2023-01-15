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
	double x;	// the intermediate poing
	double ans; // we're gonna store our answer here
	while (1)
	{
		x = (x1 + x2) / 2; // the second step
		// the third step
		if (f(x1) * f(x) < 0)
			x2 = x;
		if (f(x2) * f(x) < 0)
			x1 = x;
		// break the loop(idea from class)
		if (fabs((x1) - (x2)) <= 0.001)
		{
			ans = x;
			break;
		}
	}

	printf("%lf", ans);
	return 0;
}
