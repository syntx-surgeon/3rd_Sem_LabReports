// Liang-Barsky Line Clipping Algorithm in C
// This program uses the graphics.h library for drawing.    
// Make sure to have the graphics library installed and linked properly.
// Compile with: gcc -o liang_barsky liang_barsky.c -lgraph -lm

#include <stdio.h>
#include <graphics.h>
/*
Input to be given
Enter the coordinates of the line (x1 y1 x2 y2): 50 200 350 200
*/
// Define clipping window boundaries
float x_min, y_min, x_max, y_max;

// Liang-Barsky Line Clipping function
void liangBarskyClip(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1, dy = y2 - y1;
    float t1 = 0, t2 = 1;
    float p[4], q[4];

    // Defining p and q for each boundary
    p[0] = -dx; q[0] = x1 - x_min;  // Left
    p[1] = dx;  q[1] = x_max - x1;  // Right
    p[2] = -dy; q[2] = y1 - y_min;  // Bottom
    p[3] = dy;  q[3] = y_max - y1;  // Top

    // Finding new t1 and t2 values
    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) return; // Parallel line outside
        } else {
            float t = q[i] / p[i];
            if (p[i] < 0) {
                if (t > t1) t1 = t; // Entering point
            } else {
                if (t < t2) t2 = t; // Leaving point
            }
        }
    }

    // If t1 > t2, line is completely outside
    if (t1 > t2) return;

    // Compute clipped points
    float x1_clipped = x1 + t1 * dx;
    float y1_clipped = y1 + t1 * dy;
    float x2_clipped = x1 + t2 * dx;
    float y2_clipped = y1 + t2 * dy;

    // Draw the clipped line in RED
    setcolor(RED);
    line(x1_clipped, y1_clipped, x2_clipped, y2_clipped);
}

int main() {
    int gd = DETECT, gm;
    float x1, y1, x2, y2;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // Define clipping window (Modify for better visualization)
    x_min = 100; y_min = 100;
    x_max = 300; y_max = 300;

    // Get user input for line coordinates
    printf("Enter the coordinates of the line (x1 y1 x2 y2): ");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    // Draw the clipping window (WHITE rectangle)
    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    // Draw the original line in WHITE
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    // Perform Liang-Barsky Line Clipping
    liangBarskyClip(x1, y1, x2, y2);

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}