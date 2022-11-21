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

    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        double localAns = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            localAns *= (xi - x[j]);
            localAns /= (x[i] - x[j]);
        }
        ans += localAns * y[i];
    }
    printf(" %lf ", ans);

    return 0;
}