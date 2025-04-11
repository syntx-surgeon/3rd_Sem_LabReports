// File: 2D_Translation.c
// Description: This program demonstrates 2D translation of a triangle in graphics using C.
//2D Translation
#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    int x1, y1, x2, y2, x3, y3;
    int dx, dy;

    // Input original triangle vertices
    printf("Enter the coordinates of the triangle vertices (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Input translation values
    printf("Enter translation values (dx dy): ");
    scanf("%d %d", &dx, &dy);

    // Translate the triangle
    x1 += dx; y1 += dy;
    x2 += dx; y2 += dy;
    x3 += dx; y3 += dy;

    // Draw the translated triangle
    setcolor(RED); // Change color for the translated triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Wait for a key press
    getch();

    // Close the graphics mode
    closegraph();
    return 0;
}
