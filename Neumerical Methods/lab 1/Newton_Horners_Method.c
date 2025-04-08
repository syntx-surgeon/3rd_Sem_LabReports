//Newton's Horner for polynomial
#include<stdio.h>
#include<math.h>
#define EPS 0.00001

void horner(int n, float a[], float x0, float p[])
{
    int i;
    p[0] = a[n], p[1] = a[n];
    for (i = n - 1; i >= 1; i--)
    {
        p[0] = a[i] + p[0] * x0;
        p[1] = p[0] + p[1] * x0;
    }
    p[0] = a[0] + p[0] * x0;
}

int main()
{
    float a[10], p[2], x0, x1;
    int i, n, count = 1;
    printf("Enter the degree of poynomial:\n");
    scanf("%d", &n);
    printf("Enter the coefficient of the polynomial starting from the highest degree:\n");
    for (i = n; i >= 0; i--)
    {
        scanf("%f", &a[i]);
    }

    printf("Enter the valid initial point x0:\n");
    scanf("%f", &x0);

    horner(n, a, x0, p);
    x1 = x0 - (p[0] / p[1]);
    while (fabs((x1 - x0) / x1) > EPS)
    {
        count++;
        x0 = x1;
        horner(n, a, x0, p);
        x1 = x0 - (p[0] / p[1]);
    }

    printf("The approximation root of given fuction is %f with %d  number of iteration\n", x1, count);
    return 0;
}