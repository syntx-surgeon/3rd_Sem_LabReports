// 3D Shearing Transformation in C using graphics.h
// This program demonstrates 3D shearing transformation on a triangle in C.

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
/*
Enter the original coordinates of the triangle:
Vertex 1 (x1, y1, z1): 50 100 0
Vertex 2 (x2, y2, z2): 100 50 0
Vertex 3 (x3, y3, z3): 80 150 0
Enter shearing factors (Shxy, Shxz, Shyx, Shyz, Shzx, Shzy): 0.5 0 0 0.5 0 0
*/
// Function to draw a 3D triangle
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, int color) {
    setcolor(color);
    int shiftX = 100; // Move left for better visibility
    line(x1 + shiftX, 240 - y1, x2 + shiftX, 240 - y2);
    line(x2 + shiftX, 240 - y2, x3 + shiftX, 240 - y3);
    line(x3 + shiftX, 240 - y3, x1 + shiftX, 240 - y1);
}

int main() {
    int gd = DETECT, gm;
    float x1, y1, z1, x2, y2, z2, x3, y3, z3;
    float shxy, shxz, shyx, shyz, shzx, shzy;
    float x1_new, y1_new, z1_new, x2_new, y2_new, z2_new, x3_new, y3_new, z3_new;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // Get user input for 3D triangle coordinates
    printf("Enter the original coordinates of the triangle:\n");
    printf("Vertex 1 (x1, y1, z1): ");
    scanf("%f %f %f", &x1, &y1, &z1);
    printf("Vertex 2 (x2, y2, z2): ");
    scanf("%f %f %f", &x2, &y2, &z2);
    printf("Vertex 3 (x3, y3, z3): ");
    scanf("%f %f %f", &x3, &y3, &z3);

    // Get shearing factors
    printf("Enter shearing factors (Shxy, Shxz, Shyx, Shyz, Shzx, Shzy): ");
    scanf("%f %f %f %f %f %f", &shxy, &shxz, &shyx, &shyz, &shzx, &shzy);

    // Draw original triangle in WHITE
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);

    // Apply 3D Shearing transformation
    x1_new = x1 + shxy * y1 + shxz * z1;
    y1_new = shyx * x1 + y1 + shyz * z1;
    z1_new = shzx * x1 + shzy * y1 + z1;

    x2_new = x2 + shxy * y2 + shxz * z2;
    y2_new = shyx * x2 + y2 + shyz * z2;
    z2_new = shzx * x2 + shzy * y2 + z2;

    x3_new = x3 + shxy * y3 + shxz * z3;
    y3_new = shyx * x3 + y3 + shyz * z3;
    z3_new = shzx * x3 + shzy * y3 + z3;

    // Draw sheared triangle in RED
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new, RED);

    // Pause and wait for user input before closing
    getch();
    closegraph();

    return 0;
}