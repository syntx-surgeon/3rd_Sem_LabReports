//4th order RK method
#include<stdio.h>
#include<math.h>

float f(float x, float y) {
   return y +x;  // Define the differential equation: dy/dx = y * cos(x)
}

int main() {
   int i, n;
   float x, y, xp, h, m1, m2, m3, m4;

   // Input initial values for x and y
   printf("Input initial value of x and y: ");
   scanf("%f %f", &x, &y);

   // Input the value of x at which y is required
   printf("Input x at which y is required: ");
   scanf("%f", &xp);

   // Input the step-size h
   printf("Input step-size h: ");
   scanf("%f", &h);

   // Calculate the number of iterations needed
   n = (int)((xp - x) / h + 0.5);

   // Printing header for output
   printf("\nStep\t x\t\t y\n");

   // Perform RK4 method
   for(i = 1; i <= n; i++) {
       m1 = f(x, y);  // Calculate m1
       m2 = f(x + 0.5 * h, y + 0.5 * m1 * h);  // Calculate m2
       m3 = f(x + 0.5 * h, y + 0.5 * m2 * h);  // Calculate m3
       m4 = f(x + h, y + m3 * h);  // Calculate m4

       x = x + h;  // Update x
       y = y + (m1 + 2.0 * m2 + 2.0 * m3 + m4) * h / 6.0;  // Update y using RK4 formula

       // Print the current step values of x and y
       printf("%d\t %.4f\t %.4f\n", i, x, y);
   }

   // Final result
   printf("\nThe value of y at x = %.4f is %.4f\n", x, y);

   return 0;
}