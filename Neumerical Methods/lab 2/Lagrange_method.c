#include <stdio.h>
#include <math.h>
#define MAX 15

int main()
{
    int i, n, j;
    float x[MAX], f[MAX], fp, lf, sum, xp;
    char q;
    printf("Input the number of data pairs:");
    scanf("%d", &n);
    printf("Input data pairs x(i) and values f(i) (one set in each line):");
    for (i = 0; i < n; i++)
        scanf("%f%f", &x[i], &f[i]);
    do
    {
        printf("Input x at which interpolation is required: ");
        scanf("%f%", &xp);
        sum = 0.0;
        for (i = 0; i < n; i++)
        {
            lf = 1.0;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                    lf = lf * (xp - x[j]) / (x[i] - x[j]);
            }
            sum = sum + lf * f[i];
        }

        fp = sum;
        printf("Interpolated function value at x=%f is %f ", xp, fp);
        printf("Do you want to input another value?(y/n):");
        scanf("%s", &q);

    } while (q == 'y');
    return 0;
}