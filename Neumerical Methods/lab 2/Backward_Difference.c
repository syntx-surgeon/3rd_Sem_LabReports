#include <stdio.h>
#include <math.h>
#include <conio.h>
#define MAX 15

int main()
{
    int n, i, j, k;
    float x[MAX], fx[MAX], bd[MAX], xp, s, h, v, p;
    printf("\nInput the number of data pairs:");
    scanf("%d", &n);
    printf("\nInput data pairs x(i) and values f(i) (one set in each line):\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%f%f", &x[i], &fx[i]);
    }
    h = x[2] - x[1];

    printf("\nEnter the value at which interpolation is required:");
    scanf("%f", &xp);
    s = (xp - x[n]) / h;
    p = 1;
    v = fx[n];

    for (i = 1; i <= n; i++)
        bd[i] = fx[i];
    for (i = n, k = 1; i >= 1, k < n; i--, k++)
    {
        for (j = n; j >= n - i; j--)
        {
            bd[j] = bd[j] - bd[j - 1];
        }
        p = p * (s + k - 1) / k;
        v = v + p * bd[n];
    }

    printf("\nInterpolated function value at x=%f is %f.", xp, v);

    getch();
    return 0;
}