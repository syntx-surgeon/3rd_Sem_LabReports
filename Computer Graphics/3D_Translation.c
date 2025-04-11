// 3D Translation using Perspective Projection in C using graphics.h
// This program uses the graphics.h library to perform 3D translation of a shape in perspective projection.

#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define d 500 
//Input to be given
// Enter the number of points in the shape: 3
// Enter the coordinates (x, y, z) for 3 points:
// Point 1: -330 -242 50
// Point 2: -130 -242 50
// Point 3: -230 -42 50
// Enter translation factors (Tx, Ty, Tz): 20 20 0

void project3D(int x, int y, int z, int *xp, int *yp) {
    *xp = x * d / (d + z) + getmaxx() / 2;  // Centering on screen
    *yp = y * d / (d + z) + getmaxy() / 2;
}

// Function to draw the original and translated 3D objects
void draw3DObject(int x[], int y[], int z[], int n, int Tx, int Ty, int Tz) {
    int xp[n], yp[n];       // Projected 2D points for original
    int xpt[n], ypt[n];     // Projected 2D points for translated

    // Convert original points to 2D using perspective projection
    for (int i = 0; i < n; i++) {
        project3D(x[i], y[i], z[i], &xp[i], &yp[i]);
    }

    // Convert translated points to 2D using perspective projection
    for (int i = 0; i < n; i++) {
        project3D(x[i] + Tx, y[i] + Ty, z[i] + Tz, &xpt[i], &ypt[i]);
    }

    // Draw original object (White)
    setcolor(WHITE);
    for (int i = 0; i < n - 1; i++) {
        line(xp[i], yp[i], xp[i + 1], yp[i + 1]);
    }
    line(xp[n - 1], yp[n - 1], xp[0], yp[0]);  // Closing the shape

    // Draw translated object (Red)
    setcolor(RED);
    for (int i = 0; i < n - 1; i++) {
        line(xpt[i], ypt[i], xpt[i + 1], ypt[i + 1]);
    }
    line(xpt[n - 1], ypt[n - 1], xpt[0], ypt[0]);  // Closing the shape
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // Initialize graphics mode

    int n;  // Number of vertices
    printf("Enter the number of points in the shape: ");
    scanf("%d", &n);

    int x[n], y[n], z[n];  // Arrays to store 3D coordinates
    int Tx, Ty, Tz;        // Translation factors

    // Get user input for original 3D points
    printf("Enter the coordinates (x, y, z) for %d points:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
    }

    // Get user input for translation values
    printf("Enter translation factors (Tx, Ty, Tz): ");
    scanf("%d %d %d", &Tx, &Ty, &Tz);

    // Draw original and translated 3D objects
    draw3DObject(x, y, z, n, Tx, Ty, Tz);

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}