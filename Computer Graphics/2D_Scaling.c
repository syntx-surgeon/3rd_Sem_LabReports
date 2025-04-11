
// C program to demonstrate reflection of a triangle about the X-axis using graphics.h
// This program uses the graphics.h library, which is specific to Turbo C/C++ and may not work in modern compilers.
#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void scaleTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float sx, float sy) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw original triangle (WHITE)
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);
    
    // Scaling transformation
    int x1_new = x1 * sx;
    int y1_new = y1 * sy;
    int x2_new = x2 * sx;
    int y2_new = y2 * sy;
    int x3_new = x3 * sx;
    int y3_new = y3 * sy;

    // Draw scaled triangle (RED)
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new, RED);

    getch();
    closegraph();
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    float sx, sy;

    printf("Enter first vertex (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter second vertex (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter third vertex (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    printf("Enter scaling factors (sx, sy): ");
    scanf("%f %f", &sx, &sy);

    scaleTriangle(x1, y1, x2, y2, x3, y3, sx, sy);

    return 0;
}

