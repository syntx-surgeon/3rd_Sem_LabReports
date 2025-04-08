//Boundary Value Problem using Shooting Method
#include<stdio.h>
#include<math.h>

#define EPS 0.00001

// Function to return y2 (first derivative of y1)
float f1(float x, float y1, float y2) {
   return y2;
}

// Function to return the second derivative (f2)
float f2(float x, float y1, float y2) {
   return -3 *y2+2*y1+2*x+3;
}

// Heun's method to solve second-order ODE
float heun(float x0, float x1, float y0, float y1, float h) {
   float m11, m12, m21, m22;
   printf("\n\nCalculation of y(%f) for guess value %f: ", x1, y1);
   printf("\n x \t\t y(x)");

   while (fabs(x0 - x1) > EPS) {
       m11 = f1(x0, y0, y1);  // First slope at (x0, y0)
       m21 = f2(x0, y0, y1);  // Second slope at (x0, y0)

       // Compute slopes at the next step (x0 + h)
       m12 = f1(x0 + h, y0 + h * m11, y1 + h * m21);
       m22 = f2(x0 + h, y0 + h * m11, y1 + h * m21);

       // Update y0 and y1 using Heun's method
       y0 = y0 + 0.5 * h * (m11 + m12);
       y1 = y1 + 0.5 * h * (m21 + m22);

       // Increment x by step size
       x0 = x0 + h;
   }

   printf("\n%f\t%f", x0, y0);
   return y0;
}

int main() {
   float x0, yx0, x1, yx1, guess1, guess2, guess3, yguess1, yguess2, yguess3, xp, yxp, h;
   char q;

   // Input boundary conditions
   printf("\nEnter the first boundary conditions x and y(x): ");
   scanf("%f%f", &x0, &yx0);

   printf("\nEnter the secondary boundary condition x and y(x): ");
   scanf("%f%f", &x1, &yx1);

   printf("\nEnter the step length: ");
   scanf("%f", &h);

   // First guess for y'
   printf("\nEnter the first guess of y'(%f): ", x0);
   scanf("%f", &guess1);

   // Apply Heun's method to calculate y(x) for the first guess
   yguess1 = heun(x0, x1, yx0, guess1, h);
   printf("\nThe calculated value of y(%f) is %f.", x1, yguess1);

   if (fabs(yguess1 - yx1) < EPS) {
       guess3 = guess1;  // If the guess is good enough, we're done
   } else {
       // If the first guess is not good, try a second guess
       printf("\n\nEnter the second guess of y'(%f): ", x0);
       scanf("%f", &guess2);

       // Apply Heun's method to calculate y(x) for the second guess
       yguess2 = heun(x0, x1, yx0, guess2, h);
       printf("\nThe calculated value of y(%f) is %f.", x1, yguess2);

       if (fabs(yguess2 - yx1) < EPS) {
           guess3 = guess2;  // If the second guess works, we're done
       } else {
           // Use the secant method to improve the guess
           do {
               guess3 = guess2 + (yx1 - yguess2) * (guess1 - guess2) / (yguess1 - yguess2);
               yguess3 = heun(x0, x1, yx0, guess3, h);
               guess1 = guess2;
               guess2 = guess3;
               yguess1 = yguess2;
               yguess2 = yguess3;
           } while (fabs(yguess2 - yx1) >= EPS);

           printf("\n\nThe extrapolated value of y'(%f) is %f.", x0, guess3);
           printf("\n\nThe calculated value of y(%f) using y'(%f)=%f is %f.", x1, x0, guess3, yguess3);
       }
   }

   // Allow the user to enter other points to approximate y(x)
   do {
       printf("\n\nEnter the point x at which y(x) is required: ");
       scanf("%f", &xp);

       // Calculate y(xp) using the final guess for y'
       yxp = heun(x0, xp, yx0, guess3, h);
       printf("\nThe approximate value of y(%f) is %f.", xp, yxp);

       printf("\n\nDo you want to approximate at another point? (y/n): ");
       scanf(" %c", &q);  // Note the space before %c to handle newline character

   } while (q == 'y' || q == 'Y');  // Repeat if the user wants another approximation

   return 0;
}