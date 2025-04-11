// C program to reflect a triangle about the X-axis using graphics.h
#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void reflectTriangleX(int x1, int y1, int x2, int y2, int x3, int y3) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw original triangle in WHITE
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);

    // Reflection about X-axis: (x, y) -> (x, -y)
    int x1_reflected = x1, y1_reflected = getmaxy() - y1;
    int x2_reflected = x2, y2_reflected = getmaxy() - y2;
    int x3_reflected = x3, y3_reflected = getmaxy() - y3;

    // Draw reflected triangle in RED
    drawTriangle(x1_reflected, y1_reflected, x2_reflected, y2_reflected, x3_reflected, y3_reflected, RED);

    printf("\nReflected Triangle Points:\n");
    printf("A'(%d, %d)\n", x1_reflected, y1_reflected);
    printf("B'(%d, %d)\n", x2_reflected, y2_reflected);
    printf("C'(%d, %d)\n", x3_reflected, y3_reflected);

    getch();
    closegraph();
}

int main() {
    int x1, y1, x2, y2, x3, y3;

    printf("Enter first vertex (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter second vertex (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter third vertex (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    reflectTriangleX(x1, y1, x2, y2, x3, y3);

    return 0;
}