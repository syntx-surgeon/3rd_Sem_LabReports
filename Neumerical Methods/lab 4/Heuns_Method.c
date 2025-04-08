//Heun's Method
#include <stdio.h>
#include <math.h>

float f(float x, float y) {
   return x/y;  // Example ODE function: dy/dx = y - x^2 + 1
}

int main() {
   int i, n;
   float x, y, xp, h, m1, m2;

   // Input initial values for x and y
   printf("\nInput the initial values of x and y: ");
   scanf("%f %f", &x, &y);

   // Input the value of x at which y is required
   printf("\nInput x at which y is required: ");
   scanf("%f", &xp);

   // Input the step-size h
   printf("\nInput the step-size h: ");
   scanf("%f", &h);

   // Calculate the number of iterations needed
   n = (int)((xp - x) / h + 0.5);

   // Printing header for output
   printf("\nStep\t x\t\t y\n");

   // Perform Heun's Method
   for(i = 1; i <= n; i++) {
       m1 = f(x, y);  // slope at the current point
       m2 = f(x + h, y + m1 * h);  // slope at the next point using Euler's method

       x = x + h;  // Update x
       y = y + 0.5 * h * (m1 + m2);  // Update y using the average slope

       // Print the current step values of x and y
       printf("%d\t %.4f\t %.4f\n", i, x, y);
   }

   // Final result
   printf("\nThe value of y at x = %.4f is %.4f\n", x, y);

   return 0;
}