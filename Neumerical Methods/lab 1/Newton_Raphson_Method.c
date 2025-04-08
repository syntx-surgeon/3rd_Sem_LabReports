// newton raphson method

#include <stdio.h>
#include <math.h>
#include <conio.h>
#define EPS 0.000001

float f(float x)
{
   return x*x-3*x;
}
float f1(float x)
{
   return 2 * x-3;
}

int main()
{
   float a, b,c;
   int n = 0;
   printf("Enter the valid inital value\n");
   do
   {
      scanf("%f", &b);
      c=b;
   } while (f1(b) == 0);

    printf("f(x)= x*x-3*x\n");
    printf("Input\n");
    printf("a = %f\n",b);

   do
   {
      n++;
      a = b;
      b = a - (f(a) / f1(a));
      if (f(a) == 0)
         break;

   } while (fabs((b - a) / a) > EPS);

   // printf("Input Value\n");
   // printf("a = %f \n",c);
   printf("The approximation root of fiven function is = %f \n with %d iteration\n", a, n);
   getch();
   return 0;
}