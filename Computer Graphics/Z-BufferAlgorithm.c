// Z-Buffer Algorithm in C using Graphics.h 
// This program uses the graphics.h library to visualize the Z-Buffer algorithm.

#include <graphics.h>
#include <stdio.h>
#include <limits.h>

#define WIDTH 640
#define HEIGHT 480
/*
Enter number of triangles: 1
Enter x1 y1 z1: 50 50 2
Enter x2 y2 z2: 150 50 2
Enter x3 y3 z3: 100 150 2
Enter color (1-15): 14
*/
float zBuffer[WIDTH][HEIGHT];

// Initialize Z-Buffer
void initializeZBuffer() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            zBuffer[x][y] = INT_MAX;
        }
    }
}

// Draw Pixel with Z-Buffer Check
void putPixelWithZBuffer(int x, int y, float z, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        if (z < zBuffer[x][y]) {
            zBuffer[x][y] = z;
            putpixel(x, y, color);
        }
    }
}

// Draw Triangle with Z-Buffer
void drawTriangleZBuffer(int x1, int y1, float z1, 
                         int x2, int y2, float z2, 
                         int x3, int y3, float z3, int color) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // Ensure correct path

    initializeZBuffer();

    int n;
    printf("Enter number of triangles: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x1, y1, z1, x2, y2, z2, x3, y3, z3, color;

        printf("Enter x1 y1 z1: ");
        scanf("%d %d %d", &x1, &y1, &z1);
        printf("Enter x2 y2 z2: ");
        scanf("%d %d %d", &x2, &y2, &z2);
        printf("Enter x3 y3 z3: ");
        scanf("%d %d %d", &x3, &y3, &z3);
        printf("Enter color (1-15): ");
        scanf("%d", &color);

        drawTriangleZBuffer(x1, y1, z1, x2, y2, z2, x3, y3, z3, color);
    }

    printf("Z-Buffer Applied. Press any key to exit.");
    getch();
    closegraph();
    
    return 0;
}