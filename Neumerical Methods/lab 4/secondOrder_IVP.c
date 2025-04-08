#include <stdio.h>
#include <math.h>

#define EPS 0.00001

float f1(float x, float y1, float y2) {
    // return y2; // y' = y2
    return y2; // y' = y2
}

float f2(float x, float y1, float y2) {
    // return -y1; // Example of a simple harmonic oscillator
    return 2 * x - y1 - y2; // Example of a different second equation
}

// Routine for Heun's method
float heun(float x0, float x1, float y0, float y1, float h) {
    float m11, m12, m21, m22;

    while (fabs(x0 - x1) > EPS) {
        m11 = f1(x0, y0, y1);
        m21 = f2(x0, y0, y1);
        m12 = f1(x0 + h, y0 + h * m11, y1 + h * m21);
        m22 = f2(x0 + h, y0 + h * m11, y1 + h * m21);
        y0 = y0 + 0.5 * h * (m11 + m12);
        y1 = y1 + 0.5 * h * (m21 + m22);
        x0 = x0 + h;
    }

    return y0;
}

int main() {
    float x0, yx0, yx1, xp, yxp, h;
    char q;
    printf("\n Enter the initial point x: ");
    scanf("%f", &x0);

    printf("\n Enter the value of y(x): ");
    scanf("%f", &yx0);

    printf("\n Enter the value of y'(x): ");
    scanf("%f", &yx1);

    printf("\n Enter the step length (h): ");
    scanf("%f", &h);

    do {
        printf("\n\n Enter the point x at which y(x) is required: ");
        scanf("%f", &xp);
        yxp = heun(x0, xp, yx0, yx1, h);
        printf("\n The approximate value of y(%.2f) is %.6f.", xp, yxp);
        printf("\n\n Do you want to approximate at another point? (y/n): ");
        scanf(" %c", &q); // Note the space before %c to consume any leftover newline
    } while (q == 'y' || q == 'Y');

    return 0;
}