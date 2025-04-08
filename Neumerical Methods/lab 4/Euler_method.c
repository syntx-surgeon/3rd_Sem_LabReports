//Euler's Method
#include<stdio.h>
#include<math.h>

float f(float x, float y){
//    return x*x + y*y; // Example ODE function: dy/dx = x^2 + y^2
    return x + y; // Example ODE function: dy/dx = x + y
    // You can change this function to any other ODE you want to solve.
}

int main(){
   int i, n;
   float x, y, xp, h, dy;

   // Input initial values for x and y
   printf("Input initial values of x and y: ");
   scanf("%f%f", &x, &y);

   // Input the value of x at which y is required
   printf("Input x at which y is required: ");
   scanf("%f", &xp);

   // Input the step-size h
   printf("Input step-size h: ");
   scanf("%f", &h);

   // Calculate the number of iterations needed
   n = (int)((xp - x) / h + 0.5);

   // Printing the header
   printf("\nStep\t x\t\t y\n");

   // Perform Euler's Method
   for(i = 1; i <= n; i++){
       dy = h * f(x, y);
       x = x + h;
       y = y + dy;

       // Output current step values of x and y
       printf("%d\t %.4f\t %.4f\n", i, x, y);
   }

   // Final result
   printf("\nThe value of y at x = %.4f is %.4f\n", x, y);

   return 0;
}