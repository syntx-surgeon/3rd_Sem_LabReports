// 2D Shearing of a Triangle in C using graphics.h
// This program uses the graphics.h library to perform 2D shearing on a triangle.
#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

}

void shearTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float shx, float shy) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw original triangle in WHITE
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);

    // Apply shearing transformation
    int x1_sheared = x1 + shx * y1;
    int y1_sheared = y1 + shy * x1;
    int x2_sheared = x2 + shx * y2;
    int y2_sheared = y2 + shy * x2;
    int x3_sheared = x3 + shx * y3;
    int y3_sheared = y3 + shy * x3;

    // Draw sheared triangle in RED
    drawTriangle(x1_sheared, y1_sheared, x2_sheared, y2_sheared, x3_sheared, y3_sheared, RED);


    printf("\nSheared Triangle Points:\n");
    printf("A'(%d, %d)\n", x1_sheared, y1_sheared);
    printf("B'(%d, %d)\n", x2_sheared, y2_sheared);
    printf("C'(%d, %d)\n", x3_sheared, y3_sheared);

    getch();
    closegraph();
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    float shx, shy;

    printf("Enter first vertex (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter second vertex (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter third vertex (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    printf("Enter shearing factors (shx, shy): ");
    scanf("%f %f", &shx, &shy);

    shearTriangle(x1, y1, x2, y2, x3, y3, shx, shy);

    return 0;
}