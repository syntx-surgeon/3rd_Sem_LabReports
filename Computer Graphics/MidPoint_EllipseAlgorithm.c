// Mid-Point Ellipse Algorithm in C
// This program uses the graphics.h library to draw an ellipse using the Mid-Point Ellipse Algorithm.
//Mid-Point Ellipse
#include <graphics.h>
#include <stdio.h>
#include <math.h>

void drawEllipse(int xc, int yc, int a, int b) {
    int x = 0, y = b;
    int a2 = a * a, b2 = b * b;
    int p = round(b2 - (a2 * b) + (0.25 * a2));

    // Region 1
    while (a2 * y > b2 * x) {
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        if (p < 0) p += b2 * (2 * x + 3);
        else { p += b2 * (2 * x + 3) + a2 * (-2 * y + 2); y--; }
        x++;
    }

    // Region 2
    p = round(b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2);
    while (y >= 0) {
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        if (p > 0) p += a2 * (-2 * y + 3);
        else { p += a2 * (-2 * y + 3) + b2 * (2 * x + 2); x++; }
        y--;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    int xc, yc, a, b;
    printf("Enter center (xc, yc) and axes (a, b): ");
    scanf("%d %d %d %d", &xc, &yc, &a, &b);

    drawEllipse(xc, yc, a, b); // Draw the ellipse
    getch(); // Wait for a key press
    closegraph(); // Close graphics mode
    return 0;
}
