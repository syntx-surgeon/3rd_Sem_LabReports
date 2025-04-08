// Fixed point Iteration Method

#include <stdio.h>
#include <math.h>
#define EPS 0.000001
float g(float x)
{
    return (sin(x) + 10) / 10;
}

int main()
{
    float x0, x1;
    int n = 1;
    printf("Enter the initial point x0:\n");
    scanf("%f", &x0);

    printf("g(x)= (sin(x)+10)/10\n");
    printf("Input\n");
    printf("x0 = %f\n", x0);

    x1 = g(x0);
    while (fabs(g(x1 - x0) / x1) > EPS)
    {
        n++;
        x0 = x1;
        x1 = g(x0);
        if (g(x1) == x1)
            break;
    }

    printf("The approximation root of given function is %f with  %d number of iteration:\n", x1, n);
    return 0;
}