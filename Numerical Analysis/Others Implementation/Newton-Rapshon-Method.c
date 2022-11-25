#include <stdio.h>
#include <math.h>
#define f(x) (x * x * x - 2 * x - 5)
#define diff(x) (3 * x * x - 2)
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

    // MAIN CODE
    double x0;
    double ans;
    if (fabs(f(x1)) < fabs(f(x2)))
        x0 = x1;
    else
        x0 = x2;

    while (1)
    {
        double x = x0 - (f(x0) / diff(x0));
        if (fabs(x - x0) <= 0.001)
        {
            ans = x;
            break;
        }
        x0 = x;
    }
    printf("%lf", ans);
    return 0;
}