// 3D Rotation of a Triangle in C using Graphics.h
// This program uses the graphics.h library to perform 3D rotation of a triangle in C.

#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>

#define PI 3.14159265
/*
Input to be given:
Enter the coordinates of the triangle:
Vertex 1 (x1, y1, z1): 100 100 50
Vertex 2 (x2, y2, z2): 200 100 50
Vertex 3 (x3, y3, z3): 150 200 50
Enter rotation angle (degrees): 45
Rotate about which axis? (1 = X, 2 = Y, 3 = Z): 1
*/
// Function to rotate around X-axis
void rotateX(float x, float y, float z, float angle, float *x_new, float *y_new, float *z_new) {
    float rad = angle * (PI / 180.0);
    *x_new = x;
    *y_new = y * cos(rad) - z * sin(rad);
    *z_new = y * sin(rad) + z * cos(rad);
}

// Function to rotate around Y-axis
void rotateY(float x, float y, float z, float angle, float *x_new, float *y_new, float *z_new) {
    float rad = angle * (PI / 180.0);
    *x_new = x * cos(rad) + z * sin(rad);
    *y_new = y;
    *z_new = -x * sin(rad) + z * cos(rad);
}

// Function to rotate around Z-axis
void rotateZ(float x, float y, float z, float angle, float *x_new, float *y_new, float *z_new) {
    float rad = angle * (PI / 180.0);
    *x_new = x * cos(rad) - y * sin(rad);
    *y_new = x * sin(rad) + y * cos(rad);
    *z_new = z;
}

// Function to draw a 3D triangle (before and after rotation)
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, int color) {
    setcolor(color);
    line(x1 + 320, 240 - y1, x2 + 320, 240 - y2);
    line(x2 + 320, 240 - y2, x3 + 320, 240 - y3);
    line(x3 + 320, 240 - y3, x1 + 320, 240 - y1);
}

int main() {
    int gd = DETECT, gm;
    float x1, y1, z1, x2, y2, z2, x3, y3, z3;
    float x1_new, y1_new, z1_new, x2_new, y2_new, z2_new, x3_new, y3_new, z3_new;
    float angle;
    int axis;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // Get user input for 3D triangle vertices
    printf("Enter the coordinates of the triangle:\n");
    printf("Vertex 1 (x1, y1, z1): ");
    scanf("%f %f %f", &x1, &y1, &z1);
    printf("Vertex 2 (x2, y2, z2): ");
    scanf("%f %f %f", &x2, &y2, &z2);
    printf("Vertex 3 (x3, y3, z3): ");
    scanf("%f %f %f", &x3, &y3, &z3);

    // Get rotation details
    printf("Enter rotation angle (degrees): ");
    scanf("%f", &angle);
    printf("Rotate about which axis? (1 = X, 2 = Y, 3 = Z): ");
    scanf("%d", &axis);

    // Draw original triangle in WHITE
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);

    // Apply rotation based on user input
    if (axis == 1) {
        rotateX(x1, y1, z1, angle, &x1_new, &y1_new, &z1_new);
        rotateX(x2, y2, z2, angle, &x2_new, &y2_new, &z2_new);
        rotateX(x3, y3, z3, angle, &x3_new, &y3_new, &z3_new);
    } else if (axis == 2) {
        rotateY(x1, y1, z1, angle, &x1_new, &y1_new, &z1_new);
        rotateY(x2, y2, z2, angle, &x2_new, &y2_new, &z2_new);
        rotateY(x3, y3, z3, angle, &x3_new, &y3_new, &z3_new);
    } else if (axis == 3) {
        rotateZ(x1, y1, z1, angle, &x1_new, &y1_new, &z1_new);
        rotateZ(x2, y2, z2, angle, &x2_new, &y2_new, &z2_new);
        rotateZ(x3, y3, z3, angle, &x3_new, &y3_new, &z3_new);
    } else {
        printf("Invalid axis choice!\n");
        closegraph();
        return 1;
    }

    // Draw rotated triangle in RED
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new, RED);

    // Pause and wait for user input before closing
    getch();
    closegraph();

    return 0;
}
