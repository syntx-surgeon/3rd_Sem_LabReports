// 3D Scaling of a Triangle using C Graphics
// This program uses the graphics.h library to perform 3D scaling of a triangle in C.

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
/*
Enter the original coordinates of the triangle:
Vertex 1 (x1, y1, z1): 50 100 0
Vertex 2 (x2, y2, z2): 100 50 0
Vertex 3 (x3, y3, z3): 80 150 0
Enter scaling factors (Sx, Sy, Sz): 1.5 1.5 1
*/
// Function to draw a 3D triangle
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, int color) {
    setcolor(color);
    line(x1 + 320, 240 - y1, x2 + 320, 240 - y2);
    line(x2 + 320, 240 - y2, x3 + 320, 240 - y3);
    line(x3 + 320, 240 - y3, x1 + 320, 240 - y1);
}

int main() {
    int gd = DETECT, gm;
    float x1, y1, z1, x2, y2, z2, x3, y3, z3;
    float sx, sy, sz;
    float x1_new, y1_new, z1_new, x2_new, y2_new, z2_new, x3_new, y3_new, z3_new;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // Get user input for the 3D triangle coordinates
    printf("Enter the original coordinates of the triangle:\n");
    printf("Vertex 1 (x1, y1, z1): ");
    scanf("%f %f %f", &x1, &y1, &z1);
    printf("Vertex 2 (x2, y2, z2): ");
    scanf("%f %f %f", &x2, &y2, &z2);
    printf("Vertex 3 (x3, y3, z3): ");
    scanf("%f %f %f", &x3, &y3, &z3);

    // Get scaling factors
    printf("Enter scaling factors (Sx, Sy, Sz): ");
    scanf("%f %f %f", &sx, &sy, &sz);

    // Draw original triangle in WHITE
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);

    // Apply 3D Scaling
    x1_new = x1 * sx;
    y1_new = y1 * sy;
    z1_new = z1 * sz;

    x2_new = x2 * sx;
    y2_new = y2 * sy;
    z2_new = z2 * sz;

    x3_new = x3 * sx;
    y3_new = y3 * sy;
    z3_new = z3 * sz;

    // Draw scaled triangle in RED
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new, RED);

    // Pause and wait for user input before closing
    getch();
    closegraph();

    return 0;
}