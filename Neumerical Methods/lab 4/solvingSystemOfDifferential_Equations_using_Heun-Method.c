//Solving system of Differential Equations
#include<stdio.h>
#include<math.h>
#define EPS 0.00001

// Defining the system of differential equations
float f1(float x, float y1, float y2) {
//    return -4 * y1 - 2 * y2 + cos(x) + 4 * sin(x);
    return 2 * y1 + y2 - 2 ;
    //return 3 * y1 + y2 - 3 * sin(x);
    //return 4 * y1 + y2 - 4 * sin(x);
    //return 5 * y1 + y2 - 5 * sin(x);
    //return 6 * y1 + y2 - 6 * sin(x);
    //return 7 * y1 + y2 - 7 * sin(x);
    //return 8 * y1 + y2 - 8 * sin(x);
}

float f2(float x, float y1, float y2) {
//    return 3 * y1 + y2 - 3 * sin(x);
    // return 2 * y1 + y2 - 2 * sin(x) - 2 * cos(x);
    //return 4 * y1 + y2 - 4 * sin(x);
    return 5 * y1 + y2 ;
    //return 6 * y1 + y2 - 6 * sin(x);
    //return 7 * y1 + y2 - 7 * sin(x);
    //return 8 * y1 + y2 - 8 * sin(x);
}

// Routine for Heun's method to solve system of differential equations
void heun(float x0, float x1, float y0, float y1, float h) {
   float m11, m12, m21, m22;
   printf("\nCalculation of y1(x) and y2(x) for x = %f: ", x1);
   printf("\n\nx \t\t y1(x) \t\t y2(x)");

   // Loop until we reach the desired x1 value
   while (fabs(x0 - x1) > EPS) {
       printf("\n %f \t %f \t %f", x0, y0, y1);

       // Calculate slopes (derivatives)
       m11 = f1(x0, y0, y1);
       m21 = f2(x0, y0, y1);
       m12 = f1(x0 + h, y0 + h * m11, y1 + h * m21);
       m22 = f2(x0 + h, y0 + h * m11, y1 + h * m21);

       // Update values using Heun's method
       y0 = y0 + 0.5 * h * (m11 + m12);
       y1 = y1 + 0.5 * h * (m21 + m22);

       // Increment x0 by step size h
       x0 = x0 + h;
   }

   // Final values at x1
   printf("\n %f \t %f \t %f", x0, y0, y1);
}

int main() {
   float x0, yx0, yx1, xp, h;
   char q;

   // Input initial conditions and parameters
   printf("\nEnter the initial point x0: ");
   scanf("%f", &x0);
   printf("\nEnter the value of y1(x0): ");
   scanf("%f", &yx0);
   printf("\nEnter the value of y2(x0): ");
   scanf("%f", &yx1);
   printf("\nEnter the step size h: ");
   scanf("%f", &h);

   // Loop for repeated calculations at different points
   do {
       printf("\n\nEnter the point x at which y1(x) and y2(x) are required: ");
       scanf("%f", &xp);

       // Call Heun's method to calculate values at xp
       heun(x0, xp, yx0, yx1, h);

       // Ask user if they want to calculate at another point
       printf("\n\nDo you want to approximate at another point? (y/n): ");
       scanf(" %c", &q); // Notice the space before %c to clear the buffer
   } while (q == 'y');

   return 0;
}