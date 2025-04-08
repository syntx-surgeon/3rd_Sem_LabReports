// Secant Method
#include <stdio.h>
#include <math.h>
#include <conio.h>
#define EPS 0.000001
float fl(float x)
{
   return sin(x)-2*x+1;
}

int main()
{
   float a, b, c;
   int n = 0;
   do
   {

      printf("Enter teo valid  intial points a and b\n");
      scanf("%f%f", &a, &b);
   } while (fl(a) == fl(b));
   
    printf("f(x)= sin(x)-2*x+1\n");
    printf("Input\n");
    printf("a = %f\nb= %f \n", a, b);
   do
   {
      n++;
      c = (a * fl(b) - b * fl(a)) / (fl(b) - fl(a));
      if (fl(c) == 0)
         break;
      a = b;
      b = c;
   } while (fabs((b - a) / b) > EPS);

   printf("The approximation root of given function is %f with %d number of iteration", c, n);
   getch();
   return 0;
}