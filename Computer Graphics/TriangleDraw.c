// C program to draw a triangle using graphics.h
// This program uses the graphics library to draw a triangle on the screen.
//triangle
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    // Draw the three sides of the triangle
    line(x1, y1, x2, y2); // Side 1
    line(x2, y2, x3, y3); // Side 2
    line(x3, y3, x1, y1); // Side 3
}

int main() {
    // Initialize the graphics system
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Adjust the path as necessary

    // Define the coordinates of the triangle's vertices
    int x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first vertex (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second vertex (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the third vertex (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    // Call the function to draw the triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Wait for a key press
    getch();

    // Close the graphics system
    closegraph();
    return 0;
}
    